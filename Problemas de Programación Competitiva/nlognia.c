#include <stdio.h>

int main(){
    int k,n,m,x,y;
    scanf("%d", &k);
    while(k!=0){
        scanf("%d", &n);
        scanf("%d", &m);
        while(k>0){
            scanf("%d", &x);
            scanf("%d", &y);
            if(x == n || y == m) printf("divisa\n");
            else if(x > n && y > m) printf("NE\n");
            else if(x < n && y > m) printf("NO\n");
            else if(x < n && y < m) printf("SO\n");
            else printf("SE\n");
            k--;
        }
        scanf("%d", &k);
    }
    return 0;
}
