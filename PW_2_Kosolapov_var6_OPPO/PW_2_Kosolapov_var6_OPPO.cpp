// PW_2_Kosolapov_var6_OPPO.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

//#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Date
{
    int year;
    int month;
    int day;
};
class Temp_Measurement
{
private:
    Date Date;
    string location;
    float temperature;
public:
    void print_tm(ostream& ost) // Выводит в поток ost одно измерение.
    {
        ost << Date.year << "." << Date.month << "." << Date.day << " " << location << " ";
        if (temperature > 0)
            ost << "+" << temperature << endl;
        else
            ost << temperature << endl;
    }
    void read_tm(istream& ist) // Считывает из потока ist одно измерение.
    {
        string line;
        getline(ist, line, '.');
        Date.year = stoi(line);
        getline(ist, line, '.');
        Date.month = stoi(line);
        getline(ist, line, ' ');
        Date.day = stoi(line);
        getline(ist, line, ' ');
        location = line;
        getline(ist, line);
        temperature = stof(line);
    }
};


vector <Temp_Measurement> Temp_Measurement_Box; // Вектор измерений

void print_measurements(vector <Temp_Measurement>& data1, ostream& ost)
{
    for (int i = 0; i < data1.size(); i++)
    {
        data1[i].print_tm(ost);
    }
}

void save_measurements(vector <Temp_Measurement>& data1, istream& ist)
{
    while (!ist.eof())
    {
        Temp_Measurement buff;
        buff.read_tm(ist);
        data1.push_back(buff);
    }
}
int main()
{
    vector <Temp_Measurement> Temp_Measurement_Box;
    ifstream in("in.txt");
    if (!in.is_open())
    {
        cout << "File is not opened";
        return 1;
    }
    save_measurements(Temp_Measurement_Box, in);
    print_measurements(Temp_Measurement_Box, cout);
    return 0;
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
