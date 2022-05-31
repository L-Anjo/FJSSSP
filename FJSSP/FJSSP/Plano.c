/**
*  @file Plano.c
 * @author Luis Anjo
 * @date 2022
 * @brief Plano para Jobs
 *
 * Metodos para manipular um Plano com Arrays
 * @bug No known bugs.
*/

#include "Arvore.h"
#include "listas.h"

#pragma region CriaPlano
/**
 * @brief Inicia Plano
 *
 * @param p - Plano
 * @param codj - Cód Job
 * @param codo - Cód Operacao
 */
void IniciaPlano(PlanoJob p[][T], int codj, int codo) {

	for (int l = 0; l < M; l++)
		for (int col = 0; col < T; col++) {
			p[l][col].codj = codj;
			p[l][col].codo = codo;
		}
}


/**
 * @brief Ocupa várias unidades de tempo.
 *
 * @param p	- Plano
 * @param m	- Maquina
 * @param totTempo	- Tempo a ocupar
 * @param c	- Job e Operacao
 */
void OcupaVarios(PlanoJob p[][T], int m,int codJ,int totTempo, PlanoJob* c) {
	int aux = T;
	//Procurar a primeira "casa" livre
	int col = 0;
	while (p[m][col].codj != -1)
		col++;

	//Ocupa a partir da posição livre encontrada
	totTempo += col;	
	
		if(totTempo < aux)
		for (; col < totTempo; col++) {
			p[m][col].codj = c->codj;
			p[m][col].codo = c->codo;
		}
	
	//Fase 2 - Procurar quando a operação anterior

}

/**
 * @brief Ocupa
 *
 * @param cod - CodOperacao
 */
Ocupa(PlanoJob p[][T],int codJ,int codO, int m, int totTempo) {
	PlanoJob c = { .codj = codJ, .codo = codO };
	OcupaVarios(p, m,codJ, totTempo, &c);
}

/**
 * @brief Ocupa Plano através dos jobs do ficheiro
 *
 * @param Node - Árvore
 * @param root
 */
Node* OcupaPlano(Node* root) {
	PlanoJob plano[M][T];
	IniciaPlano(plano, -1, -1);
	ListaOperacoes* aux = root->data.oper;
	Job auxx;

		while (aux != NULL) {
			auxx.op = aux->cod;
			auxx.cod = root->data.dados;
			ListaMaquinaa* maquinas = aux->maquinas;
			while (maquinas) {
				auxx.codm = maquinas->maquinaa.codm;
				auxx.tempo = maquinas->maquinaa.tempo;
				maquinas = maquinas->prox;
				Ocupa(plano, auxx.cod, auxx.op, auxx.codm, auxx.tempo);
			}
			aux = aux->proximo;
		}
}

/**
 * @brief Guarda Plano de Jobs
 *
 * @param p - Plano
 * @param filename - Ficheiro
 */
bool SavePlan(char* fileName, PlanoJob p[][T]);



/**
 * @brief Carrega dados de um ficheiro CSV.
 *
 * @param fileName
 */
Node* CarregarDadosFicheiro(char* fileName) {
	FILE* fp;
	char texto[MAX];
	int a, b, c, d;

	Node* listaJobs = NULL;
	ListaOperacoes auxOper;
	Job aux;
	ListaMaquinaa auxMaq;
	Node* root = NULL;
	//char d[20];

	fp = fopen(fileName, "r");
	if (fp == NULL) return;

	while (!feof(fp)) {
		//fgets
		//fscanf()
		Node* nodo = NULL;
		
		ListaOperacoes* op = NULL;
		ListaOperacoes* mo = NULL;
		Maquinaa* m = NULL;
		ListaMaquinaa* mac = NULL;
		if (fgets(texto, MAX, fp) != NULL)
		{

			sscanf(texto, "%d;%d;%d;%d", &aux.cod, &aux.op, &aux.codm, &aux.tempo);
			printf("LIDO: %d - %d - %d - %d \n", aux.cod, aux.op, aux.codm, aux.tempo);
			
	
				root = AdicionaNode(root, aux.cod);
				op = CriaOperacao(aux.op);
				root = AdicionaOper(root, op, aux.cod);
				if (aux.op > 0) {
					m = CriaMaquina(aux.codm, aux.tempo, "");
					m = CriaNodoListaMaquinas(m);
					Node* search = ProcuraArvore(root, aux.cod);
					/*ListaOperacoes* proc = ProcuraOperacao(search->data.oper,aux.op);*/
					search->data.oper = InsereMaquinaOperacaoOrd(search->data.oper, m, aux.op);
					//CUIDADO PODE TER ALGUM ERRO INSERIR MAQUINAS ORDENADAS
				}
			}
			
		}
	
	fclose(fp);
	return root;
}


#pragma endregion

