// PW_2_Kosolapov_var6_OPPO.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

//#include "pch.h"
#include "Temp_Measurement.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

void print_measurements(vector <TempMeasurement>& data1, ostream& ost)
{
    for (int i = 0; i < data1.size(); i++)
    {
        data1[i].print(ost);
    }
}

void write_measurements(vector <TempMeasurement>& data1, istream& ist)
{
    while (!ist.eof())
    {
        TempMeasurement buff;
        buff.read(ist);
        data1.push_back(buff);
    }
}

int main()
{
    /*string line;
    getline(cin, line);
    find(line.begin(), line.end(), ' ');
    find(line.rbegin(), line.rend(), ' ');
    find_end(line.begin(), line.end(), ' ');*/



    vector <TempMeasurement> temp_measurements_box;
    ifstream in("in.txt");
    if (!in.is_open())
    {
        cout << "File is not opened";
        return 1;
    }
    write_measurements(temp_measurements_box, in);
    print_measurements(temp_measurements_box, cout);

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
