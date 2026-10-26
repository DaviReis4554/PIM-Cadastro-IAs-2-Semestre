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

void buscarNome();

void buscarId(int x[y], char z[][y], int a[], int b);//ficou genérico(confirmar se podemos deixar o protótipo assim)


void cadastrarIA(){
print("Digite o nome da IA:\n");
fgets(nomesIA, tamNome, stdin);
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
void promptIA[qtdIA][tamPrompt] = {"Auxilie na administração do estoque, modifique a quantidade de acordo com a necessidade",
 "Auxilie no desenvolvimento de sistemas e programas com a linguagem escolhida pelo usuário.",
 "Aja como orientadora de como usar o programa desenvolvido neste projeto para novos usuários"};
int notas[qtdIA] = {4, 4, 5};
int ids[qtdIA] = {0, 1, 2}; //não precisamos criar os ids, somente procurálos já que são pré existentes
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
                printf("Opção inválida! Tente novamente.\n");
        }

    } while (escolha != 6);

    return 0;


}

//funções completas

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







Rastreando dois laços
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
    }
}

