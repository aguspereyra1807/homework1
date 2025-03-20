#include "ej2.hpp"

// a)
void logMessage(string message, SEVERITY severityLevel) {
    ofstream outFile("console.txt", ios::app);
    if (outFile.is_open()) {
        switch (severityLevel) {
            case SEVERITY::DEBUG:
                outFile << "[DEBUG] ";
                break;
            case SEVERITY::INFO:
                outFile << "[INFO] ";
                break;
            case SEVERITY::WARNING:
                outFile << "[WARNING] ";
                break;
            case SEVERITY::ERROR:
                outFile << "[ERROR] ";
                break;
            case SEVERITY::CRITICAL:
                outFile << "[CRITICAL] ";
                break;
        }
        outFile << message << endl;
        outFile.close();
    } else cerr << "Error" << endl;
}

// b)

// ii.
void logMessage(string errorMesagge, string fileName, int line) {
    ofstream outFile("console.txt", ios::app);
    if (outFile.is_open()) {
        outFile << fileName << ":" << to_string(line) << " '" << errorMesagge << "'" << endl;
        outFile.close();
    } else cerr << "Error" << endl;
    return;
}

// iii.
void logMessage(string accessMessage, string username) {
    ofstream outFile("console.txt", ios::app);
    if (outFile.is_open()) {
        outFile << "[SECURITY] ";
        if (accessMessage == "Access Granted") {
            outFile << "Acceso correcto de '" + username + "'" << endl;           
        } else if (accessMessage == "Access Denied") {
            outFile << "Acceso incorrecto de '" + username + "'" << endl;
        }
       outFile.close();
    } else cerr << "Error" << endl;
    return;
}

// iv.
int main() {
    // Prueba de logMessage general
    logMessage("debug message example", SEVERITY::DEBUG);
    logMessage("info message example", SEVERITY::INFO);
    logMessage("warning message example", SEVERITY::WARNING);
    logMessage("error message example", SEVERITY::ERROR);
    logMessage("critical message example", SEVERITY::CRITICAL);
    logMessage("SintaxError", "ej2.cpp", 45);
    logMessage("Access Granted", "apereryra@udesa.edu.ar");
    logMessage("Access Denied", "mscaramal@udesa.edu.ar");

    // Ejemplo de registro con logMessage
    try {
        throw runtime_error("Error 1");
    } catch (const runtime_error& e) {
        logMessage(e.what(), SEVERITY::ERROR);
        return 1;
    }
    return 0;
}k