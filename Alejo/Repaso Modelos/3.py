
def ingresarLetras(lista):
    lista = []
    while True:
        letra = input("Ingrese una letra o '0' para dejar de ingresar: ")
        if letra == "0":
            break
        lista.append(letra)
        
    return lista

lista_1 = []
print("\nIngrese las letras de la primera lista-->")
lista_1 = ingresarLetras(lista_1)

lista_2 = []
print("\nIngrese las letras de la segunda lista-->")
lista_2 = ingresarLetras(lista_2)

booleano = False
for elemento in lista_1:
    if elemento not in lista_2:
        booleano = False
        break
    else:
        booleano = True

if booleano == True:
    print("\nla lista 1 es subconjunto de la lista 2")
else:
    print("\nla lista 1 no es subconjunto de la lista 2")