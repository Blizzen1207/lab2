#ifndef CPPCLASSUNIT_H
#define CPPCLASSUNIT_H

#include "ClassUnit.h"

class cpp_class_unit : public ClassUnit
{
public:
    // Конструктор класса, устанавливающий размер вектора полей
    cpp_class_unit(const std::string & name): ClassUnit(name)
    {
        // Устанавливаем размер вектора m_fields, чтобы он мог хранить поля с уровнями доступа от PUBLIC до PRIVATE
        m_fields.resize( PRIVATE + 1);
    }

    // Метод для добавления элемента с указанным уровнем доступа
    void add(const std::shared_ptr<Unit>& unit, Flags flags)
    {
        // Инициализируем accessModifier значением PRIVATE по умолчанию
        Flags accessModifier = PRIVATE;
        // Если переданный флаг flags меньше текущего accessModifier,
        // то обновляем accessModifier на минимальное значение
        if (flags < accessModifier)
        {
            accessModifier = flags;
        }
        // Добавляем переданный элемент unit в вектор полей с соответствующим уровнем доступа accessModifier
        m_fields[accessModifier].push_back(unit);
    }

    // Метод компиляции класса с учетом уровня вложенности
    std::string compile(unsigned int level = 0) const
    {
        // Начинаем генерацию кода класса с отступом, соответствующим уровню вложенности
        std::string result = generateShift(level) + "class " + m_name + " {\n";
        // Итерируемся по всем уровням доступа полей (от PUBLIC до PRIVATE)
        for (size_t i = 0; i < m_fields.size(); ++i)
        {
            // Пропускаем пустые уровни доступа
            if (m_fields[i].empty())
            {
                continue;
            }
            // Добавляем соответствующий модификатор доступа для текущего уровня
            if (i == PUBLIC)
            {
                result += "public:\n";
            }
            else if (i == PROTECTED)
            {
                result += "protected:\n";
            }
            else if (i == PRIVATE)
            {
                result += "private:\n";
            }
            // Компилируем каждый элемент с увеличенным уровнем отступа
            for (const auto& f : m_fields[i])
            {
                result += f->compile(level + 1);
            }
            // Добавляем пустую строку для разделения блоков
            result += "\n";
        }
        // Завершаем определение класса с соответствующим отступом
        result += generateShift(level) + "};\n";

        return result;
    }
};

#endif // CPPCLASSUNIT_H
