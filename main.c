#include "conexao.h"
#include "view.h"



void menuInicial();
void chat();

int main()
{
    printf("Conectando ao servidor...");
    conecta("sql3.freemysqlhosting.net", "sql3222753", "XNAw3Payd3", "sql3222753"); //online server
    menuInicial();
}

void menuInicial(){
    int op;
    cls
    printf("Informe o usuario: ");
    scanf("%40[^\n]", usuario);

    do {
        cls
        vMenuInicial();
        fflush(stdin);
        scanf("%d", &op);

        switch ( op ){

            case 1: criaSalaChat();
            break;

            case 2: mostrarSalas();
            break;

            case 3: chat();
            break;

            default : printf("Opcao Invalida");
            break;
        }
    }while(op);
    cls
}

void chat(){
    char mensagem[255];
    int op, cod_sala_escolhida;

    printf("Informe o numero da sala: ");
    scanf("%d", &cod_sala_escolhida);

    do{
        printf("--- Opcoes ---\n1 - Enviar Mensagem\n2 - Ver Mensagens\n\nOPCAO: ");
        scanf("%d", &op);
        system("cls");

        if(op==1){
            printf("Mensagem >>");
            fflush(stdin);
            scanf("%[^\n]", mensagem);
            system("cls");
            enviaMensagem(mensagem, cod_sala_escolhida);
        }
        else if(op==2){

            telaDeMensagens(cod_sala_escolhida);
            printf("----------------------------------\n");

        }
        else{
            return;
        }

    }while(op);

}
