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
    float temperature;
    void read_location(std::istream& ist);
    void read_temperature(std::istream& ist);
public:
    void print(std::ostream& ost);
    void read(std::istream& ist);
};
