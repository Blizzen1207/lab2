#ifndef FACTORY_H
#define FACTORY_H

#include "ClassUnit.h"
#include "MethodUnit.h"
#include "PrintOperatorUnit.h"

#include <iostream>

class factory
{
public:
    // Виртуальный метод для создания объекта класса
    virtual std::shared_ptr<ClassUnit> Create_Class(const std::string &name) = 0;

    // Виртуальный метод для создания объекта метода
    virtual std::shared_ptr<MethodUnit> Create_Method(const std::string &func_name,
                                                      const std::string &return_type,
                                                      const unsigned int &modificator) = 0;

    // Виртуальный метод для создания объекта оператора вывода
    virtual std::shared_ptr<PrintOperatorUnit> Create_Print(const std::string &body) = 0;

    // Виртуальный деструктор
    virtual ~factory(){}
};

#endif // FACTORY_H
