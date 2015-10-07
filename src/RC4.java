import java.io.*;
import java.nio.ByteBuffer;
import java.nio.ByteOrder;
import java.text.DateFormat;
import java.util.*;

public class RC4 {
	private static final boolean DEBUG = false;
	
	private static final int NUM_FILES = 60; 
	private static final String INPUT_FILENAME_FORMAT = "input/A%02d.data";
	private static final String OUTPUT_FILENAME_FORMAT = "output/A%02d.out";
	private static final String KEY_FILENAME_FORMAT = "keys/A%02d.key";
	
	private static final int EXACT_FILE_NUMBER = 9; 
	
	private static final int N = 160;
	private static final int KEY_BYTE_SPACE = 90;
	
	private int KEY_LENGTH; // size of array K
	private int T;
	
	private ArrayList<byte[]> tuples;
	
	public RC4() {
		this.KEY_LENGTH = 0; // size of K, including 3 bytes of IV
		this.T = 0; // num of tuples
		tuples = new ArrayList<byte[]>();
	}
	
	public void run() throws IOException {
		// read the file
		// first 4 bytes = L
		// next 4 bytes = numTuples
		// (v1, v2, v3, x)
		// where (v1, v2, v3) is the 3 bytes IV
		// and x is the first byte output by RC4
		
		for (int ii = 0; ii < NUM_FILES; ii++) {
			System.out.printf("Reading from file: " + INPUT_FILENAME_FORMAT + "\n", ii);
			BufferedInputStream fs = new BufferedInputStream(new FileInputStream(String.format(INPUT_FILENAME_FORMAT, ii)));
			System.out.printf("Writing to file: " + OUTPUT_FILENAME_FORMAT + "\n", ii);
			BufferedWriter bw = new BufferedWriter(new FileWriter(String.format(OUTPUT_FILENAME_FORMAT, ii)));
			BufferedWriter keybw = new BufferedWriter(new FileWriter(String.format(KEY_FILENAME_FORMAT, ii)));
			
			bw.write("|-- BEGIN --------------------- " + String.format(INPUT_FILENAME_FORMAT, ii) + " -----------------------|\n");
			bw.write(Calendar.getInstance().getTime().toString() + "\n");
			System.out.println("Started at " + Calendar.getInstance().getTime().toString());
			// read the first 4 bytes for the value of L (also get keysize);
			byte[] bytesL = new byte[4];
			fs.read(bytesL);
			this.KEY_LENGTH = toInt(bytesL);
			System.out.println("Size of K = " + this.KEY_LENGTH);
			
			// read the second 4 bytes for the number of tuples
			byte[] bytesT = new byte[4];
			fs.read(bytesT);
			this.T = toInt(bytesT);
			System.out.println("numTuples = " + T);
			
			// read and store the tuples
			readTuples(fs);
			
			System.out.println("Done reading tuples");
			
			// initialise the master key array
			int[] k = new int[KEY_LENGTH];
			
			for (int c = 3; c < KEY_LENGTH; c++) { // we know the first 3 bytes (IV)
				// carry out fms for each known length of key
				fms(c, k, bw);
				System.out.println("finished " + c);
			}
			
			String keyString = getKeyString(k);
			keybw.write(keyString);
			
			bw.write("Final Key = " + Arrays.toString(k) + "\n");
			
			bw.write(Calendar.getInstance().getTime().toString() + "\n");
			bw.write("|-- END ----------------------- " + String.format(INPUT_FILENAME_FORMAT, EXACT_FILE_NUMBER) + " -----------------------|\n\n");
			
			// finally close
			fs.close();
			bw.flush();
			bw.close();
			keybw.flush();
			keybw.close();
			System.out.println("End");
		}
	}
	
