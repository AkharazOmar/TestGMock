/*
 * Birthday.h
 *
 *  Created on: 17 déc. 2017
 *      Author: omar
 */

#ifndef LIB_BIRTHDAY_H_
#define LIB_BIRTHDAY_H_

#include <ctime>
#include <iostream>
#include <vector>

namespace BirthDay {
	namespace DAYS {
		enum class Type : unsigned short {
			SUNDAY,
			MONDAY,
			TUESDAY,
			WEDNESDAY,
			THURSDAY,
			FRIDAY,
			SATURDAY,
			UNKNOWN
		};
		static const Type All[] = {
				Type::SUNDAY,
				Type::MONDAY,
				Type::TUESDAY,
				Type::WEDNESDAY,
				Type::THURSDAY,
				Type::FRIDAY,
				Type::SATURDAY
		};
	}
	namespace NUM_OF_DAY {
		enum class Type: unsigned short {
			_1=1,
			_2,
			_3,
			_4,
			_5,
			_6,
			_7,
			_8,
			_9,
			_10,
			_11,
			_12,
			_13,
			_14,
			_15,
			_16,
			_17,
			_18,
			_19,
			_20,
			_21,
			_22,
			_23,
			_24,
			_25,
			_26,
			_27,
			_28,
			_29,
			_30,
			_31,
			UNKNOWN
		};
		static const Type All[] = {
				Type::_1,
				Type::_2,
				Type::_3,
				Type::_4,
				Type::_5,
				Type::_6,
				Type::_7,
				Type::_8,
				Type::_9,
				Type::_10,
				Type::_11,
				Type::_12,
				Type::_13,
				Type::_14,
				Type::_15,
				Type::_16,
				Type::_17,
				Type::_18,
				Type::_19,
				Type::_20,
				Type::_21,
				Type::_22,
				Type::_23,
				Type::_24,
				Type::_25,
				Type::_26,
				Type::_27,
				Type::_28,
				Type::_29,
				Type::_30,
				Type::_31
		};
	}
	namespace MONTH {
		enum class Type : unsigned short {
			JANUARY,
			FEBRUARY,
			MARCH,
			APRIL,
			MAY,
			JUNE,
			JULY,
			AUGUST,
			SEPTEMBER,
			OCTOBER,
			NOVEMBER,
			DECEMBER,
			UNKNOWN
		};
		static const Type All[] = {
				Type::JANUARY,
				Type::FEBRUARY,
				Type::MARCH,
				Type::APRIL,
				Type::MAY,
				Type::JUNE,
				Type::JULY,
				Type::AUGUST,
				Type::SEPTEMBER,
				Type::OCTOBER,
				Type::NOVEMBER,
				Type::DECEMBER
		};
	}

	static const std::vector<std::string> DAYS_NAME = {
			"Sunday",
			"Monday",
			"Tuesday",
			"Wednesday",
			"Thursday",
			"Friday",
			"Saturday",
			"Unknown"
	};
	static const std::vector<std::string> MONTH_NAME = {
			"January",
			"February",
			"March",
			"April",
			"May",
			"June",
			"July",
			"August",
			"September",
			"October",
			"November",
			"December",
			"Unknown"
	};


class Birthday{

public:
	Birthday();
	explicit Birthday(const Birthday&);
	explicit Birthday(::BirthDay::NUM_OF_DAY::Type numOfDay, ::BirthDay::MONTH::Type month, unsigned int years);
	Birthday& operator=(const Birthday& birthDay);
	virtual ~Birthday();

	virtual ::BirthDay::DAYS::Type getDay() const;
	virtual std::string getDayString() const;

	virtual unsigned short getAge() const;

	virtual ::BirthDay::MONTH::Type getMonth() const {
		return _month;
	}

	virtual void setMonth(::BirthDay::MONTH::Type month) {
		_month = month;
		checkBirthday();
	}

	virtual ::BirthDay::NUM_OF_DAY::Type getNumOfDay() const {
		return _numOfDay;
	}

	virtual void setNumOfDay(::BirthDay::NUM_OF_DAY::Type numOfDay) {
		_numOfDay = numOfDay;
		checkBirthday();
	}

	virtual unsigned int getYears() const {
		return _years;
	}

	virtual void setYears(unsigned int years = 1990) {
		_years = years;
		checkBirthday();
	}

	friend std::ostream& operator<<(std::ostream& os, const Birthday& brt);
	friend bool operator==(const Birthday& lbrt, const Birthday& rbrt);
	friend bool operator!=(const Birthday& lbrt, const Birthday& rbrt);

protected:

	NUM_OF_DAY::Type _numOfDay = NUM_OF_DAY::Type::UNKNOWN;
	MONTH::Type _month = MONTH::Type::UNKNOWN;
	unsigned int _years = 0;

	std::tm computedBirthday() const;
	void checkBirthday();
	void copyBirthday(const Birthday& prs);
};

}

#endif /* LIB_BIRTHDAY_H_ */
