//
// Created by picha on 27/05/2022.
//
#include <stdio.h>
#include "colaParaTarea3.h"

#define GRAPH_CAPACITY 32

typedef struct graph{
    int edges[GRAPH_CAPACITY][GRAPH_CAPACITY];
    char vertices[GRAPH_CAPACITY];
    int size;
}Graph;
void initGraph(Graph *g);
void addVertice(Graph *g, char vertice);
int existVertice(Graph graph, char vertice);
int addEdge(Graph *g, char verticeSource,char verticeDestiny);
int findVertice(Graph graph, char vertice);
void printGraph(Graph graph);



int main(){
    Graph graph;
    Cola cola;
    char vertice;
    char arreglo[10];
    char arreglo2[7];
    initGraph(&graph);
//Relaciones Ejercicios En clase y tabla de imprimir
    addVertice(&graph, 'A');
    addVertice(&graph, 'B');
    addVertice(&graph, 'C');
    addVertice(&graph, 'D');
    addVertice(&graph, 'E');
    addVertice(&graph, 'F');
    addVertice(&graph, 'G');
    addVertice(&graph, 'H');

    addEdge(&graph, 'A', 'B' );
    addEdge(&graph, 'A', 'E' );
    addEdge(&graph, 'A', 'D' );
    addEdge(&graph, 'A', 'G' );
    addEdge(&graph, 'B', 'C' );
    addEdge(&graph, 'B', 'E' );
    addEdge(&graph, 'D', 'H' );
    addEdge(&graph, 'H', 'G' );

  //  printf("Por que vertice quieres empezar? :");
  //  scanf("%c", &vertice);
  vertice='A';

    inicializaCola(&cola);
    insertar(&cola, vertice);
    arreglo2[cola.inicio]=cola.datos[cola.inicio];

    for(int i=0; i< graph.size; i++) {
        arreglo[cola.inicio]=cola.datos[cola.inicio];
        eliminar(&cola,&cola.datos[cola.inicio]);
        int contador=0;
        for (int j = 0; j < graph.size; j++) {

        if (graph.edges[i][contador] == 1) {

            if(arreglo2[j]!=graph.vertices[contador]){
            insertar(&cola, graph.vertices[contador]);
            arreglo2[contador]=graph.vertices[contador];
            }
        }
        contador++;
    }
    }
    arreglo[0]='A';
//Imprimir Recorrido en Amplitud
    for(int i = 0; i < graph.size;i++) {
        printf("%c ",arreglo[i]);
    }

return 0;
}
void initGraph(Graph *g){
    g->size=0;
}
void addVertice(Graph *g, char vertice){

    if(g->size<GRAPH_CAPACITY) {
        //Revisar que el vertice no exista Tarea
        if (existVertice(*g, vertice) == 0) {

            g->vertices[g->size]=vertice;


            for(int r=0; r<GRAPH_CAPACITY;r++){
                g->edges[r][g->size] =0;
            }
            for(int c=0; c<GRAPH_CAPACITY;c++){
                g->edges[g->size][c] =0;
            }
            g->size++;
        }
    }
}
int existVertice(Graph graph, char vertice){  //Tarea Funcio Si existe o no el vertice
    //Index=0-NoExiste    Index=1-Existe
    int index=0;

    for(int i=0; i< graph.size; i++){
        if(vertice==graph.vertices[i]){
            index=1;
        }
    }
    return index;
}
int findVertice(Graph graph, char vertice){
    int i;
    int result =-1;
    for(i = 0; i<graph.size && result==-1;i++){
        if(graph.vertices[i]==vertice){
            result=i;
        }
    }
    return result;
}
int addEdge(Graph *g, char verticeSource,char verticeDestiny){
    int posSource= findVertice(*g, verticeSource);
    int posDestiny= findVertice(*g, verticeDestiny);
    if(posSource!= -1 && posDestiny != -1){
        g->edges[posSource][posDestiny]=1;
        g->edges[posDestiny][posSource]=1;
        return 1;
    }
    return 0;
}
void printGraph(Graph graph){
    printf("\t\t");
    for(int i = 0; i< graph.size; i++){
        printf("%s\t", graph.vertices[i]);
    }
    printf("\n");
    for(int r =0; r<graph.size;r++){
        printf("%s\t", graph.vertices[r]);
        for(int c=0;c<graph.size; c++){
            printf("%d\t\t", graph.edges[r][c]);
        }
        printf("\n");
    }
}
