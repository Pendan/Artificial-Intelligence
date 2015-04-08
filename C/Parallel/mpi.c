#include <stdio.h>
#include <omp.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <mpi.h>

// You have to compile using the mpicc compiler

// Programa che calcola il limite somme su n di 1/j - log N che tende alla costante di Eulero-Mascheroni

// http://mpitutorial.com/

int main(int argc, char **argv) {

	int rank,size;
	unsigned long long int N,j;
	double s,somma;
	MPI_Comm comm;
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);

	// Comunica N da input al processo 0
	if (rank==0) scanf("%u",&N);

    /*  MPI_Bcast(
    	void* data,
    	int count,
    	MPI_Datatype datatype,
    	int root,
    	MPI_Comm communicator)  */

	// Comunica il valore di N a tutti gli altri processi
	somma=0;
	s=0;
	MPI_Bcast(&N,1,MPI_INT,0,MPI_COMM_WORLD);
	
	printf("ID process= %u di %u, N=%u\n", rank+1,size,N);
	printf("Hello World! \n");

	// Calcolo della somma

	// Questo lo fanno tutti i processi
	

	// Ciclo per dare in pasto cose ai processi, semplicemente usando "rank" nel ciclo for, che dipende dal processo
	for (j=1+rank ; j<= N ; j+=size) s+=1./j;

	// I dati devono essere raccolti e sommati, c'è quindi una routine apposita 
	// per farlo MPI_Reduce http://mpitutorial.com/tutorials/mpi-reduce-and-allreduce/

     /* MPI_Reduce(
    	void* send_data,
    	void* recv_data,
   	int count,
  	MPI_Datatype datatype,
    	MPI_Op op,
    	int root,
    	MPI_Comm communicator)  */
	
	MPI_Reduce(&s,&somma,1,MPI_DOUBLE,MPI_SUM,0,MPI_COMM_WORLD);

	if(rank==0) printf("%u \t-\t %18.14f \n", rank,somma-log(1.*N));

	MPI_Finalize();
	return 0;

}
