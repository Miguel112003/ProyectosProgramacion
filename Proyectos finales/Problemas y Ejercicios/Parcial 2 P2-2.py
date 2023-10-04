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

procedimiento()
        




