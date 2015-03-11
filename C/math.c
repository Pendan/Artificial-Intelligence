/* 

# prova.c 

*/

#include <math.h>
#include <stdio.h>


double f(double x) {

	double t = x;
	double s = t;
	int i,n=200;
	
	for (i=1; i<=n; i++) {
		t=-t*(x*x)/((2*i+1)*(2*i));
		s=s+t;
	}
	
	return s;
}
int main(int argc, char **argv)
{
	int i,v[10];
/* definiamo un puntatore */
	int *j,k[10];

	double y,x,s=0;
	
	scanf("%lf",&x);
/*	for (i=0; i<10000000; i++)
	{
		s=s+f(x/(i*i));
	}
*/
	
	y=f(x);
	printf("%lf \n",y);
	printf("%d %p \n",v[0],v);
	j=10;
	j=k;
	k[0]=150;
	k[1]=100;
	printf("%d %p %d %p %p\n", *j,j,*(j+1),j+1,&k[1]);


	struct vect { double x,y,z;} *g,p;
	g=&p;
	p.x=x;
	printf("%lf %lf %lf \n",p.x,g[0],g->x);

	return 0;
}
