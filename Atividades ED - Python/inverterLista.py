lista = input().split()

res = ""
for i in reversed(lista):
    res = res + (i) + (" ")
    
res = res.strip(" ")
print (res)
