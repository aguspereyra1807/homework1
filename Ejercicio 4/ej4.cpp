#include "ej4.hpp"

// a)
bool str_compare_runtime(const string a,const string b) {
    bool state = true;
    if (size(a) != size(b) || a[0] != b[0]) return false;
    if (size(a) == 1 || size(b) == 1) return state;
    state &= str_compare_runtime(a.substr(1),b.substr(1));
    return state;
}

// c) 
constexpr bool str_compare_compiletime(const char *a, const char *b) { // Uso constexpr porque por como estoy compilando no me toma consteval
    bool state = true;
    if (*a != *b) return false;
    if (*a == '\0' || *b == '\0') return state;
    state &= str_compare_compiletime(a+1, b+1); // Recorre caracter a caracter hasta llegar a un '\0' o hasta que sean diferentes
    return state;
}


// b) y c)
int main() {
    string a = "ejemplo", b = "ejemplo";

    auto startTime = chrono::high_resolution_clock::now();
    
    bool equal = str_compare_runtime(a,b);
    string estado;
    if (equal) estado = "iguales";
    else estado = "diferentes";
    cout << "Los strings '" << a << "' y '" << b << "' son " << estado << endl;

    auto endTime = chrono::high_resolution_clock::now();
    auto elapsedTime = chrono::duration_cast<chrono::nanoseconds>(endTime - startTime);
    cout << "str_compare_runtime() tomó " << elapsedTime.count() << " nanosegundos" << std::endl;

    // =============================================================================================

    const char c[] = "ejemplo", d[] = "ejemplo";
    auto startTime2 = chrono::high_resolution_clock::now();
    
    constexpr bool equal2 = str_compare_compiletime(c,d);

    string estado2;
    if (equal2) estado2 = "iguales";
    else estado2 = "diferentes";
    cout << "Los strings '" << c << "' y '" << d << "' son " << estado2 << endl;
    auto endTime2 = chrono::high_resolution_clock::now();
    auto elapsedTime2 = chrono::duration_cast<chrono::nanoseconds>(endTime2 - startTime2);

    cout << "str_compare_compiletime() tomó " << elapsedTime2.count() << " nanosegundos" << std::endl;
}