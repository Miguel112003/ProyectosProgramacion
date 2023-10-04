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

def primo (n):
    contador=1
    definidor=0
    while contador<=n:
        if n%contador==0:
            definidor=definidor+1
        contador=contador+1
    if definidor==2:
        return True
    else:
        return False
    
def cercania (q,m):
    indice2=1
    decididor2=0
    cantidad2=0
    while indice2<=m:
        if m%indice2==0:
            cantidad2=cantidad2+1
            if primo(indice2)==True:
                decididor2=decididor2+1
        indice2=indice2+1
    indice=1
    decididor=0
    cantidad=0
    while indice<=q:
        if q%indice==0:
            cantidad=cantidad+1
            if primo(indice)==True:
                decididor=decididor+1
        indice=indice+1
    if decididor2==decididor:
        return 1
    else:
        return 0
def procedimiento ():
    q=int(input("Ingrese el primer valor:"))
    m=int(input("Ingrese el segundo valor:")) 
    while cercania(q,m)==0:
        q=int(input("Ingrese el primer valor:"))
        m=int(input("Ingrese el segundo valor:"))
    print("Hemos encontrado un par de cercanos y ellos son:",q, "Y", m)
    
opc=100
while opc!=3:
    print("1. Préstamo de Juan Camilo")
    print("2. Encontrar un par de cercanos")
    print("3. Salir del menú")
    opc=int(input("Digite una opcion:"))
    if opc==1:
        c=int(input("Ingrese la cantidad que le presto su banco:"))
        i=float(input("Ingrese la cuota de interes:"))
        t=int(input("Ingrese el total de cuotas:"))
        prestamo (c,i,t)
    if opc==2:
        procedimiento()

##El punto 2 hay una funcion y un procedimiento, para la funcion tendria que
##añadir los valores de q y m antes de definirla, no lo hice ya que no lo crei necesario
        
