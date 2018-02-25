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
    if ( mysql_real_connect(&conexao, host, usuario, senha, banco, 0, NULL, 0) )
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

void enviaMensagem(char * mensagem){

    char query[TAM_QUERY];
     sprintf(query,"insert into chat(usuario, mensagem) values('%s', '%s')", usuario, mensagem);
    if (mysql_query(&conexao, query)) {
      erro(3);
    }
}
