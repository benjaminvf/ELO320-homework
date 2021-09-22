/*
 * @file    : main.c
 * @author	: Benjamin Villegas
 * @date	: 20/07/2021
 * @brief   : Solucion Tarea 2 2021S1.
 */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "mySearchAlg.h"

#include <sys/time.h>

#define LENGHT 1000

/**
 * @brief     : entrega un valor al azar entre 0 y max
 * @param max : valor maximo
 * @return    : valor al azar
 */
int getRand(int max);

/**
 * @brief      : imprime los valores del arreglo de nodos
 * @param A    : direccion del array de nodos
 * @param size : tamaño del arreglo
 */
void printArray(struct node *A, int size);

void main(){
    /*Inicializar random seed.*/
    srand (time(NULL));

    /*Generar el arreglo de nodos y darle valores.*/
    Node* myArray = (Node*) malloc(LENGHT * sizeof(Node));

    for(int i=0 ; i < LENGHT ; i++){
        myArray[i].data = getRand(1000000);
        myArray[i].left = -1;
        myArray[i].right = -1;
    }

    /*Solicitar indices de los subarreglos.*/
    int array1_ini = -1;
    int array1_end = -1;
    int array2_ini = -1;
    int array2_end = -1;

    do{
        printf("Inserte el primer indice del subarray 1: (valor entre 0 y %d)\n", LENGHT);
        scanf("%d", &array1_ini);
    }while((array1_ini < 0)||(array1_ini > LENGHT));
    
    do{
        printf("Inserte el ultimo indice del subarray 1: (valor entre %d y %d)\n", array1_ini, LENGHT);
        scanf("%d", &array1_end);
    }while((array1_end < array1_ini)||(array1_end > LENGHT));

    do{
        printf("Inserte el primer indice del subarray 2: (valor entre %d y %d)\n", array1_end, LENGHT);
        scanf("%d", &array2_ini);
    }while((array2_ini < array1_end)||(array2_ini > LENGHT));

    do{
        printf("Inserte el ultimo indice del subarray 2: (valor entre %d y %d)\n", array2_ini, LENGHT);
        scanf("%d", &array2_end);
    }while((array2_end < array2_ini)||(array2_end > LENGHT));

    int size1 = array1_end - array1_ini + 1;
    int size2 = array2_end - array2_ini + 1;
    
    /*Construir el min y max heap dentro del array.*/
    buildMinHeap(myArray, array1_ini, size1);
    buildMaxHeap(myArray, array2_ini, size2);

    printf("\nheap array:\n\n");
    printArray(myArray, LENGHT);
    
    /*Ordenar de menor a mayor los heaps dentro del array.*/   
    heapSort(myArray, array1_ini, size1);
    heapSort(myArray, array2_ini, size2);

    printf("\nsorted array: \n\n");
    printArray(myArray, LENGHT);

    /*Fusionar arreglos.*/
    int merged_size =size1 + size2 - 1;
    Node* mergedArray = (Node*) malloc(merged_size * sizeof(Node));

    mergeArrays(myArray, array1_ini, size1, array2_ini, size2, mergedArray);

    printf("\nmerged array:\n\n");
    printArray(mergedArray, merged_size);

    /*Crear los valores a buscar*/
    int toSearch [100];
    for(int i = 0; i < 100; i++){
        toSearch[i] = mergedArray[getRand(merged_size)].data;
    }
    
    /*Buscar valores y medir tiempos.*/
    printf("\ntiempos de busqueda del mergedArray:\n\n");
    for (int i = 0; i < 100 ; i++){
        for(int j = 0; j < 100; j++){
            struct timeval tv1, tv2;
            gettimeofday(&tv1, NULL);

            binarySearch(mergedArray, 0, merged_size - 1, toSearch[i]);

            gettimeofday(&tv2, NULL);
            srch_time[j] = (double) (tv2.tv_usec - tv1.tv_usec)*1000;
        }
        double prom = 0;
        for(int j = 0 ; j < 100 ; j++){
            prom += srch_time[j]/100;
        }
        printf("%d: la busqueda de %d demora %d [ns]\n", i, toSearch[i], (int) prom);

    }
    
    /*Crear ABB balanceado.*/
    Node* ABBArray = (Node*) malloc(merged_size * sizeof(Node));   
    buildABB(mergedArray, 0, merged_size - 1, ABBArray, 0, merged_size);
    
    printf("\nABB balanceado:\n\n");
    printArray(ABBArray, merged_size);

    /*Buscar valores y medir tiempos para el ABB balanceado.*/
    printf("\ntiempos de busqueda del ABBArray:\n\n");
    for (int i = 0; i < 100 ; i++){
        for(int j = 0; j < 100; j++){
            struct timeval tv1, tv2;
            gettimeofday(&tv1, NULL);

            binarySearch(ABBArray, 0, merged_size - 1, toSearch[i]);

            gettimeofday(&tv2, NULL);
            srch_time[j] = (double) (tv2.tv_usec - tv1.tv_usec)*1000;
        }
        double prom = 0;
        for(int j = 0 ; j < 100 ; j++){
            prom += srch_time[j]/100;
        }
        printf("%d: la busqueda de %d demora %d [ns]\n", i, toSearch[i], (int) prom);

    }    

    return;
}

int getRand(int max){
    return rand() % max;
}

void printArray(Node *A, int size){
    for (int i = 0; i < size; i++){
        printf("nodo %d: valor %d, con left %d y right %d.\n", i, A[i].data, A[i].left, A[i].right);
    }

    return;
}