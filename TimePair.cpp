#include "Date.hpp"

Date::TimePair::TimePair()
{
	m_timeInHour = getCurrentHour();
	m_timeInMinute = getCurrentMinute();
	m_timeOutHour = m_timeInHour;
	m_timeOutMinute = m_timeInMinute;
}