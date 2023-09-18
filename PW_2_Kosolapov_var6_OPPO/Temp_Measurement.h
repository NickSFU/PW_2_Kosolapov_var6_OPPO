#pragma once
#include "Date.h"
#include <string>
#include <fstream>
class Temp_Measurement
{
private:
    Date Date;
    std::string location="";
    float temperature=-100000;
    void read_location(std::istream& ist);
    void read_temperature(std::istream& ist);
    void read_date(std::istream& ist);
public:
    void print_tm(std::ostream& ost);
    void read_tm(std::istream& ist);
};
