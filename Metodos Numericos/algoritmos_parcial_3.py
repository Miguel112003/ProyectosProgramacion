# -*- coding: utf-8 -*-
"""Algoritmos Parcial 3.ipynb

Automatically generated by Colaboratory.

Original file is located at
    https://colab.research.google.com/drive/1Utr2R18WAfPCpOTiXIKiYTMsaoUgxMee
"""

import math
import numpy as np
import scipy
import scipy.linalg
import matplotlib.pyplot as plt
import sympy
import numpy as np
from scipy.interpolate import CubicSpline
from scipy.integrate import solve_ivp

x = sympy.Symbol('x')

#La funcion de abajo es con la que se hace derivdadas e integrales
funcion = sympy.sqrt(1+(2/x**(1/3))**2)

#Los datos de abajo son con los que se hacen integrales con datos espaciados irregulares
#abscisa es X, ordenada es Y
abscisa = [1,1.5,1.6,2.5,3.5]
ordenada = [0.6767,0.3734,0.3261,0.08422,0.01596]

#Aqui defino las ecuaciones diferenciales
def ecuacionDiff(t,y):
  z = 1+(t-y)**2
  return z

#Aqui defino una ecuacion diferencial cuyo resultado es real, para graficar luego
def teorica(t):
  z = -1*t
  return z

#Aqui defino los sistemas de ecuaciones diferenciales
def sistemaEdo(t,y): #y es un array o una lista de datos con posicion
  dy_1 = 2*y[0] + y[1] -np.exp(2*t)
  dy_2 = y[0] + 2*y[1]
  return [dy_1,dy_2]

def menu():
  print("""
  1. Finitas hacia Adelante
  2. Finitas hacia Atras
  3. Finitas Centrada
  4. Aproximacion Orden 2
  5. Extrapolacion de Richardson
  6. Derivada de Datos dispersos
  7. Metodo del Trapecio
  8. Metodo del Trapecio Iterado
  9. Metodo de Simpson
  10. Metodo de Simpson Iterado
  11. Segmentos Desiguales (Datos Dispersos) por Trapecio
  12. Segmentos Desiguales (Datos Dispersos) por Simpson
  13. Metodo de Romberg
  14. Metodo Gauss Legendre
  15. Metodo Gauss Legendre Mejorado
  16. Metodo de Euler (EDOS)
  17. Runge Kutta 2
  18. Runge Kutta 4
  19. Solucion de Scipy
  20. Resolver Sistema EDO
  0. Salir
  """)
  eleccion = int(input("Elija: "))
  return eleccion

def finitasAdelante(funcion):
  tol = int(input("Ingrese la potencia de la tolrancia 10^(): "))
  tolerancia = 10**tol
  condicion = float(input("Ingrese el valor en el cual aproximar la derivada: "))
  derivada = ((funcion.subs(x,condicion+tolerancia)) - (funcion.subs(x,condicion))) / tolerancia
  return derivada

def finitasAtras(funcion):
  tol = int(input("Ingrese la potencia de la tolrancia 10^(): "))
  tolerancia = 10**tol
  condicion = float(input("Ingrese el valor en el cual aproximar la derivada: "))
  derivada = ((funcion.subs(x,condicion)) - (funcion.subs(x,condicion-tolerancia))) / tolerancia
  return derivada

def finitasCentrada(funcion):
  tol = float(input("Ingrese la potencia de la tolrancia 10^(): "))
  tolerancia = 10**tol
  condicion = float(input("Ingrese el valor en el cual aproximar la derivada: "))
  derivada = ((funcion.subs(x,condicion+tolerancia)) - (funcion.subs(x,condicion-tolerancia))) / (2*tolerancia)
  return derivada

def segundoOrden(funcion):
  tol = int(input("Ingrese la potencia de la tolrancia 10^(): "))
  tolerancia = 10**tol
  condicion = float(input("Ingrese el valor en el cual aproximar la derivada: "))
  derivada = (funcion.subs(x,condicion+2*tolerancia) - 2*funcion.subs(x,condicion+tolerancia) + funcion.subs(x,condicion)) / tolerancia**2
  return derivada

