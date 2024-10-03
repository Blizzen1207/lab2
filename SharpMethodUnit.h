#ifndef SHARPMETHODUNIT_H
#define SHARPMETHODUNIT_H

#include "MethodUnit.h"

class sharp_method_unit:public MethodUnit
{


public:
    sharp_method_unit(const std::string & name, const std::string& returnType,Flags flags):MethodUnit(name,returnType,flags){}


    void add(const std::shared_ptr<Unit>& unit,Flags = 0)
    {
        m_body.push_back(unit);
    }
    std::string compile(unsigned int level = 0) const
    {
        std::string result = generateShift(level);
        if (m_flags & MethodUnit::STATIC)
        {
            result+="static ";
        }
        else if (m_flags & MethodUnit::VIRTUAL)
        {
            result+="virtual ";
        }
        result += m_returnType+" ";
        result += m_name + "()";

        result+=" {\n";
        for( const auto& b:m_body)
        {
            result+=b->compile(level+1);
        }
        result+=generateShift(level)+"}\n";
        return result;
    }
};

#endif // SHARPMETHODUNIT_H
