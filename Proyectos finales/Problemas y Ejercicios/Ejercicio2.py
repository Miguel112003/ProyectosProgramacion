bolas=3
numsab=3
sabor1="vainilla"
sabor2=str(input("Escriba el 1do sabor que desea, en minusculas: "))
sabor3=str(input("Escriba el 2er sabor que desea, en minusculas: "))
preciov=2000
precioc=2100
preciof=2200

if bolas==3:
    if sabor1=="vainilla":
        if sabor2=="vainilla":
            if sabor3=="vainilla":
                print("Usted paga", (preciov*bolas))
            else:
                if sabor3=="chocolate":
                    print("Usted paga",(preciov*2)+precioc)
                else:
                    print("Usted paga",(preciov*2)+preciof)
        else:
            if sabor2=="chocolate":
                if sabor3=="chocolate":
                    print("Usted paga",(precioc*2)+preciov)
                else:
                    if sabor3=="vainilla":
                        print("Usted paga",(preciov+precioc+preciov))
                    else:
                        print("Usted paga",(preciov+precioc+preciof))
            else:
                if sabor2=="fresa":
                    if sabor3=="fresa":
                        print("Usted paga", (preciof*2+preciov))
                    else:
                        if sabor3=="vainilla":
                            print("Usted paga",(preciov+preciof+preciov))
                        else:
                            print("Usted paga", (preciov+preciof+precioc))
