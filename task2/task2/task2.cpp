#include <iostream>
#include <vector>
#include <algorithm>

// Функция для ввода матрицы
void inputMatrix(std::vector<std::vector<int>>& matrix, int rows, int cols) {
    std::cout << "Enter the matrix elements:\n";
    for (int i = 0; i < rows; ++i) {
        matrix.push_back(std::vector<int>());
        for (int j = 0; j < cols; ++j) {
            int value;
            std::cin >> value;
            matrix[i].push_back(value);
        }
    }
}

// Функция для вывода матрицы
void printMatrix(const std::vector<std::vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int value : row) {
            std::cout << value << " ";
        }
        std::cout << "\n";
    }
}

// Функция для транспонирования матрицы
std::vector<std::vector<int>> transposeMatrix(const std::vector<std::vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    std::vector<std::vector<int>> transposed(cols, std::vector<int>(rows));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            transposed[j][i] = matrix[i][j];
        }
    }
    return transposed;
}

// Функция для вычисления ранга матрицы (для простоты, предполагаем, что ранг не может быть больше размера самой матрицы)
int calculateRank(const std::vector<std::vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    int rank = std::min(rows, cols);

    // Проверка на квадратную матрицу и вычисление ранга
    if (rows == cols) {
        for (int i = 0; i < rank; ++i) {
            if (matrix[i][i] == 0) {
                rank--;
                break;
            }
        }
    }
    return rank;
}

// Функция для проверки равенства двух матриц
bool areMatricesEqual(const std::vector<std::vector<int>>& matrix1, const std::vector<std::vector<int>>& matrix2) {
    if (matrix1.size() != matrix2.size() || matrix1[0].size() != matrix2[0].size()) {
        return false;
    }

    for (size_t i = 0; i < matrix1.size(); ++i) {
        for (size_t j = 0; j < matrix1[0].size(); ++j) {
            if (matrix1[i][j] != matrix2[i][j]) {
                return false;
            }
        }
    }
    return true;
}

// Функция для сложения двух матриц
std::vector<std::vector<int>> addMatrices(const std::vector<std::vector<int>>& matrix1, const std::vector<std::vector<int>>& matrix2) {
    int rows = matrix1.size();
    int cols = matrix1[0].size();
    std::vector<std::vector<int>> result(rows, std::vector<int>(cols));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    return result;
}

// Функция для умножения двух матриц
std::vector<std::vector<int>> multiplyMatrices(const std::vector<std::vector<int>>& matrix1, const std::vector<std::vector<int>>& matrix2) {
    int rows1 = matrix1.size();
    int cols1 = matrix1[0].size();
    int cols2 = matrix2[0].size();
    std::vector<std::vector<int>> result(rows1, std::vector<int>(cols2, 0));

    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols2; ++j) {
            for (int k = 0; k < cols1; ++k) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    return result;
}

int main() {
    int rows1, cols1, rows2, cols2;

    // Ввод размеров первой матрицы
    std::cout << "Enter the number of rows for the first matrix: ";
    std::cin >> rows1;
    std::cout << "Enter the number of columns for the first matrix: ";
    std::cin >> cols1;

    // Ввод первой матрицы
    std::vector<std::vector<int>> matrix1;
    inputMatrix(matrix1, rows1, cols1);

    // Ввод размеров второй матрицы
    std::cout << "Enter the number of rows for the second matrix: ";
    std::cin >> rows2;
    std::cout << "Enter the number of columns for the second matrix: ";
    std::cin >> cols2;

    // Ввод второй матрицы
    std::vector<std::vector<int>> matrix2;
    inputMatrix(matrix2, rows2, cols2);

    // Определение рангов матриц
    int rank1 = calculateRank(matrix1);
    int rank2 = calculateRank(matrix2);
    std::cout << "Rank of the first matrix: " << rank1 << "\n";
    std::cout << "Rank of the second matrix: " << rank2 << "\n";

    // Транспонирование матриц
    std::vector<std::vector<int>> transposed1 = transposeMatrix(matrix1);
    std::vector<std::vector<int>> transposed2 = transposeMatrix(matrix2);

    std::cout << "Transposed first matrix:\n";
    printMatrix(transposed1);
    std::cout << "Transposed second matrix:\n";
    printMatrix(transposed2);

    // Проверка на равенство, сложение и умножение матриц
    if (areMatricesEqual(matrix1, matrix2)) {
        std::cout << "Matrices are equal.\n";
    }
    else {
        std::cout << "Matrices are not equal.\n";
    }

    if (rows1 == rows2 && cols1 == cols2) {
        std::vector<std::vector<int>> sum = addMatrices(matrix1, matrix2);
        std::cout << "Sum of the matrices:\n";
        printMatrix(sum);
    }
    else {
        std::cout << "Cannot add matrices: matrices must have the same dimensions.\n";
    }

    if (cols1 == rows2) {
        std::vector<std::vector<int>> product = multiplyMatrices(matrix1, matrix2);
        std::cout << "Product of the matrices:\n";
        printMatrix(product);
    }
    else {
        std::cout << "Cannot multiply matrices: number of columns in the first matrix must match the number of rows in the second matrix.\n";
    }
    }