//
// Created by picha on 17/05/2022.
//
#include <stdio.h>
#define SET_CAPACITY 10

typedef struct set{
    int data[SET_CAPACITY];
    int size;
}Set;

void iniciar_set(Set *s);
int addvalor(Set *s, int value);
int findvalor(Set set, int value);
int removervalor(Set *s, int value);
int exist(Set set, int value);
void interseccion(Set setA, Set setB, Set *sC);
void Union(Set setA, Set setB, Set *sC);
void Complemento(Set setA, Set setB, Set *sC);
void Diferencia(Set setA, Set setB, Set *sC);
void printSet(Set set);

int main(){
    Set setA;
    Set setB;
    Set setC;


    iniciar_set(&setA);
    addvalor(&setA, 23);
    addvalor(&setA, 11);
    addvalor(&setA, 16);
    addvalor(&setA, 5);
    addvalor(&setA, 7);


    iniciar_set(&setB);
    addvalor(&setB, 10);
    addvalor(&setB, 11);
    addvalor(&setB, 21);
    addvalor(&setB, 5);
//Conjuntos
    iniciar_set(&setC);
    printf("Conjuntos\n");
    printSet(setA);
    printSet(setB);
    printSet(setC);
//Interseccion
    iniciar_set(&setC);
    interseccion(setA, setB, &setC);
    printf("\nInterseccion:");
    printSet(setC);
//Union
    iniciar_set(&setC);
    Union(setA,setB,&setC);
    printf("\nUnion:");
    printSet(setC);
//Complemento de A
    iniciar_set(&setC);
    Complemento(setA,setB, &setC);
    printf("\nComplento de A:");
    printSet(setC);
//Complemento de B
    iniciar_set(&setC);
    Complemento(setB,setA, &setC);
    printf("\nComplento de B:");
    printSet(setC);
//Diferencia de A
    iniciar_set(&setC);
    Diferencia(setA,setB,&setC);
    printf("\nDiferencia de A:");
    printSet(setC);
//Diferencia de B
    iniciar_set(&setC);
    Diferencia(setB,setA,&setC);
    printf("\nDiferencia de B:");
    printSet(setC);
}
void Diferencia(Set setA, Set setB, Set *sC){
    int e;
    for(int index=0; index<setA.size; index++){
        e= exist(setB, setA.data[index]);
        if (e==0){
            addvalor(sC, setA.data[index]);
        }
    }
}

void Complemento(Set setA, Set setB, Set *sC){
    int e;
    for(int index=0; index<setB.size; index++){
        e= exist(setA, setB.data[index]);
        if (e==0){
            addvalor(sC, setB.data[index]);
        }
    }
}
void Union(Set setA, Set setB, Set *sC){
    for(int index=0; index<setA.size; index++){
        addvalor(sC, setA.data[index]);
    }
    for(int index=0; index<setB.size; index++){
        addvalor(sC, setB.data[index]);
    }
}
void printSet(Set set){
    printf("[ ");
    for (int index =0; index<set.size; index++){
        printf("%d ", set.data[index]);
    }
    printf("]\n");
}
void interseccion(Set setA, Set setB, Set *sC){
int e;
    for(int index=0; index<setA.size;index ++){
        e = exist(setB, setA.data[index]);
        if(e==1){
            addvalor(sC, setA.data[index]);
        }
    }

}
int exist(Set set, int value){
    int index= findvalor(set, value);

    if(index == -1){
        return 0;
    }
    return 1;
}

int addvalor(Set *s, int value){
    int exists=0;
    int result=0;

    if(s->size < SET_CAPACITY){
        exists= findvalor(*s, value);
        if(exists == -1){
            int index;

            for(index = s->size-1; index >= 0 && s->data[index] > value; index--){
                s->data[index+1] = s->data[index];
            }

            s->data[index+1] = value;
            s->size++;
            result=1;
        }
    }
    return result;
}
int findvalor(Set set, int value){
    int inicio =0;
    int fin=set.size-1;
    int mitad;
    int encontrado=0;

    while (inicio <= fin && encontrado ==0){
        mitad= inicio + (fin -inicio) / 2;

        if (set.data[mitad] == value)
            encontrado=1;
        else
        if(set.data[mitad] > value)
            fin = mitad-1;
        else
            inicio=mitad+1;
    }
    if(encontrado==1)
        return mitad;
    else
        return -1;

}
void iniciar_set(Set *s){
    s->size=0;
}

int removervalor(Set *s, int value){
    int index = findvalor(*s, value);

    if(index != -1){
        s->size--;
        for(; index <= s->size -1; index++){
            s->data[index] = s->data[index+1];
        }
        return 1;
    }
    return 0;
}