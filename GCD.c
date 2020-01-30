#include <stdio.h> 
#define GCD(a,b)	euclid(a,b)
int euclidr(int a,int b) {
	if (b>a) return euclidr(b,a);
	if (b==0) return a;
	return(euclidr(b, a%b));
}

int LCM(int a,int b) {
	if (a,b>0)
		return a*b/GCD(a,b);
	return 1;
}

int isCoprime(int a, int b) {
	if (GCD(a,b)!=1)
		return 0;
	return 1;
}

int euclid(int a, int b) {
	int small=a;
	if (b<small) small=b;
	for (small; small>0; small-=1)
		if (a%small==0 && b%small==0) return small;
			
	return 1;
}

int main(void) {
	int a, b;
	printf("Enter two positive integers\n");
	scanf("%d%d",&a,&b);
	printf("GCD of (%d,%d) is %d\n",a,b,GCD(a,b));
	printf("LCM of (%d,%d) is %d\n",a,b,LCM(a,b));
	printf("(%d,%d) is Coprime (True-1/False-0) : %d\n", a,b, isCoprime(a,b));
	return 0;
}
