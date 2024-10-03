#ifndef CPPPRINTOPERATORUNITH
#define CPPPRINTOPERATORUNITH

#include "PrintOperatorUnit.h"

class cpp_print_operator_unit:public PrintOperatorUnit
{
public:
    // Конструктор класса, принимающий текст для вывода
    cpp_print_operator_unit(const std::string& text):PrintOperatorUnit(text){}

    // Метод компиляции оператора вывода с учетом уровня вложенности
    std::string compile(unsigned int level = 0)const
    {
        // Генерируем отступ, соответствующий уровню вложенности
        return generateShift(level) + "printf( \"" + m_text + "\" );\n";
    }
};

#endif // CPP_PRINT_OPERATOR_UNIT_H
