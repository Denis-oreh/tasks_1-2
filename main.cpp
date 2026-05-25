#include <iostream>
#include <string>
#include <limits>
#include "SinglyLinkedList.h"

void showMenu()
{
    std::cout << "\n========== МЕНЮ ==========\n";
    std::cout << "NACHALO - Добавить в начало\n";
    std::cout << "KONEC - Добавить в конец\n";
    std::cout << "DOBAVITb - Добавить после значения\n";
    std::cout << "YDALITb - Удалить по значению\n";
    std::cout << "POISK - Найти значение\n";
    std::cout << "SMENA - Изменить значение\n";
    std::cout << "SPISOK - Вывести список\n";
    std::cout << "RAZMER - Показать размер и статус\n";
    std::cout << "EXIT - Выход\n";
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
        case NACHALO:
            std::cout << "Введите значение для добавления в начало: ";
            std::cin >> val;
            list.insertAtBeginning(val);
            std::cout << "Список после добавления: " << list << std::endl;
            break;
            
        case KONEC:
            std::cout << "Введите значение для добавления в конец: ";
            std::cin >> val;
            list.insertAtEnd(val);
            std::cout << "Список после добавления: " << list << std::endl;
            break;
            
        case DOBAVITb:
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
            
        case YDALITb:
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
            
        case POISK:
            std::cout << "Введите значение для поиска: ";
            std::cin >> val;
            if (list.find(val))
                std::cout << "Значение " << val << " найдено в списке" << std::endl;
            else
                std::cout << "Значение " << val << " не найдено" << std::endl;
            break;
            
        case SMENA:
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
            
        case SPISOK:
            std::cout << "Текущий список: " << list << std::endl;
            break;
            
        case RAZMER:
            std::cout << "Размер списка: " << list.get_size() << std::endl;
            std::cout << "Список пуст? " << (list.is_empty() ? "Да" : "Нет") << std::endl;
            break;
            
        case EXIT:
            std::cout << "Выход из программы" << std::endl;
            break;
            
        default:
            std::cout << "Неверный выбор! Пожалуйста, выберите 0-8" << std::endl;
        }
    } while (choice != 0);
    
    return 0;
}
