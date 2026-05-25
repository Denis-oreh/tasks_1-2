#pragma once

#include <initializer_list>
#include <string>

class SinglyLinkedList
{
private:
    struct Node
    {
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}
    };

    Node* m_head;
    size_t m_count;

public:
    // Конструкторы
    SinglyLinkedList();
    SinglyLinkedList(const std::initializer_list<int> items);
    SinglyLinkedList(const SinglyLinkedList& other);
    SinglyLinkedList(SinglyLinkedList&& other) noexcept;
    
    // Деструктор
    ~SinglyLinkedList();

    // Методы вставки
    void insertAtBeginning(int value);
    void insertAtEnd(int value);
    void insertAfterValue(int afterValue, int newValue);
    
    // Методы удаления
    void removeByValue(int value);
    
    // Методы поиска и модификации
    bool find(int value) const;
    void modifyValue(int oldValue, int newValue);
    
    // Методы доступа к информации
    bool is_empty() const;
    size_t get_size() const;
    std::string to_string() const;
    
    // Операторы
    SinglyLinkedList& operator=(const SinglyLinkedList& other);
    SinglyLinkedList& operator=(SinglyLinkedList&& other) noexcept;
    
    // Дружественные операторы ввода/вывода
    friend std::ostream& operator<<(std::ostream& os, const SinglyLinkedList& list);
    friend std::istream& operator>>(std::istream& is, SinglyLinkedList& list);
};