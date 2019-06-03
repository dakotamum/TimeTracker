#include "Date.hpp"

#include <iostream>
#include <ctime>

// default Date constructor
Date::Date()
{
	m_day = getCurrentDay();
	m_month = getCurrentMonth();
	m_year = getCurrentYear();
	TimePair newTimePair = TimePair();
	timepairs.push_back(newTimePair);
	addedTime = 0;
	subtractedTime = 0;
}

// getters
double Date::getDay()
{
	return m_day;	
}

double Date::getMonth()
{
	return m_month;
}

double Date::getYear()
{
	return m_year;
}


// clock in
void Date::ClockIn(Date &aDate)
{
	TimePair newPear = TimePair();
	aDate.appendPair(newPear);
	std::cout << "This should have worked!\n";
}

void Date::ClockOut()
{

}

void Date::PrintTimes()
{
	std::cout << "      Time In                     Time Out\n";
	for (int i = 0; i < timepairs.size(); i++)
	{
		std::cout << timepairs[i].getTimeInHour() << ":" << timepairs[i].getTimeInMinute() << std::endl;
	}
}


// static functions to get current time stats
double Date::getCurrentMinute()
{
	time_t rawtime;
	struct tm timeinfo;
	time(&rawtime);
	localtime_s(&timeinfo, &rawtime);
	return timeinfo.tm_min;
}

double Date::getCurrentHour()
{
	time_t rawtime;
	struct tm timeinfo;
	time(&rawtime);
	localtime_s(&timeinfo, &rawtime);
	return timeinfo.tm_hour;
}

double Date::getCurrentDay()
{
	time_t rawtime;
	struct tm timeinfo;
	time(&rawtime);
	localtime_s(&timeinfo, &rawtime);
	return timeinfo.tm_mday;
}

double Date::getCurrentMonth()
{
	time_t rawtime;
	struct tm timeinfo;
	time(&rawtime);
	localtime_s(&timeinfo, &rawtime);
	return static_cast<double>(timeinfo.tm_mon) + 1;
}

double Date::getCurrentYear()
{
	time_t rawtime;
	struct tm timeinfo;
	time(&rawtime);
	localtime_s(&timeinfo, &rawtime);
	return static_cast<double>(timeinfo.tm_year) + 1900;
}