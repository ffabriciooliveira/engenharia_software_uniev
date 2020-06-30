#include <stdio.h>
#include <stdlib.h>
/*Centro Universit�rio UniEvang�lica, Engenharia de Software, Estrutura de Dados I
Aluno Fabricio Oliveira 
Utilizado como base o c�digo desenvolvido na aula, e implementadas as seguintes modifica��es
---Funcionalidade de menu: o usu�rio pode escolher o item a ser inserido e se prossegue ou n�o na execu��o do algoritimo.
---Fun��o verificaMinimo: � verificado qual o menor elemento inserido, atraves da compara��o com o minimo armazenado 
	at� ent�o essa fun��o est� vinculada a fun��o inserirItem.
---Fun��o verificaMaximo: � verificado qual o menor elemento inserido, atraves da compara��o com o minimo armazenado 
	at� ent�o essa fun��o est� vinculada a fun��o inserirItem.
---Fun��o alturaArvore: percorre a arvore e determina a altura da mesma
---Fun��o verificarMaior: auxilia a fun��o alturaArvore, verifica se um dado elemento � maior que outro.
---Fun��o contadorNos: conta quantos n�s tem a arvore.
--- Vari�veis: conte, contd, maximoAtual, minimoAtual, valorComparacao, a, b, token, valorlido, num.
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
//esse la�o implementa um menu onde o usu�rio escolhe o valor do item a ser inserido e se aborta ou prossegue na execu��o do algoritmo 
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


//aloca um novo n�
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


// imprime a arvore em pr� ordem
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


/*esta fun��o recebe como parametro o valor que foi digitado pelo usuario para iser��o de elementos 
na �rvore e compara com o valor considerado o maximo at� ent�o,� invocada pela fun��o inserirItem*/
int verificaMaximo(valorComparacao) {
	if(valorComparacao>maximoAtual){
		maximoAtual=valorComparacao;
		return maximoAtual; 
	} else {
		return maximoAtual;
	}
}


/*esta fun��o recebe como parametro o valor que foi digitado pelo usuario para iser��o de elementos 
na �rvore e compara com o valor considerado o minimo at� ent�o,� invocada pela fun��o inserirItem*/
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


//verifica qual dos elementos dados � maior
int verificarMaior(int a, int b)
{
if (a>b)
{
	return a;
} else return b;
}


/*calcula a altura da arvore e retorna esse valor. Altura=n�mero de links no mais longo caminho que leva da raiz at� uma folha
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


//Essa fun��o conta quantos n�s tem a �rvore
int contadorNos(Node*raiz)
{
	if(raiz==NULL)	{
		return 0;
	} else return 1 + contadorNos(raiz->esquerda)+ contadorNos(raiz->direita);
}