def extrapolacionRichardson(funcion):
  print("Realiza la aproximacion con h1")
  d1 = finitasCentrada(funcion)
  print("Ahora realiza la aproximacion con h2 (h1*2^-1)")
  d2 = finitasCentrada(funcion)
  extrapol = (4/3)*d2 - (1/3)* d1
  #Es basicamente aplicar finitas centradas y multiplicar por la formula, es chido
  return extrapol

def derivadaDatos(abscisa,ordenada):
  n = len(abscisa)
  i = 1
  primeraDer = []
  segundaDer = []
  print("Para la segunda derivada es mejor prueba de escritorio\n ya que si los datos son irregularmente espaciados el codigo colapsa\n")
  print("Pero si son regularmente espaciados funciona perfecto la 2da der :D\n")
  print("Basicamente usalos para todo menos segunda derivadad de irregulares")
  while i <= n:
    if i == n: #Si es el ultimo dato toca aplicar hacia atras para el ultimo dato
      h = (abscisa[i-1] - abscisa[i-2])
      primeraDer.append((ordenada[i-1] - ordenada[i-2]) / h)
    else: #Aqui aplico hacia adelante en todos los puntos hasta el ultimo, que ese va con atras
      h = (abscisa[i] - abscisa[i-1])
      primeraDer.append((ordenada[i] - ordenada[i-1]) / h)
      if i >= n-1: #Toca aplicar finitas hacia atras para la 2da derivada
        h = (abscisa[i-1] - abscisa[i-2])
        segundaDer.append((ordenada[i-1] - 2*ordenada[i-2] + ordenada[i-3]) / h**2)
      else:
        segundaDer.append((ordenada[i+1] - 2*ordenada[i] + ordenada[i-1]) / h**2)

    i += 1
  print(np.array(primeraDer))
  print(np.array(segundaDer))


def metodoTrapecio(funcion):
  a = float(input("Ingrese el limite de intergracion 1: "))
  b = float(input("Ingrese el limite de integracion 2: "))
  h = b-a/2
  integral = h*((funcion.subs(x,a)+funcion.subs(x,b)))
  return integral

def trapecioMejorado(funcion):
  a = float(input("Ingrese el limite de intergracion 1: "))
  b = float(input("Ingrese el limite de integracion 2: "))
  n = int(input("Ingrese el numero de particiones: "))
  abscisa = np.linspace(a,b,n)
  i = 0
  area = 0
  while i < n - 1:
    area += (((abscisa[i+1]-abscisa[i])/2)*(funcion.subs(x,(abscisa[i+1]))+funcion.subs(x,(abscisa[i]))))
    i += 1
  return [area, a,b,n]

def metodoSimpson(funcion):
  a = float(input("Ingrese el limite de intergracion 1: "))
  b = float(input("Ingrese el limite de integracion 2: "))
  h = (b-a)/2
  pmedio = (a+b)/2
  integral = h/3 * funcion.subs(x,a) + 4*funcion.subs(x,pmedio) + funcion.subs(x,b)
  return integral

def simpsonMejorado(funcion):
  a = float(input("Ingrese el limite de intergracion 1: "))
  b = float(input("Ingrese el limite de integracion 2: "))
  n = int(input("Ingrese la cantidad de intervalos (debe ser numero par): "))
  if n % 2 is not 0:
    return "Error, debe ser un par"
  else:
    h = (b-a)/n
    primera = funcion.subs(x, a)
    ultima = funcion.subs(x,b)
    apoyo = a
    area = 0
    for i in range(n-1):
      apoyo += h
      valor = funcion.subs(x,apoyo)
      if i % 2 == 0:
        area += 4 * valor
      else:
        area += 2 * valor
    total = (h/3) * (primera + area + ultima)
    return total

def segmentosDesigualesTrapecio(abscisa,ordenada): #Este es por trapecio :P
  n = len(abscisa)
  i = 0
  area = 0
  while i < n-1:
    area += ((abscisa[i+1] - abscisa[i])/2) * (ordenada[i] + ordenada[i+1])
    i+= 1
  return area

