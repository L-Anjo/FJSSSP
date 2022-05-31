/**
 * @file listas.h
 * @author Anjo
 * @date 2022
 * @brief Defini��es Globais para Lista Ligadas Simples (vers�o 1)
 *
 * Structs, Constantes e Assinaturas de Fun��es  Listas Ligadas Simples
*/
#include <stdlib.h>
#include <stdbool.h>


#pragma warning( disable : 4996 ) //evita MSG ERROS: _CRT_SECURE_NO_WARNINGS

#pragma once 
#define N 25

/**
 * @brief Informa��es de uma M�quina
 */
typedef struct Maquinaa{
	int codm; /**< C�digo da Maquina*/
	int tempo; 	/**< Unidades de Tempo da maquina*/
	char tipo[N];/**< Tipo de trabalhos executados pela maquina */
}Maquinaa;

/**
 * @brief Informa��es da Lista de Maquinas
 */
typedef struct ListaMaquinaa{
	struct Maquinaa maquinaa;
	struct ListaMaquinaa* prox; /**< Liga��o a outra maquina*/
}ListaMaquinaa;


/**
 * @brief Informa��es de uma Lista de Opera��es
 */
typedef struct ListaOperacoes {
	int cod;	/**< Cod da Opera��o*/
	struct ListaMaquinaa* maquinas;	/**< Todas as Maquinas*/
	struct ListaOperacoes* proximo;	/**< Liga��o a outra Opera��o*/
}ListaOperacoes;



/**
 * @brief Prot�tipos
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