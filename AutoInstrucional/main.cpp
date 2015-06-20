#include <stdlib.h>
#include <stdio.h>
#include <string.h>
	
	//Estrutura do tipo Endereço
	typedef struct{
		char rua[50];
		int numero;
		char bairro[20];
		char cidade[30];
		char siglaEstado[3];
		long int CEP;
	}tipoEndereco;
	
	//Estrutura do tipo Pessoa
	typedef struct{
		char cpf[11];
		char nome[50];
		char telefone[9];
		tipoEndereco endereco;
	}tipoPessoa;
		
	//Estrutura do tipo Gasto de Cliente	
	typedef struct{
		int ID; //pode ser autoincremento
		long int CPF;
		double valor;
		int IDProduto; //Esse tipo poderá ser IDProduto ou IDServico
	}tipoGastoCliente;
	
	typedef struct {
		int id ;
		char nome[20];
		char tipo[20];
	}tipoCategoria;
	
	//Estrutura do tipo produto/serviço
	typedef struct{
		int id ;
		char nome[50];
		int valor;
		tipoCategoria categoria;
	}tipoProduto;
	
	


void CadastroCliente (tipoPessoa *criaPessoa);
tipoPessoa *alocaTotalPessoa();
void CadastroCategoria (tipoCategoria *criaCategoria);
tipoCategoria *alocaCategoria();
void CadastroProduto (tipoProduto *criaProduto, tipoCategoria *criaCategoria);
tipoProduto *alocaProduto();


int main() {
	//Declaração de variáveis globais
	tipoPessoa *criaPessoa;
	tipoCategoria *criaCategoria;
	tipoProduto *criaProduto;
	int opcao;
	
	//MENU
	
	do{
		printf("\nCadastros"
				"\n1 - Cadastro de pessoas"
				"\n2 - Cadastros das categorias"
				"\n3 - Cadastro dos produtos ou serviços oferecidos"
				"\n4 - Cadastros de compras ou gastos pelos clientes");
				printf("\nDigite a opcao desejada: ");
				scanf("%d", &opcao);
				
				switch(opcao) {
					case 1: criaPessoa = alocaTotalPessoa(); CadastroCliente(criaPessoa); break;
					case 2: criaCategoria = alocaCategoria(); CadastroCategoria(criaCategoria); break;
					case 3: criaProduto = alocaProduto(); CadastroProduto(criaProduto, criaCategoria); break;
				}		
	}while(opcao != 0);
	
	
	
	

	
	
	/*Exibindo dados do cliente cadastrado (TESTE)
	printf(	       "\nNome                   : %s\n"\
                   "CPF                    : %s\n"\
                   "Telefone               : %s\n"\
                   "Rua                    : %s\n"\
				   "Numero		       : %d\n", 
				   criaPessoa[0].nome,criaPessoa[0].cpf,criaPessoa[0].telefone,
				   criaPessoa[0].endereco.rua, criaPessoa[0].endereco.numero);
	*/
	
	
	
	system("pause");
	return 0;
}


//Métodos para cadastro de Clientes
void CadastroCliente (tipoPessoa *criaPessoa) {
	printf("\n --- Cadastro de Cliente --- \n");
		
	printf("\nNOME: ");
	scanf("%s", &criaPessoa->nome);
	fflush(stdin);	
	
	printf("\nCPF: ");
	fflush(stdin);
	scanf("%s", &criaPessoa->cpf);
	
	printf("\nTELEFONE: ");
	fflush(stdin);
	scanf("%s", &criaPessoa->telefone);
	
	printf("\n  RUA: ");
	fflush(stdin);
	scanf("%s", &criaPessoa->endereco.rua);
	
	printf("\n  NUMERO: ");
	fflush(stdin);
	scanf("%d", &criaPessoa->endereco.numero);
	
	printf("\n  BAIRRO: ");
	fflush(stdin);
	scanf("%s", &criaPessoa->endereco.bairro);
	
	printf("\n  CIDADE: ");
	fflush(stdin);
	scanf("%s", &criaPessoa->endereco.cidade);
	
	printf("\n  ESTADO: ");
	fflush(stdin);
	scanf("%s", &criaPessoa->endereco.siglaEstado);
	
	
} 

tipoPessoa *alocaTotalPessoa(){
    tipoPessoa *quantidade;
    quantidade = (tipoPessoa *) malloc(1 * sizeof(tipoPessoa));

    if(!quantidade){
        printf("\nSem memória para alocar\n");
        return 0;
    }else printf("\nMemoria alocada com sucesso!!!\n");

    return quantidade;
}


//Métodos para cadastro de categoria 
tipoCategoria *alocaCategoria(){
    tipoCategoria *quantidade;
    quantidade = (tipoCategoria *) malloc(1 * sizeof(tipoCategoria));

    if(!quantidade){
        printf("\nSem memória para alocar\n");
        return 0;
    }else printf("\nMemoria alocada com sucesso!!!\n");

    return quantidade;
}

void CadastroCategoria (tipoCategoria *criaCategoria) {
	printf("\n --- Cadastro de Categorias --- \n");

	printf("\nID: ");
	scanf("%d", &criaCategoria->id);
	fflush(stdin);
	
	printf("\nNOME: ");
	scanf("%s", &criaCategoria->nome);
	fflush(stdin);	
	
	printf("\nIIPO: ");
	fflush(stdin);
	scanf("%s", &criaCategoria->tipo);		
} 


//Métodos para cadastro de Produto 
tipoProduto *alocaProduto(){
    tipoProduto *quantidade;
    quantidade = (tipoProduto *) malloc(1 * sizeof(tipoProduto));

    if(!quantidade){
        printf("\nSem memória para alocar\n");
        return 0;
    }else printf("\nMemoria alocada com sucesso!!!\n");

    return quantidade;
}

void CadastroProduto (tipoProduto *criaProduto, tipoCategoria *criaCategoria) {
	printf("\n --- Cadastro de Categorias --- \n");

	printf("\nID: ");
	scanf("%d", &criaProduto->id);
	fflush(stdin);
	
	printf("\nNOME: ");
	scanf("%s", &criaProduto->nome);
	fflush(stdin);	
	
	printf("\nVALOR: ");
	fflush(stdin);
	scanf("%d", &criaProduto->valor);
	
	printf("\nID CATEGORIA: ");
	int cat;
	int capito = 666;
	scanf("%d", &cat);
	
	for(int i = 0; i<10; i++){
		if(criaCategoria[i].id == cat){
			capito = i;
			break;
		}
	}
	
	if (capito == 666){
		printf("Vai te fuder!");
	}
	
	printf("%d", capito);	
} 
	








