#include <stdio.h>

int main(){
    int a,b,c,d,distancia;
    scanf("%d %d %d %d", &a,&b,&c,&d);
    while(b != 0 || c != 0 || d != 0){
        if(a-b < 0){
            distancia = a-b+40;
        }
        else{
            distancia = a-b;
        }
        if(c-b < 0){
            distancia += c-b+40;
        }
        else{
            distancia += c-b;
        }
        if(c-d<0){
            distancia += c-d+40;
        }
        else{
            distancia += c-d;
        }
        distancia = distancia*9+1080;
        printf("%d\n", distancia);
        scanf("%d %d %d %d", &a,&b,&c,&d);
    }
    return 0;
}
