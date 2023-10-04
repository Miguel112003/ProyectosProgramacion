#include <stdio.h>

int main(){
    int t,n;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        int temporal;
        int maximo = -1;
        int minimo = 100;
        int i = 0;
        while(n--){
            scanf("%d", &temporal);
            if(temporal > maximo)
                maximo = temporal;
            if(temporal < minimo)
                minimo = temporal;
            i++;
        }
        printf("%d\n", (maximo - minimo)* 2 );
    }
    return 0;
}


