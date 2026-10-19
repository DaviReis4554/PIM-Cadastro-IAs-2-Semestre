//criar as funçoes comentadas

/*criar as funçoes normais
agenteIA(id,nome, script, nota, classe)
menulocal(X) (devem ser dentro das funçoes?
menugeral(i)
*/

//int main

//fazer um do-while pra apresentar o menu geral ao menos uma vez dar um return 1 se o user encerrar o programa. while resposta menu != 1

//(switch-case talvez) printf("Digite o número correspondente á sua escolha:\n1- cadastrar agente\n2- listar agentes\n3- buscar agente por id\n4- buscar agente por nome\n5- encerrar programa");

//printf("menu local:\n1- Editar este agente\n2-excluir este agente\n3-voltar ao menu geral");

//TEMOS QUE FAZER ALGUMA OPÇÃO CASO O USUÁRIO DIGITE UM NÚMERO INVÁLIDO OU COLOQUE UM LETRA, PQ POR AGORA ESTÁ QUEBRANDO O PROGRAMA




#include <stdio.h>
#define MAX 5
void menuGeral(){
        int menusinhoGeral = 0; //Tirei o '()' antes do '='
        printf("Olá! Eu sou a Margaret!\nEstou aqui pra te ajudar a achar IAs para te auxiliar no trabalho!\nPrimeiro, escolha uma das opções a seguir:"); // Faltava vírgula
        printf("\n1 - Cadastrar\n");
        printf("2 - Listar\n");
        printf("3 - Buscar ID\n");
        printf("4 - Buscar Nome\n"); //faltava vírgula
        printf("5 - Buscar Setor\n");
        printf("6 - Encerrar programa\n");
        printf("Digite sua a opção desejada: ");
        scanf("%d", &menusinhoGeral);
        return menuGeral();    //Tinha um ';' a mais e aqui tem que ser menuGeral()
        }
void menuLocal(){
    int menusinhoLocal = 0;
    printf("1 - Editar esta IA");
    printf("2 - Excluir esta IA");
    printf("3 - Voltar ao menu Geral");
    scanf("%d", &menusinhoLocal);
    return menuLocal(); //Aqui tem que ser menuLocal()
    }

void listar(); //tudo que eu colocar como void vai ser uma função. Estou escrevendo elas fora do main por enquanto. se quiser mudar pode mudar - mi
void buscarId();
void buscarNome();
void buscarSetor();
void encerrar();
//nós vamos ter que usar arranjos para criar matrizes.
int ids[];
char ia[];
char nomeIA[];
char script[];
char nota[];
char setores[];


//int opcaoGeral() acho que isso n precisa

int main() {
    // I.A's cadastradas para teste.
    char nomes[MAX][50] = {"Gabrielly", "Xcode", "Margaret"}; //está com um fluxo de retorno, quando cadawstramos ele volta a pedir o nome novamente.
    float notas[MAX] = {4.0,4.0,5.0}; // pensei de ser int já que tem que ser de 1-5

    int qtd = 3; //Como já temos 3 cadastradas, tem q manter em 3 por ser qtd mínima -Mudei os nomes das ias para as que definimos no dia da reuniao-milena
    int i;
    do {
        menuGeral();
        } while (menuGeral!= 7);
    switch (menuGeral()){
case 1:
    cadastro();
    break;
case 2:
    listar();
    break;
case 3:
    buscarId();
    break;
case 4:
    buscarNome();
    break;
case 5:
    buscarSetor();
case 6:
    encerrar()
    break;}
}
