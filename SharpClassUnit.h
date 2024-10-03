#ifndef SHARPCLASSUNIT_H
#define SHARPCLASSUNIT_H

#include "ClassUnit.h"

class sharp_class_unit:public ClassUnit
{

public:
    sharp_class_unit(const std::string & name, Flags f = PUBLIC):ClassUnit(name)
    {
        m_fields.resize( PRIVATE_PROTECTED+1);
        class_modificator = f;
    }


    void add (const std::shared_ptr<Unit>& unit, Flags flags )
    {
        Flags accessModifier = PRIVATE_PROTECTED;
        if (flags<accessModifier)
        {
            accessModifier = flags;
        }

        m_fields[accessModifier].push_back(unit);
    }


    std::string compile(unsigned int level = 0) const
    {
        std::string result = "";
        if (class_modificator ==  INTERNAL)
        {
            result = generateShift( level ) +"internal class " + m_name + " {\n";
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
                result += "public:\n";
            }
            else if(i ==PROTECTED)
            {
                result += "protected:\n";
            }
            else if (i == PRIVATE)
            {
                result += "private:\n";
            }
            else if (i == INTERNAL)
            {
                result += "internal:\n";
            }
            else if (i== PROTECTED_INTERNAL)
            {
                result += "protected internal:\n";
            }
            else
            {
                result += "private protected:\n";
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

#endif // SHARPCLASSUNIT_H