def segmentosSimpson(abscisa,ordenada):
  n = len(abscisa)
  a = abscisa[0]
  b = abscisa[n-1]
  if n % 2 is not 0:
    return "Error, debe ser un par"
  else:
    h = (b-a)/n
    primera = ordenada[0]
    ultima = ordenada[n-1]
    area = 0
    for i in range(n-1):
      valor = ordenada[i]
      if i % 2 == 0:
        area += 4 * valor
      else:
        area += 2 * valor
    total = (h/3) * (primera + area + ultima)
    return total

def metodoRomberg(funcion):
  print("Primera Aproximacion I(h1)")
  i1 = trapecioMejorado(funcion)
  h1 = (i1[2]-i1[1])/i1[3]
  print(i1)
  print("Mismo intervalo, diferente # de particiones (mas)")
  print("Segunda Aproximacion I(h2)")
  i2 = trapecioMejorado(funcion)
  h2 = (i2[2]-i2[1])/i2[3]
  print(i2)
  integral = i2[0] + (1/((h1/h2)**2)-1)*(i2[0]-i1[0])
  return integral

def gaussLegendre(funcion):
  print("Esta formula te da el valor de la integral en 1,-1")
  ap = funcion.subs(x, (-1/math.sqrt(3))) + funcion.subs(x,(1/math.sqrt(3)))
  return ap

def gausslegendreMejorado(funcion):
  u = sympy.Symbol('u')
  a = float(input("Ingrese el primer valor del intervalo de integracion: "))
  b = float(input("Ingrese el ultimo valor del intervalo de integracion: "))
  sust = ((b+a)+(b-a)*u)/2
  funcionNew = funcion.subs(x,sust) * ((b-a)/2)
  area = funcionNew.subs(u,(-1/math.sqrt(3))) + funcionNew.subs(u,(1/math.sqrt(3)))
  print(funcionNew)
  print(funcionNew.subs(u,(-1/math.sqrt(3))))
  print(funcionNew.subs(u,(1/math.sqrt(3))))
  return area

def metodoEuler():
  a = float(input("Ingrese el primer valor del intervalo de aproximacion: "))
  b = float(input("Ingrese el segundo valor del intervalo de aproximacion: "))
  ci = float(input("Ingrese la condicion inicial (PVI): "))
  n = int(input("Ingrese la cantidad de intervalos: "))
  t = np.linspace(a,b,n+1)
  h = t[1] - t[0]
  y = []
  y.append(ci)
  i = 1
  while i <=n:
    y.append(y[i-1]+h*ecuacionDiff(t[i-1],y[i-1]))
    i += 1
  #A partir de aqui lo que hacemos es graficar para ver como se ve la EDO
  plt.figure(figsize=[6,6])
  plt.plot(t,y,'r')
  plt.grid()
  plt.plot(t,teorica(t),'b')
  #A partir de aqui calculamos error
  convencional = []
  for i in range(len(t)):
    convencional.append(teorica(t[i]))
  convencional = np.array(convencional)
  y = np.array(y)
  n1 = scipy.linalg.norm(convencional-y,ord=1)/scipy.linalg.norm(convencional,ord=1)
  n2 = scipy.linalg.norm(convencional-y,ord=2)/scipy.linalg.norm(convencional,ord=2)
  n3 = scipy.linalg.norm(convencional-y,ord=np.inf)/scipy.linalg.norm(convencional,ord=np.inf)
  print(n1)
  return (t,y)

