#ifndef UNIT_H
#define UNIT_H

// Подключение библиотек для ввода-вывода и умных указателей
#include <iostream>
#include <memory>

// Абстрактный класс Unit
class Unit
{
public:
    // Псевдоним для типа unsigned int, используемого для флагов
    using Flags = unsigned int;

public:
    // Виртуальный деструктор по умолчанию
    virtual ~Unit() = default;

    // Виртуальный метод add для добавления элементов, с возможностью указания флагов доступа
    virtual void add( const std::shared_ptr< Unit >&,Flags = 0){}

    // Виртуальный метод compile для компиляции, с возможностью указания уровня вложенности
    virtual std::string compile(Flags level =0)const = 0;

protected:
    // Виртуальный метод generateShift для генерации отступов в коде, с возможностью указания уровня вложенности
    virtual std::string generateShift( Flags level)const
    {
        // Статическая константа для отступа по умолчанию
        static const auto  DEFAULT_SHIFT = "    ";
        std::string result;
        for( unsigned int i =0; i <level;++i)
        {
            result+=DEFAULT_SHIFT;
        }
        return result;
    }
};

#endif // UNIT_H
