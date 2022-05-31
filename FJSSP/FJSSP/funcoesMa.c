/**
*  @file funcoesMa.c
 * @author Anjo
 * @date 2022
 * @brief Lista Ligadas Simples (versão 1)
 *
 * Metodos para manipular uma Lista Ligada de Maquinas
 * @bug No known bugs.
*/

#include "listas.h"
#include <stdio.h>

#pragma region Criar
//Cria Maquina
/**
 * @brief Aloca memória para armazenar a Máquina
 *
 * @param codm - CodMaquina
 * @param tempo - Unidades Tempo máquina
 * @param tipo - Tipo de Máquina
 */
Maquinaa* CriaMaquina(int codm, int tempo, char* tipo) {
	Maquinaa* aux = (Maquinaa*)malloc(sizeof(Maquinaa));
	if (aux == NULL) return NULL;
	aux->codm = codm;
	aux->tempo = tempo;
	strcpy(aux->tipo, tipo);
	return aux;
}

#pragma endregion

#pragma region InsereLista
/**
 * @brief Aloca memória para armazenar Nodo de Máquinas
 *
 * @param Maquinaa - Maquina
 */
ListaMaquinaa* CriaNodoListaMaquinas(Maquinaa* c) {
	ListaMaquinaa* novo = (ListaMaquinaa*)malloc(sizeof(ListaMaquinaa));
	novo->maquinaa.codm = c->codm;
	novo->maquinaa.tempo = c->tempo;
	strcpy(novo->maquinaa.tipo, c->tipo);
	novo->prox = NULL;
	return novo;
}

/**
 * @brief Insere uma nova maquina na lista
 *
 * @param ListaMaquinaa - Lista Maquinas
 * @param Maquinaa - Maquina que será introduzida
 */
ListaMaquinaa* InsereMaquinaListaMaquinas(ListaMaquinaa* h, Maquinaa* novaM) {
	if (novaM == NULL)	return h;	//se novo está vazio
	//Cria novo nodo para lista de maquinas
	ListaMaquinaa* novo = CriaNodoListaMaquinas(novaM);
	if (h == NULL) h = novo;		//se lista está vazia
	else {
		//Assumir que se insere sempre no inicio
		novo->prox = h;
		h = novo;
	}
	return h;
}

/**
 * @brief Insere Lista Maquinas Ordenadas
 *
 * @param ListaMaquinaa - Lista Maquinas
 * @param Maquinaa - Maquina que será introduzida
 */
ListaMaquinaa* InsereMaquinaListaMaquinasOrd(ListaMaquinaa* h, Maquinaa* novaM) {
	if (novaM == NULL)	return h;	//se novo está vazio
	ListaMaquinaa* novo = CriaNodoListaMaquinas(novaM);

	if (h == NULL) h = novo;		//se lista está vazia
	else {
		ListaMaquinaa* aux = h;
		ListaMaquinaa* auxAnt = NULL;
		while (aux && aux->maquinaa.codm < novo->maquinaa.codm) {
			auxAnt = aux;
			aux = aux->prox;
		}
		if (auxAnt == NULL) {	//Insere no meio
			novo->prox = h;
			h = novo;
		}
		else
		{
			auxAnt->prox = novo;	//Insere no fim
			novo->prox = aux;
		}
	}
	return h;
}


/**
 * @brief Ordena a lista
 *
 * @param ListaMaquinaa - Lista Maquinas
 */
ListaMaquinaa* OrdenaLista(ListaMaquinaa* h) {
	if (h == NULL) return NULL;
	ListaMaquinaa* listaOrdenada = NULL;
	ListaMaquinaa* aux = h;
	ListaMaquinaa* novo;
	while (aux) {
		novo = CriaMaquina(aux->maquinaa.codm, aux->maquinaa.tempo, aux->maquinaa.tipo);
		listaOrdenada = InsereMaquinaListaMaquinasOrd(listaOrdenada, novo);
		aux = aux->prox;
	}
	return listaOrdenada;
}

#pragma endregion

#pragma region Procura
/**
 * @brief Procura Maquina pelo seu código
 *
 * @param ListaMaquinaa - Lista Maquinas
 * @param nc - Cod Maquina
 */
ListaMaquinaa* ProcuraMaquina(ListaMaquinaa* inicio, int nc) {
	ListaMaquinaa* aux = inicio;
	while (aux) {
		if (aux->maquinaa.codm == nc) return aux;	//se encontrou
		aux = aux->prox;
	}
	return NULL;			//se não encontrou
}
#pragma endregion

#pragma region Mostrar
/**
 * @brief Lista na Consola Todas as Máquinas
 *
 * @param ListaMaquinaa - Lista Maquinas
 */
void listar3(ListaMaquinaa* inicio)
{
	ListaMaquinaa* aux = inicio;
	if (inicio == NULL) return NULL;
	printf("MAQUINAS:\n");
	while (aux) {
		printf("CODM:%d\n", aux->maquinaa.codm);
		printf("Tempo= %d\n", aux->maquinaa.tempo);
		printf("Tipo= %s\n", aux->maquinaa.tipo);
		/*printf("Prox= %p\n", aux->prox);*/
		printf("\n");
		aux = aux->prox;
	}
	}

#pragma endregion
