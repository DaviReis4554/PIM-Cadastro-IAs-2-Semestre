
#include <stdio.h>
#include <string.h>
#define MAX 50

/*
char prompt[];
int notas[];
int setor[];
*/

int setores(){
	printf("1 - TI\n");
	printf("2 - Cozinha\n");
	printf("3 - Recursos Humanos\n");
	printf("4 - Financeiro\n");
	printf("5 - Estoque\n");
	printf("6 - Outros\n");
	printf("7 - voltar ao menu Geral\n"); //quando clicar, cancela a criação de uma ia e volta ao menu geral
}


int menuGeral() {
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

int menuLocal(){
	int menusinhoLocal = 0;
	printf("1 - Editar esta IA");
	printf("2 - Excluir IA");
	printf("3 - Voltar ao menu Geral");
	scanf("%d", &menusinhoLocal);
	return menusinhoLocal;
}

char cadastro(int ids[MAX], char nomes[MAX][50], char setor[MAX][50], int notas[MAX], int *qtd) {
    /*
	if (*qtd >= MAX) {
        printf("Limite de IAs atingido!\n");
        return;
    }
    */
    ids[*qtd] = *qtd + 1;

    printf("\n--- Cadastro de nova IA ---\n");

    // O espaço antes do %s limpa o buffer automaticamente
    printf("Digite o nome da IA: ");
    scanf(" %s", nomes[*qtd]);

    printf("Digite o setor da IA: ");
    setores();

    printf("Digite a nota da IA (1 - 5):");
    scanf(" %d", &notas[*qtd]);

    (*qtd)++;


    printf("IA cadastrada com sucesso!\n");
}

void buscarId(int ids[MAX], char nomes[][50], int notas[], int qtd){
    int idBusca;
    int encontrado = 0;
    int i;

    printf("Qual ID deseja buscar? ");
    scanf("%d", &idBusca);

    for (i = 0; i < qtd; i++){
        if (ids[i] == idBusca){
			printf("\nAgente encontrado!\n");
			printf("ID: %d\n", ids[i]);
			printf("Nome: %s\n", nomes[i]);
			printf("Nota: %d\n", notas[i]);

			encontrado = 1;
			break;
		}
	}

	if (encontrado == 0){
		printf("Nenhum agente encontrado com o ID %d.\n", idBusca);
	}
}

int main() {
    char nomes[MAX][50] = {"Gabrielly", "Xcode", "Margaret"};
    int notas[MAX] = {4, 4, 5};
    char setor[MAX][50] = {"Estoque", "TI", "Outros"};
    int ids[MAX] = {1, 2, 3};
	int qtd = 3;
    int escolha;

    do {
        escolha = menuGeral();

        switch (escolha) {
            case 1:
                cadastro(ids, nomes, setor, notas, &qtd);
                break;

            case 2:
                printf("Listar IAs\n");
                break;

			case 3:
    		buscarId(ids, nomes, notas, qtd);
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
