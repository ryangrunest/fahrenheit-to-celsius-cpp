/*
 read Fahrenheit temperatures
 and output to new Celsius file
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void ReadFile(vector<int> &temperatures) {
  ifstream temperatureFS;
  string location;
  int temperature;

  temperatureFS.open("FahrenheitTemperature.txt");

  if (!temperatureFS.is_open()) {
    cout << "Could not open file" << endl;
  } else {
    
    while (!temperatureFS.fail()) {
      temperatureFS >> location;
      temperatureFS >> temperature;

      cout << "Location: " << location << endl;
      cout << "Temperature: " << temperature << endl;

      temperatures.push_back(temperature);
    }

    temperatureFS.close();
  }
}

int main() {
  vector<int> temperatures;

  ReadFile(temperatures);
}