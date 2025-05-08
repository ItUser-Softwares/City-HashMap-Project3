#pragma once

#include <iomanip>
#include <iostream>
#include <string>

class City {
public:
  std::string cityName;
  std::string stateID;
  std::string stateName;
  std::string countyName;
  int population;
  double landArea;

  City(std::string cityName = "", std::string stateID = "",
       std::string stateName = "", std::string countyName = "",
       int population = 0, double landArea = 0.0)
      : cityName(cityName), stateID(stateID), stateName(stateName),
        countyName(countyName), population(population), landArea(landArea) {}

  void display() const {
    std::cout << std::left << std::setw(20) << cityName << std::setw(10)
              << stateID << std::setw(15) << stateName << std::setw(20)
              << countyName << std::setw(12) << population << std::setw(10)
              << landArea << std::endl;
  }
};
