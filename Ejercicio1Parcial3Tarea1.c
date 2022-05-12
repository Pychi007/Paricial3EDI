//
// Created by picha on 10/05/2022.
//
#include <stdio.h>
#include <string.h>
#include "stack.h"
#include "cola.h"

#define CIRCLE_SANDWICH 0
#define SQUARE_SANDWICH 1

void sell_sandwich(Cola *c, Stack *s);
int main() {

    Stack stack;
    Cola cola;
    Estudiante estudiante;


    //Inicializamos las estructuras
    inicializaCola(&cola);
    setup(&stack);

//Insertar los sandwich
    push(&stack, SQUARE_SANDWICH);
    push(&stack, SQUARE_SANDWICH);
    push(&stack, CIRCLE_SANDWICH);
    push(&stack, SQUARE_SANDWICH);
    push(&stack, CIRCLE_SANDWICH);


    //Formar a los estudiantes

    strcpy(estudiante.nombre, "Emiliano");
    estudiante.sandwich= SQUARE_SANDWICH;
    insertar(&cola, estudiante);
//
    strcpy(estudiante.nombre, "Adrian");
    estudiante.sandwich= CIRCLE_SANDWICH;
    insertar(&cola, estudiante);
//
    strcpy(estudiante.nombre, "Erick");
    estudiante.sandwich= SQUARE_SANDWICH;
    insertar(&cola, estudiante);
//
    strcpy(estudiante.nombre, "Karla");
    estudiante.sandwich= CIRCLE_SANDWICH;
    insertar(&cola, estudiante);
//
    strcpy(estudiante.nombre, "Tony");
    estudiante.sandwich= CIRCLE_SANDWICH;
    insertar(&cola, estudiante);
    sell_sandwich(&cola, &stack);
    return 0;
}
void sell_sandwich(Cola *c, Stack *s){

    Estudiante estudianteActual;
    int sandwichActual;

    while(estaVacia(*c) == 0){

        eliminar(c,&estudianteActual);
        pop(s, &sandwichActual);

        printf("\nEl estudiante %s quiere un sandwich: %d y en la pila hay: %d",estudianteActual.nombre, estudianteActual.sandwich, sandwichActual);

        if(estudianteActual.sandwich != sandwichActual){
            printf("\n\tNo se pudo entregar, regresando el estudiante a la cola y el sandwich a la pila.");
            insertar(c,estudianteActual);
            push(s, sandwichActual);
        } else{
            printf("\n\tEl sandwich se entrego.");
        }
    }
}