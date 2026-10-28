/*
ESSA É UMA VERSÃO FEITA PELO CLAUDE AI
APENAS PARA ESTUDAR A ESTRUTURA E A LÓGICA


*/




// Incluindo bibliotecas e definindo constantes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define qtdIA 50
#define tamNome 81
#define tamPrompt 101
#define tamSetor 20
#define tamLinha 400
#define arquivoIAs "ias.txt"

// Protótipos de funções
int lerInt();
int menuSetores();
int menuGeral();
int menuLocal();
void nomeDoSetor(int opcao, char destino[]);
void limparTexto(char texto[]);
void mostrarIA(int id, char nome[], char prompt[], char setor[], int nota);
char *proximoCampo(char **pos);

int carregar(int ids[], char nomes[][tamNome], char prompts[][tamPrompt],
             char setores[][tamSetor], int notas[]);
void salvar(int ids[], char nomes[][tamNome], char prompts[][tamPrompt],
            char setores[][tamSetor], int notas[], int qtd);
void cadastro(int ids[], char nomes[][tamNome], char prompts[][tamPrompt],
              char setores[][tamSetor], int notas[], int *qtd);
void listar(int ids[], char nomes[][tamNome], char prompts[][tamPrompt],
            char setores[][tamSetor], int notas[], int qtd);
void buscarId(int ids[], char nomes[][tamNome], char prompts[][tamPrompt],
              char setores[][tamSetor], int notas[], int qtd);
void buscarNome(int ids[], char nomes[][tamNome], char prompts[][tamPrompt],
                char setores[][tamSetor], int notas[], int qtd);
void buscarSetor(int ids[], char nomes[][tamNome], char prompts[][tamPrompt],
                 char setores[][tamSetor], int notas[], int qtd);

