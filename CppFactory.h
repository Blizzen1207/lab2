#ifndef CPPFACTORY_H
#define CPPFACTORY_H

#include "Factory.h"

#include "CppClassUnit.h"
#include "CppMethodUnit.h"
#include "CppPrintOperatorUnit.h"

class cpp_factory:public factory
{
public:
    // Метод создания объекта класса на языке C++
    std::shared_ptr<ClassUnit> Create_Class(const std::string &name)
    {
        return std::make_shared<cpp_class_unit>(name);
    }

    // Метод создания объекта метода на языке C++
    std::shared_ptr<MethodUnit> Create_Method(const std::string &func_name,
                                              const std::string &return_type,
                                              const unsigned int &modificator)
    {
        return std::make_shared<cpp_method_unit>(func_name, return_type, modificator);
    }

    // Метод создания объекта оператора вывода на языке C++
    std::shared_ptr<PrintOperatorUnit> Create_Print(const std::string &body)
    {
        return std::make_shared<cpp_print_operator_unit>(body);
    }
};

#endif // CPPFACTORY_H
