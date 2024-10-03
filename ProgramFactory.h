#ifndef PROGRAMFACTORY_H
#define PROGRAMFACTORY_H

#include "Factory.h"

#include <iostream>

class ProgramFactory
{
public:
    // Конструктор, принимающий уникальный указатель на фабрику (factory)
    ProgramFactory(std::unique_ptr<factory> fac)
    {
        // Перемещаем указатель на фабрику в член-данные f
        f = std::move(fac);
    }

    // Метод для генерации первой программы
    std::string GenerateProgram_1()
    {
        // Выводим сообщение о начале первого теста
        std::cout<<"FIRST TEST\n\n";

        // Создаем класс myClass с помощью фабрики
        auto myClass = f->Create_Class("myClass");

        // Добавляем методы в класс myClass
        myClass->add(f->Create_Method("testFunc1", "void", 0), ClassUnit::PUBLIC);
        myClass->add(f->Create_Method("testFunc2", "void", MethodUnit::STATIC), ClassUnit::PRIVATE);
        myClass->add(f->Create_Method("testFunc3", "void", MethodUnit::VIRTUAL | MethodUnit::ABSTRACT), ClassUnit::PUBLIC);

        // Создаем статический метод testFunc4 и оператор вывода
        auto method = f->Create_Method("testFunc4", "void", MethodUnit::STATIC);
        auto print = f->Create_Print("Here is Func 4");

        // Добавляем оператор вывода в метод testFunc4
        method->add(print);

        // Добавляем метод testFunc4 в класс myClass с модификатором protected
        myClass->add(method, ClassUnit::PROTECTED);

        // Компилируем класс myClass и возвращаем результат
        return myClass->compile();
    }

    // Метод для генерации второй программы
    std::string GenerateProgram_2()
    {
        // Выводим сообщение о начале второго теста
        std::cout<<"\nSECOND TEST\n\n";

        // Создаем классы Person и Account с помощью фабрики
        auto Person = f->Create_Class("Person");
        auto Account = f->Create_Class("Account");

        // Добавляем Account в качестве приватного поля класса Person
        Person->add(Account, ClassUnit::PRIVATE);

        // Добавляем конструктор и метод print в класс Person
        Person->add(f->Create_Method("Person", "", 0), ClassUnit::PUBLIC);
        Person->add(f->Create_Method("print", "void", 0), ClassUnit::PUBLIC);

        // Добавляем конструктор в класс Account
        Account->add(f->Create_Method("Account", "", 0), ClassUnit::PUBLIC);

        // Компилируем класс Person и возвращаем результат
        return Person->compile();
    }

private:
    // Уникальный указатель на фабрику (factory)
    std::unique_ptr<factory> f;
};

#endif // PROGRAMFACTORY_H
