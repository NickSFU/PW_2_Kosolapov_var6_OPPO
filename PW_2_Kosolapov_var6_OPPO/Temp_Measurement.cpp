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
    check_location_symbols(line);
    location = line;
}
void TempMeasurement::read_temperature(std::istream& ist)
{
    std::string line;
    getline(ist, line);
    check_temperature_symbols(line);
    temperature = stof(line);
}

void TempMeasurement::read(std::istream& ist)
{
    date.read_date(ist);
    read_location(ist);
    read_temperature(ist);
}

void TempMeasurement::check_location_symbols(std::string line)
{
    if (line.empty())
        throw(std::runtime_error("Поле местоположения пусто."));
    std::string symbols = "QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm1234567890_-";
    for(int i =0;i<line.size();i++)
    {
        if(symbols.find(line[i])== std::string::npos)
            throw(std::runtime_error("Использованы неразрешенные символы в названии города."));
    }

}
void TempMeasurement::check_temperature_symbols(std::string line)
{
    if (line.empty())
        throw(std::runtime_error("Поле температуры пусто."));
    std::string symbols = "1234567890-+.,";
    for (int i = 0; i < line.size(); i++)
    {
        if (symbols.find(line[i]) == std::string::npos)
            throw(std::runtime_error("Использованы неразрешенные символы в показателях температуры."));
    }

}

Date TempMeasurement::get_date()
{
    return date;
}

std::string TempMeasurement::get_location()
{
    return location;
}

double TempMeasurement::get_temperature()
{
    return temperature;
}