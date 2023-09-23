#include "Date.h"
void Date::read_date(std::istream& ist)
{

    std::string line;
    getline(ist, line, '.');
    year = stoi(line);
    getline(ist, line, '.');
    month = stoi(line);
    getline(ist, line, ' ');
    day = stoi(line);
}
void Date::print_date(std::ostream& ost)
{
    ost << year << "." << month << "." << day << " ";
}