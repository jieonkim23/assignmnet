#include <stdio.h> 

int num=0;
void hanoi_tower(int n, int ox, int tx, int mx)
{
	if (n < 1) {
		printf("Error: n >= 1\n");
	}
	else if (n == 1) {
		printf("%d -> %d\n", ox, tx);
	}
	else {
		hanoi_tower(n-1, ox, mx, tx);
		printf("%d -> %d\n", ox, tx);
		hanoi_tower(n-1, mx, tx, ox);
	}
	num++;
}

int main(void)
{
	int n;

	printf("Enter the height of the tower\n");
	scanf("%d", &n);
	hanoi_tower(n, 1, 3, 2);
	printf("The lowest number of times is %d",num);

	return 0;
}
