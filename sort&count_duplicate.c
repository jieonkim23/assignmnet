#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <assert.h>
void sort_integers(int *pn) {
	int i,j,end_index,temp;
	
	for(i=0;*(pn+i)!=-1;i++) ;
	end_index=i-1;
	
	for(i=0;i<end_index;i++){
		for(j=0;j<end_index-i;j++){
			if( pn[j]> pn[j+1]){
				temp = pn[j];  
				pn[j]=pn[j+1];
				pn[j+1] = temp;
			}
		}
	}
}


int count_duplicate(int *pn) {
	int i,j,num=0;
	for (i=0;*(pn+i)!=-1;i++){
		if (pn[i]==pn[i+1]){
			num++;
			for(j=1;pn[i]==pn[i+j];j++){
				num++;
			}
			i=i+j-1;
		}
	}
	return num;
}

int main(void) 
{
    int *pns = NULL;
    unsigned int nsize;
    int i;

    puts("Enter the number of random numbers to generate:");
    scanf("%u", &nsize);
    srand(time(0));

    pns = (int*)malloc(sizeof(int)*(nsize+1));
    assert(pns);

    for(i=0;i<nsize;i++){
		*(pns+i)=rand()%9+1;
    }
    *(pns+nsize)= -1;
    sort_integers(pns);
    printf("The number of duplicate numbers is %d\n",
	count_duplicate(pns));

    return 0;
}
