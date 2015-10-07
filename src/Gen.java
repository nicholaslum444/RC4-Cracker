import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class Gen {

	private static final String KEY_FILENAME_FORMAT = "keys/A%02d.key";
	private static final String GEN_SCRIPT_FILENAME_FORMAT = "gen.sh";
	private static final String DIFF_SCRIPT_FILENAME_FORMAT = "diffkeys.sh";
	
	// shell script format 
	// ./rc4 0 8  5000000  0   56  28  64  72  64 > A00.data
	private static final int[] KEY_LENGTH_ARRAY = {8, 10, 12, 14, 16, 18};
	private static final int[] NUM_TUPLES_ARRAY = {5000000, 3000000, 2000000, 1500000, 1000000, 750000, 500000, 300000, 200000, 100000}; 
	private static final String GEN_SCRIPT_FORMAT = "./rc4 0 %d %d %d %s > decoded/A%02d.data.mine\n";
	private static final String DIFF_SCRIPT_FORMAT = "diff decoded/A%02d.data.mine input/A%02d.data\n";
	
	public static void main(String[] args) throws IOException {
		writeGen();
		writeDiff();
	}

	public static void writeGen() throws IOException {
		BufferedWriter bw = new BufferedWriter(new FileWriter(GEN_SCRIPT_FILENAME_FORMAT));
		for (int i = 0; i < 6; i++) { // outer loop for tens
			for (int j = 0; j < 10; j++) { // inner loop for ones
				int n = i*10 + j;
				BufferedReader br = new BufferedReader(new FileReader(String.format(KEY_FILENAME_FORMAT, n)));
				String keyString = br.readLine();
				bw.write(String.format(GEN_SCRIPT_FORMAT, KEY_LENGTH_ARRAY[i], NUM_TUPLES_ARRAY[j], n, keyString, n));
				br.close();
			}
		}
		bw.flush();
		bw.close();
	}
	
	private static void writeDiff() throws IOException {
		BufferedWriter bw = new BufferedWriter(new FileWriter(DIFF_SCRIPT_FILENAME_FORMAT));
		for (int i = 0; i < 60; i++) {
			bw.write(String.format(DIFF_SCRIPT_FORMAT, i, i));
		}
		bw.flush();
		bw.close();
	}
}