def rungeKutta2():
  a = float(input("Ingrese el primer valor del intervalo de aproximacion: "))
  b = float(input("Ingrese el segundo valor del intervalo de aproximacion: "))
  ci = float(input("Ingrese la condicion inicial (PVI): "))
  n = int(input("Ingrese la cantidad de intervalos: "))
  t = np.linspace(a,b,n+1)
  h = t[1] - t[0]
  y = []
  y.append(ci)
  i = 1
  while i <=n:
    k1 = h*ecuacionDiff(t[i-1],y[i-1])
    k2 = h*ecuacionDiff(t[i-1]+h/2,y[i-1]+k1/2)
    y.append(y[i-1]+k2)
    i=i+1
  #A partir de aqui lo que hacemos es graficar para ver como se ve la EDO
  plt.figure(figsize=[6,6])
  plt.plot(t,y,'r')
  plt.grid()
  plt.plot(t,teorica(t),'b')
  #A partir de aqui calculamos error
  convencional = []
  for i in range(len(t)):
    convencional.append(teorica(t[i]))
  convencional = np.array(convencional)
  y = np.array(y)
  n1 = scipy.linalg.norm(convencional-y,ord=1)/scipy.linalg.norm(convencional,ord=1)
  n2 = scipy.linalg.norm(convencional-y,ord=2)/scipy.linalg.norm(convencional,ord=2)
  n3 = scipy.linalg.norm(convencional-y,ord=np.inf)/scipy.linalg.norm(convencional,ord=np.inf)
  print(n1)
  return (t,y)

def rungeKutta4():
  a = float(input("Ingrese el primer valor del intervalo de aproximacion: "))
  b = float(input("Ingrese el segundo valor del intervalo de aproximacion: "))
  ci = float(input("Ingrese la condicion inicial (PVI): "))
  n = int(input("Ingrese la cantidad de intervalos: "))
  t = np.linspace(a,b,n+1)
  h = t[1] - t[0]
  y = []
  y.append(ci)
  i = 1
  while i <= n:
    k1 = h * ecuacionDiff(t[i-1],y[i-1])
    k2 = h * ecuacionDiff((t[i-1]+h/2),(y[i-1] + k1/2))
    k3 = h * ecuacionDiff((t[i-1]+h/2),(y[i-1] + 0*k1 + k2/2))
    k4 = h * ecuacionDiff((t[i-1]+h),(y[i-1] + 0*k1 + 0*k2 + k3))
    y.append(y[i-1] + k1/6 + k2/3 + k3/ 3 + k4/6)
    i += 1
  #A partir de aqui lo que hacemos es graficar para ver como se ve la EDO
  plt.figure(figsize=[6,6])
  plt.plot(t,y,'r')
  plt.grid()
  plt.plot(t,teorica(t),'b')
  #A partir de aqui calculamos error
  convencional = []
  for i in range(len(t)):
    convencional.append(teorica(t[i]))
  convencional = np.array(convencional)
  y = np.array(y)
  n1 = scipy.linalg.norm(convencional-y,ord=1)/scipy.linalg.norm(convencional,ord=1)
  n2 = scipy.linalg.norm(convencional-y,ord=2)/scipy.linalg.norm(convencional,ord=2)
  n3 = scipy.linalg.norm(convencional-y,ord=np.inf)/scipy.linalg.norm(convencional,ord=np.inf)
  print(n1)
  return (t,y)

def metodoScipy():
  a = float(input("Ingrese el primer valor del intervalo de aproximacion: "))
  b = float(input("Ingrese el segundo valor del intervalo de aproximacion: "))
  ci = [float(input("Ingrese la condicion inicial (PVI): "))]
  n = int(input("Ingrese la cantidad de intervalos: "))
  ts = np.linspace(a,b,n+1)
  y_apro = solve_ivp(fun=ecuacionDiff,t_span=[a,b],y0=ci,t_eval=ts)
  print(y_apro.t)
  print(y_apro.y[0])
  #A partir de aqui lo que hacemos es graficar para ver como se ve la EDO
  plt.figure(figsize=[6,6])
  plt.plot(ts,y_apro.y[0],'r')
  plt.grid()
  plt.plot(ts,teorica(ts),'b')
  #A partir de aqui calculamos error
  convencional = []
  for i in range(len(ts)):
    convencional.append(teorica(ts[i]))
  n1 = scipy.linalg.norm(convencional-y_apro.y[0],ord=1)/scipy.linalg.norm(convencional,ord=1)
  n2 = scipy.linalg.norm(convencional-y_apro.y[0],ord=2)/scipy.linalg.norm(convencional,ord=2)
  n3 = scipy.linalg.norm(convencional-y_apro.y[0],ord=np.inf)/scipy.linalg.norm(convencional,ord=np.inf)
  print(n1)

