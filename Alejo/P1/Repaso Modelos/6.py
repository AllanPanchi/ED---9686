def unirConjuntos(c1, c2):
    c1.update(c2)
    c1 = sorted(c1)
    return c1

c1 = {1,2,3,4,5}
c2 = {-1, -2, -3, -4, -5}

print(unirConjuntos(c1, c2))