int main() {
    // Arrays paralelos (mesmo índice = mesma IA), sem struct
    int ids[qtdIA];
    char nomes[qtdIA][tamNome];
    char prompts[qtdIA][tamPrompt];
    char setores[qtdIA][tamSetor];
    int notas[qtdIA];
    int qtd;
    int escolha;

    qtd = carregar(ids, nomes, prompts, setores, notas);

    if (qtd == -1) {
        // Arquivo ainda não existe: começa com as 3 IAs iniciais e cria o .txt
        qtd = 3;
        ids[0] = 1; strcpy(nomes[0], "Gabrielly"); strcpy(prompts[0], ""); strcpy(setores[0], "Estoque"); notas[0] = 4;
        ids[1] = 2; strcpy(nomes[1], "Xcode");     strcpy(prompts[1], ""); strcpy(setores[1], "TI");      notas[1] = 4;
        ids[2] = 3; strcpy(nomes[2], "Margaret");  strcpy(prompts[2], ""); strcpy(setores[2], "Outros");  notas[2] = 5;
        salvar(ids, nomes, prompts, setores, notas, qtd);
    }

    do {
        escolha = menuGeral();

        switch (escolha) {
            case 1:
                cadastro(ids, nomes, prompts, setores, notas, &qtd);
                break;
            case 2:
                listar(ids, nomes, prompts, setores, notas, qtd);
                break;
            case 3:
                buscarId(ids, nomes, prompts, setores, notas, qtd);
                break;
            case 4:
                buscarNome(ids, nomes, prompts, setores, notas, qtd);
                break;
            case 5:
                buscarSetor(ids, nomes, prompts, setores, notas, qtd);
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

// ---------------------------------------------------------------
// Arquivo .txt
// Formato: uma IA por linha -> id;nome;prompt;setor;nota
// ---------------------------------------------------------------

// Separa o próximo campo da linha (troca o ';' por '\0' e avança o ponteiro)
char *proximoCampo(char **pos) {
    char *inicio = *pos;
    char *sep;

    if (inicio == NULL) {
        return "";
    }

    sep = strchr(inicio, ';');
    if (sep != NULL) {
        *sep = '\0';
        *pos = sep + 1;
    } else {
        *pos = NULL; // era o último campo
    }
    return inicio;
}

// Lê o .txt para os arrays. Devolve a quantidade lida, ou -1 se o arquivo não existe
int carregar(int ids[], char nomes[][tamNome], char prompts[][tamPrompt],
             char setores[][tamSetor], int notas[]) {
    FILE *arq = fopen(arquivoIAs, "r");
    char linha[tamLinha];
    char *pos, *campoId, *campoNome, *campoPrompt, *campoSetor, *campoNota;
    int qtd = 0;

    if (arq == NULL) {
        return -1;
    }

    while (qtd < qtdIA && fgets(linha, sizeof(linha), arq) != NULL) {
        linha[strcspn(linha, "\r\n")] = '\0';
        if (linha[0] == '\0') {
            continue; // ignora linhas em branco
        }

        pos = linha;
        campoId     = proximoCampo(&pos);
        campoNome   = proximoCampo(&pos);
        campoPrompt = proximoCampo(&pos);
        campoSetor  = proximoCampo(&pos);
        campoNota   = proximoCampo(&pos);

        if (campoNome[0] == '\0') {
            continue; // linha corrompida
        }

        ids[qtd] = atoi(campoId);
        snprintf(nomes[qtd], tamNome, "%s", campoNome);
        snprintf(prompts[qtd], tamPrompt, "%s", campoPrompt);
        snprintf(setores[qtd], tamSetor, "%s", campoSetor);
        notas[qtd] = atoi(campoNota);
        qtd++;
    }

    fclose(arq);
    return qtd;
}

// Reescreve o .txt inteiro com o que está nos arrays
void salvar(int ids[], char nomes[][tamNome], char prompts[][tamPrompt],
            char setores[][tamSetor], int notas[], int qtd) {
    FILE *arq = fopen(arquivoIAs, "w");
    int i;

    if (arq == NULL) {
        printf("Erro: não foi possível salvar no arquivo %s!\n", arquivoIAs);
        return;
    }

    for (i = 0; i < qtd; i++) {
        fprintf(arq, "%d;%s;%s;%s;%d\n", ids[i], nomes[i], prompts[i], setores[i], notas[i]);
    }

    fclose(arq);
}

// ---------------------------------------------------------------
// Funções auxiliares
// ---------------------------------------------------------------

// Lê um inteiro com segurança: se o usuário digitar letras, limpa o buffer e devolve -1
int lerInt() {
    int n;
    if (scanf("%d", &n) != 1) {
        n = -1;
    }
    while (getchar() != '\n'); // descarta o resto da linha
    return n;
}

// Troca ';' por ',' para não quebrar o formato do .txt
void limparTexto(char texto[]) {
    int i;
    for (i = 0; texto[i] != '\0'; i++) {
        if (texto[i] == ';') {
            texto[i] = ',';
        }
    }
}

void nomeDoSetor(int opcao, char destino[]) {
    switch (opcao) {
        case 1: strcpy(destino, "TI"); break;
        case 2: strcpy(destino, "Cozinha"); break;
        case 3: strcpy(destino, "Recursos Humanos"); break;
        case 4: strcpy(destino, "Financeiro"); break;
        case 5: strcpy(destino, "Estoque"); break;
        default: strcpy(destino, "Outros"); break;
    }
}

void mostrarIA(int id, char nome[], char prompt[], char setor[], int nota) {
    printf("\nID: %d\n", id);
    printf("Nome: %s\n", nome);
    printf("Prompt: %s\n", prompt);
    printf("Setor: %s\n", setor);
    printf("Nota: %d\n", nota);
}

// ---------------------------------------------------------------
// Funcionalidades
// ---------------------------------------------------------------

void cadastro(int ids[], char nomes[][tamNome], char prompts[][tamPrompt],
              char setores[][tamSetor], int notas[], int *qtd) {
    int opcao, nota;

    if (*qtd >= qtdIA) {
        printf("Limite de IAs atingido!\n");
        return;
    }

    printf("\n--- Cadastro de nova IA ---\n");

    // O espaço antes do % limpa o buffer; %80[^\n] lê até o Enter (aceita espaços)
    printf("Digite o nome da IA: ");
    scanf(" %80[^\n]", nomes[*qtd]);
    limparTexto(nomes[*qtd]);

    printf("Digite o prompt desta IA: ");
    scanf(" %100[^\n]", prompts[*qtd]);
    limparTexto(prompts[*qtd]);

    printf("Digite o setor da IA: \n");
    opcao = menuSetores();
    while (opcao < 1 || opcao > 7) {
        printf("Opção inválida!\n");
        opcao = menuSetores();
    }

    if (opcao == 7) {
        printf("Cadastro cancelado!\n");
        return;
    }
    nomeDoSetor(opcao, setores[*qtd]);

    printf("Digite a nota da IA (1 - 5): ");
    nota = lerInt();
    while (nota < 1 || nota > 5) {
        printf("Nota inválida! Digite de 1 a 5: ");
        nota = lerInt();
    }
    notas[*qtd] = nota;

    ids[*qtd] = *qtd + 1;
    (*qtd)++;

    salvar(ids, nomes, prompts, setores, notas, *qtd);

    printf("IA cadastrada com sucesso! ;D\n");
}

void listar(int ids[], char nomes[][tamNome], char prompts[][tamPrompt],
            char setores[][tamSetor], int notas[], int qtd) {
    int i;

    if (qtd == 0) {
        printf("Nenhuma IA cadastrada.\n");
        return;
    }
    for (i = 0; i < qtd; i++) {
        mostrarIA(ids[i], nomes[i], prompts[i], setores[i], notas[i]);
    }
}

void buscarId(int ids[], char nomes[][tamNome], char prompts[][tamPrompt],
              char setores[][tamSetor], int notas[], int qtd) {
    int i, idBusca, encontrado = 0;

    printf("Digite o ID que gostaria de buscar: ");
    idBusca = lerInt();

    for (i = 0; i < qtd; i++) {
        if (ids[i] == idBusca) {
            printf("\nAgente encontrado! ;D");
            mostrarIA(ids[i], nomes[i], prompts[i], setores[i], notas[i]);
            encontrado = 1;
            break;
        }
    }

    if (encontrado == 0) {
        printf("Nenhum agente encontrado com o ID %d. :(\n", idBusca);
    }
}

void buscarNome(int ids[], char nomes[][tamNome], char prompts[][tamPrompt],
                char setores[][tamSetor], int notas[], int qtd) {
    char busca[tamNome];
    int i, encontrado = 0;

    printf("Digite o nome que gostaria de buscar: ");
    scanf(" %80[^\n]", busca);

    for (i = 0; i < qtd; i++) {
        if (strstr(nomes[i], busca) != NULL) { // acha nomes parciais: "Mar" acha "Margaret"
            printf("\nAgente encontrado! ;D");
            mostrarIA(ids[i], nomes[i], prompts[i], setores[i], notas[i]);
            encontrado = 1;
        }
    }

    if (encontrado == 0) {
        printf("Nenhum agente encontrado com o nome \"%s\". :(\n", busca);
    }
}

void buscarSetor(int ids[], char nomes[][tamNome], char prompts[][tamPrompt],
                 char setores[][tamSetor], int notas[], int qtd) {
    char busca[tamSetor];
    int i, opcao, encontrado = 0;

    opcao = menuSetores();
    while (opcao < 1 || opcao > 7) {
        printf("Opção inválida!\n");
        opcao = menuSetores();
    }
    if (opcao == 7) {
        return; // volta ao menu geral
    }
    nomeDoSetor(opcao, busca);

    for (i = 0; i < qtd; i++) {
        if (strcmp(setores[i], busca) == 0) {
            mostrarIA(ids[i], nomes[i], prompts[i], setores[i], notas[i]);
            encontrado = 1;
        }
    }

    if (encontrado == 0) {
        printf("Nenhum agente encontrado no setor %s. :(\n", busca);
    }
}

// ---------------------------------------------------------------
// Menus
// ---------------------------------------------------------------

int menuLocal() {
    printf("O que gostaria de fazer?\n");
    printf("1 - Editar esta IA\n");
    printf("2 - Excluir IA\n");
    printf("3 - Voltar ao menu Geral\n");
    printf("Digite a opção desejada: ");
    return lerInt();
}

int menuGeral() {
    printf("\nOlá! Eu sou a Margaret!\n");
    printf("Estou aqui para te ajudar a achar I.A's!\n");
    printf("\n1 - Cadastrar\n");
    printf("2 - Listar\n");
    printf("3 - Buscar ID\n");
    printf("4 - Buscar Nome\n");
    printf("5 - Buscar Setor\n");
    printf("6 - Encerrar Programa\n");
    printf("Digite a opção desejada: ");
    return lerInt();
}

int menuSetores() {
    printf("Agora, digite o número desejado!\n");
    printf("1 - TI\n");
    printf("2 - Cozinha\n");
    printf("3 - Recursos Humanos\n");
    printf("4 - Financeiro\n");
    printf("5 - Estoque\n");
    printf("6 - Outros\n");
    printf("7 - Voltar ao menu Geral\n"); // cancela a operação e volta ao menu geral
    printf("Escolha o setor: ");
    return lerInt();
}
