#include "pch.h"
#include "CppUnitTest.h"
#include "..\PW_2_Kosolapov_var6_OPPO\Date.cpp"
#include "..\PW_2_Kosolapov_var6_OPPO\main.cpp"
#include "..\PW_2_Kosolapov_var6_OPPO\Date.h"
#include "..\PW_2_Kosolapov_var6_OPPO\Temp_Measurement.h"
#include "..\PW_2_Kosolapov_var6_OPPO\Temp_Measurement.cpp"
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(LoadTests)
	{
	public:

		TEST_METHOD(LoadCorrectData)
		{
			std::istringstream ist("2023.12.29 Krasnoyarsk -2");
			std::vector <TempMeasurement> temp_measurements_box;
			write_measurements(temp_measurements_box, ist);
			Date buffdate = temp_measurements_box[0].get_date();
			Assert::AreEqual(buffdate.get_year(), 2023);
			Assert::AreEqual(buffdate.get_month(), 12);
			Assert::AreEqual(buffdate.get_day(), 29);
			std::string line = "Krasnoyarsk";
			Assert::AreEqual(temp_measurements_box[0].get_location(), line);
			Assert::AreEqual(temp_measurements_box[0].get_temperature(), -2.0);
		}

		TEST_METHOD(LoadIncorrectData)
		{
			std::istringstream ist("Full incorect data: ^^sadsadasdAS*DFSDgasd8asdhhAsd8xczsa7d-zhgxczx78a");
			std::vector <TempMeasurement> temp_measurements_box;
			Assert::ExpectException <std::runtime_error&>([&] { write_measurements(temp_measurements_box, ist); });
		};


	};


	TEST_CLASS(DateTests)
	{
	public:
		TEST_METHOD(LoadCorrectDate)
		{
			std::istringstream ist("2023.12.29 ");
			Date buffdate;
			buffdate.read_date(ist);
			Assert::AreEqual(buffdate.get_year(), 2023);
			Assert::AreEqual(buffdate.get_month(), 12);
			Assert::AreEqual(buffdate.get_day(), 29);
		}

		TEST_METHOD(LoadIncorrectYear)
		{
			std::istringstream ist("**.12.29 ");
			Date buffdate;
			Assert::ExpectException <std::runtime_error&>([&] { buffdate.read_date(ist); });
		}

		TEST_METHOD(LoadIncorrectMonth)
		{
			std::istringstream ist("2023..29 ");
			Date buffdate;
			Assert::ExpectException <std::runtime_error&>([&]
				{
					buffdate.read_date(ist);
				});
		};

		TEST_METHOD(LoadIncorrectDay)
		{
			std::istringstream ist("2023.12.--");
			Date buffdate;
			Assert::ExpectException <std::runtime_error&>([&] {buffdate.read_date(ist); });
		};
	};


	TEST_CLASS(LocationTests)
	{
	public:
		TEST_METHOD(LoadCorrectLocation)
		{
			std::istringstream ist("Krasnoyarsk ");
			TempMeasurement bufflocation;
			bufflocation.read_location(ist);
			std::string buffline = "Krasnoyarsk";
			Assert::AreEqual(bufflocation.get_location(), buffline);

		}

		TEST_METHOD(LoadIncorrectLocation)
		{
			std::istringstream ist("**_asdalu ");
			TempMeasurement bufflocation;
			Assert::ExpectException <std::runtime_error&>([&] { bufflocation.read_location(ist); });
		}

		
	};


	TEST_CLASS(TemperatureTests)
	{
	public:
		TEST_METHOD(LoadCorrectTemperature)
		{
			std::istringstream ist("-12");
			TempMeasurement bufftemperature;
			bufftemperature.read_temperature(ist);
			Assert::AreEqual(bufftemperature.get_temperature(), -12.0);

		}

		TEST_METHOD(LoadIncorrectTemperature)
		{
			std::istringstream ist("");
			TempMeasurement bufftemperature;
			Assert::ExpectException <std::runtime_error&>([&] { bufftemperature.read_temperature(ist); });
		}


	};
}