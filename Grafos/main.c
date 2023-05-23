#include <stdio.h>

#define V 6
#define E 12

int get_index(char x){
	return x - 97;
}

void inicia_arestas(int arestas[V][V]){
	for(int i = 0; i < V; i++){
		for(int j = 0; j < V; j++){
			arestas[i][j] = 0;
		}
	}
}

void cria_arestas(int arestas[V][V], int v, int u){
	arestas[v][u] = 1;
}

void mostra_arestas(int arestas[V][V]){
  printf("mostra aresta\n");
	for(int i = 0; i < V; i++){
		for(int j = 0; j < V; j++){
			printf("%d ", arestas[i][j]);
		}
		printf("\n");
	}
}

void mostra_adjacentes(int arestas[V][V], char v){
  int posicao = get_index(v);
	for(int i=0; i<V; i++){
    if(arestas[posicao][i] != 0){
      printf("%c-> ", v);
      printf("%c\n", i+97);
    }
  }
  
}

void mostra_distancias(int arestas[V][V], char v){
  //posicao
	int posicao = get_index(v);
  int dist[V];
  int queue[V];
  int visited[V];
  int front=0;
  //anterior
  int rear=0;
  //preenchendo dist e visited com -1 e 0
  for(int i=0; i<V; i++){
    dist[i]=-1;
    visited[i]=0;
  }
  //insere 0 e 1 na posicao em que v está
  dist[posicao]=0;
  visited[posicao]=1;
  queue[rear++]=posicao;
  while(front<rear){
    int current = queue[front++];
    for(int i=0; i<V; i++){
      if(arestas[current][i] == 1 && !visited[i]){
        dist[i] = dist[current]+1;
        visited[i]=1;
        queue[rear++]=i;
      }
    }
  }
  for(int i=0; i<V;i++){
    printf("%d ", dist[i]);
  }
  printf("\n");
  
}

int main(void) {
  //nós
	char lista_de_vertices[V] = {'a', 'b', 'c', 'd', 'e', 'f'};
  //conexões
	char lista_de_arestas[E][2] = {"ab", "ad", "ae", "ba", "bc", "bf", "cb", "da", "ea", "ef", "fb", "fe"};
  //vetor 6x6 (matriz)
  int arestas[V][V];
  //inicializa todas as posições do vetor com zero
	inicia_arestas(arestas);

  //crias a arestas entre cada nó
	for(int i = 0; i < E; i++){
		cria_arestas(arestas, get_index(lista_de_arestas[i][0]), get_index(lista_de_arestas[i][1]));
	}
	mostra_arestas(arestas);
  
	for(int i = 0; i < V; i++){
		mostra_adjacentes(arestas, lista_de_vertices[i]);
	}
	for(int i = 0; i < V; i++){
		mostra_distancias(arestas, lista_de_vertices[i]);
	}		
  return 0;
}
