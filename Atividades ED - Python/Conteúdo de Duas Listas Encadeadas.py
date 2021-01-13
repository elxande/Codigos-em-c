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




jllist = LinkedList()

m = input()
n = input()

llist.head = Node(m)
second = Node(n)

llist.head.next = second;

for i in second:
    if i in llist.head:
        print(1)
    