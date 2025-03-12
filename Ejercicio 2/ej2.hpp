#include <iostream>
#include <string>
#include <fstream>
using namespace std;

enum class SEVERITY {DEBUG, INFO, WARNING, ERROR, CRITICAL};

void logMessage(string message, SEVERITY severityLevel);

void logMessage(string errorMesagge, string filePath, int line);

void logMessage(string accessMessage, string username);

