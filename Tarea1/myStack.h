/*
 * @file    : myStack.h
 * @author	: Benjamin Villegas
 * @date	: 21/06/2021
 * @brief   : Solucion Tarea 1 2021S1 Parte 2.
 */

#define NLEN 30

// Estructura de cada nodo de la lista y ABB.
typedef struct node {
  char nombre[NLEN];
  char apellido[NLEN];
  int nota;
  struct node* prev; //equivalente a left en ABB
  struct node* next; //equivalente a right en ABB
}Student; 

// Estructura del stack.
typedef struct St {
  Student *head;
  unsigned int capacity;
  int size;
} Stack;

/**
 * @brief    : ver si el stack esta lleno
 * @param st : direccion del stack
 * @return   : 1 si esta lleno, 0 si no lo esta
 */
int isFull(Stack *st);

/**
 * @brief    : ver si el stack esta vacio
 * @param st : direccion del stack
 * @return   : 1 si esta vacio, 0 si no lo esta
 */
int isEmpty(Stack *st);

/**
 * @brief      : se crea un nuevo stack de tamaño size
 * @param size : tamaño del stack
 * @return     : direccion del stack
 */
Stack* getNewStack( unsigned int size);

/**
 * @brief    : se elimina el stack
 * @param st : direccion del puntero del stack
 * @return   : 1 si se elimino, 0 si no se elimino
 */
int stackDelete(Stack **st);

/**
 * @brief          : se agrega un estudiante al stack
 * @param st       : direccion del stack
 * @param nombre   : nombre del estudiante
 * @param apellido : apellido del estudiante
 * @param nota     : nota del estudiante
 * @return         : 1 si se logro guardar el estudiante, 0 si no se logro
 */
int push(Stack* st, char nombre[NLEN],char apellido[NLEN], int nota);

/**
 * @brief    : se saca el nodo que esta en el top del stack
 * @param st : direccion del puntero al top del stack
 * @return   : nodo que se saco
 */
Student* pop(Stack* st);

/**
 * @brief          : se agrega un estudiante al inicio de la lista doblemente enlazada
 * @param headRef  : direccion del puntero al inicio de la lista
 * @param nombre   : nombre del estudiante
 * @param apellido : apellido del estudiante
 * @param nota     : nota del estudiante
 * @return         : 1 si se logro guardar el estudiante, 0 si no se logro
 */
int insertFirst (Student** headRef, char nombre[NLEN],char apellido[NLEN], int nota);

/**
 * @brief         : se saca un estudiante al inicio de la lista doblemente enlazada
 * @param headRef : direccion del puntero al inicio de la lista
 * @return        : primer nodo de la lista
 */
Student* removeFirst(Student** headRef);

/**
 * @brief         : se eliminan todos los nodos de la lista doblemente enlazada
 * @param headRef : direccion del puntero al inicio de la lista
 */
void deleteList(Student** headRef);

