# sem otimização
def selection_sort(a):
    for i in range(len(a)):
        menor = i
        for k in range(i + 1, len(a)):
            if a[k] < a[menor]:
                a[k], a[menor] = a[menor], a[k]


# otimização 1: apenas troca no final da passada
def selection_sort_otm1(a):
    for i in range(len(a)):
        menor = i
        for k in range(i + 1, len(a)):
            if a[k] < a[menor]:
                menor = k
        a[i], a[menor] = a[menor], a[i]
        print (a[i])
        print (a)
        


a = input().split()

map(int, a)


print(a)