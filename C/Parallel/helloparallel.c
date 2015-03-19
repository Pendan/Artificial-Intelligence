#include <omp.h>
#include <stdio.h>
#include <time.h>


int main (int argc, char **argv)
{	
	int i,a,con=100000000;
	clock_t start, end;
	double cpu_time_used;
	srand(time(NULL));
	start=clock();
	for (i=0; i<con; i++)
	{
		a=a+i*rand();
		a=a*a;

	}
	printf("%d \t",a);
	end=clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("Tempo senza parellelizzazione: %f \n", cpu_time_used);
	omp_set_num_threads(4);
	printf("Numero di Threads attivi: %d \n",omp_get_num_threads());
	//#pragma omp parallel
	//{
	//printf("Salve, sono il tuo thread numero %d! Numero di Threads attivi: %d\n", omp_get_thread_num(),omp_get_num_threads());
	//printf("Numero di Threads attivi: %d \n",omp_get_num_threads());
	//}
	start=clock();
	#pragma omp parallel
	#pragma omp for schedule (static)
	for (i=0; i<con; i++)
	{
		a=a=a+i*rand();
		a=a*a;

	}

	end=clock();
	printf("%d \t",a);
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("Tempo con parellelizzazione: %f \n", cpu_time_used);



	return 0;
}
