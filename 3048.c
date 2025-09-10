#include <stdio.h>
 
int main() {
 
    int n, ultimo_numero, cont=0;
    scanf("%d",&n);
    int num[n];
    
    for(int i=0;i<n;i++){
        scanf("%d",&num[i]);
        if(i==0){
            ultimo_numero = 1;
            cont++;
        }
        else{
            if(num[i]!=num[i-1]){
                cont++;
            }
        }
    }
    
    printf("%d\n",cont);
 
    return 0;
}