
def obtenerInterseccion(lista1, lista2):
    interseccion = []
    for letra in letrasMin_1:
        if letra in letrasMin_2:
            interseccion.append(letra)
    return interseccion

def ingresarLetras(lista):

    lista = []
    while True:
        letra = input("Ingrese una letra o '0' para dejar de ingresar: ")
        if letra == "0":
            break
        lista.append(letra)
        
    return lista

letrasMin_1 = []
print("\nIngrese las letras de la primera lista: ")
letrasMin_1 = ingresarLetras(letrasMin_1)

letrasMin_2 = []
print("\nIngrese las letras de la segunda lista: ")
letrasMin_2 = ingresarLetras(letrasMin_2)

interseccion = obtenerInterseccion(letrasMin_1, letrasMin_2)

print(interseccion)