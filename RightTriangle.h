#pragma once
/**
* @brief класс "прямоугольный треугольник"
 */
class RightTriangle
{
private:
    /**
     * @brief первый катет прямоугольного треугольника
     */
    double side1;
    /**
     * @brief второй катет прямоугольного треугольника
     */
    double side2;

public:
    /**
     * @brief конструктор
     * @param side1 - первый катет прямоугольного треугольника
     * @param side2 - второй катет прямоугольного треугольника
     */
    RightTriangle(const double side1, const double side2);

    /**
     * @brief расчёт радиуса описанной окружности
     * @return рассчитанное значение
     */
    double getRadius() const;

    /**
     * @brief расчёт площади прямоугольного треугольника
     * @return рассчитанное значение
     */
    double getSquare() const;
}