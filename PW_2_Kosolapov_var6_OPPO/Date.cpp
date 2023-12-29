#include "Date.h"
void Date::read_date(std::istream& ist)
{
	 
	
		std::string line;
		getline(ist, line, '.');
		check_date_symbols(line);
		year = stoi(line);
		getline(ist, line, '.');
		check_date_symbols(line);
		month = stoi(line);
		getline(ist, line, ' ');
		check_date_symbols(line);
		day = stoi(line);
		check_date();
		

}
void Date::print_date(std::ostream& ost)
{
    ost << year << "." << month << "." << day << " ";
}
bool Date::check_date()
{
	if ((year < 1) || ((month < 1) || (month > 12)) || ((day < 1) || (day > 31))) {
		throw(std::runtime_error("Обнаружена неккоректная дата."));
	}

	if ((month == 4) || (month == 6) || (month == 9) || (month == 11)) {
		if (day > 30) {
			throw(std::runtime_error("Обнаружена неккоректная дата."));;
		}
	}

	if (month == 2) {
		if ((year % 4 == 0) ||(year % 400 == 0) || (year % 100 !=0))
		{
			if (day > 29) {
				throw(std::runtime_error("Обнаружена неккоректная дата."));
			}
		}
		else {
			if (day > 28)
			{
				throw(std::runtime_error("Обнаружена неккоректная дата."));
			}
		}
	}

	return true;
}

void Date::check_date_symbols(std::string line)
{
	if ((line.empty()) || (line == " "))
		throw(std::runtime_error("Поле даты пустое"));
	std::string symbols = "1234567890";
	for (int i = 0; i < line.size(); i++)
	{
		if (symbols.find(line[i]) == std::string::npos)
			throw(std::runtime_error("Использованы неразрешенные символы в дате."));
	}
}

int Date::get_year()
{
	return year;
}

int Date::get_month()
{
	return month;
}

int Date::get_day()
{
	return day;
}