# cpp06

These exercises deal with type conversion and type identification mechanisms in C++. They cover converting between scalar types, serializing and deserializing pointers, and safely determining object types at runtime using casting.

## ex00 – Conversion of Scalar Types

In this exercise, I implemented a static class ScalarConverter that converts a string literal to its possible scalar types: char, int, float, and double.
The input is parsed to detect its type using basic checks and regex patterns for float and double formats.
The actual conversion is done by first transforming the input into a double, which simplifies later casts to the other types. Special cases like nan, inf, and overflows are handled.
The conversion results are then printed.

For the type conversions, I used static_cast, which safely performs compile-time conversions between fundamental types. After converting the input to a double, I used static_cast to explicitly cast it to char, int, and float, ensuring type safety and clarity in the conversion process.

## ex01 – Serialization

In this exercise, I implemented a simple form of serialization and deserialization using pointer casting in C++. The goal was to convert a pointer to a Data structure into an integer representation and then restore it back to its original form.

I used a Serializer class with two static methods. In serialize(Data* ptr), I took a pointer to a Data object and converted it to a uintptr_t using reinterpret_cast. This cast allowed me to treat the memory address as an integer without altering the underlying bits. In deserialize(uintptr_t raw), I reversed the operation, converting the integer back into a pointer to Data, again using reinterpret_cast. I chose uintptr_t because it’s specifically designed to safely store pointer values as integers, regardless of whether the system is 32-bit or 64-bit.

## ex02 – Identify Real Type

In this exercise, I implemented a base class Base along with three derived classes: A, B, and C. I created a generate function that returned a Base* pointing to a randomly instantiated object of type A, B, or C.

To identify the actual type of the generated object at runtime, I implemented two overloads of the identify function—one taking a pointer (Base*) and the other taking a reference (Base&). In both functions, I used dynamic_cast to safely downcast from the base class to the derived class.

Using dynamic_cast was necessary here because I had only a pointer or reference to the base class, and I needed to determine the real underlying type. For the pointer version, dynamic_cast returned nullptr if the cast failed, which allowed me to check the result without risking undefined behavior.

For the reference version, dynamic_cast cannot return nullptr—instead, it throws a std::bad_cast exception if the conversion fails. Therefore, I used try and catch blocks to safely attempt the cast and determine the correct type.
