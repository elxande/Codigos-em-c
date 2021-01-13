class No:
    def _init_(self, valor):
        self.valor = valor
        self.prox = None


class ListaEncadeada:
    def _init_(self):
        self.cabeca = None

    def inserir(self, valor):
        # 1 - criar nó: no
        # 2 - achar posição a inserir
        # 3 - se vazio: self.cabeca = no
        # 4 - se não vazio:
        #     no.prox = self.cabeca
        #     self.cabeca = no

        no = No(self, valor)
        if self.vazia():
            self.cabeca = no
        else:
            no.prox = self.cabeca
            self.cabeca = no

    def vazia(self):
        return self.cabeca is None

    def imprimir(self):
        p: No = self.cabeca
        while p is not None:
            print(p.valor)
            p = p.prox

    def imprimir_formato_lista(self):
        n = self.cabeca

        print('cabeca -> ', end='')
        while n is not None:
            print('[', n.valor, '] -> ', end='')
            n = n.prox
        print('None')

    def imprimir_posicoes_elemento(self, valor):
        pass

    def inverter(self, cabeca: No, resto: No):
        p: No = None
        if cabeca is resto:
            p = self.cabeca
        else:
            p = resto

        if p.prox is None:
            p.prox = cabeca
            self.cabeca = p
        else:
            prox = p.prox
            rl = prox.prox
            prox.prox = p
            if cabeca is resto:
                p.prox = None
            else:
                p.prox = self.cabeca
            self.cabeca = prox
            self.inverter(self.cabeca, rl)

l = ListaEncadeada()

l.inserir(1)
l.inserir(2)
l.inserir(3)
l.inserir(4)
l.inserir(5)
l.imprimir_formato_lista()
l.inverter(l.cabeca, l.cabeca)
l.imprimir_formato_lista()