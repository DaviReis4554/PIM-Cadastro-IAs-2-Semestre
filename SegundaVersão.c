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

void buscarId(int x[y], char z[][y], int a[], int b);//ficou genérico(confirmar se podemos deixar o protótipo assim)

void cadastrarIA(){
print("Digite o nome da IA:\n");
fgets(nomeIA, tamNome, stdin);
for(int i  = 0; nomeIA[i] != "\0" ; i++ ){
    if nomeIA[i] == "\n"{
        nomeIA[i] = "\0";
        break;
    }
}
}




//protótipos de variável
char nomesIA[qtdIA][tamNome] = {"Gabrielly", "Xcode", "Margaret"};
int qtdCadastradas = 3;
char promptIA[qtdIA][tamNome] = {"Auxilie na administração do estoque, modifique a quantidade de acordo com a necessidade",
 "Auxilie no desenvolvimento de sistemas e programas com a linguagem escolhida pelo usuário.",
 "Aja como orientadora de como usar o programa desenvolvido neste projeto para novos usuários"};
int notas[qtdIA] = {4, 4, 5};
int ids[qtdIA] = {0, 1, 2}; //não precisamos criar os ids, somente procurálos já que são pré existentes
int setor[qtdIA] = {"5", "1", "6"};
int escolha;



//funções completas

void buscarNome(nomesIA[qtdIA]{
    fopen(“arquivo.txt”, “r”);
    char nome();
    printf(“digite o nome que gostaria de buscar:\n”);
    fgets(nome, tamNome, stdin);
    for (i=0, i=tamNome, i++){
        if (i == nome){
            printf(i);
    fclose(“arquivo.txt”):
    }
}
