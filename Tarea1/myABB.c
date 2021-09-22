/*
 * @file    : myABB.c
 * @author	: Benjamin Villegas
 * @date	: 22/06/2021
 * @brief   : Solucion Tarea 1 2021S1 Parte 3.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "myABB.h"

void insertStudent(Student** root, char nombre[NLEN],char apellido[NLEN], int nota){
  /*Caso del primer nodo.*/
  if(*root == NULL){
    *root = createNode(nombre, apellido, nota);
    return;
  }

  /*Buscar donde debe ir el nodo guardando la direccion de su padre.*/
  Student* cursor = *root;
  Student* padre = NULL;

  while(cursor != NULL){
    if(strcmp(apellido, cursor->apellido) <= 0){
      padre = cursor;
      cursor = cursor->prev;
    }
    else{
      padre = cursor;
      cursor = cursor->next;
    }
  }
  
  /*Crear el nodo en la posicion correspondiente.*/  
  Student* newNode = createNode(nombre, apellido, nota);
  if(strcmp(apellido, padre->apellido) <= 0){
    padre->prev = newNode;
    printf("%s es hijo izquierdo de %s.\n", newNode->apellido, padre->apellido );
  } else{
    padre->next = newNode;
    printf("%s es hijo derecho de %s.\n", newNode->apellido, padre->apellido );
  }
  return;

}

/*Esta funcion se basa en https://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion/*/
void printTree(Student** root){

  if(*root == NULL) return;

  Stack2* stack = NULL;
  Student* cursor = *root;

  while(1){
  /*Recorrer arbol hasta llegar al NULL mas a la izquierda del nodo actual.*/
    if(cursor != NULL){
  /*Guardar en el stack tipo 2 cada nodo recorrido.*/
      push2(&stack, cursor);
      cursor = cursor->prev;
    }
  /*Se saca el ultimo nodo del stack tipo 2 y se imprime si es aprobado.*/
  /*Este equivale al hijo menor (el mas a la izquierda).*/
    else if (!isEmpty2(stack)){
      cursor = pop2(&stack);
      if(cursor->nota >= 55){
        printf("%s %s\n",cursor->nombre, cursor->apellido);
      }
  /*Moverse a la derecha del nodo.*/
      cursor = cursor->next;
  /*Cuando el stack tipo 2 esta vacio se recorrio todo el arbol.*/
    } else break;
  }
  free(cursor);
  return;

}

/*Esta funcion se basa en https://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion/*/
void deleteTree(Student** root){

  if(*root == NULL) return;

  Stack2* stack = NULL;
  Student* cursor = *root;

  while(1){
  /*Recorrer arbol hasta llegar al NULL mas a la izquierda del nodo actual.*/
    if(cursor != NULL){
  /*Guardar en el stack tipo 2 cada nodo recorrido.*/
      push2(&stack, cursor);
      cursor = cursor->prev;
    }
    else if (!isEmpty2(stack)){
  /*Sacar el ultimo nodo del stack tipo 2.*/
      cursor = pop2(&stack);
  /*Crear un puntero al nodo y mover el cursor al hijo derecho del nodo.*/  
      Student *temp = cursor;
      cursor = cursor->next;
  /*Liberar el nodo.*/
      free(temp);
  /*Cuando el stack tipo 2 esta vacio se recorrio todo el arbol.*/          
   } else break;
  }
 free(cursor);
 return;

}

Student* createNode(char nombre[NLEN],char apellido[NLEN], int nota){
  /*Asignar espacio para el nodo y ponerle los valores correspondientes.*/
  Student* newNode = (Student*) malloc(sizeof(Student));

  strcpy(newNode->nombre, nombre);
  strcpy(newNode->apellido, apellido);
  newNode->nota = nota;
  /*Apunta a NULL.*/
  newNode->prev = NULL;
  newNode->next = NULL;

  return newNode;
}

void push2 (Stack2** top, Student *leaf){
  Stack2 *newNode = (Stack2*) malloc(sizeof(Stack2));
  if(newNode == NULL){
    printf("Stack overflow.\n");
    getchar();
    exit(0);
  }
  
  /*Guardar el nodo en el stack y modificar el top.*/
  newNode->leaf = leaf;
  
  newNode->next = *top; 
  *top = newNode;

}

int isEmpty2(Stack2 *top){
  /*Si top apunta a NULL el stack esta vacio.*/
  return(top == NULL)? 1: 0;

}

Student *pop2(Stack2** topRef){
  Student *res;
  Stack2 *top;
  
  /*Comprobar que haya un nodo para sacar.*/
  if(isEmpty2(*topRef)){
    printf("Stack inderflow.\n");
    getchar();
    exit(0);
  }
  /*Modificar el top y retornar el nodo.*/
  else{
    top = *topRef;
    res = top->leaf;
    *topRef = top->next;
    free(top);
    return res;  
  }

}


