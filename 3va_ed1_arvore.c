#include <stdio.h>
#include <stdlib.h>
/*Centro Universitário UniEvangélica, Engenharia de Software, Estrutura de Dados I
Aluno Fabricio Oliveira 
Utilizado como base o código desenvolvido na aula, e implementadas as seguintes modificações
---Funcionalidade de menu: o usuário pode escolher o item a ser inserido e se prossegue ou não na execução do algoritimo.
---Função verificaMinimo: é verificado qual o menor elemento inserido, atraves da comparação com o minimo armazenado 
	até então essa função está vinculada a função inserirItem.
---Função verificaMaximo: é verificado qual o menor elemento inserido, atraves da comparação com o minimo armazenado 
	até então essa função está vinculada a função inserirItem.
---Função alturaArvore: percorre a arvore e determina a altura da mesma
---Função verificarMaior: auxilia a função alturaArvore, verifica se um dado elemento é maior que outro.
---Função contadorNos: conta quantos nós tem a arvore.
--- Variáveis: conte, contd, maximoAtual, minimoAtual, valorComparacao, a, b, token, valorlido, num.
*/
typedef struct node Node;
struct node {
    int valor;
    Node *esquerda;
    Node *direita; 
	};

Node *alocarNovoNode(int valor);
Node *inserirItem(Node *raiz, int valor);

int verificaMinimo (int valorComparacao);
int verificaMaximo (int valorComparacao);
int conte=0, contd=0,  maximoAtual, minimoAtual=0, a, b; 
int alturaArvore(Node *raiz);
int verificarMaior(int, int);
int contadorNos(Node*raiz);

void imprimirPreOrdem(Node *raiz);
void imprimirEmOrdem(Node *raiz);
void imprimirEmOrdemInversa(Node *raiz);
void imprimirPosOrdem(Node *raiz);
void printNode(Node *node);



int main() 
{
	int valorLido;
	char token;
    Node *arvore = NULL;
    while (1)
//esse laço implementa um menu onde o usuário escolhe o valor do item a ser inserido e se aborta ou prossegue na execução do algoritmo 
    {
    	printf("\n\n\nDigite Y e pressione enter para executar o algoritmo ou N e pressione enter para sair e exibir o resultado: ");
   		fflush(stdin);
		token=getchar();
    	if (token=='N'||token=='n')
    	{
    		break;
		} else if (token=='Y'||token=='y'){
		printf("\nDigite o valor que deseja inserir na arvore e pressione enter: ");
    	scanf("%i",&valorLido);
    		arvore = inserirItem(arvore, valorLido);
    	} else printf("VALOR INCORRETO, FAVOR DIGITAR APENAS Y OU N");
	} 
	printf("\n\n\n EM ORDEM CRESCENTE \n");
	imprimirEmOrdem(arvore);

	printf("\n\n\n EM ORDEM DECRESCENTE \n");	
	imprimirEmOrdemInversa(arvore);

	printf("\n\n\n PRE ORDEM \n");
	imprimirPreOrdem(arvore);
	
	printf("\n\n\n POS ORDEM \n");
	imprimirPosOrdem(arvore);
	
	printf("\nO maior valor da arvore e igual a %i", maximoAtual);
	printf("\nO menor valor da arvore e igual a %i", minimoAtual);
	printf("\nA arvore possui %i nos",contadorNos(arvore));
	printf("\nA arvore possui altura = %i", alturaArvore(arvore));

}


//aloca um novo nó
Node *alocarNovoNode(int valor) {
    Node *novo = (Node *)malloc(sizeof(Node));
    novo->valor = valor;
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}


//insere item na arvore
Node *inserirItem(Node *raiz, int valor) {
    if (raiz == NULL) {
    
        Node *novo = (Node *)malloc(sizeof(Node));
        novo->valor = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;
        verificaMaximo(valor);
  	    verificaMinimo(valor);	  
        return novo;
	 }
    else    {
        if (valor < raiz->valor) {
        	
            raiz->esquerda = inserirItem(raiz->esquerda, valor);
          
        }
        else if (valor > raiz->valor)  {
            raiz->direita = inserirItem(raiz->direita, valor);
         
        }
        else {

            printf("Valor ja inserido!\n\n");
        }
    }
    verificaMinimo(valor);
    verificaMaximo(valor);
    return raiz;
}


//imprime a arvore em ordem crescente
void imprimirEmOrdem(Node *raiz) {
	if (raiz != NULL) {
		imprimirEmOrdem(raiz->esquerda);
		printNode(raiz);
		imprimirEmOrdem(raiz->direita);
	}
}


//imprime a arvore em ordem inversa
void imprimirEmOrdemInversa(Node *raiz) {
	if (raiz != NULL) {
		imprimirEmOrdemInversa(raiz->direita);
		printNode(raiz);
		imprimirEmOrdemInversa(raiz->esquerda);
	}
}


// imprime a arvore em pré ordem
void imprimirPreOrdem(Node *raiz) {
	if (raiz != NULL) {
		printNode(raiz);
		imprimirPreOrdem(raiz->esquerda);
		imprimirPreOrdem(raiz->direita);
	}
}


// imprime a arvore em pos ordem 
void imprimirPosOrdem(Node *raiz) {
	if (raiz != NULL) {
		imprimirPosOrdem(raiz->esquerda);
		imprimirPosOrdem(raiz->direita);
		printNode(raiz);
	}
}


//imprime os itens 
void printNode(Node *node) {
    printf("%d \n", node->valor);
}


/*esta função recebe como parametro o valor que foi digitado pelo usuario para iserção de elementos 
na árvore e compara com o valor considerado o maximo até então,é invocada pela função inserirItem*/
int verificaMaximo(valorComparacao) {
	if(valorComparacao>maximoAtual){
		maximoAtual=valorComparacao;
		return maximoAtual; 
	} else {
		return maximoAtual;
	}
}


/*esta função recebe como parametro o valor que foi digitado pelo usuario para iserção de elementos 
na árvore e compara com o valor considerado o minimo até então,é invocada pela função inserirItem*/
int verificaMinimo(valorComparacao) { 
	if (minimoAtual==0) {
		minimoAtual=valorComparacao;
	}
	else if(valorComparacao<minimoAtual){
		minimoAtual=valorComparacao;
		return minimoAtual; 
	} else {
		return minimoAtual;
	}
}


//verifica qual dos elementos dados é maior
int verificarMaior(int a, int b)
{
if (a>b)
{
	return a;
} else return b;
}


/*calcula a altura da arvore e retorna esse valor. Altura=número de links no mais longo caminho que leva da raiz até uma folha
Fonte: IME USP: https://www.ime.usp.br/~pf/mac0122-2002/aulas/trees.html
*/
int alturaArvore(Node *raiz) {
	if (raiz == NULL || raiz->esquerda == NULL && raiz->direita ==NULL) {
		return 0;
	}
		else {
			return 1 + verificarMaior(alturaArvore(raiz->esquerda), alturaArvore(raiz->direita));
		}	
}


//Essa função conta quantos nós tem a árvore
int contadorNos(Node*raiz)
{
	if(raiz==NULL)	{
		return 0;
	} else return 1 + contadorNos(raiz->esquerda)+ contadorNos(raiz->direita);
}
