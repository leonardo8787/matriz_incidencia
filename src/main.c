#include "graph_bfs_dfs.h"

int main(){

	int op;

	system("clear");
	printf("\n===========GRAFO============\n");
	printf("Centro Federal de Educação Tecnológica de Minas Gerais\n");
	printf("Engenharia de Computação\n");
	printf("Leonardo Campos\n");
	printf("\n\n\n");
	printf("Matriz de Incidência\n");

	FILE *file1, *file2, *file3;
	Graph G = GraphInitialize(10);
	Vertex v1, v2;
	v1 = (Vertex)malloc(sizeof(Vertex));
	v2 = (Vertex)malloc(sizeof(Vertex));
	char line[100];
	char *tok;
	char limite[] = ",\n";
	clock_t t;

	file1 = fopen("src/pequeno.txt", "r");
	file2 = fopen("src/medio.txt","r");
	file3 = fopen("src/grande.txt","r");

	//GraphInsertEdge(G, G->adj[0][1], G->adj[0][2]);
	//GraphInsertEdge(G, G->adj[1][0], G->adj[1][4]);
	//GraphInsertEdge(G, G->adj[1][2], G->adj[2][2]);
	//GraphInsertEdge(G, G->adj[2][3], G->adj[2][4]);
	//GraphInsertEdge(G, G->adj[2][5], G->adj[4][3]);
	//GraphInsertEdge(G, G->adj[3][6], G->adj[4][6]);
	//GraphInsertEdge(G, G->adj[5][7], G->adj[5][8]);
	//GraphInsertEdge(G, G->adj[5][2], G->adj[5][1]);
	//GraphInsertEdge(G, G->adj[8][3], G->adj[6][9]);
	//GraphInsertEdge(G, G->adj[9][3], G->adj[9][3]);

	do{
		printf("\nInserções realizadas, escolha uma opção: \n");
		printf("0 - sair\n");
		printf("1 - inserção - pequena\n");
		printf("2 - inserção - média\n");
		printf("3 - inserção - grande\n");
		printf("4 - Ligações do grafo\n");
		printf("5 - Busca em Largura\n");
		printf("6 - Busca em profundidade\n");
		printf("7 - limpar a tela\n");
		scanf("%d", &op);

		switch(op){
			case 0: 
				return 0;
			case 1:
				if (file1 == NULL) {
					printf("Erro ao abrir o arquivo!\n");
					return 0;
				}
				printf("Inserindo elementos...\n");
				t=clock();
				while ((fgets(line, 100, file1)) != NULL) {
					tok = strtok(line, limite);
					int numero = atoi(tok);
					v1->value = numero;
					while ((tok = strtok(NULL, limite)) != NULL) {
					v2->value = atoi(tok);
					GraphInsertEdge(G, v1, v2);
					}
				}
				t=clock() - t;
				printf("Tempo de execucao: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
				break;
			case 2:
				if (file2 == NULL) {
					printf("Erro ao abrir o arquivo!\n");
					return 0;
				}
				printf("Inserindo elementos...\n");
				t=clock();
				while ((fgets(line, 100, file2)) != NULL) {
					tok = strtok(line, limite);
					int numero = atoi(tok);
					v1->value = numero;
					while ((tok = strtok(NULL, limite)) != NULL) {
					v2->value = atoi(tok);
					GraphInsertEdge(G, v1, v2);
					}
				}
				t=clock() - t;
				printf("Tempo de execucao: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
				break;
			case 3:
				if (file3 == NULL) {
					printf("Erro ao abrir o arquivo!\n");
					return 0;
				}
				printf("Inserindo elementos...\n");
				t=clock();
				while ((fgets(line, 100, file3)) != NULL) {
					tok = strtok(line, limite);
					int numero = atoi(tok);
					v1->value = numero;
					while ((tok = strtok(NULL, limite)) != NULL) {
					v2->value = atoi(tok);
					GraphInsertEdge(G, v1, v2);
					}
				}
				t=clock() - t;
				printf("Tempo de execucao: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
				break;
			case 4:
				printf("\n========Ligações=======\n");
				t=clock();
				ImprimeGraph(G);
				t=clock() - t;
				printf("Tempo de execucao: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
				break;
			case 5:
				printf("\nBFS(Busca em largura)===========\n");
				t=clock();
				BFS(G, v1);
				t=clock() - t;
				printf("Tempo de execucao: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
				break;
			case 6:
				printf("\nDFS(Busca em profundidade)======\n");
				t=clock();
				DFS(G);
				t=clock() - t;
				printf("Tempo de execucao: %lf\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
			case 7:
				system("clean");
				break;
			default:
				printf("Digite um valor válido!");	
		}
	}while(op != 0);

	fclose(file1);
	fclose(file2);
	fclose(file3);
}