/*
 * @file    : mySortAlg.h
 * @author	: Benjamin Villegas
 * @date	: 20/07/2021
 * @brief   : Header de Solucion Tarea 2 parte B 2021S1.
 */

/*Estructura de los nodos*/
typedef struct node{
    int data;
    int left;
    int right;
} Node;

/**
 * @brief   : intercambiar los datos entre dos nodos
 * @param A : direccion del primer nodo
 * @param B : direccion del segundo nodo
 */
void swapNodes(Node *A, Node *B);

/**
 * @brief      : contruir un maxHeap
 * @param A    : direccion del array de nodos
 * @param ini  : punto de inicio dentro del array
 * @param size : tamaño del arreglo
 */
void buildMaxHeap(Node *A, int ini, int size);

/**
 * @brief      : dejar el arreglo en forma de maxHeap
 * @param A    : direccion del array de nodos
 * @param i    : ubicacion actual en el array
 * @param ini  : punto de inicio dentro del array
 * @param size : tamaño del arreglo
 */
void maxHeapify(Node *A, int i, int ini, int size);

/**
 * @brief      : contruir un minHeap
 * @param A    : direccion del array de nodos
 * @param ini  : punto de inicio dentro del array
 * @param size : tamaño del arreglo
 */
void buildMinHeap(Node *A, int ini, int size);

/**
 * @brief      : dejar el arreglo en forma de minHeap
 * @param A    : direccion del array de nodos
 * @param i    : ubicacion actual en el array
 * @param ini  : punto de inicio dentro del array
 * @param size : tamaño del arreglo
 */
void minHeapify(Node *A, int i, int ini, int size);

/**
 * @brief      : ordenar array de menor a mayor
 * @param A    : direccion del array de nodos
 * @param ini  : punto de inicio dentro del array
 * @param size : tamaño del arreglo
 */
void heapSort(Node *A, int ini, int size);

/**
 * @brief       : juntar dos array ordenandos de menor a mayor
 * @param A     : direccion del primer array de nodos 
 * @param ini1  : punto de inicio dentro del array A
 * @param size1 : tamaño del arreglo A
 * @param B     : direccion del segundo array de nodos
 * @param ini2  : punto de inicio dentro del array B
 * @param size2 : tamaño del arreglo B
 * @param M     : direccion del array de nodos donde unirlos
 */
void mergeArrays(Node *A, int ini1, int size1, int ini2, int size2, Node *M);