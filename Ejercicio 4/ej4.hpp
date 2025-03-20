#include <string>
#include <iostream>
#include <chrono>
#include <cstring>
using namespace std;

// Compara 2 variables <std::string> caracter a caracter recursivamente.
bool str_compare_runtime(string a, string b);

// Compara 2 variables const char* caracter a caracter recursivamente.
bool str_compare_runtime(const char *a, const char *b);

// Compara 2 variables const char* caracter a caracter recursivamente en tiempo de ejecución.
constexpr bool str_compare_compiletime(const char *a, const char *b);
