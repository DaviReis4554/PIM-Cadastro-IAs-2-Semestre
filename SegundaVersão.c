//Bibliotecas------
#include <stdio.h>
#include <string.h>
#include <ctype.h>

//Definindo----------
#define qtdIA 50
#define tamNome 81
#define tamPrompt 101

//protótipos de funções----------------------------------------------------------------------------
int menuGeral();
int menuSetores();
int lerInt();

void cadastro(int ids[], char nomesIA[][tamNome], int setor[], int notas[], int *qtdCadastradas);

void listarIA(int ids[], char nomesIA[][tamNome], int setor[], int notas[], int qtdCadastradas);

void buscarSetor(int setor[], char nomesIA[][tamNome], int ids[], int notas[], int qtdCadastradas);

void buscarId(int x[], char z[][tamNome], int a[], int b);

void buscarNome(int ids[], char nomesIA[][tamNome], int notas[], int qtdCadastradas);

void carregarCatalogo(int ids[], char nomesIA[][tamNome], int setor[], int notas[], int *qtdCadastradas);

void terminarLinha(FILE *arq);

//variáveis globais------------
char nomesIA[qtdIA][tamNome];
int notas[qtdIA];
int setor[qtdIA];
int ids[qtdIA];
char prompts[qtdIA][tamPrompt];
int qtdCadastradas = 0;

const char *nomesSetor[] = {"Desconhecido", "TI", "Cozinha", "Recursos Humanos",
                            "Financeiro", "Estoque", "Outros"};


