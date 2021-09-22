/*
 * @file    : main.c
 * @author	: Benjamin Villegas
 * @date	: 21/06/2021
 * @brief   : Solucion Tarea 1 2021S1.
 */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <ctype.h> /*Para toupper() y tolower().*/

#include "myABB.h"

char encryptionTable[ROWS][COLS] = {{'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'},{}};

int getRandomNum();
void initEncryptionTable(char table[ROWS][COLS]);
void encrypt(char* str, char table[ROWS][COLS]);
void decrypt(char* str, char table[ROWS][COLS]);

int main(int argc, char * argv []){

  /*Inicializar random seed.*/
  srand (time(NULL));
  /*Inicializar la tabla de encriptacion.*/
  initEncryptionTable( encryptionTable);
  
  /*Abrir archivo "notas-EDA-C1.txt" en modo lectura.*/
  FILE *fp;
  if(argc == 2) 
        fp = fopen(argv[1],"r");
  else{
    puts("No se ha agregado archivo por linea de comandos.\n");
    return -1;
  }
  if(fp == NULL){
      printf("No se pudo abrir el archivo.\n");
      return 1;
  }

  char buffer[255];
  char* token;

  /*Crear stack.*/
  Stack* stack1 = getNewStack(30);

  /*Sacar cada linea del archivo, imprimir y guardar en el stack infirmaciom encriptada.*/
  printf("Los estudiantes encriptados son:\n\n");
  while(1){ 
    if(fgets(buffer,255,fp) != NULL){
      char nombre[NLEN];
      char apellido[NLEN];
      int nota;

    token = strtok(buffer, ",");
    encrypt(token, encryptionTable);
    strcpy(nombre, token);
    printf("%s,", token);

    int counter = 0;
    while(token != NULL){
      token = strtok(NULL, ",");
      if((!counter) && (token != NULL)){
        encrypt(token, encryptionTable);
        printf("%s,",token);
        strcpy(apellido,token);
      }
      else if(token != NULL){
        printf("%s\n",token);
        nota = atoi(token);
      }
      counter++;
      }
      int status = push(stack1, nombre, apellido, nota);

    }
    else break;
  }
  
  /*Cerrar archivo.*/
  fclose(fp);

  /*Para la busqueda de la mejor nota.*/
  int notaMax = 0;
  char* nombreMax = (char*) malloc(30*sizeof(char));
  char* apellidoMax = (char*) malloc(30*sizeof(char));

 /*Recorrer el stack, imprimir los aprobados y la mejor nota.*/
  printf("\nLos aprobados desde el stack son:\n\n");
  Student* cursor = stack1->head;
  while(cursor != NULL){
    if(cursor->nota >= 55){
      /*Se copian los strings y se desencripta la copia.*/
      char* nombre = (char*) malloc(30*sizeof(char));
      char* apellido = (char*) malloc(30*sizeof(char));

      strcpy(nombre, cursor->nombre);
      strcpy(apellido, cursor->apellido);

      decrypt(nombre, encryptionTable);
      decrypt(apellido, encryptionTable);

      if(cursor->nota > notaMax){
        strcpy(nombreMax,nombre);
        strcpy(apellidoMax, apellido);
        notaMax = cursor->nota;
      }

      printf("%s %s\n", nombre, apellido);
      free(nombre);
      free(apellido);

    }

    cursor = cursor->next;
  } 

  printf("\nLa mayor nota es de %s %s.\n\n", nombreMax, apellidoMax);
  free(nombreMax);
  free(apellidoMax);
  
  /*Inicializar ABB.*/
  Student* root = NULL;
  
  /*Pasar datos del stack al ABB.*/
  while(!isEmpty(stack1)){
    Student* temp = pop(stack1);
    char* nombre = (char*) malloc(30*sizeof(char));
    char* apellido = (char*) malloc(30*sizeof(char));

    strcpy(nombre, temp->nombre);
    strcpy(apellido, temp->apellido);

    decrypt(nombre, encryptionTable);
    decrypt(apellido, encryptionTable);

    insertStudent(&root, nombre, apellido, temp->nota);
  }

  /*Imprimir aprobados desde el ABB.*/
  printf("\nLos aprobados desde el ABB son:\n\n");
  printTree(&root);

  /*Eliminar ABB y stack*/
  deleteTree(&root);
  int stat = stackDelete(&stack1);

  return 0;

}


/**
 * @brief       : llena la segunda fila de la tabla con las letras desordenadas
 * @param table : tabla a rellenar 
 */
void initEncryptionTable(char table[ROWS][COLS]){
  /*Copiar la primera fila en la segunda.*/
  for(int i = 0; i <= COLS-1; i++){
    table[1][i] = table[0][i];
  }
  
  /*Cambiar la letra por una al azar.*/
  for(int i = 0; i <= COLS-1; i++){
    int errorcount = 0;
    while(1){
      errorcount++;
      if (errorcount > 100){
        printf("counter de error al maximo.\n");
        break;
      }
      /*Mayusculas.*/
      if(64 < table[1][i] <= 90){
        int temp = getRandomNum() + 65;
        /*Checkear si la letra ya fue usada o sera igual.*/
        int check = 1;
        for(int j = 0; j <= i; j++){
          if (temp == (int) table[1][j]){
            check = 0;
          }
        }
        if(check){
          table[1][i] = (char) temp;
          break;  
        }
      }

      /*Minusculas.*/
      else if(96 < table[1][i] <= 122){
        int temp2 = getRandomNum() + 97;
        /*Checkear si la letra ya fue usada o sera igual.*/
        int check2 = 1;
        for(int j = 0; j <= i; j++){
          if (temp2 == (int) table[1][j]){
            check2 = 0;
          }
        }
        if(check2){
          table[1][i] = (char) temp2;
          break;  
        }
      }
      else{
        printf("El valor entregado no es una letra.\n");
        break;
      }
    }
  }
}

/**
 * @brief       : encripta un string cambiando sus caracteres segun la tabla entregada
 * @param str   : direccion del string a encriptar
 * @param table : tabla de encripcion
 */
void encrypt(char* str, char table[ROWS][COLS]){
  /*Entrar al string y pasar a minuscula.*/
  while(*str != '\0'){
    *str = tolower(*str);
  /*Recorrer la tabla y modificar la letra.*/
    for(int i = 0; i < COLS; i++){
      if(*str == table[0][i]){
        *str = table[1][i];
      }
    }
    str++;
  }
}

/**
 * @brief       : desencripta un string cambiando sus caracteres segun la tabla entregada
 * @param str   : direccion del string a desencriptar
 * @param table : tabla de encripcion
 */
void decrypt(char* str, char table[ROWS][COLS]){
  /*Recorrer el string.*/
  while(*str != '\0'){
  /*Recorrer la tabla y reemplazar la letra.*/
    for(int i = 0; i < COLS; i++){
      if(*str == table[1][i]){
        *str = table[0][i];
      }
    }
    str++;
  }
}

/**
 * @brief : entrega un valor al azar entre 0 y 25
 * @return: interger entre 0 y 25
 */
int getRandomNum(){
  return rand()%26;
}