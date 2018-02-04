/*
 * Birthday.cpp
 *
 *  Created on: 17 déc. 2017
 *      Author: omar
 */

#include "Birthday.h"
#include <ctime>
#include <iostream>
#include <iomanip>

namespace BirthDay {

Birthday::Birthday()
{
//	setenv("TZ", "/usr/share/zoneinfo/Europe/Paris", 1);
	setenv("TZ", "", 1);
}

Birthday::Birthday(const Birthday& birthDay)
{
	setenv("TZ", "", 1);
	copyBirthday(birthDay);
}

Birthday& Birthday::operator=(const Birthday& birthDay)
{
	setenv("TZ", "", 1);
	if (*this != birthDay) {
		copyBirthday(birthDay);
	}
	return *this;
}

void Birthday::copyBirthday(const Birthday& birthDay)
{
	_numOfDay = birthDay._numOfDay;
	_month = birthDay._month;
	_years = birthDay._years;
}

unsigned short Birthday::getAge() const
{
	if (_numOfDay == NUM_OF_DAY::Type::UNKNOWN &&
			_month == MONTH::Type::UNKNOWN &&
			_years == 0) {
		return 0;
	}

	std::time_t now = std::time(nullptr);
	std::tm birthday = computedBirthday();
	std::tm nowTm = *std::gmtime(&now);

	unsigned int diffYears = nowTm.tm_year - birthday.tm_year;
	return diffYears;
}

void Birthday::checkBirthday() {
	if (!(_numOfDay == NUM_OF_DAY::Type::UNKNOWN
			|| _month == MONTH::Type::UNKNOWN)) {
		std::time_t now = std::time(nullptr);
		std::tm birthday = *std::localtime(&now);
		birthday.tm_mday = static_cast<unsigned short>(getNumOfDay());
		birthday.tm_mon = static_cast<unsigned short>(getMonth());
		birthday.tm_year = getYears() - 1900;
		std::time_t birthdayTm = std::mktime(&birthday);
		if (now - birthdayTm < 0) {
			// TODO throw exception here...
			std::cerr << "You can't born in future..." << std::endl;
		}
	}
}

Birthday::Birthday(NUM_OF_DAY::Type numOfDay, MONTH::Type month, unsigned int years):
		_numOfDay(numOfDay), _month(month), _years(years)
{
//	setenv("TZ", "/usr/share/zoneinfo/Europe/Paris", 1);
	setenv("TZ", "", 1);
	checkBirthday();
}

std::tm BirthDay::Birthday::computedBirthday() const {
	std::time_t rawtime = std::time(nullptr);
	std::tm birthday = *std::gmtime(&rawtime);
	birthday.tm_mday = static_cast<unsigned short>(getNumOfDay());
	birthday.tm_mon = static_cast<unsigned short>(getMonth());
	birthday.tm_year = getYears() - 1900;
	mktime(&birthday);
	return birthday;
}

DAYS::Type Birthday::getDay() const
{
	if (_numOfDay == NUM_OF_DAY::Type::UNKNOWN &&
			_month == MONTH::Type::UNKNOWN &&
			_years == 0) {
		return DAYS::Type::UNKNOWN;
	}

	std::tm birthday = computedBirthday();
	return static_cast<DAYS::Type>(birthday.tm_wday);
}

std::string Birthday::getDayString() const
{
	return DAYS_NAME.at(static_cast<unsigned short>(getDay()));
}

Birthday::~Birthday() {
	try {

	} catch (const std::exception& e) {
		std::cerr << "Exception throw when try to destroy the Birthday: " << e.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, const Birthday& btd)
{
	std::string numDay = "Unknown";
	if (btd.getNumOfDay() != BirthDay::NUM_OF_DAY::Type::UNKNOWN) {
		std::stringstream ss;
		ss << static_cast<short>(btd.getNumOfDay());
		numDay = ss.str();
	}
	os << btd.getDayString() << " " <<
			 numDay << " " <<
			MONTH_NAME.at(static_cast<unsigned short>(btd.getMonth())) << " " <<
			btd.getYears();

	return os;
}

bool operator==(const Birthday& lbrt, const Birthday& rbrt)
{
	return lbrt.getNumOfDay() == rbrt.getNumOfDay() &&
			lbrt.getMonth() == rbrt.getMonth() &&
			lbrt.getYears() == rbrt.getYears();
}

bool operator!=(const Birthday& lbrt, const Birthday& rbrt)
{
	return !(lbrt == rbrt);
}

}
