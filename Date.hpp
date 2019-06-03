#ifndef DATE_HPP
#define DATE_HPP

#include <iostream>
#include <vector>

class Date
{
private:
	double addedTime;
	double subtractedTime;
	double m_day;
	double m_month;
	double m_year;
	
	class TimePair
	{
	private:
		double m_timeInHour;
		double m_timeInMinute;
		double m_timeOutHour;
		double m_timeOutMinute;
	public:
		TimePair();
		double getTimeInHour() { return m_timeInHour; }
		double getTimeInMinute() { return m_timeInMinute; }
		double getTimeOutHour() { return m_timeOutHour; }
		double getTimeOutMinute() { return m_timeInMinute; }
	};
	std::vector<TimePair> timepairs;

public:
	Date();
	static void ClockIn(Date&);
	void appendPair(TimePair aPear) { timepairs.push_back(aPear); }
	void ClockOut();
	void PrintTimes();
	double getDay(), getMonth(), getYear();
	static double getCurrentDay(), getCurrentMonth(), getCurrentYear(), getCurrentHour(), getCurrentMinute();
	
};

#endif