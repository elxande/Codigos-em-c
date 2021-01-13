class Pilha(object):
    def __init__(self):
        self.pilha = list()
        self.top = -1

    def push(self, item):
        self.top += 1
        self.pilha.append(item)

    def pop(self):
        item_topo = self.pilha.pop()
        self.top -= 1
        return item_topo

    def is_empty(self):
        return self.top == -1

class No():
    def __init__(self, dado):
        self.dado = dado
        self.e = None
        self.d = None

class Arvore():
    def __init__(self):
        self.root = None

    def inserir(self, dado, raiz_atual):
        if self.root is None:
            self.root = No(dado)
            return self.root

        if dado <= raiz_atual.dado:
            if raiz_atual.d is None:
                raiz_atual.d = No(dado)
                return raiz_atual.d
            else:
                self.inserir(dado, raiz_atual.d)
        else:
            if raiz_atual.e is None:
                raiz_atual.e = No(dado)
                return raiz_atual.e
            else:
                self.inserir(dado, raiz_atual.e)

    def pre_order(self, raiz):
        if raiz is None:
            return
        print(raiz.dado)
        self.pre_order(raiz.e)
        self.pre_order(raiz.d)

    def in_order(self, raiz):
        if raiz is None:
            return
        self.in_order(raiz.e)
        print(raiz.dado)
        self.in_order(raiz.d)

    def pos_order(self, raiz):
        if raiz is None:
            return
        self.pos_order(raiz.e)
        self.pos_order(raiz.d)
        print(raiz.dado)

    # entra nessa função assim: ex.: '(8()())'
    def _trata_entrada(self, entrada, raiz):
        entrada = entrada.strip()

        #entrada apenas com espaços
        if entrada.strip() == '':
            return

        dado = self._valor_no(entrada)
        no_atual = self.inserir(dado, raiz)

        str_nulo = '()'

        # tratando filho esquerdo
        filho_esquerdo = str_nulo
        indx_inicio_filho = entrada.index('(', 1)
        if entrada[indx_inicio_filho:indx_inicio_filho + 1] != str_nulo:
            filho_esquerdo = self._define_txt_filho(indx_inicio_filho, entrada)

        # tratando filho direito
        filho_direito = str_nulo
        indx_inicio_filho_direito = entrada.index(filho_esquerdo) + len(filho_esquerdo)
        # +2 pois é o fim do índice do esquerdo + 1, pois o índice final vai até -1, +1 devido a último parênteses: )
        if entrada[indx_inicio_filho_direito:indx_inicio_filho_direito + 2] != str_nulo:
            filho_direito = self._define_txt_filho(indx_inicio_filho_direito, entrada)

        # se filhos nulos, não chama recursivo
        # TODO: fazer lógica dentro dos IFs para parar de construir árvore se não for binária de busca.
        if filho_esquerdo != str_nulo:
            valor_filho_esquerdo = self._valor_no(filho_esquerdo)
            self._trata_entrada(filho_esquerdo, no_atual)
        if filho_direito != str_nulo:
            valor_filho_direito = self._valor_no(filho_direito)
            self._trata_entrada(filho_direito, no_atual)

    def _valor_no(self, entrada):
        # a partir de índice 1 para se livrar do primeiro parêntese
        indx_parenteses_fim_dado = entrada.index('(', 1)
        dado = int(entrada[1:indx_parenteses_fim_dado])
        return dado

    def _define_txt_filho(self, indx_inicio_filho, no):
        txt_no_filho = no[indx_inicio_filho:]
        indx_finaliza_arvore = self._indx_finaliza_no(txt_no_filho)
        txt_filho = txt_no_filho[:indx_finaliza_arvore + 1]
        return txt_filho

    # devolve o índice de quando se fecha uma subárvore (parênteses batem, como no exemplo de diamantes em Pilha).
    def _indx_finaliza_no(self, texto):
        indx = -1
        p = Pilha()
        for c in texto:
            indx += 1
            if c == '(':
                p.push(c)
            elif c == ')':
                p.pop()
            if p.is_empty():
                return indx

a = Arvore()
#removendo os espaços em branco, caso haja
a._trata_entrada(input().replace(' ', ''), None)