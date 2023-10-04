nombre= str(input("Ingrese su nombre: "))
print("Su nombre es:",nombre)
edad=int(input("Digite su edad: "))
print("Usted tiene",edad, "Años")
parq= str(input("¿Va a usar el parqueadero?, escriba si o no en minusculas:"))
print("Usted", parq, "Usara el parqueadero")
almuerzo= str(input("¿Va a almorzar?, escriba si o no en minusculas:"))
print("Usted",almuerzo,"Almorzara")
bioseg=5000
costoing=38000
costoalm=25000
costoparking=10000
if edad<14:
    if parq=="si":
        if almuerzo=="si" and edad<=50:
            print(nombre,"Usted cancela:", (costoing-(costoing*0.1))+(costoalm-(costoalm*0.1))+ costoparking+bioseg)
        else:
            if almuerzo=="si" and edad>50:
                print(nombre,"Usted cancela:", (costoing-(costoing*0.1))+((costoalm*0.1)+costoalm)+ costoparking+bioseg)
            else:
                if almuerzo=="no" and parq=="si":
                    print(nombre, "Usted cancela:", (costoing-(costoing*0.1))+costoparking+bioseg)
    else:
        if almuerzo=="si" and edad<=50:
            print(nombre,"Usted cancela:", (costoing-(costoing*0.1))+(costoalm-(costoalm*0.1))+bioseg)
        else:
            if almuerzo=="si" and edad>50:
                print(nombre,"Usted cancela:", (costoing-(costoing*0.1))+((costoalm*0.1)+costoalm)+bioseg)
            else:
                if almuerzo=="no":
                    print(nombre, "Usted cancela:", (costoing-(costoing*0.1))+bioseg)

else:
    if edad<25 and edad>=14:
        if parq=="si":
            if almuerzo=="si" and edad<=50:
                print(nombre,"Usted cancela:", (costoing-(costoing*0.08))+(costoalm-(costoalm*0.1))+ costoparking+bioseg)
            else:
                if almuerzo=="si" and edad>50:
                    print(nombre,"Usted cancela:", (costoing-(costoing*0.08))+((costoalm*0.1)+costoalm)+ costoparking+bioseg)
                else:
                    if almuerzo=="no" and parq=="si":
                        print(nombre, "Usted cancela:", (costoing-(costoing*0.08))+costoparking+bioseg)
        else:
            if almuerzo=="si" and edad<=50:
                print(nombre,"Usted cancela:", (costoing-(costoing*0.08))+(costoalm-(costoalm*0.1))+bioseg)
            else:
                if almuerzo=="si" and edad>50:
                    print(nombre,"Usted cancela:", (costoing-(costoing*0.08))+((costoalm*0.1)+costoalm)+bioseg)
                else:
                    if almuerzo=="no":
                        print(nombre, "Usted cancela:", (costoing-(costoing*0.08))+bioseg)
                        
    else:
        if edad>=25 and edad<52:
            if parq=="si":
                if almuerzo=="si" and edad<=50:
                    print(nombre,"Usted cancela:", (costoing-(costoing*0.02))+(costoalm-(costoalm*0.1))+ costoparking+bioseg)
                else:
                    if almuerzo=="si" and edad>50:
                        print(nombre,"Usted cancela:", (costoing-(costoing*0.02))+((costoalm*0.1)+costoalm)+ costoparking+bioseg)
                    else:
                        if almuerzo=="no" and parq=="si":
                            print(nombre, "Usted cancela:", (costoing-(costoing*0.02))+costoparking+bioseg)
                            
            else:
                if almuerzo=="si" and edad<=50:
                    print(nombre,"Usted cancela:", (costoing-(costoing*0.02))+(costoalm-(costoalm*0.1))+bioseg)
                else:
                    if almuerzo=="si" and edad>50:
                        print(nombre,"Usted cancela:", (costoing-(costoing*0.02))+((costoalm*0.1)+costoalm)+bioseg)
                    else:
                        if almuerzo=="no":
                            print(nombre, "Usted cancela:", (costoing-(costoing*0.02))+bioseg)
                            
        else:
            if edad>=52 and edad<=60:                
                if parq=="si":
                    if almuerzo=="si" and edad<=50:
                        print(nombre,"Usted cancela:", ((costoing*0.15)+costoing)+(costoalm-(costoalm*0.1))+ costoparking+bioseg)
                    else:
                        if almuerzo=="si" and edad>50:
                            print(nombre,"Usted cancela:", ((costoing*0.15)+costoing)+((costoalm*0.1)+costoalm)+ costoparking+bioseg)
                        else:
                            if almuerzo=="no" and parq=="si":
                                print(nombre, "Usted cancela:", ((costoing*0.15)+costoing)+costoparking+bioseg)
                else:
                    if almuerzo=="si" and edad<=50:
                        print(nombre,"Usted cancela:", ((costoing*0.15)+costoing)+(costoalm-(costoalm*0.1))+bioseg)
                    else:
                        if almuerzo=="si" and edad>50:
                            print(nombre,"Usted cancela:", ((costoing*0.15)+costoing)+((costoalm*0.1)+costoalm)+bioseg)
                        else:
                            if almuerzo=="no":
                                print(nombre, "Usted cancela:", ((costoing*0.15)+costoing)+bioseg)
            else:
                if edad>60:
                    if parq=="si":
                        if almuerzo=="si" and edad<=50:
                            print(nombre,"Usted cancela:", ((costoing*0.4)+costoing)+(costoalm-(costoalm*0.1))+ costoparking+bioseg)
                        else:
                            if almuerzo=="si" and edad>50:
                                print(nombre,"Usted cancela:", ((costoing*0.4)+costoing)+((costoalm*0.1)+costoalm)+ costoparking+bioseg)
                            else:
                                if almuerzo=="no" and parq=="si":
                                    print(nombre, "Usted cancela:", ((costoing*0.4)+costoing)+costoparking+bioseg)
                    else:
                        if almuerzo=="si" and edad<=50:
                            print(nombre,"Usted cancela:", ((costoing*0.4)+costoing)+(costoalm-(costoalm*0.1))+bioseg)
                        else:
                            if almuerzo=="si" and edad>50:
                                print(nombre,"Usted cancela:", ((costoing*0.4)+costoing)+((costoalm*0.1)+costoalm)+bioseg)
                            else:
                                if almuerzo=="no":
                                    print(nombre, "Usted cancela:", ((costoing*0.4)+costoing)+bioseg)
                    
                            

                                    
            
        
        

print("Ya viendolo acabado es un señor codigo, cosas redundantes y casos imposibles pero no son bugs son funciones")

























