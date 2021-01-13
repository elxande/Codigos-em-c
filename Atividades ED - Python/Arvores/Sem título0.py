class No():
    def __init__(self, dado):
        self.dado = dado
        self.e = None
        self.d = None
        
class Arvore():
    def __init__(self):
        self.raiz = None
        
    def inserir (self, dado, raizAtual):
        if self.raiz is None:
            self.raiz = No(dado)
            return self.raiz
        
        if dado >= raizAtual.dado:
            if raizAtual.d is None:
                raizAtual.d = No(dado)
                return raizAtual.d
            else:
                self.inserir(dado, raizAtual.d)
        
        else:
            if raizAtual.e is None:
                raizAtual.e = No(dado)
                return raizAtual.e
            else:
                self.inserir(dado, raizAtual)
                
    def preOrder(self, raiz):
        if raiz is None:
            return
        print (raiz.dado)
        self.preOrder(raiz.e)
        self.preOrder(raiz.d)
        
    def inOrder(self, raiz):
        if raiz is None:
            return
        self.inOrder(raiz.e)
        print(raiz.dado)
        self.inOrder(raiz.d)
        
    def posOrder(self, raiz):
        if raiz is None:
            return
        self.posOrder(raiz.e)
        self.posOrder(raiz.d)
        print(raiz.dado)
        
    def _trata_entrada(self, entrada, raiz):
        entrada = entrada.strip() #entrada apenas com espaços
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
#        def _indx_finaliza_no(self, texto):
#            indx = -1
#            p = Pilha()
#            for c in texto:
#                indx += 1
#                if c == '(':
#                    p.push(c)
#                elif c == ')':
#                    p.pop()
#                    if p.is_empty():
#                        return indx
a = Arvore()
#removendo os espaços em branco, caso haja
a._trata_entrada(input().replace(' ', ''), None)