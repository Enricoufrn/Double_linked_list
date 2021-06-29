// LinkedList_Implementacao.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <stdlib.h>
#include <stdio.h>

struct no {
    int val;
    struct no* prox;
};

struct linkedlist {
    struct no* cabeca;
    int qtdade;
};

struct linkedlist* inicializar();
struct no* alocarNovoNo(int valor);
void inserirElementoNoFim(struct linkedlist* lista, int valor);
void inserirElementoNoInicio(struct linkedlist* lista, int valor);
void inserirElementoEmPosicao(struct linkedlist* lista, int valor, int posicao);
int obterElementoEmPosicao(struct linkedlist* lista, int posicao);
void imprimirLista(struct linkedlist* lista);
void removerElementoEmPosicao(struct linkedlist* lista, int posicao);

int main()
{
    linkedlist* lista = inicializar();
    printf("qtdade = %i || cabeca aponta para = %p\n",lista->qtdade,lista->cabeca);
    inserirElementoNoFim(lista, 10);
    inserirElementoNoFim(lista, -30);
    inserirElementoNoFim(lista, 50);
    printf("elemento da posicao 0 = %i\n", obterElementoEmPosicao(lista, 0));
    imprimirLista(lista);
    printf("\nadicionando -100 na primeira posicao\n");
    inserirElementoNoInicio(lista, -100);
    imprimirLista(lista);
    printf("\nqtdade = %i\n", lista->qtdade);
    printf("adicionando 55 na posicao 2\n");
    inserirElementoEmPosicao(lista,55,2);
    imprimirLista(lista);
    printf("\nqtdade = %i\n", lista->qtdade);
    printf("elemento da posicao 3 = %i\n", obterElementoEmPosicao(lista, 3));
    printf("removendo elemento da posicao 2\n");
    removerElementoEmPosicao(lista, 2);
    imprimirLista(lista);
    printf("\nqtdade = %i\n", lista->qtdade);
}

struct linkedlist* inicializar()
{
    struct linkedlist* aux = (struct linkedlist*)malloc(sizeof(struct linkedlist));
    if (aux != NULL) {
        aux->cabeca = NULL;
        aux->qtdade = 0;
    }
    return aux;
}

struct no* alocarNovoNo(int valor)
{
    struct no* novoNo = (struct no*)malloc(sizeof(struct no));
    if (novoNo != NULL) {
        novoNo->val = valor;
        novoNo->prox = NULL;
    }
    return novoNo;
}

void inserirElementoNoFim(struct linkedlist* lista, int valor)
{
    struct no* novoElemento = alocarNovoNo(valor);
    if (lista->cabeca == NULL){ // lista vazia 
        lista->cabeca = novoElemento;
    }else { // lista não está vazia
        struct no* aux = lista->cabeca;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = novoElemento;
    }
    lista->qtdade++;
}

void inserirElementoNoInicio(struct linkedlist* lista, int valor)
{
    struct no* novoElemento = alocarNovoNo(valor);
    if (lista->cabeca == NULL) { // lista vazia
        lista->cabeca = novoElemento;
    }else { // lista não está vazia
        struct no* aux = lista->cabeca;
        lista->cabeca = novoElemento;
        novoElemento->prox = aux;
    }
    lista->qtdade++;
}

void inserirElementoEmPosicao(struct linkedlist* lista, int valor, int posicao)
{
    if (posicao>=0&&posicao<=lista->qtdade) {
        struct no* novoElemento = alocarNovoNo(valor);
        struct no* aux = lista->cabeca;
        if (posicao == 0) {
            lista->cabeca = novoElemento;
            novoElemento->prox = aux;
        }else {
            for (int i = 0; i < posicao - 1;i++) {
                aux = aux->prox;
            }
            struct no* aux2 = aux->prox;
            aux->prox = novoElemento;
            novoElemento->prox = aux2;
        }
        lista->qtdade++;
    }
}

int obterElementoEmPosicao(struct linkedlist* lista, int posicao)
{
    if (posicao >= 0 && posicao < lista->qtdade) {
        struct no* aux = lista->cabeca;
        int cont = 0;
        while (aux->prox != NULL) {
            if (cont == posicao)
                break;
            aux = aux->prox;
            cont++;
        }
        return aux->val;
    }
}

void removerElementoEmPosicao(struct linkedlist* lista, int posicao) 
{
    if (posicao >= 0 && posicao <= lista->qtdade) {
        struct no* aux = lista->cabeca;
        if (posicao == 0) {
            lista->cabeca = aux->prox;
            free(aux);
        }
        else {
            for (int i = 0; i < posicao - 1; i++) {
                aux = aux->prox;
            }
            struct no* aux2 = aux->prox;
            aux->prox = aux2->prox;
            free(aux2);
        }
        lista->qtdade--;
    }
}

void imprimirLista(struct linkedlist* lista) {
    //usamos o aux para percorrer a lista
    if (lista->cabeca != NULL) {
        struct no* aux = lista->cabeca;
        //navega partindo da cabeça até chegar NULL
        printf("[");
        do {
            printf("%d", aux->val);
            aux = aux->prox;
            if (aux != NULL) {
                printf(", ");
            }
        } while (aux != NULL);
        printf("]");
    }
    else {
        printf("A lista está vazia!");
    }
}

// Executar programa: Ctrl + F5 ou Menu Depurar > Iniciar Sem Depuração
// Depurar programa: F5 ou menu Depurar > Iniciar Depuração

// Dicas para Começar: 
//   1. Use a janela do Gerenciador de Soluções para adicionar/gerenciar arquivos
//   2. Use a janela do Team Explorer para conectar-se ao controle do código-fonte
//   3. Use a janela de Saída para ver mensagens de saída do build e outras mensagens
//   4. Use a janela Lista de Erros para exibir erros
//   5. Ir Para o Projeto > Adicionar Novo Item para criar novos arquivos de código, ou Projeto > Adicionar Item Existente para adicionar arquivos de código existentes ao projeto
//   6. No futuro, para abrir este projeto novamente, vá para Arquivo > Abrir > Projeto e selecione o arquivo. sln
