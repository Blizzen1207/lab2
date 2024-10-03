#ifndef CPPMETHODUNIT_H
#define CPPMETHODUNIT_H

#include "MethodUnit.h"

class cpp_method_unit : public MethodUnit
{
public:
    // Конструктор класса, принимающий имя метода, возвращаемый тип и флаги
    cpp_method_unit(const std::string & name, const std::string& returnType, Flags flags)
        : MethodUnit(name, returnType, flags) {}

    // Метод для добавления элемента в тело метода
    void add(const std::shared_ptr<Unit>& unit, Flags = 0)
    {
        m_body.push_back(unit);
    }

    // Метод компиляции метода с учетом уровня вложенности
    std::string compile(unsigned int level = 0) const
    {
        std::string result = generateShift(level);
        // Если метод является статическим, добавляем ключевое слово "static"
        if (m_flags & STATIC)
        {
            result += "static ";
        }
        // Если метод является виртуальным, добавляем ключевое слово "virtual"
        else if (m_flags & VIRTUAL)
        {
            result += "virtual ";
        }
        // Добавляем возвращаемый тип метода
        result += m_returnType + " ";
        // Добавляем имя метода
        result += m_name + "()";
        // Если метод является константным, добавляем ключевое слово "const"
        if (m_flags & CONST)
        {
            result += " const";
        }
        // Начинаем тело метода
        result += " {\n";
        // Компилируем все элементы, входящие в тело метода
        for (const auto& b : m_body)
        {
            result += b->compile(level + 1);
        }
        // Завершаем тело метода
        result += generateShift(level) + "}\n";
        return result;
    }
};

#endif // CPPMETHODUNIT_H
