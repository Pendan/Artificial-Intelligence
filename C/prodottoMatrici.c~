#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// compilare con -lm -lblas


// libreria lapack dal fortran
int dgemm_(const char *TRANSA,const char *TRANSB, int *M, int *N, int *K, double *ALPHA,
	   double *A, int *LDA, double *B, int *LDB, double *BETA, double *C, int *LDC);


int main(int argc, char **argv){
	clock_t begin, end;
	double time_passed;
	begin=clock();
	int i,j,k,N;
	double *A,*B,s;

	sscanf(argv[1],"%u",&N);
	A=calloc(N*N,sizeof(double));
	B=calloc(N*N,sizeof(double));
	double uno=1,zero=0;
	// definizione matrici
	for (i=0;i<N;i++)
	{	
		for (j=0;j<N;j++)
		{
			
			A[i+j*N]=1.*rand()/RAND_MAX;
			// s+=A[i+j*N];
			

		}
	}
	end=clock();	
	time_passed=(double)(end-begin)/CLOCKS_PER_SEC;
	printf("Tempo di creazione di A: %f s\n",time_passed);


	begin=end;
	// moltiplicazione tra matrici B=A*A
	for (i=0;i<N;i++)
	{	
		for (j=0;j<N;j++)
		{
			B[i+j*N]=0.;	
			for (k=0;k<N;k++)
			{		
				B[i+j*N]+=A[i+k*N]*A[k+j*N];
			}
			s+=B[i+j*N];
		}
	}
	printf("%f\n",s);
	end=clock();
	
	time_passed=(double)(end-begin)/CLOCKS_PER_SEC;
	printf("Tempo di moltiplicazione di A: %f s\n",time_passed);
	

	begin=end;
	// chiamiamo la funzione dgemm per la moltiplicazione
	dgemm_("N","N",&N,&N,&N,&uno,A,&N,A,&N,&zero,B,&N);	
	end=clock();
	
	time_passed=(double)(end-begin)/CLOCKS_PER_SEC;
	printf("Tempo di moltiplicazione A con blas: %f s\n",time_passed);
	for(i=0;i<N*N;i++) s+=B[i];
	printf("%f\n",s);
	
return 0;
}
	
