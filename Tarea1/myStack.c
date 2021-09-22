/*
 * @file    : myStack.c
 * @author	: Benjamin Villegas
 * @date	: 21/06/2021
 * @brief   : Solucion Tarea 1 2021S1 Parte 2.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "myStack.h"

int isFull(Stack *st){
  int result = 0;
  if(st == NULL){
    printf("El puntero esta vacio.");
    return -1;
  }
  /*Comparar el tamaño maximo con el actual.*/
  if(st->size == st->capacity){
    result = 1;
  }
  return result;
}

int isEmpty(Stack *st){
  int result = 0;
  if(st == NULL){
    printf("El puntero esta vacio.\n");
    return -1;
  }
  /*Comparar tamaño actual con 0.*/
  if(st->size == 0){
    result = 1;
  }
  return result;

}

Stack* getNewStack( unsigned int size){
  Stack* newStack = NULL;
  if(size > 0){
  /*Asignar espacio al stack.*/
    newStack = (Stack*) malloc(sizeof(Stack));
    if(newStack == NULL){
      printf("Error en creacion de Stack con malloc.\n");
      return NULL;
    }
  /*Crear puntero al principio de la lista y asignar tamaño.*/
    newStack->head = NULL;
    newStack->capacity = size;
    newStack->size = 0;

  }
  return newStack;
}

int stackDelete(Stack **st){
  int status = 0;
  if(*st == NULL){
    printf("El puntero esta vacio.\n");
  }
  /*Eliminar la lista y liberar el espacio del stack.*/
  else{
    deleteList(&((*st)->head));
    free(*st);
    *st=NULL;
    status = 1;
  }
  return status;
}

int push(Stack* st, char nombre[NLEN],char apellido[NLEN], int nota){
  int status = 0;
  if(isFull(st)){
    printf("El stack esta lleno.\n");
  }
  /*Insertar un nodo al principio de la lista y aumentar el tamaño actual del stack.*/
  else{
    status = insertFirst(&(st->head), nombre, apellido, nota);
    st->size++;
  }
  return status;
}

Student* pop(Stack* st){
  Student* result = (Student*) malloc(sizeof(Student));
  if(isEmpty(st)){
    printf("El stack estÃ¡ vacio.\n");
    result = NULL;
  }
  /*Sacar un nodo del stack y disminuir el tamaño actual del stack.*/
  else{
    result = removeFirst(&(st->head));
    st->size--;
  } 
  return result;
}

int insertFirst (Student** headRef, char nombre[NLEN],char apellido[NLEN], int nota){
  /*Asignar espacio al nodo.*/
  Student* newStudent = (Student*) malloc(sizeof(Student));
  int status = 0;

  if(newStudent != NULL){
  /*Guardar los datos en el nodo.*/
    strcpy((newStudent->nombre), nombre);
    strcpy((newStudent->apellido), apellido);
    newStudent->nota = nota;
  /*Modificar el puntero prev del nodo siguiente.*/
    if(*headRef != NULL){
      (*headRef)->prev = newStudent;
    }
  /*Modificar el puntero next del nodo y el headRef.*/
    newStudent->next = *headRef;
    *headRef = newStudent;
    status = 1;
  }
  return status;
}

Student* removeFirst(Student** headRef){
  Student* temp = *headRef;

  if(*headRef != NULL){
  /*Modificar los punteros del nodo siguiente y headRef*/
    temp = *headRef;
    if((*headRef)->next != NULL){
      ((*headRef)->next)->prev = NULL;
    }
    *headRef = (*headRef)->next;
  }
  /*Retornar el nodo.*/
  return temp;
}

void deleteList(Student** headRef){
  if(*headRef != NULL){
  /*Recorrer la lista y liberar el espacio de los nodos.*/
    while(*headRef != NULL){
      Student* temp = *headRef;
      *headRef = (*headRef)->next;
      free(temp);
    }
  }
}