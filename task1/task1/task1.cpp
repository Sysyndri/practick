#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdlib>

// Функция для выполнения быстрой сортировки
int partition(std::vector<double>& arr, int low, int high) {
    double pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(std::vector<double>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <array elements>" << std::endl;
        return 1;
    }

    std::vector<double> arr;
    for (int i = 1; i < argc; ++i) {
        arr.push_back(std::atof(argv[i]));
    }

    // Задача 1: определение максимального и минимального элементов и их индексов
    double maxVal = arr[0];
    double minVal = arr[0];
    int maxIndex = 0;
    int minIndex = 0;

    for (size_t i = 1; i < arr.size(); ++i) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
            maxIndex = i;
        }
        if (arr[i] < minVal) {
            minVal = arr[i];
            minIndex = i;
        }
    }

    std::cout << "Max value: " << maxVal << " at index " << maxIndex << std::endl;
    std::cout << "Min value: " << minVal << " at index " << minIndex << std::endl;

    // Задача 2: вычисление суммы и произведения всех элементов
    double sum = 0.0;
    double product = 1.0;
    for (double val : arr) {
        sum += val;
        product *= val;
    }

    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Product: " << product << std::endl;

    // Задача 3: вычисление среднего арифметического и среднего геометрического
    double average = sum / arr.size();
    double geometricMean = std::pow(product, 1.0 / arr.size());

    std::cout << "Average: " << average << std::endl;
    std::cout << "Geometric Mean: " << geometricMean << std::endl;

    // Задача 4: подсчет четных и нечетных элементов
    int evenCount = 0;
    int oddCount = 0;
    for (double val : arr) {
        if (static_cast<int>(val) % 2 == 0) {
            evenCount++;
        }
        else {
            oddCount++;
        }
    }

    std::cout << "Even count: " << evenCount << std::endl;
    std::cout << "Odd count: " << oddCount << std::endl;

    // Задача 5: поиск значения, заданного пользователем
    double searchValue;
    std::cout << "Enter a value to search for: ";
    std::cin >> searchValue;

    int searchCount = 0;
    std::vector<int> searchIndices;
    for (size_t i = 0; i < arr.size(); ++i) {
        if (arr[i] == searchValue) {
            searchCount++;
            searchIndices.push_back(i);
        }
    }

    std::cout << "Value " << searchValue << " found " << searchCount << " times at indices: ";
    for (int index : searchIndices) {
        std::cout << index << " ";
    }
    std::cout << std::endl;

    // Задача 6: сортировка массива
    quickSort(arr, 0, arr.size() - 1);

    std::cout << "Sorted array (ascending): ";
    for (double val : arr) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    std::reverse(arr.begin(), arr.end());

    std::cout << "Sorted array (descending): ";
    for (double val : arr) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}