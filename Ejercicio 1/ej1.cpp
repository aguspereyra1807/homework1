#include "ej1.hpp"

// a)
int **createMatrix(int n) {
    if (n < 1) {
        cout << "Dimensión inválida\n";
        return NULL;
    }

    int x = 1;

    int **matrix = (int**)malloc(n*sizeof(int*));
    if (!matrix) return NULL;

    for (int i = 0; i<n; i++) {
        int *row = (int*)malloc(n*sizeof(int));
        if (!row) return NULL;
        for (int j = 0; j<n; j++) {
            row[j] = x;
            x++;
        }
        matrix[i] = row;
    }
    return matrix;
}

void destroyMatrix(int **matrix, int n) {
    for (int i = 0; i<n; i++) {
        free(matrix[i]);
        matrix[i] = nullptr;
    }
    free(matrix);
    matrix = nullptr;
}

// b)
void printMatrix(int **matrix, int n) {
    int row = n - 1, col = n - 1;

    while (row >= 0) {
        cout << "M" << n << "[" << row << "]" << "[" << col << "]" << "=" << matrix[row][col] << "\n";
        
        if (col == 0) {
            col = n - 1;
            row--;
        }
        else col--;
    }
}

int main() {
    int n;
    cout << "Ingrese la dimensión de la matriz:\n> ";
    cin >> n;
    int **matrix = createMatrix(n);
    if (matrix) {
        printMatrix(matrix, n);
        destroyMatrix(matrix, n);
    }
    return 0;
}