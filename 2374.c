#include <stdio.h>
 
int main(void) {
 
    int n, m, resp;
    do{
        scanf("%d%d",&n,&m);
    }while(n<0 || n>41 || m<0 || m>41);
    resp = n-m;
    printf("%d\n",resp);
}