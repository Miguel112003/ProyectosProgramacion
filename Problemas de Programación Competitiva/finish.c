#include <stdio.h>
#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    for (int caso = 1; caso <= t; caso++) {
        int n;
        scanf("%d", &n);
        int naftaDisp[100000], naftaRequerida[100000];
        for (int i = 0; i < n; i++) {
            scanf("%d", &naftaDisp[i]);
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", &naftaRequerida[i]);
        }

        int inicio = 0, tanque = 0;
        for (int i = 0; i < n; i++) {
            tanque += naftaDisp[i] - naftaRequerida[i];
            if (tanque < 0) {
                inicio = i + 1;
                tanque = 0;
            }
        }
        int bandera = 0;
        for (int i = 0; i < inicio && bandera == 0; i++) {
            tanque += naftaDisp[i] - naftaRequerida[i];
            if (tanque < 0) {
                printf("Case %d: Not possible\n", caso);
                bandera = 1;
            }
        }
        if (tanque >= 0) {
            printf("Case %d: Possible from station %d\n", caso, inicio + 1);
        }
    }
    return 0;
}
