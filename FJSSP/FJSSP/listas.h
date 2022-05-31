/**
 * @file listas.h
 * @author Anjo
 * @date 2022
 * @brief Definições Globais para Lista Ligadas Simples (versão 1)
 *
 * Structs, Constantes e Assinaturas de Funções  Listas Ligadas Simples
*/
#include <stdlib.h>
#include <stdbool.h>


#pragma warning( disable : 4996 ) //evita MSG ERROS: _CRT_SECURE_NO_WARNINGS

#pragma once 
#define N 25

/**
 * @brief Informações de uma Máquina
 */
typedef struct Maquinaa{
	int codm; /**< Código da Maquina*/
	int tempo; 	/**< Unidades de Tempo da maquina*/
	char tipo[N];/**< Tipo de trabalhos executados pela maquina */
}Maquinaa;

/**
 * @brief Informações da Lista de Maquinas
 */
typedef struct ListaMaquinaa{
	struct Maquinaa maquinaa;
	struct ListaMaquinaa* prox; /**< Ligação a outra maquina*/
}ListaMaquinaa;


/**
 * @brief Informações de uma Lista de Operações
 */
typedef struct ListaOperacoes {
	int cod;	/**< Cod da Operação*/
	struct ListaMaquinaa* maquinas;	/**< Todas as Maquinas*/
	struct ListaOperacoes* proximo;	/**< Ligação a outra Operação*/
}ListaOperacoes;



/**
 * @brief Protótipos
 */
ListaOperacoes* CriaOperacao(int cod);
ListaOperacoes* CriaNodoListaOperacoes(ListaOperacoes* c);
void MostraTodasOperacoes(ListaOperacoes* h);
ListaOperacoes* InsereOperacaoInicio(ListaOperacoes* h, ListaOperacoes* novo);
ListaOperacoes* InsereOperacaoOrdenada(ListaOperacoes* h, ListaOperacoes* novo);
ListaOperacoes* ProcuraOperacao(ListaOperacoes* inicio, int nc);
void MostraMaquinasOperacoes(ListaOperacoes* inicio, int nc);
ListaOperacoes* ApagaOperacao(ListaOperacoes* h, int cod);
ListaOperacoes* AlteraOperacao(ListaOperacoes* h, int cod, char novocod);
void DestroiLista(ListaOperacoes** h);
ListaOperacoes* OrdenaListaO(ListaOperacoes* h);


ListaOperacoes* InsereMaquinaOperacao(ListaOperacoes* h, Maquinaa* c, int nc);
Maquinaa* CriaMaquina(int codm, int tempo, char* tipo);
ListaMaquinaa* CriaNodoListaMaquinas(Maquinaa* c);
ListaMaquinaa* InsereMaquinaListaMaquinas(ListaMaquinaa* h, Maquinaa* novoContacto);
void listar3(ListaMaquinaa* inicio);
ListaMaquinaa* ProcuraMaquina(ListaMaquinaa* inicio, int nc);
int CalculaMinimoOper_T(ListaMaquinaa* h);
int CalculaMaximoOper_T(ListaMaquinaa* h);
float CalculaMediaOper_T(ListaMaquinaa* h);
ListaMaquinaa* InsereMaquinaListaMaquinasOrd(ListaMaquinaa* h, Maquinaa* novaM);
ListaMaquinaa* OrdenaLista(ListaMaquinaa* h);
ListaOperacoes* InsereMaquinaOperacaoOrd(ListaOperacoes* h, Maquinaa* c, int nc);