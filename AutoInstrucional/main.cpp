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
	


void CadastroCliente (tipoPessoa *criaPessoa);
tipoPessoa *alocaTotalPessoa();


int main() {
	//Declaração de variáveis globais
	tipoPessoa *criaPessoa;
	
	//Chamando as funções
	criaPessoa = alocaTotalPessoa();
	CadastroCliente(criaPessoa);
	
	//Exibindo dados do cliente cadastrado (TESTE)
	printf(	       "\nNome                   : %s\n"\
                   "CPF                    : %s\n"\
                   "Telefone               : %s\n"\
                   "Rua                    : %s\n"\
				   "Numero		       : %d\n", 
				   criaPessoa[0].nome,criaPessoa[0].cpf,criaPessoa[0].telefone,
				   criaPessoa[0].endereco.rua, criaPessoa[0].endereco.numero);
	
	
	
	
	system("pause");
	return 0;
}


//Método para cadastro de Clientes
void CadastroCliente (tipoPessoa *criaPessoa) {
	printf("\n --- Cadastro de Cliente --- \n");
		
	printf("\nNOME: ");
	fflush(stdin);
	scanf("%s", &criaPessoa->nome);
	
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











