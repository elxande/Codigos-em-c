tam1 = int(input())
lista1 = input().split()
tam2 = int(input())
lista2 = input().split()

for i in lista2:
    res = False
    for j in lista1:
        if i == j:
            res = True
if res == False:
    print(0)
else:
    print(1)