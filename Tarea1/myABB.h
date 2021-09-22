/*
 * @file    : myABB.h
 * @author	: Benjamin Villegas
 * @date	: 22/06/2021
 * @brief   : Solucion Tarea 1 2021S1 Parte 3.
 */
#include "myStack.h"

#define ROWS 2
#define COLS 26

// Esta estructura de stack se usa para guardar los nodos del ABB.
// Se referira a el como stack tipo 2.
typedef struct St2{
  Student *leaf;
  struct  St2 *next; 
}Stack2;

/**
 * @brief          : crea un nuevo nodo para el ABB y lo inserta en la posicion correspondiente segun su apellido
 * @param root     : direccion del puntero a la raiz del arbol
 * @param nombre   : nombre del estudiante
 * @param apellido : apellido del estudiante
 * @param nota     : nota del estudiante
 */
void insertStudent(Student** root, char nombre[NLEN],char apellido[NLEN], int nota);

/**
 * @brief      : imprime el nombre y apellido de los estudiantes que aprobaron
 * @param root : direccion del puntero a la raiz
 */
void printTree(Student** root);

/**
 * @brief      : elimina el ABB
 * @param root : direccion del puntero a la raiz
 */
void deleteTree(Student** root);

/**
 * @brief          : crea un nuevo nodo
 * @param nombre   : nombre del estudiante
 * @param apellido : apellido del estudiante
 * @param nota     : nota del estudiante
 * @return         : direccion al nuebo nodo
 */
Student* createNode(char nombre[NLEN],char apellido[NLEN], int nota);

/**
 * @brief      : se agrega un nodo al top del stack tipo 2
 * @param top  : direccion del puntero al top del stack tipo 2
 * @param leaf : direccion al nodo que se desea agregar al stack
 */
void push2 (Stack2** top, Student *leaf);

/**
 * @brief     : se saca el nodo que esta en el top del stack tipo 2
 * @param top : direccion del puntero al top del stack tipo 2
 * @return    : nodo que se saco
 */
Student *pop2(Stack2** topRef);

/**
 * @brief     : revisa si el stack tipo 2 esta vacio
 * @param top : puntero al top del stack tipo 2
 * @return    : 1 si esta vacio, 0 si no lo esta
 */
int isEmpty2(Stack2 *top);


