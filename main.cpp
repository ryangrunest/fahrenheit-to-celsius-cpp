/*
 read Fahrenheit temperatures
 and output to new Celsius file
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void ConvertToCelsius(vector<int> &temperatures) {
  ifstream temperatureFS;
  ofstream temperatureOFS;
  string location;
  int temperature;
  int tempInCelsius;


  temperatureFS.open("FahrenheitTemperature.txt");
  temperatureOFS.open("CelsiusTemperature.txt");


  if (!temperatureFS.is_open()) {
    cout << "Could not open file" << endl;
  } else {
    
    while (!temperatureFS.fail()) {
      temperatureFS >> location;
      temperatureFS >> temperature;

      cout << "Location: " << location << endl;
      cout << "Temperature: " << temperature << endl;
      
      if (!temperatureFS.fail()) {
        tempInCelsius = temperature - 32;
        tempInCelsius = tempInCelsius * 5;
        tempInCelsius = tempInCelsius / 9;

        temperatureOFS << location << " " << tempInCelsius << endl;

        temperatures.push_back(temperature);
      }
    }

    temperatureFS.close();
    temperatureOFS.close();
  }
}

int main() {
  vector<int> temperatures;

  ConvertToCelsius(temperatures);
}