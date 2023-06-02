def retornarLista1(lista1, lista2):
    for valor in lista2:
        if valor in lista1:
            lista1.remove(valor)
    return lista1

lista = [1, 2, 3, 4, 5]
lista2 = [3, 4, 8, 9, 10]

print(retornarLista1(lista, lista2))
    