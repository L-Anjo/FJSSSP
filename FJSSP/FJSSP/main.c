/**
*  @file main.c
 * @author Anjo
 * @date 2022
 * @brief Árvore Binária Genérica e Lista Ligada Simples
 *
 * Metodos para manipular uma Árvore de Jobs e Lista de Operações
 * @bug No known bugs.
*/


#include "Arvore.h"



int main() {

	ListaOperacoes* aux = NULL;
	Maquinaa* c1 = NULL;
	Maquinaa* c2 = NULL;
	Maquinaa* c3 = NULL;
	ListaMaquinaa* auxx = NULL;
	Node* Jobb = NULL;
	int x = 12;
	int y = 0;
	int z = 5;
	

	c1 = CriaMaquina(1,5,"Cortar");
	c3 = CriaMaquina(3, 3, "Pintar");
	c2 = CriaMaquina(2,3, "Pintar");
	auxx = InsereMaquinaListaMaquinas(auxx,c2);
	auxx = InsereMaquinaListaMaquinas(auxx,c1);
	auxx = OrdenaLista(auxx);
	/*listar3(auxx);*/

	//auxx = GetAllMaquinas("Maquinas.dat");
	//listar3(auxx);

	ListaOperacoes* inicio1 = CriaOperacao(3);
	ListaOperacoes* inicio2 = CriaOperacao(1);
	ListaOperacoes* inicio4 = CriaOperacao(4);
	inicio4 = InsereMaquinaOperacao(inicio4, c1, 4);
	ListaOperacoes* inicio3 = CriaOperacao(2);

	aux = InsereOperacaoInicio(aux, inicio2);
	aux = InsereOperacaoInicio(aux, inicio3);
	aux = InsereOperacaoInicio(aux, inicio1);
	ListaOperacoes* auxxx = NULL;
	auxxx = InsereOperacaoInicio(auxxx, inicio2);

	aux = OrdenaListaO(aux);
 
	aux = InsereMaquinaOperacao(aux, c3, 1);//Insere Maquina na Operação
	aux = InsereMaquinaOperacao(aux, c1,1);
	aux = InsereMaquinaOperacao(aux,c2,2);
	aux = InsereMaquinaOperacao(aux,c1,3);
	
	aux = AlteraOperacao(aux,3,100);
	aux = ApagaOperacao(aux,100);
	MostraTodasOperacoes(aux); //Lista Operações e mostra as máquinas
	printf("---------------------------------------\n");

	
	Jobb = AdicionaNode(Jobb, 10);
	Jobb = AdicionaNode(Jobb, 1);
	/*Jobb = AdicionaOper(Job, aux, &x);*/
	/*Jobb = AdicionaOper(Job, aux, &x);*/
	Jobb = AdicionaOper(Jobb, inicio4, 10);
	Jobb = AdicionaOper(Jobb, aux, 1);
	Jobb = InsereMaqOpeJob(Jobb,auxxx,c1,2,15); //Insere Maquina e sua Operacao na Job se não existir cria

	MostraOpeJob(Jobb, 1);
	/*MostraTodasJobs(Jobb);*/
	
	//MostraTodasOperacoes(aux); //Lista Operações e mostra as máquinas
	//MostraMaquinasOperacoes(aux,2); // Mostra Maquinas só da Operação 1


	Node* historico2 = NULL;
	
	printf("---MOSTRA JOB GUARDADA EM FICHEIRO ---\n");
	SaveJobs(Jobb, "tree.dat");
	historico2 = GetAll("tree.dat");
	printf("---------------------------------------\n");
	historico2 = DeleteNode(historico2,10);
	RemoveOperacaoJob(historico2, 15, 2);
	//MostraOpeJob(historico2, 1); //Mostra Operacoes de uma job
	MostraTodasJobsOperacoes(historico2);
	Node* teste = NULL;
	int min = CalculaMin(historico2,1);
	printf("Tempo Minimo para Completar Job: %i\n", min);
	//int max = CalculaMax(historico2,1);
	//printf("Tempo Maximo para Completar Job: %i\n", max);
	//float med = CalculaMed(historico2,1);
	//printf("Tempo Medio para Completar Job: %.2f\n", med);
	SaveJobss(historico2, "Plano.csv"); //GUARDA ARVORE EM TXT 
	Node* plann = CarregarDadosFicheiro("Plano.csv"); //CARREGA ARVORE EM TXT

	PlanoJob plano[M][T];
	IniciaPlano(plano,-1,-1);
	Ocupa(plano, 1, 1, 1,6);
	Ocupa(plano, 2, 2, 2, 6);
	Ocupa(plano, 2, 1, 2, 6);

	OcupaPlano(historico2);
	int testeee =0;
	}