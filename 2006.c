#include<stdio.h>

int main(void){
	int t, p[5], x, cont=0;
	
	do{
		scanf("%d",&t);
	}while(t<0 || t>5);
	
	for(x=0;x<5;x++){
		do{
			scanf("%d",&p[x]);
		}while(p[x]<0 || p[x]>5);
		if(t==p[x])
			cont++;
	}
	printf("%d\n",cont);
}