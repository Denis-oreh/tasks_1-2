#pragma once

#include <initializer_list>
#include <string>

/**
 * @brief Класс, представляющий односвязный список целых чисел
*/
class SinglyLinkedList
{
private:
    /**
     * @brief Внутренняя структура узла списка
     */
    struct Node
    {
        int data;    // Значение узла
        Node* next;    // Указатель на следующий узел

        /**
         * @brief Конструктор узла
         * @param val Значение для узла
         */
        Node(int val) : data(val), next(nullptr) {}
    };

    Node* m_head;    // Указатель на первый узел списка
    size_t m_count;    // Количество элементов в списке

public:
    // Конструкторы

    /**
     * @brief Конструктор по умолчанию(пустой список)
     */
    SinglyLinkedList();

    /**
     * @brief Конструктор из списка инициализации
     * @param items Список инициализации
     */
    SinglyLinkedList(const std::initializer_list<int> items);

    /**
     * @brief Конструктор копирования
     * @param other Список для копирования
     */
    SinglyLinkedList(const SinglyLinkedList& other);

     /**
     * @brief Конструктор перемещения
     * @param other Временный список для перемещения
     */
    SinglyLinkedList(SinglyLinkedList&& other) noexcept;
    
    // Деструктор

     /**
     * @brief Освобождает всю память, занятую узлами списка
     */
    ~SinglyLinkedList();

    // Методы вставки

    /**
     * @brief Вставка элемента в начало списка
     * @param value Значение для вставки
     */
    void insertAtBeginning(const int value);

    /**
     * @brief Вставка элемента в конец списка
     * @param value Значение для вставки
     */
    void insertAtEnd(const int value);

    /**
     * @brief Вставка элемента после первого вхождения заданного значения
     * @param afterValue Значение, после которого нужно вставить
     * @param newValue Значение для вставки
     */
    void insertAfterValue(const int afterValue, const int newValue);
    
    // Методы удаления

    /**
     * @brief Удаление первого узла с заданным значением
     * @param value Значение для удаления
     */
    void removeByValue(const int value);
    
    // Методы поиска и модификации

    /**
     * @brief Поиск элемента в списке
     * @param value Значение для поиска
     * @return true - если значение найдено, false - иначе
     */
    bool find(int value) const;

    /**
     * @brief Модификация значения первого найденного узла
     * @param oldValue Искомое значение
     * @param newValue Новое значение
     */
    void modifyValue(const int oldValue, const int newValue);
    
    // Методы доступа к информации

     /**
     * @brief Проверка, пуст ли список
     * @return true - если список пуст, false - иначе
     */
    bool is_empty() const;

     /**
     * @brief Получение количества элементов в списке
     * @return Количество элементов
     */
    size_t get_size() const;

    /**
     * @brief Преобразование списка в строковое представление
     * @return Строка вида "[1, 2, 3]"
     */
    std::string to_string() const;
    
    // Операторы

    /**
     * @brief Копирующий оператор присваивания
     * @param other Список для копирования
     * @return Ссылка на текущий список
     */
    SinglyLinkedList& operator=(const SinglyLinkedList& other);

    /**
     * @brief Перемещающий оператор присваивания
     * @param other Временный список для перемещения
     * @return Ссылка на текущий список
     */
    SinglyLinkedList& operator=(SinglyLinkedList&& other) noexcept;
    
    // Дружественные операторы ввода/вывода

    /**
     * @brief Оператор вывода в поток
     * @param os Поток вывода
     * @param list Выводимый список
     * @return Ссылка на поток вывода
     */
    friend std::ostream& operator<<(std::ostream& os, const SinglyLinkedList& list);

     /**
     * @brief Оператор ввода из потока
     * @param is Поток ввода
     * @param list Список для заполнения
     * @return Ссылка на поток ввода
     */
    friend std::istream& operator>>(std::istream& is, SinglyLinkedList& list);
};
