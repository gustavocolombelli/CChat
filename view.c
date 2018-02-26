#include "view.h"

void erro(int codigoErro){

    switch ( codigoErro ){

       case 1: printf("Erro ao criar a tabela Chat");
        break;

        case 2: printf("Falha de conexao\n");
        break;

        case 3: printf("Erro ao enviar a mensagem");
        break;

        default: printf("Codigo Invalido.");
        break;
     }

}

void info(int codigoInfo){

    switch ( codigoInfo ){

        case 1: printf("Tabela Chat Criada ou ja Existe");
        break;

        case 2: printf("\nConexao ao banco realizada com sucesso!\n");
        break;

        case 3: printf("\nMensagem enviada com sucesso");
        break;

        default: erro(-1);
        break;
    }
}

void vMenuInicial(){
    printf("1 - Criar uma Sala\n");
    printf("2 - Mostrar Salas\n");
    printf("3 - Conectar a uma Sala\n");
}
