#include <gtest/gtest.h>
#include "SinglyLinkedList.h"

// Тест константности методов
TEST(SinglyLinkedListTest, ConstMethodsTest)
{
    const SinglyLinkedList constList = {1, 2, 3};
    
    // Эти методы должны работать с const объектом
    EXPECT_EQ(constList.get_size(), 3);
    EXPECT_FALSE(constList.is_empty());
    EXPECT_EQ(constList.to_string(), "1 2 3");
    EXPECT_TRUE(constList.find(2));
    EXPECT_FALSE(constList.find(5));
    
    // Оператор вывода тоже должен работать с const
    std::stringstream ss;
    ss << constList;
    EXPECT_EQ(ss.str(), "1 2 3");
}

// Остальные тесты...
TEST(SinglyLinkedListTest, DefaultConstructor)
{
    SinglyLinkedList list;
    EXPECT_TRUE(list.is_empty());
    EXPECT_EQ(list.get_size(), 0);
    EXPECT_EQ(list.to_string(), "Empty");
}

TEST(SinglyLinkedListTest, InitializerListConstructor)
{
    SinglyLinkedList list = {1, 2, 3};
    EXPECT_EQ(list.get_size(), 3);
    EXPECT_EQ(list.to_string(), "1 2 3");
    EXPECT_FALSE(list.is_empty());
}

TEST(SinglyLinkedListTest, InsertAtBeginning)
{
    SinglyLinkedList list = {2, 3};
    list.insertAtBeginning(1);
    EXPECT_EQ(list.to_string(), "1 2 3");
    EXPECT_EQ(list.get_size(), 3);
}

TEST(SinglyLinkedListTest, InsertAtEnd)
{
    SinglyLinkedList list = {1, 2};
    list.insertAtEnd(3);
    EXPECT_EQ(list.to_string(), "1 2 3");
    EXPECT_EQ(list.get_size(), 3);
}

TEST(SinglyLinkedListTest, InsertAfterValue)
{
    SinglyLinkedList list = {1, 3};
    list.insertAfterValue(1, 2);
    EXPECT_EQ(list.to_string(), "1 2 3");
    EXPECT_EQ(list.get_size(), 3);
}

TEST(SinglyLinkedListTest, InsertAfterValueNotFound)
{
    SinglyLinkedList list = {1, 2, 3};
    EXPECT_THROW(list.insertAfterValue(5, 99), std::out_of_range);
}

TEST(SinglyLinkedListTest, RemoveByValue)
{
    SinglyLinkedList list = {1, 2, 3};
    list.removeByValue(2);
    EXPECT_EQ(list.to_string(), "1 3");
    EXPECT_EQ(list.get_size(), 2);
}

TEST(SinglyLinkedListTest, RemoveHead)
{
    SinglyLinkedList list = {1, 2, 3};
    list.removeByValue(1);
    EXPECT_EQ(list.to_string(), "2 3");
    EXPECT_EQ(list.get_size(), 2);
}

TEST(SinglyLinkedListTest, RemoveNotFound)
{
    SinglyLinkedList list = {1, 2, 3};
    EXPECT_THROW(list.removeByValue(99), std::out_of_range);
}

TEST(SinglyLinkedListTest, Find)
{
    SinglyLinkedList list = {5, 10, 15};
    EXPECT_TRUE(list.find(10));
    EXPECT_FALSE(list.find(99));
}

TEST(SinglyLinkedListTest, ModifyValue)
{
    SinglyLinkedList list = {1, 2, 3};
    list.modifyValue(2, 99);
    EXPECT_EQ(list.to_string(), "1 99 3");
}

TEST(SinglyLinkedListTest, ModifyValueNotFound)
{
    SinglyLinkedList list = {1, 2, 3};
    EXPECT_THROW(list.modifyValue(5, 99), std::out_of_range);
}

TEST(SinglyLinkedListTest, CopyConstructor)
{
    SinglyLinkedList list1 = {1, 2, 3};
    SinglyLinkedList list2 = list1;
    
    // Проверка независимости
    list2.modifyValue(1, 99);
    EXPECT_EQ(list1.to_string(), "1 2 3");
    EXPECT_EQ(list2.to_string(), "99 2 3");
}

TEST(SinglyLinkedListTest, CopyAssignment)
{
    SinglyLinkedList list1 = {1, 2, 3};
    SinglyLinkedList list2;
    list2 = list1;
    
    EXPECT_EQ(list2.to_string(), "1 2 3");
    
    // Проверка независимости
    list2.modifyValue(1, 99);
    EXPECT_EQ(list1.to_string(), "1 2 3");
}

TEST(SinglyLinkedListTest, MoveConstructor)
{
    SinglyLinkedList list1 = {1, 2, 3};
    SinglyLinkedList list2 = std::move(list1);
    
    EXPECT_TRUE(list1.is_empty());
    EXPECT_EQ(list1.get_size(), 0);
    EXPECT_EQ(list2.to_string(), "1 2 3");
}

TEST(SinglyLinkedListTest, MoveAssignment)
{
    SinglyLinkedList list1 = {1, 2, 3};
    SinglyLinkedList list2;
    list2 = std::move(list1);
    
    EXPECT_TRUE(list1.is_empty());
    EXPECT_EQ(list2.to_string(), "1 2 3");
}

TEST(SinglyLinkedListTest, EmptyListOperations)
{
    SinglyLinkedList list;
    EXPECT_TRUE(list.is_empty());
    EXPECT_EQ(list.get_size(), 0);
    EXPECT_EQ(list.to_string(), "Empty");
    
    // Вставка в пустой список
    list.insertAtBeginning(10);
    EXPECT_EQ(list.to_string(), "10");
    
    list.removeByValue(10);
    EXPECT_TRUE(list.is_empty());
}

TEST(SinglyLinkedListTest, StreamOperator)
{
    SinglyLinkedList list;
    std::stringstream input("42");
    input >> list;
    
    EXPECT_EQ(list.to_string(), "42");
}