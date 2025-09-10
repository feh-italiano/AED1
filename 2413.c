#include <stdio.h>
 
int main(void) {
 
    int t, resp;
    do{
        scanf("%d",&t);
    }while(t<0 || t>1001);
    resp = t*2*2;
    printf("%d\n", resp);
}