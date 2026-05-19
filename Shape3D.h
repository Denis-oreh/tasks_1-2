#pragma once
#include <string>
#include <iostream>

/**
 * @brief Абстрактный базовый класс "Правильная фигура" (трёхмерная фигура)
 */
class Shape3D {
public:
    /**
     * @brief Виртуальный метод расчёта площади поверхности
     * @return Площадь поверхности
     */
    virtual double getSurfaceArea() const = 0;

    /**
     * @brief Виртуальный метод расчёта объёма
     * @return Объём фигуры
     */
    virtual double getVolume() const = 0;

    /**
     * @brief Виртуальный метод сериализации в строку
     * @return Строковое представление фигуры
     */
    virtual std::string toString() const = 0;

    /**
     * @brief Виртуальный метод чтения из потока
     * @param is Входной поток
     */
    virtual void read(std::istream& is) = 0;

    /**
     * @brief Виртуальный деструктор
     */
    virtual ~Shape3D() = default;

    /**
     * @brief Перегрузка оператора вывода (сдвиг влево)
     * @param os Поток вывода
     * @param shape Объект фигуры
     * @return Переопределённый поток вывода
     */
    friend std::ostream& operator<<(std::ostream& os, const Shape3D& shape) {
        os << shape.toString();
        return os;
    }

    /**
     * @brief Перегрузка оператора ввода (сдвиг вправо)
     * @param is Входной поток
     * @param shape Объект фигуры
     * @return Переопределённый входной поток
     */
    friend std::istream& operator>>(std::istream& is, Shape3D& shape) {
        shape.read(is);
        return is;
    }
};