#include <stdio.h>

int main(void)
{
    int n, resp=0, x;
    do{
        scanf("%d",&n);
    }while(n<0 || n>13);
    
    for(x=n;x>0;x--){
        if(x==n)
            resp=n;
        else
            resp=resp*x;
    }
    printf("%d\n",resp);
}