def sistScipy():
  t0 = float(input("Ingrese el primer valor del intervalo de aproximacion: "))
  tf = float(input("Ingrese el segundo valor del intervalo de aproximacion: "))
  y0 = [1,-1]
  ts = np.linspace(t0,tf,60)
  y_apro = solve_ivp(fun=sistemaEdo, t_span=[t0,tf], y0=y0, t_eval=ts)
  print(y_apro.y)
  #A partir de aqui lo que hacemos es graficar para ver como se ve la EDO
  #Toma en cuenta que se solucionan dos edos, la de posicion 0 es la que sale de la
  #Transformacion y la de posicion 1 es la que nos interesa :D
  plt.figure(figsize=[6,6])
  plt.plot(ts,y_apro.y[1],'r')
  plt.grid()
  plt.plot(ts,teorica(ts),'b')

  #A partir de aqui calculamos error
  convencional = []
  for i in range(len(ts)):
    convencional.append(teorica(ts[i]))
  convencional = np.array(convencional)
  y_apro.y[1] = np.array(y_apro.y[1])
  n1 = scipy.linalg.norm(convencional-y_apro.y[1],ord=1)/scipy.linalg.norm(convencional,ord=1)
  n2 = scipy.linalg.norm(convencional-y_apro.y[1],ord=2)/scipy.linalg.norm(convencional,ord=2)
  n3 = scipy.linalg.norm(convencional-y_apro.y[1],ord=np.inf)/scipy.linalg.norm(convencional,ord=np.inf)
  print(n1)


def main():
  alternativa = menu()
  if alternativa == 1:
    print(finitasAdelante(funcion))
  elif alternativa == 2:
    print(finitasAtras(funcion))
  elif alternativa == 3:
    print(finitasCentrada(funcion))
  elif alternativa == 4:
    print(segundoOrden(funcion))
  elif alternativa == 5:
    print(extrapolacionRichardson(funcion))
  elif alternativa == 6:
    print(derivadaDatos(abscisa,ordenada))
  elif alternativa == 7:
    print(metodoTrapecio(funcion))
  elif alternativa == 8:
    print(trapecioMejorado(funcion))
  elif alternativa == 9:
    print(metodoSimpson(funcion))
  elif alternativa == 10:
    print(simpsonMejorado(funcion))
  elif alternativa == 11:
    print(segmentosDesigualesTrapecio(abscisa,ordenada))
  elif alternativa == 12:
    print(segmentosSimpson(abscisa,ordenada))
  elif alternativa == 13:
    print(metodoRomberg(funcion))
  elif alternativa == 14:
    print(gaussLegendre(funcion))
  elif alternativa == 15:
    print(gausslegendreMejorado(funcion))
  elif alternativa == 16:
    print(metodoEuler())
  elif alternativa == 17:
    print(rungeKutta2())
  elif alternativa == 18:
    print(rungeKutta4())
  elif alternativa == 19:
    print(metodoScipy())
  elif alternativa == 20:
    print("Si necesitas cambiar algunos parametros anda a la funcion, linea 352")
    print(sistScipy())
  else:
    print("Saliendo :D")

main()

"""Como transformar una ecuacion diferencial de orden superior en un sistema de orden inferior.
El truco es introducir tantas variables independietnes como sea el orden de la derivada mayor
Ej:

x'''+2x'-x'+3x=2t

x = w1
x' = w1' = w2
x'' = w1'' = w2' = w3
x'''= w1'''=w2''=w3'

ahora de (1) dejamos en forma normal

x''' = -2x'' + x' - 3x +2t

Sustituyendo las variables

w3' = -2w3 + w2 - 3w1 + 2t

El sistema me queda, y ya, solucionao

w1' = w2

w2' = w3

w3' = -3w1 + w2 - 2w3 + 2t


"""