#pragma once
#include "Shape3D.h"
#include "Point.h"
#include <stdexcept>

/**
 * @brief Класс Параллелепипед (правильная фигура)
 *
 * Предусмотрены конструкторы:
 * 1. По трём вершинам (одна общая вершина и три смежные)
 * 2. По вершине и трём сторонам (длина, ширина, высота)
 * 3. По двум вершинам главной диагонали
 * 4. По двенадцати координатам (четыре вершины)
 */
class Parallelipiped : public Shape3D {
private:
    Point p1;        // Нижняя левая передняя вершина (минимальные координаты)
    Point p2;        // Верхняя правая задняя вершина (максимальные координаты)
    double length;   // Длина (по оси X)
    double width;    // Ширина (по оси Y)
    double height;   // Высота (по оси Z)

    /**
     * @brief Вспомогательный метод для обновления размеров из точек
     */
    void updateDimensions();

public:
    /**
     * @brief Конструктор по умолчанию (создаёт единичный куб)
     */
    Parallelipiped();

    /**
     * @brief Конструктор через три вершины (одна общая)
     * @param v1 Первая вершина (общая)
     * @param v2 Вторая вершина (смежная по оси X)
     * @param v3 Третья вершина (смежная по оси Y)
     * @param v4 Четвёртая вершина (смежная по оси Z)
     */
    Parallelipiped(const Point& v1, const Point& v2, const Point& v3, const Point& v4);

    /**
     * @brief Конструктор через вершину и три стороны
     * @param vertex Базовая вершина
     * @param length Длина (положительное число)
     * @param width Ширина (положительное число)
     * @param height Высота (положительное число)
     */
    Parallelipiped(const Point& vertex, double length, double width, double height);

    /**
     * @brief Конструктор через две вершины главной диагонали
     * @param minVertex Нижняя левая передняя вершина
     * @param maxVertex Верхняя правая задняя вершина
     */
    Parallelipiped(const Point& minVertex, const Point& maxVertex);

    /**
     * @brief Конструктор через 12 координат (x1 y1 z1 x2 y2 z2 x3 y3 z3 x4 y4 z4)
     * @param x1 абсцисса первой точки
     * @param y1 ордината первой точки
     * @param z1 аппликата первой точки
     * @param x2 абсцисса второй точки
     * @param y2 ордината второй точки
     * @param z2 аппликата второй точки
     * @param x3 абсцисса третьей точки
     * @param y3 ордината третьей точки
     * @param z3 аппликата третьей точки
     * @param x4 абсцисса четвёртой точки
     * @param y4 ордината четвёртой точки
     * @param z4 аппликата четвёртой точки
     */
    Parallelipiped(const double x1, const double y1, const double z1,
        const double x2, const double y2, const double z2,
        const double x3, const double y3, const double z3,
        const double x4, const double y4, const double z4);

    /**
     * @brief Функция получения минимальной вершины
     * @return Точка с минимальными координатами
     */
    Point getMinVertex()

    /**
     * @brief Функция получения максимальной вершины
     * @return Точка с максимальными координатами
     */
    Point getMaxVertex()

    /**
     * @brief Функция получения длины параллелепипеда
     * @return Длина
     */
    double getLength()

    /**
     * @brief Функция получения ширины параллелепипеда
     * @return Ширина
     */
    double getWidth()

    /**
     * @brief Функция получения высоты параллелепипеда
     * @return Высота
     */
    double getHeight()

    /**
     * @brief Функция расчёта площади поверхности параллелепипеда
     * @return Площадь поверхности (S = 2*(ab + ac + bc))
     */
    double getSurfaceArea()

    /**
     * @brief Функция расчёта объёма параллелепипеда
     * @return Объём (V = a * b * c)
     */
    double getVolume()

    /**
     * @brief Метод сериализации в строку toString
     * @return Сериализованная строка
     */
    std::string toString()

    /**
     * @brief Метод чтения из стандартного потока ввода
     * @param is Входной поток
     */
    void read(std::istream& is)
    /**
     * @brief Статический метод чтения из стандартного потока ввода
     * @param is Входной поток
     * @return Созданный объект параллелепипеда
     */
    static Parallelipiped readFrom(std::istream& is);
};
