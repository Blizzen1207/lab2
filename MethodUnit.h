#ifndef METHODUNIT_H
#define METHODUNIT_H

#include <Unit.h>
#include <vector>

class MethodUnit: public Unit
{
public:
    // Перечисление модификаторов метода
    enum Modifier {
        STATIC  = 1,
        CONST   = 1 << 1, // сдвиг бита на 1 влево: = 10
        VIRTUAL = 1 << 2,
        FINAL   = 1 << 3,
        ABSTRACT = 1 << 4
    };

public:
    // Конструктор метода, принимающий имя, возвращаемый тип и флаги
    MethodUnit(const std::string& name, const std::string& returnType, Flags flags)
        : m_name(name), m_returnType(returnType), m_flags(flags) {}

protected:
    std::string m_name; // Имя метода
    std::string m_returnType; // Возвращаемый тип
    Flags m_flags; // Флаги метода
    std::vector<std::shared_ptr<Unit>> m_body; // Тело метода
};

#endif // METHODUNIT_H
