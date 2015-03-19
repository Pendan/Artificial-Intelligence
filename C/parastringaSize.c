#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
	
	char *stringa;
	int i,j,N;
	double s=0,*A;
	
	stringa=argv[1];
	sscanf(stringa,"%u",&N);
	printf ("%u 	\n",N);
	A=calloc(N*N,sizeof(double));
	for (i=0;i<N;i++)
	{	
		for (j=0;j<N;j++)
		{
			
			A[i+j*N]=1.*rand()/RAND_MAX;
			s+=A[i+j*N];
			

		}
	}

	printf("%f ",s);
	return 0;
}