	private void fms(int c, int[] k, BufferedWriter bw) throws IOException {
		// the frequency array for analysis
		int freq[] = new int[N];
		
		// read T tuples of 4 bytes
		for (int iii = 0; iii < T; iii++) { // TODO: REPLACE WITH <T WHEN NOT DEBUG
			
			byte[] tuple = tuples.get(iii);
			
			int r = (tuple[3] & 0xff); // the R value
			for (int i = 0; i < 3; i++) {
				k[i] = tuple[i] & (0xff);
			} // Setting the IVs
			
			// simulate ksa for c moves
			// then check the x + y == c
			
			// set up S
			int[] s = new int[N];
			for (int i = 0; i < N; i++) {
				s[i] = i;
			}
			
			// run ksa for C times
			int j = 0;
			for (int i = 0; i < c; i++) {
				j = (int) ((j + s[i] + k[i]) % N);
				int temp = s[j];
				s[j] = s[i];
				s[i] = temp;
			}
			
			// check the condition
			int x = s[1];
			int y = s[x];
			int z = (x + y) % N;
			
			if (x + y == c) {
//				bw.write("Tuple = " + toHexString(tuple) + "\n");
//				bw.write("Key = " + Arrays.toString(k) + "\n");
//				bw.write("R = " + (r & 0xff) + "\n");
//				bw.write("S[] = " + Arrays.toString(s) + "\n");
				// find jc
				int jc = 0;
				boolean jcFound = false;
				for (int i = 0; i < s.length; i++) {
					if (s[i] == r) {
						jc = i;
						jcFound = true;
						break;
					}
				}
				if (!jcFound) {
					System.out.println("JC NOT FOUND");
					return;
				}
				
//				bw.write("Jc = " + jc + "\n");
//				bw.write("J = " + j + "\n");
//				bw.write("S[C] = " + s[c] + "\n");
				// jc = j + s[c] + k[c] mod n
				// k[c] = jc - j - s[c] mod n
				int kc = (jc - j - s[c]) % N;
				if (kc < 0) {
					kc = kc + N;
				}
				//kc = kc % 90;

//				bw.write("Possible K[C] = " + kc + "\n");
				freq[kc]++;
			}
		} // end of reading all tuples
		
		bw.write(c + "th frequency array = " + toIndexedString(freq) + "\n");
		
		int mostLikelyKc = getMax(freq);
		int secondMostLikelyKc = getSecondMax(freq);
		bw.write(c+ "th most likely K[C] " + mostLikelyKc + "\n");
		bw.write(c+ "th second most likely K[C] " + secondMostLikelyKc + "\n");
		k[c] = mostLikelyKc;
		
		if (c == 4) {
			//k[c] = 63;
		}
	}

	private void readTuples(BufferedInputStream fs) throws IOException {
		tuples = new ArrayList<byte[]>();
		for (int i = 0; i < T; i++) {
			byte[] tuple = new byte[4];
			int bytesRead = fs.read(tuple);
			if (bytesRead == 4) {
				tuples.add(tuple);
			} else {
				System.out.println("Premature end of file");
				break;
			}
		}
	}
	
	
	
	
	
	
	// ------- helper methods
	
	private String getKeyString(int[] k) {
		StringBuffer sb = new StringBuffer();
		for (int i = 3; i < k.length - 1; i++) {
			sb.append(k[i] + " ");
		}
		sb.append(k[k.length - 1]);
		return sb.toString();
	}
	
	private int getMax(int[] freq) {
		int highest = 0;
		int index = 0;
		for (int i = 0; i < KEY_BYTE_SPACE; i++) {
			if (highest < freq[i]) {
				highest = freq[i];
				index = i;
			}
		}
		return index;
	}
	
	private int getSecondMax(int[] freq) {
		int highest = 0;
		int second = -1;
		int highestIndex = 0;
		int secondIndex = 0;
		for (int i = 0; i < KEY_BYTE_SPACE; i++) {
			if (highest < freq[i]) {
				second = highest;
				highest = freq[i];
				secondIndex = highestIndex;
				highestIndex = i;
			}
		}
		return secondIndex;
	}
	
	private int toInt(byte[] bs) {
		ByteBuffer bb = ByteBuffer.wrap(bs);
		bb.order(ByteOrder.LITTLE_ENDIAN);
		return bb.getInt();
	}
	
	private String toHexString(byte[] bs) {
		StringBuilder sb = new StringBuilder();
	    for (byte b : bs) {
	        sb.append(String.format("%02X ", b));
	    }
	    return sb.toString();
	}
	
	private String toIntString(byte[] bs) {
		StringBuilder sb = new StringBuilder();
	    for (byte b : bs) {
	        sb.append(String.format("%02d ", b));
	    }
	    return sb.toString();
	}
	
	private String toIndexedString(int[] freq) {
		StringBuilder sb = new StringBuilder();
		sb.append("[");
	    for (int i = 0; i < freq.length - 1; i++) {
	        sb.append(String.format("(%d: %d), ", i, freq[i]));
	    }
	    sb.append(String.format("%d: %d", freq.length - 1, freq[freq.length - 1]));
	    sb.append("]");
	    return sb.toString();
	}

	
	
	


	public static void main(String[] args) {
		try {
			new RC4().run();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}



/*totalConditionsPassedTuples++;
System.out.println("Condition Met at Tuple " + t + ": locations " + 1 + ", " + xi + " and " + zi + " may not change, with p>0.05");

long r = Integer.toUnsignedLong(tuple[3] & 0xff);
System.out.println("Value of R is " + r);
// if the locations remain unchanged, then Si+1[zi] must be R
// means Si[ji] must be R
// since S is all unique number, we can do a linear search to find the position it occured --> ji
int ji = 0;
for (int q = 0; q < N; q++) {
	if (s[q] == r) {
		ji = q;
		break;
	}
}
System.out.println("R is found at position " + ji);

// using the equation ji = (jp + Si[i] + K[i]) mod N
// we can find K[4] but how


break;
//System.out.println(Arrays.toString(s));
//System.exit(1);*/
//System.out.println(Arrays.toString(s));
