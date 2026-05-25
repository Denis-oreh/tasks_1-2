#include <iostream>
#include <string>
#include <limits>
#include "SinglyLinkedList.h"

void showMenu()
{
    std::cout << "\n========== МЕНЮ ==========\n";
    std::cout << "1 - Добавить в начало\n";
    std::cout << "2 - Добавить в конец\n";
    std::cout << "3 - Добавить после значения\n";
    std::cout << "4 - Удалить по значению\n";
    std::cout << "5 - Найти значение\n";
    std::cout << "6 - Изменить значение\n";
    std::cout << "7 - Вывести список\n";
    std::cout << "8 - Показать размер и статус\n";
    std::cout << "0 - Выход\n";
    std::cout << "Ваш выбор: ";
}

int main()
{
    // Демонстрация работы со списком инициализации
    SinglyLinkedList list = {10, 20, 30, 40};
    std::cout << "Начальный список: " << list << std::endl;
    std::cout << "Размер списка: " << list.get_size() << std::endl;
    std::cout << "Список пуст? " << (list.is_empty() ? "Да" : "Нет") << std::endl;
    
    int choice, val, oldVal, newVal;
    
    do
    {
        showMenu();
        std::cin >> choice;
        
        // Очистка буфера ввода при некорректном вводе
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Ошибка ввода! Попробуйте снова.\n";
            continue;
        }
        
        switch (choice)
        {
        case 1:
            std::cout << "Введите значение для добавления в начало: ";
            std::cin >> val;
            list.insertAtBeginning(val);
            std::cout << "Список после добавления: " << list << std::endl;
            break;
            
        case 2:
            std::cout << "Введите значение для добавления в конец: ";
            std::cin >> val;
            list.insertAtEnd(val);
            std::cout << "Список после добавления: " << list << std::endl;
            break;
            
        case 3:
            std::cout << "После какого значения вставить: ";
            std::cin >> oldVal;
            std::cout << "Какое значение вставить: ";
            std::cin >> newVal;
            try
            {
                list.insertAfterValue(oldVal, newVal);
                std::cout << "Список после вставки: " << list << std::endl;
            }
            catch (const std::exception& e)
            {
                std::cout << "Ошибка: " << e.what() << std::endl;
            }
            break;
            
        case 4:
            std::cout << "Введите значение для удаления: ";
            std::cin >> val;
            try
            {
                list.removeByValue(val);
                std::cout << "Список после удаления: " << list << std::endl;
            }
            catch (const std::exception& e)
            {
                std::cout << "Ошибка: " << e.what() << std::endl;
            }
            break;
            
        case 5:
            std::cout << "Введите значение для поиска: ";
            std::cin >> val;
            if (list.find(val))
                std::cout << "Значение " << val << " найдено в списке" << std::endl;
            else
                std::cout << "Значение " << val << " не найдено" << std::endl;
            break;
            
        case 6:
            std::cout << "Какое значение заменить: ";
            std::cin >> oldVal;
            std::cout << "На какое значение заменить: ";
            std::cin >> newVal;
            try
            {
                list.modifyValue(oldVal, newVal);
                std::cout << "Список после изменения: " << list << std::endl;
            }
            catch (const std::exception& e)
            {
                std::cout << "Ошибка: " << e.what() << std::endl;
            }
            break;
            
        case 7:
            std::cout << "Текущий список: " << list << std::endl;
            break;
            
        case 8:
            std::cout << "Размер списка: " << list.get_size() << std::endl;
            std::cout << "Список пуст? " << (list.is_empty() ? "Да" : "Нет") << std::endl;
            break;
            
        case 0:
            std::cout << "Выход из программы" << std::endl;
            break;
            
        default:
            std::cout << "Неверный выбор! Пожалуйста, выберите 0-8" << std::endl;
        }
    } while (choice != 0);
    
    return 0;
}