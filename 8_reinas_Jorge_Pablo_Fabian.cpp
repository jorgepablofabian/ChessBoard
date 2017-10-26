/*
    Alumno: Jorge Pablo Fabi�n
    Programa: 8reinas.cpp
    Descripci�n: Obtener las 92 soluciones posibles de las 8 reinas.

    Se inicia desde el primer rengl�n poniendo a la reina en cada cuadrado de
    este rengl�n y recursivamente explorar los renglones restantes para
    checar si estos gu�an a la soluci�n o no.
    Si la configuraci�n actual no arroja una soluci�n, se realiza el Back-Track.

    Referencia y CopyRight:
    http://www.techiedelight.com/print-possible-solutions-n-queens-problem/
*/
#include <bits/stdc++.h>
using namespace std;

// Ajedrez N x N
#define N 8

int contador=1;

// Funci�n para checar si 2 reinas amenazan a las dem�s o no
bool EsSeguro(char mat[][N], int r, int c)
{
	// regresa falso si 2 reinas comparten la misma columna
	for (int i = 0; i < r; i++)
		if (mat[i][c] == 'Q')
			return false;

	// regresa falso si 2 reinas comparten la misma \ diagonal
	for (int i = r, j = c; i >= 0 && j >= 0; i--, j--)
		if (mat[i][j] == 'Q')
			return false;

	// regresa falso si 2 reinas comparten la misma / diagonal
	for (int i = r, j = c; i >= 0 && j < N; i--, j++)
		if (mat[i][j] == 'Q')
			return false;

	return true;
}

void nReinas(char mat[][N], int r, int c)
{
	if (c == 0 && r == N) // Imprime la soluci�n si existe combinaci�n
	{
	    cout << "Solucion: " << contador << endl;
        cout << "Por coordenadas: ";
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                    if(mat[i][j]=='Q') { cout << "(" << i << "," << j << ") ";}
            }
            cout << endl;
/*        cout << endl << "Graficamente: " << endl;
            cout << "\n\t0\t1\t2\t3\t4\t5\t6\t7\n\n";
            for (int i = 0; i < N; i++)
            {
                cout << i << "\t";
                for (int j = 0; j < N; j++)
                    cout << mat[i][j] << "\t";
                cout << endl << endl << endl;
            }
            cout << endl;
 */       contador = contador + 1;
		return;
	}

	// Poner la Reina en cada cuadro del rengl�n r
	// y recursividad para cada movimiento v�lido
	for (int i = 0; i < N; i++)
	{
		// Si no hay 2 reinas que se amenazen
		if (EsSeguro(mat, r, i))
		{
			// poner la reina en el cuadrado actual
			mat[r][i] = 'Q';

			// Recursividad para el siguiente rengl�n
			nReinas(mat, r + 1, 0);

			// backtrack y remover la reina del cuadrado actual
			mat[r][i] = '-';
		}
	}
}


void nReinasG(char mat[][N], int r, int c)
{
	if (c == 0 && r == N) // Imprime la soluci�n si existe combinaci�n
	{
	    cout << "Solucion: " << contador << endl;
        cout << "Coordenadas: ";
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                    if(mat[i][j]=='Q') { cout << "(" << i << "," << j << ") ";}
            }
            cout << endl;

	    cout << "Graficamente: " << endl;
        cout << "\n\t0\t1\t2\t3\t4\t5\t6\t7\n\n";
        for (int i = 0; i < N; i++)
        {
            cout << i << "\t";
            for (int j = 0; j < N; j++)
                cout << mat[i][j] << "\t";
            cout << endl << endl << endl;
        }
        cout << endl;
        contador = contador + 1;
        cout << "presiona cualquier tecla para continuar...";
        cin.get();
		return;
	}

	// Poner la Reina en cada cuadro del rengl�n r
	// y recursividad para cada movimiento v�lido
	for (int i = 0; i < N; i++)
	{
		// Si no hay 2 reinas que se amenazen
		if (EsSeguro(mat, r, i))
		{
			// poner la reina en el cuadrado actual
			mat[r][i] = 'Q';

			// Recursividad para el siguiente rengl�n
			nReinasG(mat, r + 1, 0);

			// backtrack y remover la reina del cuadrado actual
			mat[r][i] = '-';
		}
	}
}

int main()
{
    int opcion;
	char mat[N][N]; // matriz que guarda el seguimiento de las posiciones de las Reinas
	memset(mat, '-', sizeof mat); // inicializar mat[][] con '-'
	//nReinas(mat, 0, 0);

    cout<<"1. Por coordenadas" << endl;
    cout<<"2. Graficamente" << endl;
    cout<<"3. Salir" << endl;
    cout<<"Seleccion: ";
    cin>> opcion;
      switch ( opcion ) {
      case 1:
        nReinas(mat, 0, 0);
        break;
      case 2:
        nReinasG(mat, 0, 0);
        break;
      case 3:
        cout<<"Gracias por jugar!" << endl;
        break;
      default:
        cout<<"Error, opcion no valida, saliendo" << endl;
        break;
      }
    cin.get();

	return 0;
}
