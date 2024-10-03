#ifndef SHARPFACTORY_H
#define SHARPFACTORY_H


#include "Factory.h"

#include "SharpClassUnit.h"
#include "SharpMethodUnit.h"
#include "SharpPrintOperatorUnit.h"

class sharp_factory: public factory
{
public:
    std::shared_ptr<ClassUnit> Create_Class(const std::string &name)
    {
        return std::make_shared<sharp_class_unit>(name);
    }
    std::shared_ptr<MethodUnit> Create_Method(const std::string &func_name,
                                              const std::string &return_type,
                                              const unsigned int &modificator)
    {
        return std::make_shared<sharp_method_unit>(func_name,return_type,modificator);
    }
    std::shared_ptr<PrintOperatorUnit> Create_Print(const std::string &body)
    {
        return std::make_shared<sharp_print_operator_unit>(body);
    }

};

#endif // SHARPFACTORY_H
