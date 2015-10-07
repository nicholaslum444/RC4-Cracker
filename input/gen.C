
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int  C = 90;
unsigned long A,B,D,E,F,G,H,S;

int main()
{
int i;
long j;


//
S=37821; A=1341324; B=314; D=314; E=89234; F=3142; G=13424; H=234524; srandom(S);
cout << "./rc4 0 8  5000000  0  ";  for (i=3;i<8;i++) cout << setw(3) << (E*random()+F*random()+G*random()+H*random()+D*random()+A*random()+B)%C << " "; cout << "> A00.data" <<  endl;
cout << "./rc4 0 8  3000000  1  ";  for (i=3;i<8;i++) cout << setw(3) << (E*random()+F*random()+G*random()+H*random()+D*random()+A*random()+B)%C << " "; cout << "> A01.data" <<  endl;
cout << "./rc4 0 8  2000000  2  ";  for (i=3;i<8;i++) cout << setw(3) << (E*random()+F*random()+G*random()+H*random()+D*random()+A*random()+B)%C << " "; cout << "> A02.data" <<  endl;
cout << "./rc4 0 8  1500000  3  ";  for (i=3;i<8;i++) cout << setw(3) << (E*random()+F*random()+G*random()+H*random()+D*random()+A*random()+B)%C << " "; cout << "> A03.data" <<  endl;
cout << "./rc4 0 8  1000000  4  ";  for (i=3;i<8;i++) cout << setw(3) << (E*random()+F*random()+G*random()+H*random()+D*random()+A*random()+B)%C << " "; cout << "> A04.data" <<  endl;
cout << "./rc4 0 8   750000  5  ";  for (i=3;i<8;i++) cout << setw(3) << (E*random()+F*random()+G*random()+H*random()+D*random()+A*random()+B)%C << " "; cout << "> A05.data" <<  endl;
cout << "./rc4 0 8   500000  6  ";  for (i=3;i<8;i++) cout << setw(3) << (E*random()+F*random()+G*random()+H*random()+D*random()+A*random()+B)%C << " "; cout << "> A06.data" <<  endl;
cout << "./rc4 0 8   300000  7  ";  for (i=3;i<8;i++) cout << setw(3) << (E*random()+F*random()+G*random()+H*random()+D*random()+A*random()+B)%C << " "; cout << "> A07.data" <<  endl;
cout << "./rc4 0 8   200000  8  ";  for (i=3;i<8;i++) cout << setw(3) << (E*random()+F*random()+G*random()+H*random()+D*random()+A*random()+B)%C << " "; cout << "> A08.data" <<  endl;
cout << "./rc4 0 8   100000  9  ";  for (i=3;i<8;i++) cout << setw(3) << (E*random()+F*random()+G*random()+H*random()+D*random()+A*random()+B)%C << " "; cout << "> A09.data" <<  endl;

S=3454; A=1324; B=14; D=1234; E=389234; F=342; G=1324; H=23524; srandom(S);
cout << "./rc4 0 10 5000000 10  ";  for (i=3;i<10;i++) cout << setw(3) << (E*random()+F*random()+G*random()+H*random()+D*random()+A*random()+B)%C << " "; cout << "> A10.data" <<  endl;
cout << "./rc4 0 10 3000000 11  ";  for (i=3;i<10;i++) cout << setw(3) << (E*random()+F*random()+G*random()+H*random()+D*random()+A*random()+B)%C << " "; cout << "> A11.data" <<  endl;
cout << "./rc4 0 10 2000000 12  ";  for (i=3;i<10;i++) cout << setw(3) << (E*random()+F*random()+G*random()+H*random()+D*random()+A*random()+B)%C << " "; cout << "> A12.data" <<  endl;
cout << "./rc4 0 10 1500000 13  ";  for (i=3;i<10;i++) cout << setw(3) << (E*random()+F*random()+G*random()+H*random()+D*random()+A*random()+B)%C << " "; cout << "> A13.data" <<  endl;
cout << "./rc4 0 10 1000000 14  ";  for (i=3;i<10;i++) cout << setw(3) << (E*random()+F*random()+G*random()+H*random()+D*random()+A*random()+B)%C << " "; cout << "> A14.data" <<  endl;
cout << "./rc4 0 10  750000 15  ";  for (i=3;i<10;i++) cout << setw(3) << (E*random()+F*random()+G*random()+H*random()+D*random()+A*random()+B)%C << " "; cout << "> A15.data" <<  endl;
cout << "./rc4 0 10  500000 16  ";  for (i=3;i<10;i++) cout << setw(3) << (E*random()+F*random()+G*random()+H*random()+D*random()+A*random()+B)%C << " "; cout << "> A16.data" <<  endl;
cout << "./rc4 0 10  300000 17  ";  for (i=3;i<10;i++) cout << setw(3) << (E*random()+F*random()+G*random()+H*random()+D*random()+A*random()+B)%C << " "; cout << "> A17.data" <<  endl;
cout << "./rc4 0 10  200000 18  ";  for (i=3;i<10;i++) cout << setw(3) << (E*random()+F*random()+G*random()+H*random()+D*random()+A*random()+B)%C << " "; cout << "> A18.data" <<  endl;
cout << "./rc4 0 10  100000 19  ";  for (i=3;i<10;i++) cout << setw(3) << (E*random()+F*random()+G*random()+H*random()+D*random()+A*random()+B)%C << " "; cout << "> A19.data" <<  endl;

S=765; A=1324; B=14; D=1234; E=389234; F=3342; G=1424; H=234524; srandom(S);
cout << "./rc4 0 12 5000000 20  ";  for (i=3;i<12;i++) cout << setw(3) << (E*random()+F*random()+G*random()+H*random()+D*random()+A*random()+B)%C << " "; cout << "> A20.data" <<  endl;
cout << "./rc4 0 12 3000000 21  ";  for (i=3;i<12;i++) cout << setw(3) << (E*random()+F*random()+G*random()+H*random()+D*random()+A*random()+B)%C << " "; cout << "> A21.data" <<  endl;
cout << "./rc4 0 12 2000000 22  ";  for (i=3;i<12;i++) cout << setw(3) << (E*random()+F*random()+G*random()+H*random()+D*random()+A*random()+B)%C << " "; cout << "> A22.data" <<  endl;
cout << "./rc4 0 12 1500000 23  ";  for (i=3;i<12;i++) cout << setw(3) << (E*random()+F*random()+G*random()+H*random()+D*random()+A*random()+B)%C << " "; cout << "> A23.data" <<  endl;
cout << "./rc4 0 12 1000000 24  ";  for (i=3;i<12;i++) cout << setw(3) << (E*random()+F*random()+G*random()+H*random()+D*random()+A*random()+B)%C << " "; cout << "> A24.data" <<  endl;
cout << "./rc4 0 12  750000 25  ";  for (i=3;i<12;i++) cout << setw(3) << (E*random()+F*random()+G*random()+H*random()+D*random()+A*random()+B)%C << " "; cout << "> A25.data" <<  endl;
cout << "./rc4 0 12  500000 26  ";  for (i=3;i<12;i++) cout << setw(3) << (E*random()+F*random()+G*random()+H*random()+D*random()+A*random()+B)%C << " "; cout << "> A26.data" <<  endl;
cout << "./rc4 0 12  300000 27  ";  for (i=3;i<12;i++) cout << setw(3) << (E*random()+F*random()+G*random()+H*random()+D*random()+A*random()+B)%C << " "; cout << "> A27.data" <<  endl;
cout << "./rc4 0 12  200000 28  ";  for (i=3;i<12;i++) cout << setw(3) << (E*random()+F*random()+G*random()+H*random()+D*random()+A*random()+B)%C << " "; cout << "> A28.data" <<  endl;
cout << "./rc4 0 12  100000 29  ";  for (i=3;i<12;i++) cout << setw(3) << (E*random()+F*random()+G*random()+H*random()+D*random()+A*random()+B)%C << " "; cout << "> A29.data" <<  endl;

S=890998; A=1324; B=14; D=1234; E=389234; F=1234231; G=13424; H=234524; srandom(S);
cout << "./rc4 0 14 5000000 30  ";  for (i=3;i<14;i++) cout << setw(3) << (E*random()+F*random()+G*random()+H*random()+D*random()+A*random()+B)%C << " "; cout << "> A30.data" <<  endl;
cout << "./rc4 0 14 3000000 31  ";  for (i=3;i<14;i++) cout << setw(3) << (E*random()+F*random()+G*random()+H*random()+D*random()+A*random()+B)%C << " "; cout << "> A31.data" <<  endl;
cout << "./rc4 0 14 2000000 32  ";  for (i=3;i<14;i++) cout << setw(3) << (E*random()+F*random()+G*random()+H*random()+D*random()+A*random()+B)%C << " "; cout << "> A32.data" <<  endl;
cout << "./rc4 0 14 1500000 33  ";  for (i=3;i<14;i++) cout << setw(3) << (E*random()+F*random()+G*random()+H*random()+D*random()+A*random()+B)%C << " "; cout << "> A33.data" <<  endl;
cout << "./rc4 0 14 1000000 34  ";  for (i=3;i<14;i++) cout << setw(3) << (E*random()+F*random()+G*random()+H*random()+D*random()+A*random()+B)%C << " "; cout << "> A34.data" <<  endl;
cout << "./rc4 0 14  750000 35  ";  for (i=3;i<14;i++) cout << setw(3) << (E*random()+F*random()+G*random()+H*random()+D*random()+A*random()+B)%C << " "; cout << "> A35.data" <<  endl;
cout << "./rc4 0 14  500000 36  ";  for (i=3;i<14;i++) cout << setw(3) << (E*random()+F*random()+G*random()+H*random()+D*random()+A*random()+B)%C << " "; cout << "> A36.data" <<  endl;
cout << "./rc4 0 14  300000 37  ";  for (i=3;i<14;i++) cout << setw(3) << (E*random()+F*random()+G*random()+H*random()+D*random()+A*random()+B)%C << " "; cout << "> A37.data" <<  endl;
cout << "./rc4 0 14  200000 38  ";  for (i=3;i<14;i++) cout << setw(3) << (E*random()+F*random()+G*random()+H*random()+D*random()+A*random()+B)%C << " "; cout << "> A38.data" <<  endl;
cout << "./rc4 0 14  100000 39  ";  for (i=3;i<14;i++) cout << setw(3) << (E*random()+F*random()+G*random()+H*random()+D*random()+A*random()+B)%C << " "; cout << "> A39.data" <<  endl;

S=347899; A=1324; B=342415; D=1234; E=389234; F=3342; G=13424; H=234524; srandom(S);
cout << "./rc4 0 16 5000000 40  ";  for (i=3;i<16;i++) cout << setw(3) << (E*random()+F*random()+G*random()+H*random()+D*random()+A*random()+B)%C << " "; cout << "> A40.data" <<  endl;
cout << "./rc4 0 16 3000000 41  ";  for (i=3;i<16;i++) cout << setw(3) << (E*random()+F*random()+G*random()+H*random()+D*random()+A*random()+B)%C << " "; cout << "> A41.data" <<  endl;
cout << "./rc4 0 16 2000000 42  ";  for (i=3;i<16;i++) cout << setw(3) << (E*random()+F*random()+G*random()+H*random()+D*random()+A*random()+B)%C << " "; cout << "> A42.data" <<  endl;
cout << "./rc4 0 16 1500000 43  ";  for (i=3;i<16;i++) cout << setw(3) << (E*random()+F*random()+G*random()+H*random()+D*random()+A*random()+B)%C << " "; cout << "> A43.data" <<  endl;
cout << "./rc4 0 16 1000000 44  ";  for (i=3;i<16;i++) cout << setw(3) << (E*random()+F*random()+G*random()+H*random()+D*random()+A*random()+B)%C << " "; cout << "> A44.data" <<  endl;
cout << "./rc4 0 16  750000 45  ";  for (i=3;i<16;i++) cout << setw(3) << (E*random()+F*random()+G*random()+H*random()+D*random()+A*random()+B)%C << " "; cout << "> A45.data" <<  endl;
cout << "./rc4 0 16  500000 46  ";  for (i=3;i<16;i++) cout << setw(3) << (E*random()+F*random()+G*random()+H*random()+D*random()+A*random()+B)%C << " "; cout << "> A46.data" <<  endl;
cout << "./rc4 0 16  300000 47  ";  for (i=3;i<16;i++) cout << setw(3) << (E*random()+F*random()+G*random()+H*random()+D*random()+A*random()+B)%C << " "; cout << "> A47.data" <<  endl;
cout << "./rc4 0 16  200000 48  ";  for (i=3;i<16;i++) cout << setw(3) << (E*random()+F*random()+G*random()+H*random()+D*random()+A*random()+B)%C << " "; cout << "> A48.data" <<  endl;
cout << "./rc4 0 16  100000 49  ";  for (i=3;i<16;i++) cout << setw(3) << (E*random()+F*random()+G*random()+H*random()+D*random()+A*random()+B)%C << " "; cout << "> A49.data" <<  endl;

S=314890; A=1324123; B=14; D=1234; E=389234; F=3342; G=13424; H=234524; srandom(S);
cout << "./rc4 0 18 5000000 50  ";  for (i=3;i<18;i++) cout << setw(3) << (E*random()+F*random()+G*random()+H*random()+D*random()+A*random()+B)%C << " "; cout << "> A50.data" <<  endl;
cout << "./rc4 0 18 3000000 51  ";  for (i=3;i<18;i++) cout << setw(3) << (E*random()+F*random()+G*random()+H*random()+D*random()+A*random()+B)%C << " "; cout << "> A51.data" <<  endl;
cout << "./rc4 0 18 2000000 52  ";  for (i=3;i<18;i++) cout << setw(3) << (E*random()+F*random()+G*random()+H*random()+D*random()+A*random()+B)%C << " "; cout << "> A52.data" <<  endl;
cout << "./rc4 0 18 1500000 53  ";  for (i=3;i<18;i++) cout << setw(3) << (E*random()+F*random()+G*random()+H*random()+D*random()+A*random()+B)%C << " "; cout << "> A53.data" <<  endl;
cout << "./rc4 0 18 1000000 54  ";  for (i=3;i<18;i++) cout << setw(3) << (E*random()+F*random()+G*random()+H*random()+D*random()+A*random()+B)%C << " "; cout << "> A54.data" <<  endl;
cout << "./rc4 0 18  750000 55  ";  for (i=3;i<18;i++) cout << setw(3) << (E*random()+F*random()+G*random()+H*random()+D*random()+A*random()+B)%C << " "; cout << "> A55.data" <<  endl;
cout << "./rc4 0 18  500000 56  ";  for (i=3;i<18;i++) cout << setw(3) << (E*random()+F*random()+G*random()+H*random()+D*random()+A*random()+B)%C << " "; cout << "> A56.data" <<  endl;
cout << "./rc4 0 18  300000 57  ";  for (i=3;i<18;i++) cout << setw(3) << (E*random()+F*random()+G*random()+H*random()+D*random()+A*random()+B)%C << " "; cout << "> A57.data" <<  endl;
cout << "./rc4 0 18  200000 58  ";  for (i=3;i<18;i++) cout << setw(3) << (E*random()+F*random()+G*random()+H*random()+D*random()+A*random()+B)%C << " "; cout << "> A58.data" <<  endl;
cout << "./rc4 0 18  100000 59  ";  for (i=3;i<18;i++) cout << setw(3) << (E*random()+F*random()+G*random()+H*random()+D*random()+A*random()+B)%C << " "; cout << "> A59.data" <<  endl;

}
