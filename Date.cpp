#include "Date.hpp"

#include <iostream>
#include <ctime>
#include <iomanip>

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

double Date::getTotalTime()
{
	double time = 0;
	for (int i = 0; i < timepairs.size(); i++)
	{
		time += (timepairs[i].getTimeOutHour() + (timepairs[i].getTimeOutMinute() / 60)) - (timepairs[i].getTimeInHour() + (timepairs[i].getTimeInMinute() / 60));
	}
	return time;
}

// clock in
void Date::ClockIn()
{
	TimePair newPear = TimePair();
	appendPair(newPear);
	std::cout << "This should have worked!\n";
}

// clock out

void Date::ClockOut()
{
	timepairs[timepairs.size() - 1].setTimeOutHour(Date::getCurrentHour()), timepairs[timepairs.size() - 1].setTimeOutMinute(Date::getCurrentMinute());
}


void Date::PrintTimes()
{
	std::cout << "   Time In                Time Out\n";
	for (int i = 0; i < timepairs.size(); i++)
	{
		std::cout << std::setw(5) << timepairs[i].getTimeInHour() << ":" << timepairs[i].getTimeInMinute() << std::setw(20) << timepairs[i].getTimeOutHour() << ":" << timepairs[i].getTimeOutMinute() << std::endl;
	}
	std::cout << "-------------------------------------------------------\n";
	std::cout << "     Total Time (in Hours): " << getTotalTime() << std::endl;
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