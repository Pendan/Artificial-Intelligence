#include <stdio.h>
#include <math.h>

struct vector {
   double x,y,z;
 };



int main(int argc, char **argv){

	struct vector bau;
	bau.x=1;
	bau.y=2;
	bau.z=3;
	printf("%lf \t %lf \t %lf \n",bau.x,bau.y,bau.z);



	return 0;
}
