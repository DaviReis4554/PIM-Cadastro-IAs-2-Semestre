//incluindo bibliotecas e definindo
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define qtdIA 50
#define tamNome 81
#define tamPrompt 101

//protótipos de funções:

int menuSetores();

int menuGeral();

int menuLocal();

void buscarNome();

void buscarId(int ids[], char nomesIA[][tamNome], int qtdCadastradas);

void cadastrarIA() {
    char nomeIA[tamNome];

    printf("Digite o nome da IA:\n");

    fgets(nomeIA, tamNome, stdin);

    // Remover o '\n' do final do nome
    nomeIA[strcspn(nomeIA, "\n")] = '\0';

    printf("Nome cadastrado: %s\n", nomeIA);
}




//protótipos de variável
char nomesIA[qtdIA][tamNome] = {
    "Gabrielly", "Xcode", "Margaret"
};

int qtdCadastradas = 3;

void buscarNome() {
    char nome[tamNome];
    int encontrado = 0;

    printf("Digite o nome da IA que gostaria de buscar:\n");

    fgets(nome, tamNome, stdin);
    nome[strcspn(nome, "\n")] = '\0';

    for (int i = 0; i < qtdCadastradas; i++) {
        if (strcmp(nomesIA[i], nome) == 0) {
            printf("IA encontrada!\n");
            printf("Nome: %s\n", nomesIA[i]);
            printf("ID: %d\n", ids[i]);
            encontrado = 1;
            break;
        }
    }

    if (encontrado == 0) {
        printf("Nenhuma IA encontrada com esse nome.\n");
    }
}



//funções completas


void buscarNome() {
    char nome[tamNome];
    int encontrado = 0;

    printf("Digite o nome da IA que gostaria de buscar:\n");

    fgets(nome, tamNome, stdin);
    nome[strcspn(nome, "\n")] = '\0';

    for (int i = 0; i < qtdCadastradas; i++) {
        if (strcmp(nomesIA[i], nome) == 0) {
            printf("IA encontrada!\n");
            printf("Nome: %s\n", nomesIA[i]);
            printf("ID: %d\n", ids[i]);
            encontrado = 1;
            break;
        }
    }

    if (encontrado == 0) {
        printf("Nenhuma IA encontrada com esse nome.\n");
    }
}

