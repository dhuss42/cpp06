## ex00 – Conversion of Scalar Types

In this exercise, I implemented a static class ScalarConverter that converts a string literal to its possible scalar types: char, int, float, and double.
The input is parsed to detect its type using basic checks and regex patterns for float and double formats. 
The actual conversion is done by first transforming the input into a double, which simplifies later casts to the other types. Special cases like nan, inf, and overflows are handled.
The conversion results are then printed.

## ex01 – Serialization

In this exercise, I implemented a simple form of serialization and deserialization using pointer casting in C++. The goal was to convert a pointer to a Data structure into an integer representation and then restore it back to its original form.

I used a Serializer class with two static methods:

    In serialize(Data* ptr), I took a pointer to a Data object and converted it to a uintptr_t using reinterpret_cast. This cast allowed me to treat the memory address as an integer without altering the underlying bits.

    In deserialize(uintptr_t raw), I reversed the operation, converting the integer back into a pointer to Data, again using reinterpret_cast.

I chose uintptr_t because it’s specifically designed to safely store pointer values as integers, regardless of whether the system is 32-bit or 64-bit. This ensured portability and reliability.

## ex02 – Identify Real Type

In this exercise, I implemented a base class Base with three derived classes: A, B, and C. The generate function randomly creates an instance of one of the derived classes and returns a Base*. I then used dynamic_cast to implement two overloads of the identify function—one for pointers and one for references—to determine the actual derived type of the object at runtime. The reference version used exception handling to avoid forbidden pointer usage. This reinforced my understanding of polymorphism, RTTI (Runtime Type Information), and safe downcasting without relying on typeid.
