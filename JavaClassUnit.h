#ifndef JAVACLASSUNIT_H
#define JAVACLASSUNIT_H

#include "ClassUnit.h"

class java_class_unit:public ClassUnit
{
public:
    java_class_unit(const std::string & name, Flags f = PUBLIC):ClassUnit(name)
    {
        m_fields.resize( PRIVATE +1);
        class_modificator = f;
    }
    void add (const std::shared_ptr<Unit>& unit, Flags flags )
    {
        Flags accessModifier = ClassUnit::PRIVATE;
        if (flags<accessModifier)
        {
            accessModifier = flags;
        }

        m_fields[accessModifier].push_back(unit);
    }
    std::string compile(unsigned int level = 0) const
    {
        std::string result ="";
        if (class_modificator == PRIVATE)
        {
            result = generateShift( level ) + "private class " + m_name + " {\n";
        }
        else
        {
            result = generateShift( level ) +"public class " + m_name + " {\n";
        }
        for( size_t i = 0; i < m_fields.size(); ++i )
        {
            if( m_fields[ i ].empty() )
            {
                continue;
            }
            if (i == PUBLIC)
            {
                result+= "public:\n";
            }
            else if (i== PROTECTED)
            {
                result+="protected:\n";
            }
            else if (i == PRIVATE)
            {
                result+="private:\n";
            }

            for( const auto& f : m_fields[ i ] )
            {
                result += f->compile( level + 1 );
            }
            result += "\n";
        }
        result += generateShift( level ) + "};\n";
        return result;
    }
private:
    Flags class_modificator;
};

#endif // JAVACLASSUNITH
