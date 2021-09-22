/*
 * @file    : mySortAlg.c
 * @author	: Benjamin Villegas
 * @date	: 20/07/2021
 * @brief   : Solucion Tarea 2 parte B 2021S1.
 */

#include <stdlib.h>
#include <stdio.h>

#include "mySortAlg.h"

void swapNodes(Node *A, Node *B){
    Node temp ;
    temp = *A;
    *A = *B;
    *B = temp;
    A->left = B->left ;
    A->right = B->right ; 

    B->left = temp.left ;
    B->right = temp.right ; 
    
}

void buildMaxHeap(Node *A, int ini, int size){
    /*for desde la mitad al principio del array.*/
    for(int i = size/2 + ini - 1; i >=  ini; i--){
        maxHeapify(A, i, ini, size);
    }

}

void maxHeapify(Node *A, int i, int ini, int size){
    int largest = i;
    /*Dar valores a left y right.*/
    A[i].left = 2*i + 1 - ini;
    A[i].right = 2*i + 2 - ini;
    
    /*Comparar valor del nodo con el de sus hijos.*/
    if((A[i].left < size + ini)&&(A[A[i].left].data > A[largest].data)){
        largest = A[i].left;
    }
    if((A[i].right < size + ini)&&(A[A[i].right].data > A[largest].data)){
        largest = A[i].right;
    }

    /*Cambiar valor del nodo por el mas grande.*/
    if(largest != i){
        swapNodes(A + i, A + largest);
        maxHeapify(A, largest, ini, size);
    }

}

void buildMinHeap(Node *A, int ini, int size){
    for(int i = size/2 + ini - 1; i >=  ini; i--){
        minHeapify(A, i, ini, size);
    }

}

void minHeapify(Node *A, int i, int ini, int size){
    int smallest = i;
    /*Dar valores a left y right.*/
    A[i].left = 2*i + 1 - ini;
    A[i].right = 2*i + 2 - ini;

    /*Comparar valor del nodo con el de sus hijos.*/
    if((A[i].left < size + ini)&&(A[A[i].left].data < A[smallest].data)){
        smallest = A[i].left;
    }
    if((A[i].right < size + ini)&&(A[A[i].right].data < A[smallest].data)){
        smallest = A[i].right;
    }

    /*Cambiar valor del nodo por el mas pequeño.*/
    if(smallest != i){
        swapNodes(A + i, A + smallest);
        maxHeapify(A, smallest, ini, size);
    }

}

void heapSort(Node *A, int ini, int size){
    buildMaxHeap(A, ini, size);
    for (int i = ini + size - 1; i >= ini; i--){
        swapNodes(A + i , A + ini);
        maxHeapify(A, ini, ini, i - ini);
    }

}

void mergeArrays(Node *A, int ini1, int size1, int ini2, int size2, Node *M){
    int sizeM = size1 + size2;

    int i = 0;
    int j = 0;
    int k = 0;

    /*Agregar valores a M desde los dos arrays.*/
    while((i < size1)&&(j < size2)){
        /*Comparar los valores y agregar el menor.*/
        if(A[ini1 + i].data <= A[ini2 + j].data){
            M[k] = A[ini1 + i];
            i++;
        }
        else{
            M[k] = A[ini2 + j];
            j++;
        }
        if(k < size1 + size2){
                M[k].left = 2*k + 1 ;
                M[k].right= 2*k + 2 ;
        }
        k++;
        /*Solo avanza el que se agrega y M. */
    }
    /*Cuando uno de los arreglos se recorre por completo se recorre el faltante.*/
    while(i < size1){
        M[k] = A[ini1 + i];
        i++;
        if(k < size1 + size2){
                M[k].left = 2*k + 1 ;
                M[k].right= 2*k + 2 ;
        }
        k++;
    }

    while(j < size2){
        M[k] = A[ini2 + j];
        j++;
        if(k < size1 + size2){
                M[k].left = 2*k + 1 ;
                M[k].right= 2*k + 2 ;
        }
        k++;
    }

}