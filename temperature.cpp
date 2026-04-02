#include <fstream>   // Para leer archivos
#include <iostream>  // Para imprimir en pantalla
#include <sstream>   // Para procesar líneas de texto
#include <string>    // Para usar cadenas de texto
#include <vector>    // Para usar vectores

using namespace std;

// La clase Measurement representa una medición de temperatura con su valor y fecha.
class Measurement {
private:
  double value;   // Temperatura medida
  string date;    // Fecha de la medición

public:
  // Constructor: recibe el valor y la fecha
  Measurement(double v, const string &d) : value(v), date(d) {}

  // Devuelve el valor de la temperatura
  double getValue() const { return value; }

  // Devuelve la fecha de la medición
  string getDate() const { return date; }
};

// Esta función lee las mediciones desde un archivo CSV.
// Omite las primeras 4 líneas (cabecera) y guarda cada medición en un vector.
vector<Measurement> readMeasurements(const string &filename) {
  vector<Measurement> measurements;

  ifstream file(filename);
  if (!file.is_open()) {
    cerr << "Error al abrir el archivo: " << filename << endl;
    return measurements;
  }

  string line;
  unsigned int lineNumber = 0;

  while (getline(file, line)) {
    lineNumber++;
    if (lineNumber < 5)
      continue; // Salta las líneas de cabecera

    stringstream ss(line);
    string date, temp;
    if (!getline(ss, date, ',')) {
      cerr << "Error al leer la fecha en la línea " << lineNumber << endl;
    }
    if (!getline(ss, temp, ',')) {
      cerr << "Error al leer la temperatura en la línea " << lineNumber << endl;
    }
    double temperature = stod(temp); // Convierte la temperatura a número
    Measurement m(temperature, date); // Crea una medición
    measurements.push_back(m);        // La agrega al vector
  }
  return measurements;
}

// Calcula el promedio de todas las temperaturas en el vector de mediciones.
double averageTemperature(const vector<Measurement> &measurements) {
  double sum = 0.0;
  for (const Measurement &m : measurements) {
    sum += m.getValue();
  }
  return measurements.empty() ? 0.0 : sum / measurements.size();
}

int main() {
  // Nombre del archivo CSV con las mediciones
  string filename = "open-meteo-4.82N75.72W1410m.csv";

  // Lee las mediciones del archivo
  vector<Measurement> measurements = readMeasurements(filename);

  // Muestra cuántas mediciones se leyeron
  cout << "Total de mediciones leídas: " << measurements.size() << endl;

  // Muestra cuánta memoria ocupa cada medición
  cout << "Memoria por medición: " << sizeof(Measurement) << endl;

  // Muestra el promedio de temperatura
  cout << "Temperatura promedio: " << averageTemperature(measurements) << endl;
  return 0;
}