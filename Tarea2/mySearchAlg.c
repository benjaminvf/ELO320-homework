/*
 * @file    : mySearchAlg.c
 * @author	: Benjamin Villegas
 * @date	: 20/07/2021
 * @brief   : Solucion Tarea 2 parte C y D 2021S1.
 */

#include <stdlib.h>
#include <stdio.h>

#include "mySearchAlg.h"

/*Funcion basada en https://www.geeksforgeeks.org/binary-search/ */
int binarySearch(Node *A, int l, int r, int val){
    if(r >= l){
        /*Buscar punto medio.*/
        int mid = l + (r - l)/2;
        
        /*Si valor está en punto medio se rotarna la direccion.*/
        if(A[mid].data == val){
            return mid;
        }
        /*Llamar a la funcion en la mitad izquierda.*/
        else if (A[mid].data > val){
            return binarySearch(A, l, mid - 1, val);
        }
        /*Llamar a la funcion en la mitad derecha.*/
        else if (A[mid].data < val){
            return binarySearch(A, mid + 1, r, val);
        }
    }
    
    return -1;
}

void buildABB(Node *S, int l, int r, Node *ABB, int i, int size){
    ABB[i].left = 2*i + 1;
    ABB[i].right = 2*i + 2;
    if (r >= l){
        int mid = l + (r - l)/2; 
        /*Agregar valor de punto medio a la posicion i.*/
        ABB[i].data = S[mid].data;
        /*Llamar a la funcion en la mitad izquierda.*/
        if (2*i + 1 <= size){
            buildABB(S, l, mid - 1, ABB, 2*i + 1, size);
        }
        /*Llamar a la funcion en la mitad derecha.*/
        if (2*i + 2 <= size){
            buildABB(S, mid + 1, r, ABB, 2*i + 2, size);
        }
    }
}

