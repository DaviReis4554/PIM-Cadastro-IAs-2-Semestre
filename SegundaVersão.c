//Bibliotecas------
#include <stdio.h>
#include <string.h>
#include <ctype.h>

//Definindo----------
#define qtdIA 50
#define tamNome 81
#define tamPrompt 101

//prot√≥tipos de fun√ß√µes----------------------------------------------------------------------------
int menuGeral();
int menuSetores();
int lerInt();

void cadastro(int ids[], char nomesIA[][tamNome], int setor[], int notas[], int *qtdCadastradas);

void listarIA(int ids[], char nomesIA[][tamNome], int setor[], int notas[], int qtdCadastradas);

void buscarSetor(int setor[], char nomesIA[][tamNome], int ids[], int notas[], int qtdCadastradas);

<<<<<<< HEAD

void cadastrarIA(){
print("Digite o nome da IA:\n");
fgets(nomesIA, tamNome, stdin);
for(int i  = 0; nomeIA[i] != "\0" ; i++ ){
    if nomeIA[i] == "\n"{
        nomeIA[i] = "\0";
        break;
=======
void buscarId(int x[], char z[][tamNome], int a[], int b);

void buscarNome(int ids[], char nomesIA[][tamNome], int notas[], int qtdCadastradas);

void carregarCatalogo(int ids[], char nomesIA[][tamNome], int setor[], int notas[], int *qtdCadastradas);

void terminarLinha(FILE *arq);

//vari√°veis globais------------
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
>>>>>>> b30b596ef3000bfcc01e0e0bdf2fe71cc6c8a720
    }
}


void buscarId(int x[], char z[][tamNome], int a[], int b) {

    int idBusca;
    int encontrado = 0;
    int i;

<<<<<<< HEAD
//protÛtipos de vari·vel
char nomesIA[qtdIA][tamNome] = {"Gabrielly", "Xcode", "Margaret"};
int qtdCadastradas = 3;
void promptIA[qtdIA][tamPrompt] = {"Auxilie na administraÁ„o do estoque, modifique a quantidade de acordo com a necessidade",
 "Auxilie no desenvolvimento de sistemas e programas com a linguagem escolhida pelo usu·rio.",
 "Aja como orientadora de como usar o programa desenvolvido neste projeto para novos usu·rios"};
int notas[qtdIA] = {4, 4, 5};
int ids[qtdIA] = {0, 1, 2}; //n„o precisamos criar os ids, somente procur·los j· que s„o prÈ existentes
int setor[qtdIA] = {"5", "1", "6"};

int main(){
do {
        int menuGeral();
        switch (menuGeral) {
            case 1:
                cadastro(ids, nomes, setor, notas, &qtdCadastradas);
                break;

            case 2:
                printf("Listar IAs:\n");
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
                printf("OpÁ„o inv·lida! Tente novamente.\n");
        }

    } while (escolha != 6);

    return 0;
=======
    printf("Qual ID deseja buscar? ");
    idBusca = lerInt();
>>>>>>> b30b596ef3000bfcc01e0e0bdf2fe71cc6c8a720

    for (i = 0; i < b; i++){

<<<<<<< HEAD
}
=======
        if (x[i] == idBusca){
>>>>>>> b30b596ef3000bfcc01e0e0bdf2fe71cc6c8a720

            printf("\nAgente encontrado!;D\n");
            printf("ID: %d\n", x[i]);
            printf("Nome: %s\n", z[i]);
            printf("Nota: %d\n", a[i]);

<<<<<<< HEAD
<<<<<<< HEAD
int menuGeral(){

    int escolhaMenuGeral = 0;

    printf("\nOl·! Eu sou a Margaret!\n");
    printf("Estou aqui para te ajudar a achar I.A's!\n");
    printf("\n1 - Cadastrar\n");
    printf("2 - Listar\n");
    printf("3 - Buscar ID\n");
    printf("4 - Buscar Nome\n");
    printf("5 - Buscar Setor\n");
    printf("6 - Encerrar Programa\n");
    printf("Digite a opÁ„o desejada: ");

    scanf("%d", &escolhaMenuGeral);

    return escolhaMenuGeral;
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

int menuSetores(){
	int opcao = 0;
	printf("Agora, digite o n˙mero desejado!\n");
	printf("1 - TI\n");
	printf("2 - Cozinha\n");
	printf("3 - Recursos Humanos\n");
	printf("4 - Financeiro\n");
	printf("5 - Estoque\n");
	printf("6 - Outros\n");
	printf("7 - voltar ao menu Geral\n"); //quando clicar, cancela a criaÁ„o de uma ia e volta ao menu geral
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







Rastreando dois laÁos
for (int i = 1; i <= 2; i++) {
 for (int j = 1; j <= 3;
j++) {
 printf("%d %d\n", i,
j);
 }
}


void promptIA[qtdIA][tamPrompt];
printf("Digite o prompt desta IA:\n");
fgets(promptIA, tamPrompt, stdin);
for(int i  = 0; promptIA[i] != '\0' ; i++ ){
    if (promptIA[i] == '\n'){
        promptIA[i] = '\0';
        break;
=======
void buscarNome(nomesIA[qtdIA]{
    fopen(ìarquivo.txtî, ìrî);
    char nome();
    printf(ìdigite o nome que gostaria de buscar:\nî);
    fgets(nome, tamNome, stdin);
    for (i=0, i=tamNome, i++){
        if (i == nome){
            printf(i);
    fclose(ìarquivo.txtî):
>>>>>>> 7278fd45e1494f5a9b121855670ee52567c10ba2
    }
}

=======
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
>>>>>>> b30b596ef3000bfcc01e0e0bdf2fe71cc6c8a720
