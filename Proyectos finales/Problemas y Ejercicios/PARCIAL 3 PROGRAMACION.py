filas=5
columnas=4
matriz=[]
for f in range(filas):
    lista=[]
    for c in range(columnas):
        lista.append("O")
    matriz.append(lista)

def mostrarClinica(matriz):
    for i in range(len(matriz)):
        print(matriz[i],end="\n")

def ConocerCupo (matriz):
    cupo=0
    piso=int(input("Ingrese el piso que desea conocer su cupo:"))
    for i in range(len(matriz[piso])):
        if matriz[piso][i]=="O":
            cupo=cupo+1
    print("Hay un total de:",cupo,"habitaciones disponibles en el piso",piso)

def registrarPaciente(matriz):
    paciente=[]
    registro=False
    piso=int(input("Ingrese en que piso quiere ingresar al paciente:"))
    for i in range (len(matriz[piso])):
        if matriz[piso][i]=="O" and registro==False:
            registro=True
            habitacion=i
    if registro==False:
        print("Lo siento el piso esta lleno")
    
    if registro==True:
        cedula=int(input("Ingrese el numero de cedula del paciente:"))
        nombre=input("Ingrese el nombre del paciente:")
        enfermedad=input("Ingrese la enfermedad del paciente:")
        edad=int(input("Ingrese la edad:"))
        sexo=input("Ingrese el genero del paciente:")
        paciente.append(cedula)
        paciente.append(nombre)
        paciente.append(enfermedad)
        paciente.append(edad)
        paciente.append(sexo)
        matriz[piso][habitacion]=paciente

def retirarPaciente(matriz):
    retirado=False
    cedula=int(input("Ingrese la cedula del paciente a retirar:"))
    for i in range(len(matriz)):
        for j in range(len(matriz[i])):
            if matriz[i][j][0]==cedula and retirado==False:
                matriz[i][j]="O"
                print("El paciente ha sido retirado satisfactoriamente")
                retirado=True

def buscarPaciente (matriz):
    cedula=int(input("Ingrese la cedula del paciente a buscar:"))
    for i in range(len(matriz)):
        for j in range(len(matriz[i])):
            if matriz[i][j][0]==cedula:
                print("El paciente se encuentra registrado en el piso",i,"habitacion",j)

def moverPaciente (matriz):
    movimiento=False
    libre=False
    mensaje=False
    cedula=int(input("Ingrese que cedula tiene el paciente a mover:"))
    piso=int(input("Ingrese en que piso desea poner al paciente:"))
    for j in range(len(matriz[piso])):
        if matriz[piso][j]=="O" and mensaje==False:
            libre=True
            print("Hay habitacion disponible")
            mensaje=True
    if libre==True:
        for i in range(len(matriz)):
            for j in range(len(matriz[i])):
                if matriz[i][j][0]==cedula:
                    mover=matriz[i][j]
                    matriz[i][j]="O"
        
        for i in range(len(matriz[piso])):
            if matriz[piso][i]=="O" and movimiento==False:
                matriz[piso][i]=mover
                movimiento=True
                print("El paciente fue trasladado con exito")
    else:
        print("No hay cupo en el piso, sorry")

                
print("◆◆◆◆◆ SOFTWARE DE LA CLINICA BIENVENIDOS ◆◆◆◆")       
print("1. Conocer cupo de un piso")
print("2. Registrar un paciente")
print("3. Retirar un paciente")
print("4. Buscar un paciente")
print("5. Mover un paciente de piso")
print("6. Mostrar ocupación de la clinica")
print("0. SALIR")

opcion=int(input("Seleccione la opcion deseada:"))
while opcion!=0:
    if opcion==1:
        ConocerCupo(matriz)
        opcion=int(input("Seleccione la opcion deseada:"))   
    
    if opcion==2:
        registrarPaciente(matriz)
        opcion=int(input("Seleccione la opcion deseada:"))   
    
    if opcion==3:
        retirarPaciente(matriz)
        opcion=int(input("Seleccione la opcion deseada:"))   
    
    if opcion==4:
        buscarPaciente(matriz)
        opcion=int(input("Seleccione la opcion deseada:"))   

    if opcion==5:
        moverPaciente(matriz)
        opcion=int(input("Seleccione la opcion deseada:"))    
    
    if opcion==6:
        mostrarClinica(matriz)
        opcion=int(input("Selecione la opcion deseada:"))

        
