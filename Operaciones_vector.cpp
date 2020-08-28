#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <cmath>
#include <iostream>

//Universidad del Valle de Guatemala
//Laboratorio 3
//Bryann Alfaro
//Referencias recursos de clase y plusplus
//Programa 2 operaciones entre 2 vectores

//parametros a usarse
struct parameters { 
  int id;
  int valorA;
  int valorB;
  };


//subrutina para sumar
void *suma(void* argument){
  //Paso de los argumentos
	struct parameters *ps;
  ps=(struct parameters *)argument;

	int resultadoSuma;

	resultadoSuma = ps -> valorA+ps -> valorB;   
  usleep(1000);
	return (void*) resultadoSuma;
}

//subrutina para producto
void *multiplicar(void* argument){
  //Paso de los argumentos
	struct parameters *ps;
  ps=(struct parameters *)argument;

	int resultadoProducto;
	resultadoProducto = ps -> valorA*ps -> valorB;
   
  usleep(1000);
	return (void*) resultadoProducto;
}

//subrutina para raiz
void *raiz(void* argument){
  //Paso de los argumentos
	struct parameters *ps;
  ps=(struct parameters *)argument;

	int resultadoRaiz;
	
	
	resultadoRaiz = sqrt((double)ps->valorA);
   
  usleep(1000);
	return (void*) resultadoRaiz;
}

//subrutina para exponente
void *exponencial(void* argument){
  //Paso de los argumentos
	struct parameters *ps;
  ps=(struct parameters *)argument;

	int resultadoExponente;
	
	
	resultadoExponente = pow((double)ps->valorA, (double)ps->valorB);
   
  usleep(1000);
	return (void*) resultadoExponente;
}


int main(){


//Variables a utilizarse
	pthread_t thread_id;
	pthread_attr_t attr;
  char opcion;
	pthread_attr_init (&attr);
	pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_JOINABLE);
  struct parameters parametros;
	void *exit_value;
	unsigned int result = 1;


//Peticion de datos
	std::cout<<"Ingresa tu opcion: ";
  printf("\n");
  std::cout<<"1. Suma\n";
  std::cout<<"2. Producto\n";
  std::cout<<"3. Raiz\n";
  std::cout<<"4. Exponente\n";
  
  std::cin>>opcion;
  int vectorA[3] = {1,2,3};
  int vectorB[3] = {4,5,6};

  //Suma
  if(opcion=='1'){
    for(int j=0;j<3;j++){
      parametros.valorA = vectorA[j];
      parametros.valorB = vectorB[j];

      pthread_create(&thread_id, &attr,suma, (void*)&parametros);
		  pthread_join(thread_id, &exit_value);
		
		  int* result = (int*) exit_value;
		  printf("Resultado suma es: %d\n ", result);

    }
    
  }

  //Producto
  if(opcion=='2'){
    for(int j=0;j<3;j++){
      parametros.valorA = vectorA[j];
      parametros.valorB = vectorB[j];

      pthread_create(&thread_id, &attr,multiplicar, (void*)&parametros);
		  pthread_join(thread_id, &exit_value);
		
		  int* result = (int*) exit_value;
		  printf("Resultado multiplicacion es: %d\n ", result);

    }
    
  }

  //Raiz
  if(opcion=='3'){
    for(int j=0;j<3;j++){
      parametros.valorA = vectorA[j];
      parametros.valorB = vectorB[j];

      pthread_create(&thread_id, &attr,raiz, (void*)&parametros);
		  pthread_join(thread_id, &exit_value);
		
		  int* result = (int*) exit_value;
		  printf("Resultado raiz es: %d\n ", result);

    }
    
  }

  //Exponente
  if(opcion=='4'){
    for(int j=0;j<3;j++){
      parametros.valorA = vectorA[j];
      parametros.valorB = vectorB[j];

      pthread_create(&thread_id, &attr,exponencial, (void*)&parametros);
		  pthread_join(thread_id, &exit_value);
		
		  int* result = (int*) exit_value;
		  printf("Resultado exponente es: %d\n ", result);

    }
    
  }

	pthread_attr_destroy(&attr);
	pthread_exit(NULL);
	return 0;
	
}
