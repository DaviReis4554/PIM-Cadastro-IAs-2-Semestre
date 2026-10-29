
#include <stdio.h>

#define qtdIA 50
#define tamNome 81
#define tamPrompt 101

int menuGeral() {
    int opcao;
    printf("\n|================ BEM - VINDO ===============|\n");
    printf("|          Ola! Eu sou a Margaret!           |\n");
    printf("|  Estou aqui para te ajudar a achar I.A's!  |\n");
    printf("|============================================|\n");
    printf("1 - Cadastrar IA\n");
    printf("2 - Listar IAs\n");
    printf("3 - Buscar por ID\n");
    printf("4 - Buscar por nome\n");
    printf("5 - Buscar por setor\n");
    printf("6 - Sair\n");
    printf("Escolha uma opcao: ");

    scanf("%d", &opcao);

    return opcao;
}

int main() {
    char nomesIA[qtdIA][tamNome] = {"Gabrielly", "Xcode", "Margaret"};
    int notas[qtdIA] = {4, 4, 5};
    int setor[qtdIA] = {5, 1, 6};
    int ids[qtdIA] = {0, 1, 2};
    int qtdCadastradas = 3;
    int escolha;

    do {
        escolha = menuGeral();

        switch (escolha) {
            case 1:
                cadastro(ids, nomesIA, setor, notas, &qtdCadastradas);
                break;

            case 2:
                listarIAs(ids, nomesIA, setor, notas, qtdCadastradas);
                break;

            case 3:
                buscarId(ids, nomesIA, notas, qtdCadastradas);
                break;

            case 4:
                printf("Funcao de busca por nome ainda nao implementada.\n");
                break;

            case 5:
                buscarSetor(setor, nomesIA, ids, notas, qtdCadastradas);
                break;

            case 6:
                printf("Encerrando o programa...\n");
                break;

            case 0:
                printf("Entrada invalida! Digite um numero.\n");
                break;

            default:
                printf("Opcao invalida! Tente novamente.\n");
        }

    } while (escolha != 6);

    return 0;
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








//FUNÇÃO PARA CADASTRAR AS I.A'S
void cadastro(int ids[], char nomesIA[][tamNome], int setor[], int notas[], int *qtdCadastradas) {
    if (*qtdCadastradas >= qtdIA) {
        printf("Limite de IAs cadastradas atingido.\n");
        return;
    }

    printf("Digite o nome da IA:\n");
    getchar(); // Limpar o buffer do teclado
    fgets(nomesIA[*qtdCadastradas], tamNome, stdin);
    nomesIA[*qtdCadastradas][strcspn(nomesIA[*qtdCadastradas], "\n")] = '\0';

    printf("Digite o setor da IA (1 - 6):\n");
    setor[*qtdCadastradas] = menuSetores();

    printf("Digite a nota da IA (1 - 5):\n");
    scanf("%d", &notas[*qtdCadastradas]);

    ids[*qtdCadastradas] = *qtdCadastradas;

    (*qtdCadastradas)++;
    printf("IA cadastrada com sucesso!\n");
}




//FUNÇÃO DE LISTAR AS I.A'S
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


//FUNÇÃO DE BUSCAR O SETOR DAS I.A'S
void buscarSetor(int setor[], char nomesIA[][tamNome], int ids[], int notas[], int qtdCadastradas) {
    int setorBusca;
    int encontrado = 0;

    printf("Digite o setor que deseja buscar (1 - 6): ");
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


//FUNÇÃO PARA BUSCAR O ID DAS I.A'S
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