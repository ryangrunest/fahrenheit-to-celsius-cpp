/*
  Ryan Grunest 10/4/2024
  read Fahrenheit temperatures
  and output to new Celsius file
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// read through file, convert temperatures to Celsius
void ConvertToCelsius() {
  ifstream temperatureFS;
  ofstream temperatureOFS;

  string location;

  int temperature;
  int tempInCelsius;

  temperatureFS.open("FahrenheitTemperature.txt"); // open Fahrenheit file stream
  temperatureOFS.open("CelsiusTemperature.txt"); // open Celsius file stream


  if (!temperatureFS.is_open()) { // there was an error opening the Fahrenheit file
    cout << "Could not open file" << endl;
  } else {
    
    while (!temperatureFS.fail()) { // read until end of fle
      temperatureFS >> location; // get location
      temperatureFS >> temperature; // get temperature

      cout << "Location: " << location << endl; // output location to console
      cout << "Temperature: " << temperature << endl; // output temperature to console
      
      if (!temperatureFS.fail()) { // if it hasn't reached the end of the file
        tempInCelsius = temperature - 32; // convert to celsius
        tempInCelsius = tempInCelsius * 5;
        tempInCelsius = tempInCelsius / 9;

        temperatureOFS << location << " " << tempInCelsius << endl; // write new value to Celsius file
      }
    }

    temperatureFS.close(); // close input stream
    temperatureOFS.close(); // close output stream
  }
}

int main() {
  ConvertToCelsius();
}