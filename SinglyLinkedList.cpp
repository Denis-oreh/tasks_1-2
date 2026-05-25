#include "SinglyLinkedList.h"
#include <sstream>
#include <stdexcept>
#include <iostream>

// Конструктор по умолчанию
SinglyLinkedList::SinglyLinkedList() : m_head(nullptr), m_count(0) {}

// Конструктор со списком инициализации
SinglyLinkedList::SinglyLinkedList(const std::initializer_list<int> items)
    : m_head(nullptr), m_count(0)
{
    for (const int& val : items)
        insertAtEnd(val);
}

// Конструктор копирования
SinglyLinkedList::SinglyLinkedList(const SinglyLinkedList& other)
    : m_head(nullptr), m_count(0)
{
    const Node* current = other.m_head;
    while (current)
    {
        insertAtEnd(current->data);
        current = current->next;
    }
}

// Конструктор перемещения
SinglyLinkedList::SinglyLinkedList(SinglyLinkedList&& other) noexcept
    : m_head(other.m_head), m_count(other.m_count)
{
    other.m_head = nullptr;
    other.m_count = 0;
}

// Деструктор
SinglyLinkedList::~SinglyLinkedList()
{
    while (m_head)
    {
        Node* temp = m_head;
        m_head = m_head->next;
        delete temp;
    }
}

// Вставка в начало
void SinglyLinkedList::insertAtBeginning(int value)
{
    Node* newNode = new Node(value);
    newNode->next = m_head;
    m_head = newNode;
    m_count++;
}

// Вставка в конец
void SinglyLinkedList::insertAtEnd(int value)
{
    Node* newNode = new Node(value);
    if (!m_head)
    {
        m_head = newNode;
    }
    else
    {
        Node* current = m_head;
        while (current->next)
            current = current->next;
        current->next = newNode;
    }
    m_count++;
}

// Вставка после значения
void SinglyLinkedList::insertAfterValue(int afterValue, int newValue)
{
    Node* current = m_head;
    while (current && current->data != afterValue)
        current = current->next;

    if (!current)
        throw std::out_of_range("Значение для вставки после не найдено");

    Node* newNode = new Node(newValue);
    newNode->next = current->next;
    current->next = newNode;
    m_count++;
}

// Удаление по значению
void SinglyLinkedList::removeByValue(int value)
{
    if (!m_head)
        throw std::out_of_range("Список пуст");

    if (m_head->data == value)
    {
        Node* temp = m_head;
        m_head = m_head->next;
        delete temp;
        m_count--;
        return;
    }

    Node* current = m_head;
    while (current->next && current->next->data != value)
        current = current->next;

    if (!current->next)
        throw std::out_of_range("Значение не найдено");

    Node* temp = current->next;
    current->next = current->next->next;
    delete temp;
    m_count--;
}

// Поиск значения
bool SinglyLinkedList::find(int value) const
{
    Node* current = m_head;
    while (current)
    {
        if (current->data == value)
            return true;
        current = current->next;
    }
    return false;
}

// Модификация значения
void SinglyLinkedList::modifyValue(int oldValue, int newValue)
{
    Node* current = m_head;
    while (current && current->data != oldValue)
        current = current->next;

    if (!current)
        throw std::out_of_range("Значение для модификации не найдено");

    current->data = newValue;
}

// Проверка на пустоту
bool SinglyLinkedList::is_empty() const
{
    return m_count == 0;
}

// Получение размера
size_t SinglyLinkedList::get_size() const
{
    return m_count;
}

// Преобразование в строку
std::string SinglyLinkedList::to_string() const
{
    if (is_empty())
        return "Empty";

    std::stringstream ss;
    Node* current = m_head;
    while (current)
    {
        ss << current->data;
        if (current->next)
            ss << " ";
        current = current->next;
    }
    return ss.str();
}

// Оператор присваивания (копирование)
SinglyLinkedList& SinglyLinkedList::operator=(const SinglyLinkedList& other)
{
    if (this != &other)
    {
        // Очистка текущего списка
        while (m_head)
        {
            Node* temp = m_head;
            m_head = m_head->next;
            delete temp;
        }
        m_count = 0;

        // Копирование из other
        const Node* current = other.m_head;
        while (current)
        {
            insertAtEnd(current->data);
            current = current->next;
        }
    }
    return *this;
}

// Оператор присваивания (перемещение)
SinglyLinkedList& SinglyLinkedList::operator=(SinglyLinkedList&& other) noexcept
{
    if (this != &other)
    {
        // Очистка текущего списка
        while (m_head)
        {
            Node* temp = m_head;
            m_head = m_head->next;
            delete temp;
        }
        
        // Перемещение данных
        m_head = other.m_head;
        m_count = other.m_count;
        
        // Обнуление другого объекта
        other.m_head = nullptr;
        other.m_count = 0;
    }
    return *this;
}

// Оператор вывода
std::ostream& operator<<(std::ostream& os, const SinglyLinkedList& list)
{
    os << list.to_string();
    return os;
}

// Оператор ввода
std::istream& operator>>(std::istream& is, SinglyLinkedList& list)
{
    int value;
    if (is >> value)
        list.insertAtEnd(value);
    return is;
}