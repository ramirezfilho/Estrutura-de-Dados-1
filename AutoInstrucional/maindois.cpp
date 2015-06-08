#include <stdio.h>
#include  <stdlib.h>

typedef struct {
    char descricao[40];
    int codigo;
    int preco;
    int quantidade;
}produto;

typedef struct{
    int id;
    char nome[30];
    produto *listaProduto;
}lista;


//Identificadores das funções.
produto *totalProduto(int x);
bool cadastroProduto(int tamanho, produto *recebe );
void exibeProduto(int x, produto *recebe);
void exibeProdutoIndisponivel(int x, produto *recebe);
lista *cadastraCategoria();
void realocar (lista *cad, int cont);

//Método principal do programa.
int main(){
    int quantidadeProduto = 0;
    produto *recebe;
    int opcao = 0;
    lista *listaCompleta;

    printf(" --- PROGRAMA DE CONTROLE DE ESTOQUE --- ");
do{
    printf("\n\n --------------------- ");
    printf("\n 1 - CADASTRO DE PRODUTO ");
    printf("\n 2 - EXIBE PRODUTOS NO ESTOQUE ");
    printf("\n 3 - EXIBE PRODUTOS EM FALTA ");
    printf("\n 4 - CADASTRA NOVA CATEGORIA ");
    printf("\n 5 - SAIR ");
    printf("\n Digite a opcao desejada: ");
    scanf("%d", &opcao);

    if(opcao == 1){
        do{
            printf("Digite a quantidade de produtos que deseja cadastrar no estoque: ");
            scanf("%d", &quantidadeProduto);
        }while(quantidadeProduto <= 0);
        recebe = totalProduto(quantidadeProduto);
        cadastroProduto(quantidadeProduto, recebe);
    }else if(opcao == 2){
        exibeProduto(quantidadeProduto, recebe);
    }else if(opcao == 3){
        exibeProdutoIndisponivel(quantidadeProduto, recebe);
    }else if(opcao == 4){
            printf("Digite a quantidade de produtos que deseja cadastrar na lista: ");
            listaCompleta = cadastraCategoria() ;
    }else{
        printf("Opcao invalida!");
    }
}while(opcao !=5);

system("PAUSE");
return 0;
}




// Método para alocar a memória
produto *totalProduto(int x){
    produto *quantidade;
    quantidade = (produto *) malloc(x * sizeof(produto));

    if(!quantidade){
        printf("\nSem memória para alocar\n");
        return 0;
    }else printf("\nMemoria alocada com sucesso!!!\n");

    return quantidade;
}

//Cadastro de produtos
bool cadastroProduto(int tamanho, produto *recebe ){

    for(int i = 0; i<tamanho; i++){
    printf("\n--- Produto %d ---  \n", i+1);
    printf("\nNome: ");
    fflush(stdin);
    scanf("%s", &recebe->descricao);

    printf("\nCodigo: ");
    fflush(stdin);
    scanf("%d", &recebe->codigo);

    printf("\nPreco: ");
    fflush(stdin);
    scanf("%d", &recebe->preco);

    printf("\nQuantidade: ");
    fflush(stdin);
    scanf("%d", &recebe->quantidade);

    recebe++;
    }
    return 1;
}


//Método que exibe os produtos no estoque
void exibeProduto(int x, produto *recebe){
 printf(" ---- LISTA DE PRODUTOS DISPONIVEIS NO ESTOQUE --- ");
    for(int i = 0; i<x; i++){
        if(recebe[i].quantidade !=0){
            printf("\n\nProduto                 : %s\n"\
                   "Codigo                  : %d\n"\
                   "Preco                   : %d\n"\
                   "Quantidade              : %d\n", recebe[i].descricao,recebe[i].codigo,recebe[i].preco,recebe[i].quantidade);
            }
    }
}

//Método para exibir os produtos indisponivels no estoque!
void exibeProdutoIndisponivel(int x, produto *recebe){
 printf(" ---- LISTA DE PRODUTOS INDISPONIVEIS NO ESTOQUE --- ");
    for(int i = 0; i<x; i++){
        if(recebe[i].quantidade ==0){
            printf("\n\nProduto                 : %s\n"\
                   "Codigo                  : %d\n"\
                   "Preco                   : %d\n"\
                   "Quantidade              : %d\n", recebe[i].descricao,recebe[i].codigo,recebe[i].preco,recebe[i].quantidade);
            }
    }
}


lista *cadastraCategoria(){
    int contador = 1;
    int opcao;
    do{
    lista *cad = (lista*) calloc(contador, sizeof(lista));
    if(!cad){
        printf("Memoria indisponivel!! ");
        return 0;
    }

    printf(" --- CADASTRO DE CATEGORIA --- ");
    printf("\nID: ");
    scanf("%d", &cad->id);
    printf("\nNOME: ");
    scanf("%s", &cad->nome);

    printf("\n\nDeseja cadastrar produtos nessa categoria? (S/N)");
    char c;
    scanf("%s", &c);
    if(c == 'S'){
        printf("Quantos produtos gostaria de cadastrar? ");
        int x=0;
        printf("Digite a quantidade de produtos que deseja cadastrar: ");
        scanf("%d", &x);
        cad->listaProduto = totalProduto(x);
        cadastroProduto(x, cad->listaProduto);

    }

    printf("\n\n Deseja cadastrar mais alguma categoria? (0 = NAO)");
    scanf("%d", &opcao);

    if(opcao != 0){

        contador++;
        realocar(cad, contador);

    }

    }while(opcao != 0);
    return 0;
}

 void realocar (lista *cad, int cont){
    cad = (lista*)realloc(cad,2 *sizeof(*cad));
    if (!cad){
        printf("\n\nTOMOU NO CU!\n\n");
    }
}

