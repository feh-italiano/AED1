#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int qtde, x, abre, fecha, y;
    char entrada[1000];
    scanf("%d",&qtde);
    int diamantes[qtde];
    
    for(x=0;x<qtde;x++){
        abre = 0;
        fecha = 0;
        diamantes[x] = 0;
        scanf("%s",&entrada);
        for(y=0;entrada[y]!='\0';y++){
            if(entrada[y] == '<')
                abre ++;
            else if(entrada[y] == '>')
                    if(abre>0){
                        diamantes[x] ++;
                        abre--;
                    }
        }
    }
    
    for(x=0;x<qtde;x++)
        printf("%d\n",diamantes[x]);
}
