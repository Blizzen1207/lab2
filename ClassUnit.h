#ifndef CLASSUNIT_H
#define CLASSUNIT_H

#include "Unit.h"
#include <iostream>
#include <vector>

class ClassUnit : public Unit
{
public:
    // Перечисление модификаторов доступа для класса
    enum AccessModifier
    {
        PUBLIC,
        PROTECTED,
        PRIVATE,
        INTERNAL,
        PROTECTED_INTERNAL,
        PRIVATE_PROTECTED
    };

public:
    // Конструктор класса, принимающий имя класса
    ClassUnit(const std::string& name): m_name(name){}

protected:
    std::string m_name; // Имя класса
    using Fields = std::vector<std::shared_ptr<Unit>>; // Вектор элементов класса
    std::vector< Fields > m_fields; // Вектор векторов элементов класса
};
#endif // CLASSUNIT_H
