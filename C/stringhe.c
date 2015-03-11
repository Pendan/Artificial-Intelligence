#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int *i;

/*	diamo spazio in memoria per 'ste cose (viene usata per defiire cose grandi senza che dia problemi di memoria) */
/*	i=malloc(2*sizeof(int));        */
	i=calloc(5,sizeof(int));
	printf("%p %p %p %p %p \n",i,i+1,i+2,i+3);
	printf("%d %d %d %d %d \n",*i,*(i+1),*(i+2),*(i+3));
	free(i);
	return 0;
}
