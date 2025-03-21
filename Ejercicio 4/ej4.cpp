#include "ej4.hpp"

bool str_compare_runtime(string a,string b) {
    bool state = true;
    if (size(a) != size(b) || a[0] != b[0]) return false;
    if (size(a) == 1 || size(b) == 1) return state;
    state &= str_compare_runtime(a.substr(1),b.substr(1));
    return state;
}

bool str_compare_runtime(char *a, char *b) {
    bool state = true;
    if (strlen(a) != strlen(b)) return false; 
    if (*a != *b) return false;
    if (*a == '\0' || *b == '\0') return state;
    state &= str_compare_runtime(a+1, b+1); // Recorre caracter a caracter hasta llegar a un '\0' o hasta que sean diferentes
    return state;
}

constexpr bool str_compare_compiletime(const char *a, const char *b) { // Uso constexpr porque por como estoy compilando no me toma consteval
    bool state = true;
    if (strlen(a) != strlen(b)) return false; 
    if (*a != *b) return false;
    if (*a == '\0' || *b == '\0') return state;
    state &= str_compare_compiletime(a+1, b+1); 
    return state;
}

int main() {
    string a = "ejemplo", b = "ejemplo";
    char c[] = "ejemplo", d[] = "ejemplo";
    const char e[] = "ejemplo", f[] = "ejemplo";

    auto startTime1 = chrono::high_resolution_clock::now();
    
    str_compare_runtime(a,b);

    auto endTime1 = chrono::high_resolution_clock::now();
    auto elapsedTime1 = chrono::duration_cast<chrono::nanoseconds>(endTime1 - startTime1);
    
    // =============================================================================================
    
    auto startTime2 = chrono::high_resolution_clock::now();
    
    str_compare_runtime(c,d);
    
    auto endTime2 = chrono::high_resolution_clock::now();
    auto elapsedTime2 = chrono::duration_cast<chrono::nanoseconds>(endTime2 - startTime2);
    
    // =============================================================================================
    
    auto startTime3 = chrono::high_resolution_clock::now();
    
    str_compare_compiletime(e,f);
    
    auto endTime3 = chrono::high_resolution_clock::now();
    auto elapsedTime3 = chrono::duration_cast<chrono::nanoseconds>(endTime3 - startTime3);
    
    cout << "str_compare_runtime() (con string) tomó " << elapsedTime1.count() << " nanosegundos" << std::endl;
    cout << "str_compare_runtime() (con char*) tomó " << elapsedTime2.count() << " nanosegundos" << std::endl;
    cout << "str_compare_compiletime() tomó " << elapsedTime3.count() << " nanosegundos" << std::endl;
}

/* CONCLUSIÓN:
Podemos ver que la comparación de strings de varaible <std::string> es muchísimo mas lento que a la hora de comparar
variables 'char*' (una diferencia de 2000 nanosegundos en promedio). Supongo que esto se debe a que <std::string> es una clase, 
y durante la comparaciónuso métodos de esta clase. Mientras que al usar punteros a char, se maneja directamente con cada char y 
es más facil comparar (de esta manera recursiva).
Y a su vez, la función definida como constexpr, compara los strings de tipo 'const char*' en tiempo de compilación,
la cual en ocasiones acorta o iguala el tiempo medido por la libreria <chronos>. Supongo que esto se debe a que como el tiempo 
medido es el tiempo de ejecución, y esta función ya tiene cosas resueltas de antes que no tienen q ser ejecutadas durante el tiempo 
en el que es medido.
*/