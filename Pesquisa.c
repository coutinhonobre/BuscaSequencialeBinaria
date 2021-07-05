//
// Created by Igor Coutinho Ferreira Nobre on 04/07/21.
//

#include <printf.h>
#include "Pesquisa.h"
#include <stdio.h>
#include <string.h>

void Inicializa (TipoTabela *T) {
    T->n = 0;
}

TipoIndice PesquisaSequencial(TipoChave x , TipoTabela *T) {
    int i ;

    T->Item[0].Chave = x;
    i = T->n + 1;

    do {
        i--;
    } while (T->Item[i].Chave != x);

    return i ;
}

int * busca(TipoTabela *vet, int n, TipoChave chave, int posicoes[]) {
    int i, indice = 0;

    vet->Item[0].Chave = chave;
    i = vet->n + 1;

    while (i > 0) {
        if(vet->Item[i].Chave == chave) {
            posicoes[indice] = i;
            indice++;
            n++;
        }
        i--;
    }

    return posicoes;
}

TipoRegistro PesquisaSequencialPorPosicao(int indice, TipoTabela *T) {
    return T->Item[indice];
}

TipoTabela RetirarItemPesquisaSequencial(TipoChave x , TipoTabela *T) {

    TipoTabela tabelaDeAlunos;
    Inicializa(&tabelaDeAlunos);

    for(int i=1; i<=T->n; i++) {
        if (T->Item[i].Chave != x) {
            TipoRegistro a;
            a = T->Item[i];
            Insere(a, &tabelaDeAlunos);
        }
    }

    return tabelaDeAlunos;
}

int ordemCrescente(TipoTabela *T) {

    for (int i = 1; i <=T->n; i++)
    {
        for (int j = i + 1; j <=T->n; j++)
        {
            if (T->Item[i].Chave > T->Item[j].Chave)
            {
                return 0;
            }
        }
    }

    return 1;
}

void Insere(TipoRegistro Reg, TipoTabela *T) {
    if (T->n == MAXN)
        printf ("Erro: Tabela cheia\n");
    else {
        T->n++;
        T->Item[T->n] = Reg;
    }
}

TipoIndice PesquisaBinaria(TipoChave x , TipoTabela *T) {
    TipoIndice i , Esq, Dir ;

    if (T->n == 0)
        return 0;
    else {
        Esq = 1;
        Dir = T->n;
        do {

            i = (Esq + Dir ) / 2;

            if (x > T->Item[i].Chave)
                Esq = i + 1;
            else Dir = i - 1;

        } while (x != T->Item[i].Chave && Esq <= Dir );

        if (x == T->Item[i].Chave)
            return i ;
        else
            return 0;
    }
}

void ListaTabela(TipoTabela *T) {

    printf("\n");
    printf("%-8s %-15s %-8s\n", "CHAVE", "NOME", "IDADE");
    printf("------------------------------------\n");
    for(int i=1; i<=T->n; i++) {
        printf("%-8d %-15s %-8d\n", T->Item[i].Chave, T->Item[i].Nome, T->Item[i].Idade);
    }
    printf("------------------------------------\n\n");
}

void insertionSort(TipoTabela *T) {
    int i, j;
    TipoRegistro Key;

    for(int i=1; i<=T->n; i++) {

        Key = T->Item[i];
        j = i-1;

        while (j >= 1 && T->Item[j].Chave > Key.Chave) {
            T->Item[j+1] = T->Item[j];
            j = j-1;
        }
        T->Item[j+1] = Key;
    }
}
