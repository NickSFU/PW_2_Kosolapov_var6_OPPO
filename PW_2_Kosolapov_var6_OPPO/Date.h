#pragma once
#include <fstream>
#include <string>
#include <exception>
class Date
{
private:
    int year;
    int month;
    int day;
public:
    bool check_date();
    void check_date_symbols(std::string line);
    void read_date(std::istream& ist);
    void print_date(std::ostream& ost);
    int get_year();
    int get_month();
    int get_day();
};