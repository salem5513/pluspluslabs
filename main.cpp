#include <iostream>
using namespace std;
/*створити матрицю m x n, якщо матриця квадратна порахувату сумму елементів
 верхнього трикутнка матриці */


//create
int** createMatrix(int n, int m) {
    int** matrix = new int*[n]; //масив вказівників
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[m];
    }

    cout << "Введіть елементи матриці:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    return matrix; //повернули вказівник
}

//print
void printMatrix(int** matrix, int n, int m) {
    cout << "Ваша матриця:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int sum_Matrix(int** matrix, int N) {
    int sum = 0;
    for (int i = 0; i < N / 2; i++) {
        for (int j = i + 1; j < N - i - 1; j++) {
            sum += matrix[i][j];
        }
    }
    return sum;
}

int main() {
    int n, m;
    cout << "Введіть кількість рядків (n): ";
    cin >> n;
    cout << "Введіть кількість стовпців (m): ";
    cin >> m;

    // Створюємо матрицю
    int** matrix = createMatrix(n, m);

    // Виводимо матрицю
    printMatrix(matrix, n, m);
    if (n == m) {
        cout << "Сума  елементів верхнього трикутника: " << sum_Matrix(matrix, n) << endl;
    } else {
        cout << "Матриця не квадратна" << endl;
    }
    // Звільняємо пам'ять
    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
