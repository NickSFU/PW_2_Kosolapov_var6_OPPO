#pragma once
#include "Date.h"
#include <string>
#include <fstream>
#include <iostream>
class TempMeasurement
{
private:
    Date date;
    std::string location;
    double temperature;
public:
    void check_location_symbols(std::string line);
    void check_temperature_symbols(std::string line);
    void read_location(std::istream& ist);
    void read_temperature(std::istream& ist);
    void print(std::ostream& ost);
    void read(std::istream& ist);
    Date get_date();
    std::string get_location();
    double get_temperature();

};
