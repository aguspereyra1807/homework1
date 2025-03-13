#include <string>
#include <iostream>
#include <chrono>
using namespace std;

bool str_compare_runtime(string a, string b);

// Uso const char * porque lo necesita para que la comparación se realice en tiempo de compilación
constexpr bool str_compare_compiletime(const char *a, const char *b);
