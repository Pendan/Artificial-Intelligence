#include <stdio.h>
#include <math.h>

int main(int argc, char **argv){
 	printf("Bau: %s \n",argv[1]);
	double x;
	scanf("%lf", &x);

	printf("indirizzo: %p valore: %f\n",&x,sin(x));
	return 0;
}
