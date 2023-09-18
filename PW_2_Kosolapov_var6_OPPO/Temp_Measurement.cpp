#include "Temp_Measurement.h"
Temp_Measurement:Temp_Measurement()
{
}
void Temp_Measurement::print_tm(std::ostream& ost) // Выводит в поток ost одно измерение.
{
    ost << Date.year << "." << Date.month << "." << Date.day << " " << location << " ";
    if (temperature > 0)
        ost << "+" << temperature << endl;
    else
        ost << temperature << endl;
}
void Temp_Measurement:: read_date(std::istream& ist)
{
    std::string line;
    getline(ist, line, '.');
    Date.year = stoi(line);
    getline(ist, line, '.');
    Date.month = stoi(line);
    getline(ist, line, ' ');
    Date.day = stoi(line);
}
void Temp_Measurement:: read_location(std::istream& ist)
{
    std::string line;
    getline(ist, line, ' ');
    location = line;
}
void Temp_Measurement::read_location(std::istream& ist)
{
    std::string line;
    getline(ist, line);
    temperature = stof(line);
}

void Temp_Measurement::read_tm(std::istream& ist)
{
    read_date(ist);
    read_location(ist);
    read_temperature(ist);
}