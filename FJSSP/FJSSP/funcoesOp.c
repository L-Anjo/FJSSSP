/**
*  @file funcoesOp.c
 * @author Anjo
 * @date 2022
 * @brief Lista Ligadas Simples (vers�o 1)
 *
 * Metodos para manipular uma Lista Ligada de Opera��es
 * @bug No known bugs.
*/

#include "listas.h"
#include <stdio.h>

#pragma region Criar
/**
 * @brief Aloca mem�ria para armazenar a Operacao
 *
 * @param cod - CodOperacao
 */
ListaOperacoes* CriaOperacao(int cod) {
	ListaOperacoes* aux = (ListaOperacoes*)malloc(sizeof(ListaOperacoes));
	if (aux == NULL) return NULL;
	aux->cod = cod;
	aux->maquinas = NULL;
	aux->proximo = NULL;
	return aux;
}
#pragma	endregion

#pragma region InsereLista

/**
 * @brief Insere na lista uma operacao
 *
 * @param ListaOperacoes - Lista de Opera��es Existentes
 * @param ListaOperacoes - Nova Opera��o
 */
ListaOperacoes* InsereOperacaoInicio(ListaOperacoes* h, ListaOperacoes* novo) {
	if (novo == NULL) return h;	//Verificar se apontadores s�o v�lidos
	/*ListaOperacoes* nova = CriaNodoListaOperacoes(novo);*/
	if (h == novo) return h;
	if (h == NULL) h = novo;
	else
	{
		novo->proximo = h;	//aponta para onde "h" est� a apontar
		h = novo;
	}
	return h;
}

/**
 * @brief Insere uma lista de Opera��es Ordenada
 *
 * @param ListaOperacoes - Lista de Opera��es Existentes
 * @param ListaOperacoes - Nova Opera��o
 */
ListaOperacoes* InsereOperacaoOrdenada(ListaOperacoes* h, ListaOperacoes* novo) {
	if (novo == NULL) return h;
	/*ListaOperacoes* nova = CriaNodoListaOperacoes(novo);*/
	if (h == NULL) h = novo;
	else
	{
		ListaOperacoes* aux = h;
		ListaOperacoes* auxAnt = NULL;
		while (aux && aux->cod < novo->cod) {
			auxAnt = aux;
			aux = aux->proximo;
		}
		if (auxAnt == NULL) {	//Insere no meio
			novo->proximo = h;
			h = novo;
		}
		else
		{
			auxAnt->proximo = novo;	//Insere no fim
			novo->proximo = aux;
		}
	}
	return h;
}


/**
 * @brief Ordena a lista
 *
 * @param ListaOperacoes - Lista de Opera��es que vai Ordenar
 */
ListaOperacoes* OrdenaListaO(ListaOperacoes* h) {
	if (h == NULL) return NULL;
	ListaOperacoes* listaOrdenada = NULL;
	ListaOperacoes* aux = h;
	ListaOperacoes* novo;
	while (aux) {
		novo = CriaOperacao(aux->cod);
		listaOrdenada = InsereOperacaoOrdenada(listaOrdenada, novo);
		aux = aux->proximo;
	}
	return listaOrdenada;
}


/**
 * @brief Insere Maquinas na lista Operacao
 *
 * @param ListaOperacoes - Aponta Inicio da Lista
 * @param Maquinaa - Maquina que ser� introduzida
 * @param nc - C�digo da opera��o onde ir� ser inserida a m�quina
 */
ListaOperacoes* InsereMaquinaOperacao(ListaOperacoes* h, Maquinaa* c, int nc) {
	if (h == NULL) return NULL;	// se lista vazia
	if (c == NULL) return h;	//se maquina n�o tem informa��o

	ListaOperacoes* aux = ProcuraOperacao(h, nc);
	if (aux) {		//se existe essa Operacao
		aux->maquinas = InsereMaquinaListaMaquinas(aux->maquinas, c);
	}
	return h;
}

/**
 * @brief Insere Maquinas na lista Operacao de Forma Ordenada
 *
 * @param ListaOperacoes - Aponta Inicio da Lista
 * @param Maquinaa - Maquina que ser� introduzida
 * @param nc - C�digo da opera��o onde ir� ser inserida a m�quina
 */
ListaOperacoes* InsereMaquinaOperacaoOrd(ListaOperacoes* h, Maquinaa* c, int nc) {
	if (h == NULL) return NULL;	// se lista vazia
	if (c == NULL) return h;	//se maquina n�o tem informa��o

	ListaOperacoes* aux = ProcuraOperacao(h, nc);
	if (aux) {		//se existe essa Operacao
		aux->maquinas = InsereMaquinaListaMaquinasOrd(aux->maquinas, c);
	}
	return h;
}

#pragma endregion


#pragma region Procurar
/**
 * @brief Procura Opera��o pelo seu c�digo
 *
 * @param ListaOperacoes - Lista Opera��es
 * @param nc - Cod Opera��o
 */
ListaOperacoes* ProcuraOperacao(ListaOperacoes* inicio, int nc) {
	ListaOperacoes* aux = inicio;
	while (aux) {
		if (aux->cod == nc) return aux;	//se encontrou
		aux = aux->proximo;
	}
	return NULL;			//se n�o encontrou
}
#pragma endregion

