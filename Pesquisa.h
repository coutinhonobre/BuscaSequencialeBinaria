//
// Created by Igor Coutinho Ferreira Nobre on 04/07/21.
//
#include <stdio.h>
#include <string.h>

#define MAXN 100

typedef int TipoChave;
typedef int TipoIndice;

typedef struct {
    TipoChave Chave;
    char Nome[10];
    int Idade;
} TipoRegistro;

typedef struct {
    TipoRegistro Item[MAXN + 1];
    TipoIndice n;
} TipoTabela;

void Inicializa (TipoTabela *T);
void insertionSort(TipoTabela *T);
int ordemCrescente(TipoTabela *T);
TipoIndice PesquisaSequencial(TipoChave x , TipoTabela *T);
void Insere(TipoRegistro Reg, TipoTabela *T);
TipoRegistro PesquisaSequencialPorPosicao(int indice, TipoTabela *T);
TipoTabela RetirarItemPesquisaSequencial(TipoChave x , TipoTabela *T);
TipoIndice PesquisaBinaria(TipoChave x , TipoTabela *T);
void ListaTabela(TipoTabela *T);
