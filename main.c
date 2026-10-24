
/*
Coisa que você pediu para anotar...
#define QTD 5
#define TAM_NOME 81
#define QTD_NOTAS 2

int ras[QTD]
char nome[QTD][TAM_NOME]
int faltas[QTD]
*/

/*
char prompt[];
int notas[];
int setor[];
*/

//incluindo bibliotecas e definindo
#include <stdio.h>
#include <string.h>
#define qtdIA 50
#define tamNome 81
#define tamPrompt 101

//protótipos de funções:

int menuSetores();

int menuGeral();

int menuLocal();

void buscarId(int x[y], char z[][y], int a[], int b);//ficou genérico(confirmar se podemos deixar o protótipo assim)

//protótipos de variável
char nomeIA[];
char promptIA[];
int qtdCadastradas();

char nomeIA[qtdIA][tamNome];
print("Digite o nome da IA:\n");
fgets(nomeIA, tamNome, stdin);

for(int i  = 0; nomeIA[i] != "\0" ; i++ ){
    if nomeIA[i] == "\n"{
        nomeIA[i] = "\0";
        break;
    }
}

char promptIA[qtdIA][tamPrompt];
printf("Digite o prompt desta IA:\n");
fgets(promptIA, tamPrompt, stdin);
for(int i  = 0; promptIA[i] != '\0' ; i++ ){
    if (promptIA[i] == '\n'){
        promptIA[i] = '\0';
        break;
    }
}






char cadastro(
int ids[qtdIA];
char nomes[qtdIA][nomeIA];
char prompt[qtdIA][promptIA];
char setor[qtdIA][qtdIA];
int notas[qtdIA];
int *qtdCadastradas) {
    /*
	if (*qtdCadastradas >= MAX) {
        printf("Limite de IAs atingido!\n");
        return;
    }
    */
    int opcao;

    printf("\n--- Cadastro de nova IA ---\n");

    // O espaço antes do %s limpa o buffer automaticamente
    printf("Digite o nome da IA: ");
    scanf(" %s", nomes[*qtdCadastradas]);

    printf("Digite o setor da IA: \n");
    opcao = menuSetores();

    while (opcao < 1 || opcao > 7){
    	printf("Opção inválida!\n");
    	opcao = setores();
	}

	if (opcao == 7){
		printf("Cadastro cancelado!\n");
		return;
	}

	//strcpy pega a string
	if (opcao == 1){
		strcpy(setor[*qtdCadastradas], "TI");
	} else if (opcao == 2) {
        strcpy(setor[*qtdCadastradas], "Cozinha");
    } else if (opcao == 3) {
        strcpy(setor[*qtdCadastradas], "Recursos Humanos");
    } else if (opcao == 4) {
        strcpy(setor[*qtdCadastradas], "Financeiro");
    } else if (opcao == 5) {
        strcpy(setor[*qtdCadastradas], "Estoque");
    } else if (opcao == 6) {
        strcpy(setor[*qtdCadastradas], "Outros");
    }

    printf("Digite a nota da IA (1 - 5):");
    scanf(" %d", &notas[*qtdCadastradas]);

    ids[*qtdCadastradas] = *qtdCadastradas + 1;
	(*qtdCadastradas)++;

    printf("IA cadastrada com sucesso!;D\n");
}

	if (encontrado == 0){
		printf("Nenhum agente encontrado com o ID %d. :(\n", idBusca);
	}
}

int main() {


    char nomesIA[qtdIA][tamNome] = {"Gabrielly", "Xcode", "Margaret"};
    int notas[qtdIA] = {4, 4, 5};
    int setor[qtdIA] = {"5", "1", "6"};
    int ids[qtdIA] = {0, 1, 2};
	int qtdCadastradas = 3;
    int escolha;

    do {
        escolha = menuGeral();

        switch (escolha) {
            case 1:
                cadastro(ids, nomes, setor, notas, &qtdCadastradas);
                break;

            case 2:
                printf("Listar IAs\n");
                break;

			case 3:
    		buscarId(int ids[qtdIA], char nomes[][50], int notas[], int qtdCadastradas);
    		break;

            case 4:
                printf("Buscar por nome\n");
                break;

            case 5:
                printf("Buscar por setor\n");
                break;

            case 6:
                printf("Encerrando o programa...\n");
                break;

            default:
                printf("Opção inválida! Tente novamente.\n");
        }

    } while (escolha != 6);

    return 0;
}

int menuLocal(){
	int menusinhoLocal = 0;
	printf("O que gostaria de fazer?\n");
	printf("1 - Editar esta IA");
	printf("2 - Excluir IA");
	printf("3 - Voltar ao menu Geral");
	scanf("%d", &menusinhoLocal);
	return menusinhoLocal;
}


int menuGeral(){

    int escolhaMenuGeral = 0;

    printf("\nOlá! Eu sou a Margaret!\n");
    printf("Estou aqui para te ajudar a achar I.A's!\n");
    printf("\n1 - Cadastrar\n");
    printf("2 - Listar\n");
    printf("3 - Buscar ID\n");
    printf("4 - Buscar Nome\n");
    printf("5 - Buscar Setor\n");
    printf("6 - Encerrar Programa\n");
    printf("Digite a opção desejada: ");

    scanf("%d", &escolhaMenuGeral);

    return escolhaMenuGeral;
}

int menuSetores(){
	int opcao = 0;
	printf("Agora, digite o número desejado!\n");
	printf("1 - TI\n");
	printf("2 - Cozinha\n");
	printf("3 - Recursos Humanos\n");
	printf("4 - Financeiro\n");
	printf("5 - Estoque\n");
	printf("6 - Outros\n");
	printf("7 - voltar ao menu Geral\n"); //quando clicar, cancela a criação de uma ia e volta ao menu geral
	printf("Escolha o setor: ");
	scanf(" %d", &opcao);

	return opcao;
}


void buscarId(int x[y], char z[][y], int a[], int b);{
    int idBusca;
    int encontrado = 0;
    int i;

    printf("Qual ID deseja buscar? ");
    scanf("%d", &idBusca);

    for (i = 0; i < b; i++){
        if (x[i] == idBusca){
			printf("\nAgente encontrado!;D\n");
			printf("ID: %d\n", x[i]);
			printf("Nome: %s\n", z[i]);
			printf("Nota: %d\n", a[i]);

			encontrado = 1;
			break;
		}
	}
