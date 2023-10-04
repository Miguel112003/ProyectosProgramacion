#include<stdio.h>
#include<math.h>

int main(){
    int n,i,j,datos[3000],prueba[3000],dif[3000];
    int acumulador,contador,bandera;
    while(scanf("%d", &n) != EOF){
        for(i = 0; i < n; i++){
            scanf("%d", &datos[i]);
        }
        for(i = 0; i < n-1; i++){
            dif[i] = abs(datos[i] - datos[i+1]);
        }
        acumulador = 1;
        for(i = 0; i < n-1; i++){
            prueba[i] = acumulador;
            acumulador++;
        }
        contador = 0;
        for(i = 0; i<n-1;i++){
            bandera = 1;
            for(j=0;j<n-1 && bandera == 1;j++){
                if(prueba[i] == dif[j]){
                    contador += 1;
                    bandera = 0;
                }
            }
        }
        if(contador == n-1){
            printf("Jolly\n");
        }
        else{
            printf("Not Jolly\n");
        }
    }
    return 0;
}
