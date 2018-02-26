#include "conexao.h"
#include "view.h"

#define TAM_QUERY 2000


void criaTabelaChat(){
     if(mysql_query(&conexao, "CREATE TABLE IF NOT EXISTS chat(USUARIO VARCHAR(40), MENSAGEM TEXT, DATAENVIO TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP)")==0){
        info(1);
     }
     else erro(1);

}
//mysql_real_connect(&conexao, "endereço", "usuário", "senha", "banco de dados", 0, NULL, 0)
void criaSalaChat(){
    char host[50], usuario[50], senha[50], banco[50];
    printf("Insira o endereco do host: ");
    scanf("%s", host);

    printf("Usuario do Banco: ");
    scanf("%s", usuario);

    printf("Senha: ");
    scanf("%s", senha);

    printf("Base de Dados: ");
    scanf("%s", banco);
    conecta(host, usuario, senha, banco);
    criaTabelaChat();
}

int conecta(char * host, char * usuario, char * senha, char * banco){
    //mysql_real_connect(&conexao, "sql3.freemysqlhosting.net", "sql3222753", "XNAw3Payd3", "sql3222753", 0, NULL, 0)


    mysql_init(&conexao);
    if (  mysql_real_connect(&conexao, host, usuario, senha, banco, 0, NULL, 0))
    {
       info(2);
    }
    else
    {
        erro(2);
        printf("Erro %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));
        system("PAUSE");
        return(0);
    }
return 1;

}

void enviaMensagem(char * mensagem, int cod_sala_escolhida){

    char query[TAM_QUERY];
    sprintf(query,"insert into chat(usuario, mensagem, cod_sala) values('%s', '%s', '%d')", usuario, mensagem, cod_sala_escolhida);
    if (mysql_query(&conexao, query)) {
      erro(3);
    }
    else{
        info(3);
    }
}

void telaDeMensagens(int cod_sala_escolhida){
    MYSQL_RES * res;
    MYSQL_ROW * row;

    char query[TAM_QUERY];
    sprintf(query, "select usuario, mensagem, dataenvio from sql3222753.chat where cod_sala = %d", cod_sala_escolhida);

    mysql_query(&conexao, query);
    res = mysql_store_result(&conexao);

    nomeSala(cod_sala_escolhida);

    while( row = mysql_fetch_row(res) )
    {
        printf("%s | %s >> %s\n", row[2], row[0], row[1] );

    }

    /*
    strcpy(data, row[2]);
    printf("\n\n---%s\n\n", data);
    */
}

void nomeSala(int cod_sala_escolhida){
    MYSQL_RES * res;
    MYSQL_ROW * row;

    char query[TAM_QUERY];
    sprintf(query, "select nome from sql3222753.sala where codsala = %d", cod_sala_escolhida);

    mysql_query(&conexao, query);
    res = mysql_store_result(&conexao);

    while( row = mysql_fetch_row(res) )
    {
        printf("Sala: %s\n\n", row[0]);

    }
}

void mostrarSalas(){

    MYSQL_RES * res;
    MYSQL_ROW * row;

    char query[TAM_QUERY];
    sprintf(query, "select codsala, nome from sql3222753.sala");

    mysql_query(&conexao, query);
    res = mysql_store_result(&conexao);

    printf("Codigo\t|\tSala\n");
    while( row = mysql_fetch_row(res) )
    {
        printf("%s\t|\t%s\n", row[0], row[1]);

    }

    printf("Pressione uma tecla para sair");
    getch();

}





