int main(){
    int escolha;   // declarada FORA do do-while para poder ser usada na condicao

    // carrega o que ja foi salvo em execucoes anteriores
    carregarCatalogo(ids, nomesIA, setor, notas, &qtdCadastradas);

    do{
        escolha = menuGeral();

        switch (escolha) {
            case 1:
                cadastro(ids, nomesIA, setor, notas, &qtdCadastradas);
                break;

            case 2:
                listarIA(ids, nomesIA, setor, notas, qtdCadastradas);
                break;

            case 3:
                buscarId(ids, nomesIA, notas, qtdCadastradas);
                break;

            case 4:
                buscarNome(ids, nomesIA, notas, qtdCadastradas);
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


//Funcoes completas-----------------------------------------

// Le um inteiro de forma segura. Se o usuario digitar letras, retorna 0.
// Sempre descarta o resto da linha (inclusive o '\n').
int lerInt() {
    int valor;

    if (scanf("%d", &valor) != 1) {
        valor = 0;
    }
    terminarLinha(stdin);

    return valor;
}


void terminarLinha(FILE *arq){

    int c;

    while ((c = fgetc(arq)) != '\n' && c != EOF);
}


int menuGeral() {
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

    return lerInt();
}


// Carrega o catalogo.txt para os vetores ao iniciar o programa
void carregarCatalogo(int ids[], char nomesIA[][tamNome], int setor[], int notas[], int *qtdCadastradas) {

    FILE *arq = fopen("catalogo.txt", "r");
    char linha[200];

    if (arq == NULL) {
        return;   // primeira execucao: ainda nao existe arquivo
    }

    while (*qtdCadastradas < qtdIA && fgets(linha, sizeof(linha), arq)) {
        int id, s, n;
        char nome[tamNome];

        if (sscanf(linha, "%d;%80[^;];%d;%d", &id, nome, &s, &n) == 4) {
            ids[*qtdCadastradas] = id;
            strcpy(nomesIA[*qtdCadastradas], nome);
            setor[*qtdCadastradas] = s;
            notas[*qtdCadastradas] = n;
            (*qtdCadastradas)++;
        }
    }

    fclose(arq);
}


void buscarNome(int ids[], char nomesIA[][tamNome], int notas[], int qtdCadastradas){

    char nomeBusca[tamNome];
    char nomeMin[tamNome];
    char atualMin[tamNome];
    int encontrado = 0;
    int i, j;

    printf("Qual nome gostaria de buscar? ");
    fgets(nomeBusca, tamNome, stdin);
    nomeBusca[strcspn(nomeBusca, "\n")] = '\0';

    // deixa tudo minusculo para a busca nao diferenciar maiuscula de minuscula
    for (j = 0; nomeBusca[j] != '\0'; j++) {
        nomeMin[j] = tolower((unsigned char)nomeBusca[j]);
    }
    nomeMin[j] = '\0';

    for (i = 0; i < qtdCadastradas; i++){

        for (j = 0; nomesIA[i][j] != '\0'; j++) {
            atualMin[j] = tolower((unsigned char)nomesIA[i][j]);
        }
        atualMin[j] = '\0';

        if (strstr(atualMin, nomeMin) != NULL) {   // aceita nome parcial
            printf("\nAgente encontrado!;D\n");
            printf("ID: %d\n", ids[i]);
            printf("Nome: %s\n", nomesIA[i]);
            printf("Nota: %d\n", notas[i]);
            encontrado = 1;
        }
    }

    if (!encontrado) {
        printf("Agente nao encontrado!\n");
    }
}


void buscarId(int x[], char z[][tamNome], int a[], int b) {

    int idBusca;
    int encontrado = 0;
    int i;

    printf("Qual ID deseja buscar? ");
    idBusca = lerInt();

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


void cadastro(int ids[], char nomesIA[][tamNome],
              int setor[], int notas[], int *qtdCadastradas) {

    FILE *arquivoIA;
    int pos = *qtdCadastradas;
    int s, n;

    if (pos >= qtdIA) {
        printf("Limite de IAs cadastradas atingido.\n");
        return;
    }

    printf("Digite o nome da IA:\n");

    fgets(nomesIA[pos], tamNome, stdin);
    nomesIA[pos][strcspn(nomesIA[pos], "\n")] = '\0';

    if (nomesIA[pos][0] == '\0') {
        printf("O nome nao pode ficar vazio.\n");
        return;
    }

    // o ';' e o separador do arquivo, entao nao pode aparecer no nome
    for (int i = 0; nomesIA[pos][i] != '\0'; i++) {
        if (nomesIA[pos][i] == ';') nomesIA[pos][i] = ',';
    }

    // setor: repete ate ser valido (1 a 6) ou o usuario voltar (7)
    do {
        s = menuSetores();
        if (s == 7) {
            printf("Cadastro cancelado.\n");
            return;
        }
        if (s < 1 || s > 6) {
            printf("Setor invalido! Escolha de 1 a 6.\n");
        }
    } while (s < 1 || s > 6);

    // nota: repete ate ser valida (1 a 5)
    do {
        printf("Digite a nota da IA (1 - 5):\n");
        n = lerInt();
        if (n < 1 || n > 5) {
            printf("Nota invalida! Escolha de 1 a 5.\n");
        }
    } while (n < 1 || n > 5);

    setor[pos] = s;
    notas[pos] = n;
    ids[pos] = pos + 1;

    arquivoIA = fopen("catalogo.txt", "a");

    if (arquivoIA == NULL) {
        printf("Nao foi possivel abrir o arquivo.\n");
        return;
    }

    fprintf(arquivoIA, "%d;%s;%d;%d\n", ids[pos], nomesIA[pos], setor[pos], notas[pos]);

    fclose(arquivoIA);

    (*qtdCadastradas)++;

    printf("IA cadastrada com sucesso!\n");
}


void buscarSetor(int setor[], char nomesIA[][tamNome],
                 int ids[], int notas[], int qtdCadastradas) {

    int setorBusca;
    int encontrado = 0;

    setorBusca = menuSetores();

    if (setorBusca == 7) {
        return;   // voltar ao menu geral
    }

    if (setorBusca < 1 || setorBusca > 6) {
        printf("Setor invalido! Escolha de 1 a 6.\n");
        return;
    }

    printf("\n--- IAs no Setor %s ---\n", nomesSetor[setorBusca]);

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
        printf("Nenhuma IA encontrada no setor %s.\n", nomesSetor[setorBusca]);
    }
}


int menuSetores(){

    printf("Agora, digite o numero desejado!\n");
    printf("1 - TI\n");
    printf("2 - Cozinha\n");
    printf("3 - Recursos Humanos\n");
    printf("4 - Financeiro\n");
    printf("5 - Estoque\n");
    printf("6 - Outros\n");
    printf("7 - voltar ao menu Geral\n");
    printf("Escolha o setor: ");

    return lerInt();
}


void listarIA(int ids[], char nomesIA[][tamNome], int setor[], int notas[], int qtdCadastradas) {

    if (qtdCadastradas == 0) {
        printf("Nenhuma IA cadastrada.\n");
        return;
    }

    printf("\n--- Lista de IAs Cadastradas ---\n");

    for (int i = 0; i < qtdCadastradas; i++) {
        int s = setor[i];
        if (s < 1 || s > 6) s = 0;  // setor invalido vira "Desconhecido"

        printf("ID: %d\n", ids[i]);
        printf("Nome: %s\n", nomesIA[i]);
        printf("Setor: %s\n", nomesSetor[s]);
        printf("Nota: %d\n", notas[i]);
        printf("-----------------------------\n");
    }
}