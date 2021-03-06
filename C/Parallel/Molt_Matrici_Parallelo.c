#include <stdio.h>
#include <omp.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>

// You have to use -fopenmp

int main(int argc, char **argv) {

	int i,j,k,N;
	double *A,*B;
	double uno=1,zero=0,time_passed;
	clock_t begin, end, begin1, end1;

	
	sscanf(argv[1],"%u",&N);

	A=calloc(N*N,sizeof(double));
	B=calloc(N*N,sizeof(double));
	
	begin=clock();
	// definizione matrici
	for (i=0;i<N;i++)
	{	
		for (j=0;j<N;j++)
		{
			
			A[i+j*N]=2.*rand()/RAND_MAX-1;

		}
	}
	end=clock();	
	time_passed=(double)(end-begin)/CLOCKS_PER_SEC;
	printf("Tempo di creazione di A: %f s\n",time_passed);
	begin=clock();
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
			
		}
	}
	end=clock();	
	time_passed=(double)(end-begin)/CLOCKS_PER_SEC;
	printf("Tempo di moltilicazione lineare di A: %f s\n",time_passed);
	omp_set_num_threads(8);
	begin1=clock();
	#pragma omp parallel shared(A,B)
	#pragma omp for schedule (dynamic) private (i,j,k) 
	for (i=0;i<N;i++)
	{	
		for (j=0;j<N;j++)
		{
			B[i+j*N]=0.;	
			for (k=0;k<N;k++)
			{		
				B[i+j*N]+=A[i+k*N]*A[k+j*N];
			}
			
		}
	}

	end1=clock();	
	time_passed=(double)(end1-begin1)/CLOCKS_PER_SEC;
	printf("Tempo di moltilicazione parallela di A: %f s\n",time_passed);

	return 0;

}
