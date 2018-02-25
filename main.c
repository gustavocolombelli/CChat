#include "conexao.h"
#include "view.h"



void menuInicial();
void chat();

int main()
{
    menuInicial();
    chat();
}

void menuInicial(){
    int op;

    printf("Informe o usuario: ");
    scanf("%40[^\n]", usuario);
    cls

    vMenuInicial();

    //scanf("%d", &op);
    op=3;

    switch ( op ){

        case 1: criaSalaChat();
        break;

        case 2: printf("Conectando...");
        break;

        case 3: conecta("localhost", "root", "root", "chat");
        break;

        default : printf("Opcao Invalida");
        break;
    }
    cls
}

void chat(){
    char mensagem[255];
    do{
        cls
        fflush(stdin);
        scanf("%255[^\n]", mensagem);
        enviaMensagem(mensagem);
    }while(1);
}
