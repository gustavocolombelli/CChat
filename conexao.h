#ifndef CONEXAO_H   // guardas de cabeçalho, impedem inclusões cíclicas
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
    int conecta(char * host, char * usuario, char * senha, char * banco);
    void enviaMensagem(char * mensagem, int cod_sala_escolhida);
    void mostrarSalas();
    void telaDeMensagens(int cod_sala_escolhida);
    void nomeSala(int cod_sala_escolhida);
#endif
