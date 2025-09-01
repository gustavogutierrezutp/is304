#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Measurement {
private:
  double value;
  string date;

public:
  Measurement(double v, const string &d) : value(v), date(d) {}
  double getValue() const { return value; }
  string getDate() const { return date; }
};

vector<Measurement> readMeasurements(const string &filename) {
  vector<Measurement> measurements;

  ifstream file(filename);
  if (!file.is_open()) {
    cerr << "Error opening file: " << filename << endl;
    return measurements;
  }

  string line;
  unsigned int lineNumber = 0;

  while (getline(file, line)) {
    lineNumber++;
    if (lineNumber < 5)
      continue; // Skip header lines

    //cout << "Line " << lineNumber << ": " << line << endl;
    stringstream ss(line);
    string date, temp;
    if (!getline(ss, date, ',')) {
      cerr << "Error parsing date on line " << lineNumber << endl;
    }
    if (!getline(ss, temp, ',')) {
      cerr << "Error parsing temp on line " << lineNumber << endl;
    }
    //cout << "Line " << lineNumber << ": " << date << "   " << temp << endl;
    double temperature = stod(temp);
    Measurement m(temperature, date);
    measurements.push_back(m);
  }
  return measurements;
}

double averageTemperature(const vector<Measurement> &measurements) {
  double sum = 0.0;
  for (const Measurement &m : measurements) {
    sum += m.getValue();
  }
  return measurements.empty() ? 0.0 : sum / measurements.size();
}

int main() {
  string filename = "open-meteo-4.82N75.72W1410m.csv";
  vector<Measurement> measurements = readMeasurements(filename);
  cout << "Total measurements read: " << measurements.size() << endl;
  cout << "Memory by Measurment: " << sizeof(Measurement) << endl;
  cout << "Average temperature: " << averageTemperature(measurements) << endl;
  return 0;
}