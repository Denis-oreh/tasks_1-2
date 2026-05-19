#include <gtest/gtest.h>
#include <sstream>
#include "Parallelipiped.h"

/**
 * @brief Класс для тестирования параллелепипеда
 */
class ParallelipipedTest : public ::testing::Test {
protected:
    void SetUp() override {
        куб = Parallelipiped(Point(0, 0, 0), 1.0, 1.0, 1.0);
        коробка = Parallelipiped(Point(0, 0, 0), 2.0, 3.0, 4.0);
    }
    Parallelipiped куб;
    Parallelipiped коробка;
};

/**
 * @brief Тест конструктора по вершине и размерам
 */
TEST_F(ParallelipipedTest, КонструкторПоВершинеИРазмерам) {
    EXPECT_NEAR(куб.getVolume(), 1.0, 0.0001);
    EXPECT_NEAR(куб.getSurfaceArea(), 6.0, 0.0001);
    EXPECT_NEAR(коробка.getVolume(), 24.0, 0.0001);
    EXPECT_NEAR(коробка.getSurfaceArea(), 52.0, 0.0001);
}

/**
 * @brief Тест конструктора по двум вершинам диагонали
 */
TEST_F(ParallelipipedTest, КонструкторПоДвумВершинамДиагонали) {
    Parallelipiped диагональ(Point(0, 0, 0), Point(3, 2, 1));
    EXPECT_NEAR(диагональ.getLength(), 3.0, 0.0001);
    EXPECT_NEAR(диагональ.getWidth(), 2.0, 0.0001);
    EXPECT_NEAR(диагональ.getHeight(), 1.0, 0.0001);
    EXPECT_NEAR(диагональ.getVolume(), 6.0, 0.0001);
}

/**
 * @brief Тест конструктора по трём вершинам
 */
TEST_F(ParallelipipedTest, КонструкторПоТрёмВершинам) {
    Parallelipiped п(Point(1, 1, 1), Point(4, 1, 1), Point(1, 3, 1), Point(1, 1, 5));
    EXPECT_NEAR(п.getLength(), 3.0, 0.0001);
    EXPECT_NEAR(п.getWidth(), 2.0, 0.0001);
    EXPECT_NEAR(п.getHeight(), 4.0, 0.0001);
}

/**
 * @brief Тест конструктора по 12 координатам
 */
TEST_F(ParallelipipedTest, КонструкторПоКоординатам) {
    Parallelipiped п(0, 0, 0, 5, 0, 0, 0, 3, 0, 0, 0, 2);
    EXPECT_NEAR(п.getLength(), 5.0, 0.0001);
    EXPECT_NEAR(п.getWidth(), 3.0, 0.0001);
    EXPECT_NEAR(п.getHeight(), 2.0, 0.0001);
}

/**
 * @brief Тест исключения при отрицательных размерах
 */
TEST_F(ParallelipipedTest, ОтрицательныеРазмерыИсключение) {
    EXPECT_THROW(Parallelipiped(Point(0, 0, 0), -1.0, 2.0, 3.0), std::invalid_argument);
    EXPECT_THROW(Parallelipiped(Point(0, 0, 0), 1.0, -2.0, 3.0), std::invalid_argument);
    EXPECT_THROW(Parallelipiped(Point(0, 0, 0), 1.0, 2.0, -3.0), std::invalid_argument);
}

/**
 * @brief Тест исключения при нулевых размерах
 */
TEST_F(ParallelipipedTest, НулевыеРазмерыИсключение) {
    EXPECT_THROW(Parallelipiped(Point(0, 0, 0), 0.0, 2.0, 3.0), std::invalid_argument);
    EXPECT_THROW(Parallelipiped(Point(0, 0, 0), 1.0, 0.0, 3.0), std::invalid_argument);
    EXPECT_THROW(Parallelipiped(Point(0, 0, 0), 1.0, 2.0, 0.0), std::invalid_argument);
}

/**
 * @brief Тест исключения при неверном порядке вершин диагонали
 */
TEST_F(ParallelipipedTest, НеверныйПорядокВершинДиагоналиИсключение) {
    EXPECT_THROW(Parallelipiped(Point(5, 0, 0), Point(0, 0, 0)), std::invalid_argument);
}

/**
 * @brief Тест метода toString
 */
TEST_F(ParallelipipedTest, МетодToString) {
    std::string str = куб.toString();
    EXPECT_FALSE(str.empty());
    EXPECT_TRUE(str.find("Параллелепипед") != std::string::npos);
    EXPECT_TRUE(str.find("объём") != std::string::npos);
}

/**
 * @brief Тест метода чтения из потока
 */
TEST_F(ParallelipipedTest, МетодЧтенияИзПотока) {
    std::stringstream ss;
    ss << "2\n0 0 0\n2.5 3.5 4.5\n";

    Parallelipiped п;
    п.read(ss);

    EXPECT_NEAR(п.getLength(), 2.5, 0.0001);
    EXPECT_NEAR(п.getWidth(), 3.5, 0.0001);
    EXPECT_NEAR(п.getHeight(), 4.5, 0.0001);
}

/**
 * @brief Тест операторов ввода/вывода
 */
TEST_F(ParallelipipedTest, ОператорыВводаВывода) {
    std::stringstream ss;
    ss << куб;
    std::string вывод = ss.str();
    EXPECT_FALSE(вывод.empty());
}

/**
 * @brief Тест класса Точка
 */
TEST(PointTest, ОператорыТочки) {
    Point p1(1, 2, 3);
    Point p2(1, 2, 3);
    Point p3(4, 5, 6);

    EXPECT_TRUE(p1 == p2);
    EXPECT_TRUE(p1 != p3);
    EXPECT_NEAR(p1.distanceTo(p3), std::sqrt(27), 0.0001);
}

/**
 * @brief Главная функция тестирования
 */
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}