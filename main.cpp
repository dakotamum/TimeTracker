#include <iostream>
#include <ctime>
#include <chrono>
#include "Date.hpp"

void printGary()
{
	std::cout << "\n        ------                                                     ";
	std::cout << "\n       |      |                                                    ";
	std::cout << "\n      \\|______|/                                                  ";
	std::cout << "\n      /        \\                                                  ";
	std::cout << "\n     |  0   0  |  Hi! I'm Gary, your personal GUIduck. Ha. Get it? ";
	std::cout << "\n     | \\  *  / |                                                  ";
	std::cout << "\n     |  -----  |     How may I help you?                           ";
	std::cout << "\n     |          \\                                                 ";
	std::cout << "\n      \\          \\                                               ";
	std::cout << "\n       \\          \\                                            \n";
}

void printMenu()
{
	std::cout << "1. Punch in current time\n";
	std::cout << "2. Punch out with current time\n";
	std::cout << "3. Add time\n";
	std::cout << "4. Take out time\n";
	std::cout << "5. Exit\n";
}

void PrintDateStats(std::vector<Date> aDateVector)
{
	for (int i = 0; i < aDateVector.size(); i++)
	{
		std::cout << aDateVector[i].getMonth() << "/" << aDateVector[i].getDay() << "/" << aDateVector[i].getYear() << std::endl;
		aDateVector[i].PrintTimes();
	}
}

int main()
{
	printGary();
	std::vector<Date> theDateVector = {};

	int option;
	do
	{
		printMenu();
		std::cin >> option;
		switch (option)
		{
		case 1:
			if (theDateVector.size() != 0)
			{
				Date lastDate = theDateVector[theDateVector.size() - 1];
				if (lastDate.getDay() == Date::getCurrentDay() && lastDate.getMonth() == Date::getCurrentMonth() && lastDate.getYear() == Date::getCurrentYear())
				{
					theDateVector[theDateVector.size()-1].ClockIn();
				}
				else
				{
					Date newDate = Date();
					theDateVector.push_back(newDate);
				}
			}
			else
			{
				Date aNewDate = Date();
				theDateVector.push_back(aNewDate);
			}
			break;
		case 2:
			theDateVector[theDateVector.size() - 1].ClockOut();
			break;
		}


	} while (option != 5);

	/*time_t rawtime;
	struct tm timeinfo;
	time(&rawtime);
	localtime_s(&timeinfo, &rawtime);

	std::cout << Date::getCurrentMinute() << std::endl;
	*/

	PrintDateStats(theDateVector);

	return 0;
}