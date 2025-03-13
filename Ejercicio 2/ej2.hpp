#include <iostream>
#include <string>
#include <fstream>
using namespace std;

enum class SEVERITY {DEBUG, INFO, WARNING, ERROR, CRITICAL};

// Registra un mensaje con una etiqueta "severityLevel" en console.txt
void logMessage(string message, SEVERITY severityLevel);

// Registra un mensaje de error sobre el archivo "fileName" sobre la linea "line" en console.txt
void logMessage(string errorMesagge, string fileName, int line);

// Registra un mensaje de acceso indicando el nombre de usuario "username" y el estado del acceso "accessMessage" en console.txt
void logMessage(string accessMessage, string username);