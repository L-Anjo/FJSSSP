/**
 * @file �rvore.h
 * @author Anjo
 * @date 2022
 * @brief Defini��es Globais para �rvore Bin�ria Gen�rica
 *
 * Structs, Constantes e Assinaturas de Fun��es para �rvore Bin�ria
*/
#include <stdio.h>
#include <stdbool.h>
#include "listas.h"
#include  <locale.h>

#pragma warning( disable : 4996 ) //evita MSG ERROS: _CRT_SECURE_NO_WARNINGS
#define M 8		//N�mero de M�quinas
#define T 10	//N�mero de Tempos
#define MAX 100
#pragma once 

/**
 * @brief Dados Node �rvore
 */
typedef struct Data{
	int dados; /**< C�digo do Nodo da �rvore*/
	struct ListaOperacoes* oper; /**< Liga��o �s Opera��es */
}Data;

/**
 * @brief �rvore
 */
typedef struct Node {
	Data data; /**< Dados da �rvore*/
	struct Node* direito; /**< Liga��o lado direto da �rvore*/
	struct Node* esquerdo; /**< Liga��o lado esquerdo da �rvore*/
}Node, *PtrNode;

/**
 * @brief Estrutura Auxiliar para preservar dados em ficheiro
 */
typedef struct Job {
	int cod; /**< C�digo da Job*/
	int op; /**< C�digo da Opera��o*/
	int codm; /**< C�digo da Maquina*/
	char tipoM[N]; /**< Tipo de Maquina*/
	int tempo; /**< Tempo da M�quina */
}Job;

/**
 * @brief Estrutura para o Planeamento
 */
typedef struct PlanoJob {
	int codj;
	int codo;
}PlanoJob;


/**
 * @brief Prot�tipos
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