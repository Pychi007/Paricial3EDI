//
// Created by picha on 26/05/2022.
// Grafos
#include <stdio.h>
#include <string.h>

#define GRAPH_CAPACITY 32

typedef struct graph{
    int edges[GRAPH_CAPACITY][GRAPH_CAPACITY];
    char vertices[GRAPH_CAPACITY][20];
    int size;
}Graph;
void initGraph(Graph *g);
void addVertice(Graph *g, char vertice[20]);
int addEdge(Graph *g, char verticeSource[20],char verticeDestiny[20]);
int findVertice(Graph graph, char vertice[20]);
void printGraph(Graph graph);
//  Tarea
int existVertice(Graph graph, char vertice[20]);
void eliminarVertice(Graph *g, char vertice[20]);
int eliminarRelaciones(Graph *g, char verticeSource[20], char verticeDestiny[20]);
int existRelacionVertice(Graph graph, char verticeSource[20], char verticeDestiny[20]);


int main(){
    Graph graph;
    int relacion;
    initGraph(&graph);
//Relaciones Ejercicios En clase y tabla de imprimir
    addVertice(&graph, "San Luis Potosi");
    addVertice(&graph, "Queretaro");
    addVertice(&graph, "Nuevo Leon");
    addVertice(&graph, "Jalisco");
    addVertice(&graph, "Mexico");
    eliminarVertice(&graph, "Queretaro");

    for(int r=0;r<graph.size;r++){
        for(int c=r; c<graph.size;c++){
            printf("%s tiene relacion con %s? (1- si. 0- no)", graph.vertices[r],graph.vertices[c]);
            scanf("%d", &relacion);
            if(relacion==1){
                addEdge(&graph,graph.vertices[r],graph.vertices[c]);
            }
        }
    }
    eliminarRelaciones(&graph, "San Luis Potosi", "Nuevo Leon");



    printGraph(graph);
    //Ejemplo de si una relacion entre dos vertices
    int exist;
    printf("Existe la relacion entre Jalisco y Mexico?\n");
    exist=existRelacionVertice(graph, "Jalisco", "Mexico");
    if(exist==1){
        printf("----Si existe la relacion----");
    }

    return 0;
};
void initGraph(Graph *g){
    g->size=0;
}
void addVertice(Graph *g, char vertice[20]){

    if(g->size<GRAPH_CAPACITY) {
        //Revisar que el vertice no exista Tarea
        if (existVertice(*g, vertice) == 0) {

        strcpy(g->vertices[g->size], vertice);


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
int existVertice(Graph graph, char vertice[20]){  //Tarea Funcio Si existe o no el vertice
    //Index=0-NoExiste    Index=1-Existe
    int index=0;

    for(int i=0; i< graph.size; i++){
        if(strcmp(vertice ,graph.vertices[i])==0){
            index=1;
        }
    }
    return index;
}
int findVertice(Graph graph, char vertice[20]){
    int i;
    int result =-1;
    for(i = 0; i<graph.size && result==-1;i++){
        if(strcmp(graph.vertices[i], vertice)==0){
            result=i;
        }
    }
    return result;
}
int addEdge(Graph *g, char verticeSource[20],char verticeDestiny[20]){
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

//Tarea
void eliminarVertice(Graph *g, char vertice[20]){

    int r= findVertice(*g,vertice);
    if(r!=-1){
        for(int i=r;i<g->size;i++){
            strcpy(g->vertices[i], g->vertices[i+1]);
        }
        g->size--;
    }
}
//Tarea
int eliminarRelaciones(Graph *g, char verticeSource[20], char verticeDestiny[20]){
    //regresa 1 si puedo Eliminar, regresa 0 si no pudo
    int posSource= findVertice(*g, verticeSource);
    int posDestiny= findVertice(*g, verticeDestiny);
    if(posSource!= -1 && posDestiny != -1){
        g->edges[posSource][posDestiny]=0;
        g->edges[posDestiny][posSource]=0;
        return 1;
    }
    return 0;
}
//Tarea
int existRelacionVertice(Graph graph, char verticeSource[20], char verticeDestiny[20])
{
    //regresa 1 si existe, regresa 0 si no pudo
    int posSource= findVertice(graph, verticeSource);
    int posDestiny= findVertice(graph, verticeDestiny);
    if(graph.edges[posSource][posDestiny]==1){
        return 1;
    }
    return 0;
}
