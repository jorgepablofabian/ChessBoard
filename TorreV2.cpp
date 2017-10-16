/* Movimientos de la Torre de Ajedrez */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

long int x = 0, y = 0;
int i, j;   /* agregado para imprimir tabla*/
char tabla[8][8];    /* agregado para imprimir tabla*/

/* Las estructuras que almacenan los estados y la de control -------------------------------------------*/
typedef struct nodo{
 int n;
 int m;
 struct nodo *sig;
} LISTA;

/* Estructuras para los movimientos  de la Torre -----------------------------------*/
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
		tabla[ptr->n][ptr->m]='T';
		ptr = ptr->sig;
	}
}

/* Inicializar tablero de ajedrez*/
void inicializar_tablero(){
        for (i=0; i<8; i++) {
            for (j=0; j<8; j++) {
                tabla[i][j]='-';
            }
        }
}

/* Imprimir el movimiento en el tablero de ajedrez  agregado para imprimir tabla*/
void imprimir_movto(){
		//cout<<"("<<ptr->n<<","<<ptr->m<<") - ";
		cout<<"\n\n\n\t\tTablero de Ajedrez con movimientos";
        cout<<"\n\n\n\t0\t1\t2\t3\t4\t5\t6\t7\n\n\n";
        for (i=0; i<8; i++) {
            printf("%d\t",i);
            for (j=0; j<8; j++) {
                printf("%c\t", tabla[j][i]);
            }
            printf("\n");
            puts("");
        }
}

/* Movimiento Horizontal de la Torre -----------------------------------*/
void horizontalTorre(){
	int cont;
	for(cont = 0; cont <= 7; cont++) insertar(&movHori, cont, y);
}

/* Movimiento Vertical de la Torre -----------------------------------*/
void verticalTorre(){
	int cont;
	for(cont = 0; cont <= 7; cont++) insertar(&movVert, x, cont);
}

void torre(){
	verticalTorre();
	horizontalTorre();
}

main(){
    int num=0;
    cout <<"\nMovimientos posibles de la Torre de Ajedrez por coordenadas (X,Y)"<< endl;
    do{
        cout <<"Valor de X: ";
        cin >> x;
        if(x>7 || x<0){printf("Valor de X debe ser entre 0 y 7\n"); num=0;} else {num=1;}
    }while(num==0);
    do{
        cout <<"Valor de Y: ";
        cin >> y;
        if(y>7 || y<0){printf("Valor de Y debe ser entre 0 y 7\n"); num=0;} else {num=1;}
    }while(num==0);
 	torre();
    inicializar_tablero();
 	cout <<"\n\nLa posicion de la Torre es: x= "<<x <<" y= "<< y<< endl;
	cout <<"\nLa Lista de posiciones es: "<< endl;
	cout <<"\n\nVertical"<< endl;
	mostrar_lista(movVert);
	cout << "\n\nHorizontal"<< endl;
	mostrar_lista(movHori);
	imprimir_movto();
}
