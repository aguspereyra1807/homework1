#include <iostream>
using namespace std;

// Crea una matriz cuadrada de [n] x [n] como un array de arrays de enteros. Completando los celdas del 1 a n^2
int **createMatrix(int n);

// Imprime una matriz cuadrada a partir de un solo bucle, de la celda [n][n] a la [0][0] indicando a que fila y columna le corresponde cada una
void destroyMatrix(int **matrix, int n); 