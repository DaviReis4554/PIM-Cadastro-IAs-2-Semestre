//Bibliotecas------
#include <stdio.h>
#include <string.h>

//Definindo----------
#define qtdIA 50
#define tamNome 81 //tem um caractere a mais para que o '\0' não afete o número total de caracteres normais.
#define tamPrompt 101 // mesma coisa

//protótipos de funções----------------------------------------------------------------------------
int menuGeral();
int menuSetores();
void cadastro(int ids[], char nomesIA[][tamNome], int setor[], int notas[], int *qtdCadastradas);
void listarIAs(int ids[], char nomesIA[][tamNome], int setor[], int notas[], int qtdCadastradas);
void buscarSetor(int setor[], char nomesIA[][tamNome], int ids[], int notas[], int qtdCadastradas);
void buscarId(int x[], char z[][tamNome], int a[], int b);
void terminarLinha(FILE *arq);
void apagarIA[qtdIA];
void editarIA[qtdIA];
FILE *arquivoIA;

//variáveis globais
char nomesIA[qtdIA][tamNome];
int notas[qtdIA];
int setor[qtdIA];
int ids[qtdIA];
char prompts[qtdIA];
int qtdCadastradas();







int main(){
arquivoIA = fopen("catalogo.txt","w");
fprintf(arquivoIA, "-------Bem-vindo ao catálogo de IA's da Gobal Comunidade!--------");
fclose(arquivoIA);












}






void terminarLinha(FILE *arq){
    int c;
    while ((c = fgetc(arq)) != '\n' && != EOF};
    }



void buscarId(int x[], char z[][tamNome], int a[], int b) {
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

    if (!encontrado) {
        printf("Nenhum agente encontrado com o ID %d. :(\n", idBusca);
    }
}



void cadastro(int ids[], char nomesIA[][tamNome], int setor[], int notas[], int *qtdCadastradas) {
    if (*qtdCadastradas >= qtdIA) {
        printf("Limite de IAs cadastradas atingido.\n");
        return;
    }
    arquivoIA = fopen("catalogo.txt", "w");
    if(arquivoIA == NULL) printf("Não foi possível abrir o arquivo");
    printf("Digite o nome da IA:\n");
    terminarLinha(); // Limpa o buffer do teclado
    fgets(nomesIA[*qtdCadastradas], tamNome, arquivoIA);
    nomesIA[*qtdCadastradas][strcspn(nomesIA[*qtdCadastradas], "\n")] = '\0';

    printf("Digite o setor da IA (1 - 6):\n");
    setor[*qtdCadastradas] = menuSetores();

    printf("Digite a nota da IA (1 - 5):\n");
    fscanf("%d", &notas[*qtdCadastradas]);

    ids[*qtdCadastradas] = *qtdCadastradas;

    (*qtdCadastradas)++;
    printf("IA cadastrada com sucesso!\n");
}



void buscarSetor(int setor[], char nomesIA[][tamNome], int ids[], int notas[], int qtdCadastradas) {
    int setorBusca;
    int encontrado = 0;

    printf("Digite o setor que deseja buscar (1 - 6): ");
	printf("1 - TI\n");
	printf("2 - Cozinha\n");
	printf("3 - Recursos Humanos\n");
	printf("4 - Financeiro\n");
	printf("5 - Estoque\n");
	printf("6 - Outros\n");
	printf("7 - voltar ao menu Geral\n");
	printf("Escolha o setor: ")
    scanf("%d", &setorBusca);


    printf("\n--- IAs no Setor %d ---\n", setorBusca);
    for (int i = 0; i < qtdCadastradas; i++) {
        if (setor[i] == setorBusca) {
            printf("ID: %d\n", ids[i]);
            printf("Nome: %s\n", nomesIA[i]);
            printf("Nota: %d\n", notas[i]);
            printf("-----------------------------\n");
            encontrado = 1;
        }
    }
    if (!encontrado) {
        printf("Nenhuma IA encontrada no setor %d.\n", setorBusca);
    }
}



int menuSetores(){
	int opcao = 0;
	printf("Agora, digite o numero desejado!\n");
	printf("1 - TI\n");
	printf("2 - Cozinha\n");
	printf("3 - Recursos Humanos\n");
	printf("4 - Financeiro\n");
	printf("5 - Estoque\n");
	printf("6 - Outros\n");
	printf("7 - voltar ao menu Geral\n"); //quando clicar, cancela a cria��o de uma ia e volta ao menu geral
	printf("Escolha o setor: ");
	scanf(" %d", &opcao);

	return opcao;
}



void listarIAs(int ids[], char nomesIA[][tamNome], int setor[], int notas[], int qtdCadastradas) {
    if (qtdCadastradas == 0) {
        printf("Nenhuma IA cadastrada.\n");
        return;
    }

    printf("\n--- Lista de IAs Cadastradas ---\n");
    for (int i = 0; i < qtdCadastradas; i++) {
        printf("ID: %d\n", ids[i]);
        printf("Nome: %s\n", nomesIA[i]);
        //printf("Setor: %d\n", setor[i]);
        if (setor[i] == 1) {
            printf("Setor: TI\n");
        } else if (setor[i] == 2) {
            printf("Setor: Cozinha\n");
        } else if (setor[i] == 3) {
            printf("Setor: Recursos Humanos\n");
        } else if (setor[i] == 4) {
            printf("Setor: Financeiro\n");
        } else if (setor[i] == 5) {
            printf("Setor: Estoque\n");
        } else if (setor[i] == 6) {
            printf("Setor: Outros\n");
        }
        printf("Nota: %d\n", notas[i]);
        printf("-----------------------------\n");
    }
}
