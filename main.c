#include <stdio.h>
#include <string.h>
#include "Pesquisa.h"

int main(int argc, char *argv[]) {

    TipoTabela tabelaDeAlunos;
    TipoChave chaveDePesquisa;
    TipoIndice indice;

    Inicializa(&tabelaDeAlunos);

    TipoRegistro a1, a2, a3, a4, a5, a6;

    a1.Chave = 10; a1.Idade = 32; strcpy(a1.Nome, "Maria");
    Insere(a1, &tabelaDeAlunos);

    a2.Chave = 31; a2.Idade = 21; strcpy(a2.Nome, "Pedro");
    Insere(a2, &tabelaDeAlunos);

    a3.Chave = 8; a3.Idade = 15; strcpy(a3.Nome, "Samara");
    Insere(a3, &tabelaDeAlunos);

    a6.Chave = 10; a6.Idade = 32; strcpy(a6.Nome, "Maria");
    Insere(a6, &tabelaDeAlunos);

    a4.Chave = 15; a4.Idade = 41; strcpy(a4.Nome, "Joao");
    Insere(a4, &tabelaDeAlunos);

    a5.Chave = 4; a5.Idade = 27; strcpy(a5.Nome, "Carla");
    Insere(a5, &tabelaDeAlunos);


    insertionSort(&tabelaDeAlunos);
    ListaTabela(&tabelaDeAlunos);
//
//    TipoRegistro tipoRegistro = PesquisaSequencialPorPosicao(1, &tabelaDeAlunos);
//    printf("\n------------------------------------\n");
//    printf("Registro Encontrado Por Pesquisa Sequencial Por Posição:\n");
//    printf("Chave: %d\nNome: %s\nIdade: %d", tipoRegistro.Chave, tipoRegistro.Nome, tipoRegistro.Idade);
//    printf("\n------------------------------------\n");
//
//    TipoTabela tabelaDeAlunosNovas = RetirarItemPesquisaSequencial(10, &tabelaDeAlunos);
//    Inicializa(&tabelaDeAlunos);
//    tabelaDeAlunos = tabelaDeAlunosNovas;
//    ListaTabela(&tabelaDeAlunos);
//
//    printf("\n------------------------------------\n");
//    printf("Remoção por Pesquisa Sequencial Por Posição:\n");
//    ListaTabela(&tabelaDeAlunos);
//    printf("\n------------------------------------\n");
//
//    printf("Ordem Crescente: %d\n", ordemCrescente(&tabelaDeAlunos));
//    printf("\n------------------------------------\n");


    do {

        //ListaTabela(&tabelaDeAlunos);
        printf("Digite a chave de pesquisa ou -1 para sair: ");
        scanf("%d", &chaveDePesquisa);

        if (chaveDePesquisa != -1) {
            indice = PesquisaSequencial(chaveDePesquisa, &tabelaDeAlunos);
            //indice = PesquisaBinaria(0, &tabelaDeAlunos);

            if (indice != 0) {
                printf("\n------------------------------------\n");
                printf("Registro Encontrado:\n");
                printf("Chave: %d\nNome: %s\nIdade: %d", tabelaDeAlunos.Item[indice].Chave, tabelaDeAlunos.Item[indice].Nome, tabelaDeAlunos.Item[indice].Idade);
                printf("\n------------------------------------\n");
            } else {
                printf("\n---------------------------------------------------------\n");
                printf("Nao foi encontrado nenhum registro com a chave informada.");
                printf("\n---------------------------------------------------------\n");
            }
            getchar(); getchar();
        }
    } while (chaveDePesquisa != -1);

    return 0;
}

