//
// Created by picha on 28/05/2022.
//
#include <stdio.h>
#define r 3 //renglones
#define c 3 //columnas
typedef struct EjercicioDeAprendizaje{
    int a;
    int b;
}Robot;
int main(){
    Robot robot;
    FILE *archivo = fopen("matriz.txt", "w");
    int Matriz[r][c];
    if (archivo == NULL) {
        printf("No he podido abrir el archivo\n");
        return 1;
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            printf("Ingresa O libre, 1 obstaculo-[%d][%d]:", i, j);
            scanf("%d",&Matriz[i][j]);
            fprintf(archivo, "%d", Matriz[i][j]);
        }
        fprintf(archivo, "\n");
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c; ++j){
            fscanf(archivo, "%d", &Matriz[i][j]);
        }
    }
    fclose(archivo);
    archivo= fopen("matriz.txt", "r");
    //Posicion del robot
    robot.a=0;
    robot.b=0;
    int aux=r+1;
    for(int i = aux ; i > 0 && robot.b != c - 1 || robot.a != r - 1 ; i-- ){
        if(Matriz[robot.b][robot.a+1] == 0 && robot.a + 1 < r){
            robot.a = robot.a + 1;
            //El robot se movio abajo
        }else{
            if(Matriz[robot.b+1][robot.a] == 0 && robot.b + 1 < c){
                robot.b=robot.b+1;
                //El robot se movio a la derecha
            }
        }
        printf("[%d,%d] " , robot.a , robot.b);
        if(robot.a && robot.b != r - 1) {
            printf("-> ");
        }
    }

}