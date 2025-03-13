#include "ej4.hpp"

bool str_compare_runtime(string a,string b) {
    bool state = true;
    if (size(a) != size(b) || a[0] != b[0]) return false;
    if (size(a) == 1 || size(b) == 1) return state;
    state &= str_compare_runtime(a.substr(1),b.substr(1));
    return state;
}

bool str_compare_runtime(const char *a, const char *b) {
    bool state = true;
    if (*a != *b) return false;
    if (*a == '\0' || *b == '\0') return state;
    state &= str_compare_runtime(a+1, b+1); // Recorre caracter a caracter hasta llegar a un '\0' o hasta que sean diferentes
    return state;
}

constexpr bool str_compare_compiletime(const char *a, const char *b) { // Uso constexpr porque por como estoy compilando no me toma consteval
    bool state = true;
    if (*a != *b) return false;
    if (*a == '\0' || *b == '\0') return state;
    state &= str_compare_compiletime(a+1, b+1); 
    return state;
}

int main() {
    string a = "ejemplo", b = "ejemplo";

    auto startTime = chrono::high_resolution_clock::now();
    
    str_compare_runtime(a,b);

    auto endTime = chrono::high_resolution_clock::now();
    auto elapsedTime = chrono::duration_cast<chrono::nanoseconds>(endTime - startTime);
    cout << "str_compare_runtime() (con string) tomó " << elapsedTime.count() << " nanosegundos" << std::endl;

    // =============================================================================================
    const char c[] = "ejemplo", d[] = "ejemplo";

    auto startTime2 = chrono::high_resolution_clock::now();
    
    str_compare_runtime(c,d);
    
    auto endTime2 = chrono::high_resolution_clock::now();
    auto elapsedTime2 = chrono::duration_cast<chrono::nanoseconds>(endTime2 - startTime2);

    cout << "str_compare_runtime() (con const char*) tomó " << elapsedTime2.count() << " nanosegundos" << std::endl;

    // =============================================================================================
    const char e[] = "ejemplo", f[] = "ejemplo";
    
    auto startTime3 = chrono::high_resolution_clock::now();
    
    str_compare_compiletime(e,f);
    
    auto endTime3 = chrono::high_resolution_clock::now();
    auto elapsedTime3 = chrono::duration_cast<chrono::nanoseconds>(endTime3 - startTime3);

    cout << "str_compare_compiletime() tomó " << elapsedTime3.count() << " nanosegundos" << std::endl;
}

/* CONCLUSIÓN:
    Podemos ver que la comparación de strings de varaible <std::string> es mucho mas lento que a la hora de comparar
variables 'const *char'. Supongo que esto se debe a que <std::string> es una clase, y durante la comparación
uso métodos de esta clase. Mientras que al usar punteros a char, se maneja directamente con cada char y es más facil
comparar (de esta manera recursiva).
Y a su vez, la función definida como constexpr, la cual compara los strings en tiempo de compilación,
acorta el tiempo medido por la libreria <chronos> porque como el tiempo medido es el tiempo de ejecución,
esta función ya tiene cosas resueltas de antes que no tienen q ser ejecutadas durante el tiempo que es medido.
*/