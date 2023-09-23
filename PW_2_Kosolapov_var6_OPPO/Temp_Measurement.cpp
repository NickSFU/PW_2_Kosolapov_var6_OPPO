#include "Temp_Measurement.h"

void TempMeasurement::print(std::ostream& ost) // Выводит в поток ost одно измерение.
{
    date.print_date(ost);
    ost << location << " ";
    if (temperature > 0)
        ost << "+" << temperature << std::endl;
    else
        ost << temperature << std::endl;
}

void TempMeasurement::read_location(std::istream& ist)
{
    std::string line;
    getline(ist, line, ' ');
    location = line;
}
void TempMeasurement::read_temperature(std::istream& ist)
{
    std::string line;
    getline(ist, line);
    temperature = stof(line);
}

void TempMeasurement::read(std::istream& ist)
{
    date.read_date(ist);
    read_location(ist);
    read_temperature(ist);
}