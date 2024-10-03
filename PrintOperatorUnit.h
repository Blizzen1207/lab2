#ifndef PRINTOPERATOR_UNIT_H
#define PRINTOPERATOR_UNIT_H

#include <iostream>
#include "Unit.h"

class PrintOperatorUnit: public Unit
{
public:
    // Конструктор класса, принимающий текст оператора вывода
    PrintOperatorUnit(const std::string& text): m_text(text){}

protected:
    std::string m_text; // Текст оператора вывода
};

#endif // PRINTOPERATOR_UNIT_H
