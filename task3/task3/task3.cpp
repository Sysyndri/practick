#include <iostream>
#include <fstream>
#include <queue>
#include <string>

void printLastNLines(const std::string& filename, int n) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    std::queue<std::string> lastLines;
    std::string line;

    // Чтение файла строка за строкой
    while (std::getline(file, line)) {
        lastLines.push(line);
        if (lastLines.size() > n) {
            lastLines.pop(); // Удаление первой строки, если количество строк больше n
        }
    }

    // Вывод последних n строк
    while (!lastLines.empty()) {
        std::cout << lastLines.front() << std::endl;
        lastLines.pop();
    }

    file.close();
}

int main() {
    std::string filename;
    int n;

    std::cout << "Enter the name of the file: ";
    std::cin >> filename;

    std::cout << "Enter the number of last lines to print: ";
    std::cin >> n;

    printLastNLines(filename, n);

    return 0;
}