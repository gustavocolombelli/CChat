#ifndef CONEXAO_H   // guardas de cabe�alho, impedem inclus�es c�clicas
#define CONEXAO_H

#include <stdio.h>
#include <windows.h>
#include <winsock2.h>
#include <mysql.h>

    MYSQL conexao;
    char usuario[40];
    //void finish_with_error(MYSQL *con);
    void criaTabelaChat();
    void criaSalaChat();
    int conecta();
    void enviaMensagem(char * mensagem);
    void telaDeMensagens();
#endif