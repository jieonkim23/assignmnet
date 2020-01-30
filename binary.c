#include <stdio.h> 

int print_binary(int n)
{
	int  i,j,num;
	int binary[300];
	if (n>0) {
		for (i=0,num=n;num!=0;num/=2,i+=1) 
			binary[i]=num%2;
		printf("%d = ",n);
		
		for(j=0;j<i;j+=1)
			printf("%d",binary[i-j-1]);
		printf(" in bianry\n");
	}
	else return -1;
}
int main(void)
{
    int n = 1;

    while (n>0) {
        printf("Enter a positive integer (Enter 0 to Quit) : ");
        scanf("%d", &n);
        print_binary(n);
    }  

    return 0;
}

