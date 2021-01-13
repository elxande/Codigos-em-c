lista1 = []
for i in range(0,20):
    x = int(input())
    lista1.append(x)
    lista1.sort()
lista2 = []
for i in range(0, 20):
    y = int(input())
    lista2.append(y)
    lista2.sort()

for i in lista1:
    inter = []
    if i in lista2:
        inter.append(i)
        for k in inter:
            if len(inter) == 0:
                print('VAZIO')
            else:
                print(k)

