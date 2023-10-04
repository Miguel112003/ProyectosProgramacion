c=int(input("Ingrese la cantidad que le presto su banco:"))
i=float(input("Ingrese la cuota de interes:"))
t=int(input("Ingrese el total de cuotas:"))
def prestamo (c,i,t):
    abono=c/t
    abonoT=abono*t
    total=abonoT
    ti=1
    print("Cuota   Deuda capital   Abono Fijo     Intereses")
    print("=====   =============   ==========     =========")
    while ti<=t:
        interes=c*(i/100)
        total=total+interes
        print(ti,end="\t")
        print(c,end="\t")
        print(abono,end="\t")
        print(interes,end="\t")
        print()
        c=c-abono
        ti=ti+1
    print()
    print("el total pagado fue", total)
prestamo (c,i,t)
        
##Para que el print no se vuelva loco lo mejor (Mas no obligatorio)
##es que la cantidad de cuotas sea la misma cantidad del prestamo pero divido a una potencia de 10
