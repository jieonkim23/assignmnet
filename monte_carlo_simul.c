#include <stdio.h> 
#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#define N_MAX 1000000

double urand(void) { 
    return (double)rand()/(RAND_MAX+1);
}
int main(void)
{
    double monte_pi, x, y;
    int num_in=0, num_out=0;
    int n, i;
    
    srand(time(0));
    
    scanf("%d",&n);
    if (n<=0) n=1000000;

    for (i=0; i<n; i=i+1) {
        x=urand();
        y=urand();
        if(x*x+y*y<=1)
		num_in+=1;
	else
		num_out+=1;		
       
    }

    monte_pi = 4*((double)num_in/n); 

    printf("Monte-Carlo PI = %.20f, (Number of Sample = %d)\n",monte_pi,n);

    return 0;
}
