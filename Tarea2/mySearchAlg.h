/*
 * @file    : mySearchAlg.h
 * @author	: Benjamin Villegas
 * @date	: 20/07/2021
 * @brief   : Header de Solucion Tarea 2 parte C y D 2021S1.
 */

#include "mySortAlg.h"

/*Se usa para guardar las mediciones de tiempo*/
double srch_time[100];

/**
 * @brief     : buscar un valor en un arreglo ordenado
 * @param A   : direccion del array de nodos ordenado
 * @param l   : punto de inicio dentro del array
 * @param r   : punto final del array
 * @param val : valor a buscar
 * @return    : posicion del valor o -1 si no existe
 */
int binarySearch(Node *A, int l, int r, int val);

/**
 * @brief      : crear un ABB balanceado desde un array ordenado
 * @param S    : direccion del array de nodos ordenado
 * @param l    : punto de inicio dentro del array
 * @param r    : punto final del array
 * @param ABB  : ABB balanceado a crear
 * @param i    : posicion actual en el ABB
 * @param size : tamaño del arreglo
 */
void buildABB(Node *S, int l, int r, Node *ABB, int i, int size);