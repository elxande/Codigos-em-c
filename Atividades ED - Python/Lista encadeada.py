class Node:
 
    def __init__(self, data):
        self.data = data
        self.next = None
 
class LinkedList:
 
    def __init__(self):
        self.head = None
        
    def printList(self):
        temp = self.head
        while (temp):
            print (temp.data)
            temp = temp.next

    def append(self, data):
        if(self.head == None):
           self.head = Node(data);
           return;
        actual = self.head
        while(actual.next):
            actual = actual.next
        actual.next = Node(data)

lista = LinkedList()

n = int(input())
lista.append(input().split())

for i in lista:
    if i > 1:
        print(i)
    