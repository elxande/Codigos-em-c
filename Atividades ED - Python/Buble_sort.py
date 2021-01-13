def booble_sort(a):
    passagens = 0
    for i in range(len(a)-1):
        trocas = 0
        for j in range(len(a)-1, i, -1):
            if a[j]<a[j-1]:
                a[j], a[j-1] = a[j-1], a[j]
                print(a)
                trocas +=1
            passagens +=1
        print (passagens)
        print (trocas)
        if trocas == 0:
            print (passagens)
            print (trocas)
            return
        
a = [10,9,3,2,5,7,8,1,0]
booble_sort(a)
print (a)