#pragma region Mostrar
/**
 * @brief Mostra Todas as Opera��es Existentes com as suas M�quinas
 *
 * @param ListaOpera��es - Lista Opera��es
 */
void MostraTodasOperacoes(ListaOperacoes* h) {
	ListaOperacoes* aux = h;
	if (h == NULL) return NULL;
		while (aux) {
		printf("OPERACAO N: %d\n", aux->cod);
		listar3(aux->maquinas);
		aux = aux->proximo;
	}
}


/**
 * @brief Mostra Maquinas inseridas numa s� Opera��o
 *
 * @param ListaOperacoes - Lista Opera��es
 * @param nc - Cod da Opera��o que ir� ser mostrada
 */
void MostraMaquinasOperacoes(ListaOperacoes* inicio, int nc) {
	ListaOperacoes* aux = inicio;
	aux = ProcuraOperacao(inicio, nc);
	if (aux) {
		ListaOperacoes* maq = aux->maquinas;
		printf("OPERACAO ENCONTRADA CODIGO: %d\n", aux->cod);
		listar3(maq);
	}
}
#pragma endregion

#pragma region Remover

/**
 * @brief Remove Opera��o. C�digo indexado pelo seu c�digo (cod)
 * 
 * @param ListaOperacoes - Lista Opera��es
 * @param cod - Cod Opera��o que ser� Apagada
 */
ListaOperacoes* ApagaOperacao(ListaOperacoes* h, int cod) {
	if (h == NULL) return NULL;			//Lista vazia

	if (h->cod == cod) {		//remove no inicio da lista
		ListaOperacoes* aux = h;
		h = h->proximo;
		free(aux);
	}
	else
	{
		ListaOperacoes* aux = h;
		ListaOperacoes* auxAnt = aux;
		while (aux && aux->cod != cod) {	//procura para remover
			auxAnt = aux;
			aux = aux->proximo;
		}
		if (aux != NULL) {					//se encontrou, remove
			auxAnt->proximo = aux->proximo;
			free(aux);
		}
	}
	return h;
}
#pragma endregion

#pragma region Alterar

/**
 * @brief Altera codigo Operacao
 *
 * @param ListaOperacoes - Lista Opera��es
 * @param cod - CodOperacao
 * @param novocod - Novo C�digo de Opera��o
 */
ListaOperacoes* AlteraOperacao(ListaOperacoes* h, int cod, char novocod) {
	ListaOperacoes* aux = ProcuraOperacao(h, cod);
	if (aux != NULL)		//se encontrou operacao
	{
		aux->cod = novocod;
	}
	return h;
}


#pragma endregion 


//Destroi toda a lista
void DestroiLista(ListaOperacoes** h) {
	if (h != NULL) {
		ListaOperacoes* aux;
		while (*h) {
			aux = *h;
			*h = (*h)->proximo;
			free(aux);
		}
	}
}
#pragma endregion

#pragma region CalculaTempo_O
/**
 * @brief Percorre a Lista e Encontra a maquina que demora menos tempo
 *
 * @param ListaMaquinaa - Lista Maquinas
 */ 
int CalculaMinimoOper_T(ListaMaquinaa* h) {
	ListaMaquinaa* aux = h;
	int min;
	if (h == NULL) return(NULL);
	else {
		min = h->maquinaa.tempo;
		while (aux != NULL) {
			//Se o Valor da Lista for menor que o min
			//Entao vai repor com o valor mais pequeno  
			if (min > aux->maquinaa.tempo) {
				min = aux->maquinaa.tempo;
			}
			aux = aux->prox;
		}
		//printf("Valor Minimo na Operacao: % d\n", min);     Valor Minimo em Cada Operacao
	}	
	return min;
}


/**
 * @brief Percorre a Lista e Encontra a maquina que demora mais tempo 
 *
 * @param ListaMaquinaa - Lista Maquinas
 */
int CalculaMaximoOper_T(ListaMaquinaa* h) {
	ListaMaquinaa* aux = h;
	int max;
	if (h == NULL) return(NULL);
	else {
		max = h->maquinaa.tempo;
		while (aux != NULL) {
			//Se o Valor da Lista for maior que o max
			//Entao vai repor com o valor mais pequeno  
			if (max < aux->maquinaa.tempo) {
				max = aux->maquinaa.tempo;
			}
			aux = aux->prox;
		}
		//printf("Valor M�ximo da Operacao: %d\n", max);
	}
	return max;
}


/**
 * @brief Percorre a Lista e Faz a M�dia de tempo de todas as maquinas 
 *
 * @param ListaMaquinaa - Lista Maquinas
 */
float CalculaMediaOper_T(ListaMaquinaa* h) {
	ListaMaquinaa* aux = h;
	int media = 0;
	int cont = 0;
	if (h == NULL) return(0);
	else {
		while (aux != NULL) {
			media += aux->maquinaa.tempo;
			cont++;
			aux = aux->prox;
			}
		media = media / cont;
			/*aux = aux->prox;*/
		
		/*printf("Valor Medio na Operacao: % f\n", media);*/     //Valor M�dio em Cada Operacao
	}
	return media;
}

#pragma endregion

