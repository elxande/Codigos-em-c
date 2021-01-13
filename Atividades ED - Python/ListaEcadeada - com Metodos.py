# Implemente os métodos que faltam abaixo: buscar e remover
class No:
    def __init__(self, valor):
        self.valor = valor
        self.prox = None

class ListaSimplesmenteEncadeada:
    def __init__(self):
        self.cabeca = None

    def inserir(self, valor):
        n = No(valor)
        if self.vazia():
            self.cabeca = n
        else:
            n.prox = self.cabeca
            self.cabeca = n

    def vazia(self):
        return self.cabeca is None

    def imprimir(self):
        n = self.cabeca
        while n is not None:
            print(n.valor)
            n = n.prox


    def imprimir_formato_lista(self):
        n = self.cabeca
        print('cabeca -> ', end='')
        while n is not None:
            print('[', n.valor, '] -> ', end='')
            n = n.prox
        print('None')

    def buscar(self, valor):
        '''Retorna o valor se encontrar, None se não encontrar'''
        n: No = self.cabeca
        while n is not None:
          if n.valor == valor:
            print(n.valor)
          n = n.prox
        return None

    def remover(self):
        '''Remove o valor, se encontrar'''
        no: No = self.cabeca
        if self.vazia():
          print("A pilha está VAZIA!")
        else:
          no = no.prox
          self.cabeca = no
        

# Exemplo de uso. Essa lista encadeada está funcionando como uma pilha

l = ListaSimplesmenteEncadeada()
l.inserir(1)
l.inserir(2)
l.inserir(3)
l.inserir(4)

l.imprimir()

l.remover()
l.remover()
l.remover()

print("===========================================")
l.imprimir()
print("===========================================")