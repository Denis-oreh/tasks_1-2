#include <iostream>
#include "RightTriangle.h"

/**
 * @brief считывает катет прямоугольного треугольника с клавиатуры
 * @param reports - строка информации
 * @return 1, если ошибка ввода; иначе - считанное значение
 */
double getSide(const std::string reports = "");

/**
 * @brief точка входа в программу
 * @return 0, если программа выполнена корректно
 */
int main()
{
    double side1 = getSide("Введите первый катет прямоугольного треугольника: ");
    double side2 = getSide("Введите второй катет прямоугольного треугольника: ");
    RightTriangle newTriangle(side1, side2);
    std::cout<<"Радиус описанной окружности прямоугольного треугольника = "<<newTriangle.getRadius()<<std::endl;
    std::cout<<"Площадь прямоугольного треугольника = "<<newTriangle.getSquare()<<std::endl;
    return 0;
}

double getSide(const std::string report)
{
    std::cout << report << std::endl;
    double side = 0;
    std::cin >> side;
    if (std::cin.fail())
    {
        std::cout<< "Error" <<std::endl;
        exit(1);
    }
    return side;
}
