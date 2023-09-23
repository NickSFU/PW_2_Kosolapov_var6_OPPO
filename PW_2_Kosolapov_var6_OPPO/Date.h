#pragma once
#include <fstream>
#include <string>
class Date
{
private:
    int year;
    int month;
    int day;
public:
    void read_date(std::istream& ist);
    void print_date(std::ostream& ost);
};