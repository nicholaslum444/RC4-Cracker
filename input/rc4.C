//-------------------------------------------------------
//       R   C   4
//
//  Project  in CS4236
//  School of Computing, National University of Singapore
//
//  This program generate the data for the project.
//  
//  Aug 2014                                 Chang Ee-Chien
//-------------------------------------------------------

#include <iostream>
#include <stdlib.h>
using namespace std;

const int N =160;     // must be <= 256   for higher value, use version 2 rc4v2.c
                      // WEP uses 256.  In this project, we set it to 160.

int  L;     // Size of array K. must be <= N,   WEP use 8. In this project, it can be
            // larger than 8.
int  S[N];  // Permutation table
int  K[N];  // Keys (size of key is L but we allocated a larger memory for programming convenience).

//------------------------
// Key Scheduling Algorithm
//-------------------------
void ksa()
{
  int i;
  int j;

  for (i=0; i<N;i++)
     S[i]=i;

  j=0;

  for (i=0; i<N; i++)
   {
     int temp;
     j =   ( j+  S[i] + K [ i % L ] )%N;
     temp = S[j]; S[j] = S[i]; S[i]=temp;
   }
}

int main( int argc, char*argv[])
{
int option;
int i;
int k;
int seed;
int rounds;

  //----  Setting the parameters
  option = atoi (argv[1]); // specify whether the output in binary or readable format.
                           //  0: binary, 1:readable    
  L      = atoi (argv[2]); // size of array K.  (hence, the number of secret bytes is L-3).
  rounds = atoi (argv[3]); // the number of tuples to be generated
  seed   = atoi (argv[4]); // a random seed

  //----  Setting the secret Keys 
  for (i=3;i<= L-1;i++)   // Input the Key
    K[i] = atoi (argv[i+2]);

  //----  Start Generating
  srandom(seed );   //  Set a seed. (same seed will give the same sequence of IVs)

  //---------- output L in byte presentation
  if (option==0) {fwrite (&L,      sizeof(int), 1, stdout); 
                  fwrite (&rounds, sizeof(int), 1, stdout);}

  //---------- output the size of K in readable formate. 
  if (option==1) {cout << L << " " << rounds<<  "  with seed " << seed<< endl;}

  for (k=0;k<rounds;k++)
  {
  unsigned char k0,k1,k2;
  unsigned char out;
  
  k0 = random() % N; K[0]=(int) k0;
  k1 = random() % N; K[1]=(int) k1;
  k2 = random() % N; K[2]=(int) k2;
  
  ksa();

  out = (unsigned short)  S[ ( S[1]+ S[S[1]] )% N ];

  //------ the following output the IV and R  in byte presentation.

  if (option==0) 
    { 
      fwrite (&k0,  sizeof( unsigned char), 1, stdout);
      fwrite (&k1,  sizeof( unsigned char), 1, stdout);
      fwrite (&k2,  sizeof( unsigned char), 1, stdout);
      fwrite (&out, sizeof( unsigned char), 1, stdout);
    }

  //------ the following outputs the IV and R in readable format. 
  if (option==1) {cout <<(int) k0 << " " << (int)k1 << " "  <<  (int) k2 << " " << (int) out<< endl;}
  }

}
