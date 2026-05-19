#pragma once
#include <iostream>
#include <cmath>
#include <limits>

/**
 * @brief Класс Точка (трёхмерная точка)
 */
class Point {
private:
    double x;   ///< Абсцисса точки
    double y;   ///< Ордината точки
    double z;   ///< Аппликата точки
    static const double EPS;  ///< Точность сравнения

public:
    /**
     * @brief Конструктор для класса Точка
     * @param x Абсцисса точки
     * @param y Ордината точки
     * @param z Аппликата точки
     */
    Point(double x = 0.0, double y = 0.0, double z = 0.0);

    /**
     * @brief Функция получения абсциссы точки
     * @return Значение абсциссы
     */
    double getX() const { return x; }

    /**
     * @brief Функция получения ординаты точки
     * @return Значение ординаты
     */
    double getY() const { return y; }

    /**
     * @brief Функция получения аппликаты точки
     * @return Значение аппликаты
     */
    double getZ() const { return z; }

    /**
     * @brief Функция установки абсциссы точки
     * @param val Новое значение абсциссы
     */
    void setX(double val) { x = val; }

    /**
     * @brief Функция установки ординаты точки
     * @param val Новое значение ординаты
     */
    void setY(double val) { y = val; }

    /**
     * @brief Функция установки аппликаты точки
     * @param val Новое значение аппликаты
     */
    void setZ(double val) { z = val; }

    /**
     * @brief Вычисление расстояния между двумя точками
     * @param other Другая точка
     * @return Расстояние между точками
     */
    double distanceTo(const Point& other) const;

    /**
     * @brief Перегрузка оператора сравнения (равенство)
     * @param other Другая точка
     * @return true, если точки равны, иначе false
     */
    bool operator==(const Point& other) const;

    /**
     * @brief Перегрузка оператора сравнения (неравенство)
     * @param other Другая точка
     * @return true, если точки не равны, иначе false
     */
    bool operator!=(const Point& other) const;

    /**
     * @brief Перегрузка оператора вывода (сдвиг влево)
     * @param os Поток вывода
     * @param p Объект точки
     * @return Переопределённый поток вывода
     */
    friend std::ostream& operator<<(std::ostream& os, const Point& p);

    /**
     * @brief Перегрузка оператора ввода (сдвиг вправо)
     * @param is Входной поток
     * @param p Объект точки
     * @return Переопределённый входной поток
     */
    friend std::istream& operator>>(std::istream& is, Point& p);
};