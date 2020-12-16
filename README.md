# decoupling

This github repo demonstrates the power of new features of C++17 when it comes to decouplation of classes and reduce hierarchies.

This example shows instead of using inheritence in the famous shape examples in C++,
how you can use the std::any feature to decouple classes and minimize dependencies.

Compilation instructions:
 g++ -std=c++17 area_calculator.cpp

