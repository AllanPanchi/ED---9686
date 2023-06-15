from itertools import chain, combinations

def conjunto_potencia(conjuntos):
    elementos = list(chain(*conjuntos))
    combinaciones = chain.from_iterable(combinations(elementos, r) for r in range(len(elementos) + 1))
    conjunto_potencia = [set(combinacion) for combinacion in combinaciones]

    conjunto_potencia = [conjunto if conjunto else "{}" for conjunto in conjunto_potencia]

    return conjunto_potencia


conjuntos = [{"x"}, {"y"}, {"z"}]

resultado = conjunto_potencia(conjuntos)

print(resultado)
