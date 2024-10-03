#include <iostream>


#include "CppFactory.h"
#include "JavaFactory.h"
#include "SharpFactory.h"
#include "ProgramFactory.h"

int main()
{
// Создание объекта ProgramFactory для языка C++ с использованием фабрики cpp_factory
ProgramFactory* p_cpp = new ProgramFactory(std::make_unique<cpp_factory>());
// Создание объекта ProgramFactory для языка Java с использованием фабрики java_factory
ProgramFactory* p_java = new ProgramFactory(std::make_unique<java_factory>());
// Создание объекта ProgramFactory для языка C# с использованием фабрики sharp_factory
ProgramFactory* p_sharp = new ProgramFactory(std::make_unique<sharp_factory>());

// Вывод сгенерированного кода на C++
std::cout << "C++ Code:\n";
std::cout << p_cpp->GenerateProgram_1(); // Генерация и вывод первой программы на C++
std::cout << p_cpp->GenerateProgram_2(); // Генерация и вывод второй программы на C++

// Вывод сгенерированного кода на Java
std::cout << "\nJava Code:\n";
std::cout << p_java->GenerateProgram_1(); // Генерация и вывод первой программы на Java
std::cout << p_java->GenerateProgram_2(); // Генерация и вывод второй программы на Java

// Вывод сгенерированного кода на C#
std::cout << "\nC# Code:\n";
std::cout << p_sharp->GenerateProgram_1(); // Генерация и вывод первой программы на C#
std::cout << p_sharp->GenerateProgram_2(); // Генерация и вывод второй программы на C#

// Освобождение памяти, удаляем объекты ProgramFactory
delete p_cpp;
delete p_java;
delete p_sharp;

return 0; // Завершение программы
}
