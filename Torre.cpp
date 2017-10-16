/* Movimientos de la Torre de Ajedrez */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

long int x = 0, y = 0;

/* Las estructuras que almacenan los estados y la de control -------------------------------------------*/
typedef struct nodo{
 int n;
 int m;
 struct nodo *sig;
} LISTA;

/* Estructuras para los movimientos  de la Torre -----------------------------------*/
LISTA *movDiag = NULL, *movDiagInv = NULL;
LISTA *movVert = NULL, *movHori = NULL;

/*Agrega elementos a la lista de posiciones -------------------------*/
void insertar(LISTA **ptr, int elemento1, int elemento2){
	LISTA *p1, *p2;
	p1 = *ptr;
		if(p1 == NULL){
			p1 = new(LISTA);
			if (p1 != NULL){
				p1->n = elemento1;
				p1->m = elemento2;
				p1->sig = NULL;
				*ptr = p1;
			}
		}
		else{
			while(p1->sig != NULL)
				p1 = p1->sig;
				p2 = new(LISTA);
				if(p2 != NULL){
					p2->n = elemento1;
					p2->m = elemento2;
					p2->sig = NULL;
					p1->sig = p2;
				}
			}
}

/* Muestra los valores de las posiciones -----------------------------------------------------*/
void mostrar_lista(LISTA *ptr){
	while(ptr != NULL){
		cout<<"("<<ptr->n<<","<<ptr->m<<") - ";
		ptr = ptr->sig;
	}
}

/* Movimiento Horizontal de la Torre -----------------------------------*/
horizontalTorre(){
	int cont;
	for(cont = 0; cont <= 7; cont++) insertar(&movHori, cont, y);
}

/* Movimiento Vertical de la Torre -----------------------------------*/
verticalTorre(){
	int cont;
	for(cont = 0; cont <= 7; cont++){
		insertar(&movVert, x, cont);

	}
}

torre(){
	verticalTorre();
	horizontalTorre();
}

main(){
    int n=0;

    cout <<"\nMovimientos posibles de la Torre de Ajedrez"<< endl;
    do{
        cout <<"Valor de X: ";
        cin >> x;
        if(x>7 || x<0){printf("Valor de X debe ser entre 0 y 7\n"); n=0;} else {n=1;}
    }while(n==0);
    do{
        cout <<"Valor de Y: ";
        cin >> y;
        if(y>7 || y<0){printf("Valor de Y debe ser entre 0 y 7\n"); n=0;} else {n=1;}
    }while(n==0);

    /*
    cout <<"Cuales son los valores x e y (separados por un espacio '  '): ";
    cin >> x >> y;
    */

 	torre();

 	cout <<"\n\nLa posicion de la Torre es: x= "<<x <<" y= "<< y<< endl;
	cout <<"\nLa Lista de posiciones es: "<< endl;
	cout <<"\n\nVertical"<< endl;
	mostrar_lista(movVert);
	cout << "\n\nHorizontal"<< endl;
	mostrar_lista(movHori);
}
