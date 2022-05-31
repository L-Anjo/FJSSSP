/**
 * @file Árvore.h
 * @author Anjo
 * @date 2022
 * @brief Definições Globais para Árvore Binária Genérica
 *
 * Structs, Constantes e Assinaturas de Funções para Árvore Binária
*/
#include <stdio.h>
#include <stdbool.h>
#include "listas.h"
#include  <locale.h>

#pragma warning( disable : 4996 ) //evita MSG ERROS: _CRT_SECURE_NO_WARNINGS
#define M 8		//Número de Máquinas
#define T 10	//Número de Tempos
#define MAX 100
#pragma once 

/**
 * @brief Dados Node Árvore
 */
typedef struct Data{
	int dados; /**< Código do Nodo da Árvore*/
	struct ListaOperacoes* oper; /**< Ligação ás Operações */
}Data;

/**
 * @brief Árvore
 */
typedef struct Node {
	Data data; /**< Dados da Árvore*/
	struct Node* direito; /**< Ligação lado direto da Árvore*/
	struct Node* esquerdo; /**< Ligação lado esquerdo da Árvore*/
}Node, *PtrNode;

/**
 * @brief Estrutura Auxiliar para preservar dados em ficheiro
 */
typedef struct Job {
	int cod; /**< Código da Job*/
	int op; /**< Código da Operação*/
	int codm; /**< Código da Maquina*/
	char tipoM[N]; /**< Tipo de Maquina*/
	int tempo; /**< Tempo da Máquina */
}Job;

/**
 * @brief Estrutura para o Planeamento
 */
typedef struct PlanoJob {
	int codj;
	int codo;
}PlanoJob;


/**
 * @brief Protótipos
 */
Node* AdicionaNode(Node* nodo, int cod);
Node* AdicionaOper(Node* d, ListaOperacoes* h, int cod);
void MostraTodasJobs(Node* root);
Node* ProcuraArvore(Node* d, int cod);
void MostraOpeJob(Node* inicio, int cod);
Node* InsereMaqOpeJob(Node* d, ListaOperacoes* oper, Maquinaa* m, int codj, int codop);
bool SaveJob(Node* j, FILE* fp);
bool SaveJobsPreOrder(Node* h, FILE* fp);
bool SaveJobs(Node* h, char* fileName);
Node* GetAll(char* fileName);
Node* NewNode(int cod);
void MostraTodasJobsOperacoes(Node* root);
Node* DeleteNode(Node* root, int cod);
Node* DeleteCurrentNode(Node* root);
void DestroyNode(Node** p);
Node* FindMin(Node* root);
Node* RemoveOperacaoJob(Node* d, int codop, int codjob);
int CalculaMin(Node* h, int cod);
float CalculaMed(Node* h, int cod);
int CalculaMax(Node* h, int cod);
void IniciaPlano(PlanoJob p[][T], int codj, int codo);
void OcupaVarios(PlanoJob p[][T], int m,int codJ, int totTempo, PlanoJob* c);
Ocupa(PlanoJob p[][T], int codJ, int codO, int m, int totTempo);
Node* OcupaPlano(Node* root);
Node* CarregarDadosFicheiro(char* fileName); //TXT
bool SaveJobss(Node* h, char* fileName);