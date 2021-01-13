class No(object):
    def __init__(self, valor):
        self.valor = valor
        self.proximo = None


class ListaEncadeada:
    def __init__(self):
        self.cabeca = None

    def inserir(self, valor):
        no = No(valor)

        if self.vazia():
            self.cabeca = no
        else:
            no.proximo = self.cabeca
            self.cabeca = no

    def vazia(self):
        return self.cabeca is None

    def imprimir(self):
        no: No = self.cabeca
        while no is not None:
            print(no.valor)
            no = no.proximo

    def buscar(self, valor):
        '''Retorna o valor se encontrar, None se não encontrar'''
        n: No = self.cabeca
        while n is not None:
          if n.valor == valor:
            return n.valor
          n = n.proximo
        return None
        

    def inters(self, valor, valor2):
        '''Remove o valor, se encontrar'''
        x: No = self.cabeca
        x1 = self.cabeca
        while x is not None:
            while x1 is not None:
                if x.valor == x1.valor2:
                    print(x.valor)
                x = x.proximo
          
          
          


# Exemplo de uso. Essa lista encadeada está funcionando como uma pilha

l = ListaEncadeada()
for i in range(0,4):
    x = int(input())
    l.inserir(x)
l2 = ListaEncadeada()
for i in range(0, 4):
    y = int(input())
    l2.inserir(y)
    
l.inters(l,l2)

