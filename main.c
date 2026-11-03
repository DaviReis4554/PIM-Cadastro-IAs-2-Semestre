
//Bibliotecas------
#include <stdio.h>
#include <string.h>

//Definindo----------
#define qtdIA 50
#define tamNome 81
#define tamPrompt 101

//protótipos de funções----------------------------------------------------------------------------
int menuGeral();
int menuSetores();

void cadastro(int ids[], char nomesIA[][tamNome],int setor[], int notas[], int *qtdCadastradas);

void listarIAs(int ids[], char nomesIA[][tamNome],int setor[], int notas[], int qtdCadastradas);

void buscarSetor(int setor[], char nomesIA[][tamNome],int ids[], int notas[], int qtdCadastradas);

void buscarId(int x[], char z[][tamNome], int a[], int b);

void terminarLinha(FILE *arq);

void apagarIA();

void editarIA();

//variáveis globais------------
char nomesIA[qtdIA][tamNome];
int notas[qtdIA];
int setor[qtdIA];
int ids[qtdIA];
char prompts[qtdIA][tamPrompt];
int qtdCadastradas = 0;












int main(){
    do{
        FILE *arquivoIA = fopen("catalogo.txt", "a");

    if (arquivoIA == NULL) {
        printf("Nao foi possivel abrir o arquivo.\n");
        return 1;
    }

    int escolha = menuGeral();

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
        fclose(arquivoIA);
    } while (escolha != 6);

    return 0;


    fclose(arquivoIA);

}













//Funcoes completas-----------------------------------------
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


char buscarNome(int x[], char z[][tamNome], int a[], int b){
    fopen("catalogo.txt", "a");
    int nomeBusca;
    int encontrado = 0;
    int i;
    printf("Qual Nome gostaria de buscar?");
    fgets(nomesIA, tamNome,nomeBusca);
    terminarLinha(arquivoIA);
    for (i=0, i<= qdtcadastrada, i++){
        if (i==nomeBusca){
            printf("\nAgente encontrado!;D\n");
            printf("ID: %d\n", x[i]);
            printf("Nome: %s\n", z[i]);
            printf("Nota: %d\n", a[i]);
            encontrado = 1;

    }
      if (encontrado!1) {
                printf("Agente não encontrado!");
                break;
}
}


void terminarLinha(FILE *arq){

    int c;

    while ((c = fgetc(arq)) != '\n' && c != EOF);
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


void cadastro(int ids[], char nomesIA[][tamNome],int setor[], int notas[], int *qtdCadastradas) {

    FILE *arquivoIA;

    if (*qtdCadastradas >= qtdIA) {
        printf("Limite de IAs cadastradas atingido.\n");
        return;
    }

    printf("Digite o nome da IA:\n");

    getchar();

    fgets(nomesIA[*qtdCadastradas], tamNome, stdin);

    nomesIA[*qtdCadastradas]
    [strcspn(nomesIA[*qtdCadastradas], "\n")] = '\0';

    printf("Digite o setor da IA (1 - 6):\n");

    setor[*qtdCadastradas] = menuSetores();

    printf("Digite a nota da IA (1 - 5):\n");

    scanf("%d", &notas[*qtdCadastradas]);

    ids[*qtdCadastradas] = *qtdCadastradas + 1;

    arquivoIA = fopen("catalogo.txt", "a");

    if (arquivoIA == NULL) {
        printf("Nao foi possivel abrir o arquivo.\n");
        return;
    }

    fprintf(arquivoIA, "%d;%s;%d;%d\n",
            ids[*qtdCadastradas],
            nomesIA[*qtdCadastradas],
            setor[*qtdCadastradas],
            notas[*qtdCadastradas]);

    fclose(arquivoIA);

    (*qtdCadastradas)++;

    printf("IA cadastrada com sucesso!\n");
}


void buscarSetor(int setor[], char nomesIA[][tamNome],int ids[], int notas[], int qtdCadastradas) {

    int setorBusca;
    int encontrado = 0;

    printf("Digite o setor que deseja buscar (1 - 6):\n");
    printf("1 - TI\n");
    printf("2 - Cozinha\n");
    printf("3 - Recursos Humanos\n");
    printf("4 - Financeiro\n");
    printf("5 - Estoque\n");
    printf("6 - Outros\n");
    printf("7 - voltar ao menu Geral\n");

    printf("Escolha o setor: ");
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
    printf("7 - voltar ao menu Geral\n");
    printf("Escolha o setor: ");
    scanf(" %d", &opcao);

    return opcao;
}


void listarIAs(int ids[], char nomesIA[][tamNome],int setor[], int notas[], int qtdCadastradas) {

    if (qtdCadastradas == 0) {
        printf("Nenhuma IA cadastrada.\n");
        return;
    }

    printf("\n--- Lista de IAs Cadastradas ---\n");

    for (int i = 0; i < qtdCadastradas; i++) {

        printf("ID: %d\n", ids[i]);
        printf("Nome: %s\n", nomesIA[i]);

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
