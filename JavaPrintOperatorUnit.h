#ifndef JAVAPRINTOPERATORUNIT_H
#define JAVAPRINTOPERATORUNIT_H

#include "PrintOperatorUnit.h"

class java_print_operator_unit: public PrintOperatorUnit
{
public:
    java_print_operator_unit(const std::string& text):PrintOperatorUnit(text){}

    std::string compile(unsigned int level = 0) const
    {
        return generateShift(level) + "System.out.println(\"" + m_text + "\");\n";
    }
};

#endif // JAVAPRINTOPERATORUNIT_H
