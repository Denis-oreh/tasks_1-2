#include <iostream>
#include <vector>
#include <memory>
#include "Parallelipiped.h"
#include "Shape3D.h"

using namespace std;

/**
 * @brief Точка входа в программу
 * @return 0, если программа выполнена корректно, иначе 1
 */
int main() {
    cout << "=== Демонстрация работы класса Параллелепипед ===\n\n";

    // 1. Создание единичного куба по умолчанию
    cout << "1. Создание единичного куба (1x1x1) конструктором по умолчанию:\n";
    Parallelipiped defaultCube;
    cout << defaultCube << endl;
    cout << "Объём: " << defaultCube.getVolume() << endl;
    cout << "Площадь поверхности: " << defaultCube.getSurfaceArea() << endl << endl;

    // 2. Создание по вершине и размерам
    cout << "2. Создание параллелепипеда по вершине (0,0,0) и размерам (2, 3, 4):\n";
    Parallelipiped byDimensions(Point(0, 0, 0), 2.0, 3.0, 4.0);
    cout << byDimensions << endl << endl;

    // 3. Создание по двум вершинам главной диагонали
    cout << "3. Создание параллелепипеда по двум вершинам главной диагонали:\n";
    Parallelipiped byDiagonal(Point(0, 0, 0), Point(5, 4, 3));
    cout << byDiagonal << endl << endl;

    // 4. Создание по трём вершинам (общая вершина и смежные)
    cout << "4. Создание параллелепипеда по трём вершинам (общий угол):\n";
    Parallelipiped byVertices(Point(1, 1, 1), Point(4, 1, 1), Point(1, 3, 1), Point(1, 1, 5));
    cout << byVertices << endl << endl;

    // 5. Создание по 12 координатам
    cout << "5. Создание параллелепипеда по 12 координатам:\n";
    Parallelipiped byCoords(0, 0, 0, 3, 0, 0, 0, 4, 0, 0, 0, 5);
    cout << byCoords << endl << endl;

    // 6. Полиморфная коллекция (базовый класс Shape3D)
    cout << "6. Полиморфная коллекция фигур (вектор указателей на базовый класс):\n";
    vector<unique_ptr<Shape3D>> shapes;
    shapes.push_back(make_unique<Parallelipiped>(Point(0, 0, 0), 2.0, 2.0, 2.0));
    shapes.push_back(make_unique<Parallelipiped>(Point(0, 0, 0), 3.0, 4.0, 5.0));
    shapes.push_back(make_unique<Parallelipiped>(Point(1, 1, 1), Point(4, 3, 2)));

    for (size_t i = 0; i < shapes.size(); ++i) {
        cout << "\nФигура " << i + 1 << ":\n";
        cout << *shapes[i] << endl;
        cout << "  Площадь поверхности: " << shapes[i]->getSurfaceArea()
            << ", Объём: " << shapes[i]->getVolume() << endl;
    }

    // 7. Проверка обработки исключений
    cout << "\n7. Проверка обработки исключений (неположительные размеры):\n";
    try {
        cout << "   Попытка создать параллелепипед с отрицательной длиной...\n";
        Parallelipiped invalid(Point(0, 0, 0), -1.0, 2.0, 3.0);
    }
    catch (const std::invalid_argument& e) {
        cout << "   Исключение: " << e.what() << endl;
    }

    try {
        cout << "   Попытка создать параллелепипед с нулевой шириной...\n";
        Parallelipiped invalid(Point(0, 0, 0), 2.0, 0.0, 3.0);
    }
    catch (const std::invalid_argument& e) {
        cout << "   Исключение: " << e.what() << endl;
    }

    cout << "\n8. Интерактивное создание (раскомментируйте для использования):\n";
    cout << "   // Parallelipiped custom;\n";
    cout << "   // cin >> custom;\n";
    cout << "   // cout << custom << endl;\n";

    return 0;
}