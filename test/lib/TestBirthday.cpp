/*
 * TestBirthday.cpp
 *
 *  Created on: 19 déc. 2017
 *      Author: omar
 */

#include "TestBirthday.h"


TEST_F(TestBirthday, constructorTest) {
	BirthDay::Birthday b{
		BirthDay::NUM_OF_DAY::Type::_1,
		BirthDay::MONTH::Type::JANUARY,
		2015
	};
	std::stringstream ss;
	ss << b;

	EXPECT_EQ(ss.str(), "Thursday 1 January 2015");
	b.setYears(2020);
	ss.str("");
	ss.clear();
	ss << b;
	EXPECT_EQ(ss.str(), "Wednesday 1 January 2020");
}

TEST_F(TestBirthday, constructorCopyTest) {
	BirthDay::Birthday b{
		BirthDay::NUM_OF_DAY::Type::_1,
		BirthDay::MONTH::Type::JANUARY,
		2015
	};

	BirthDay::Birthday bCopy{b};
	EXPECT_TRUE(b == bCopy);
}

TEST_F(TestBirthday, operatorCopyTest) {
	BirthDay::Birthday b{
		BirthDay::NUM_OF_DAY::Type::_1,
		BirthDay::MONTH::Type::JANUARY,
		2015
	};

	BirthDay::Birthday bCopy;
	bCopy = b;
	EXPECT_TRUE(b == bCopy);
}

TEST_F(TestBirthday, get_setMonth) {
	EXPECT_EQ(BirthDay::MONTH::Type::UNKNOWN, getMonth());
	for(const auto montE: ::BirthDay::MONTH::All) {
		setMonth(montE);
		EXPECT_EQ(montE, getMonth());
	}
}

TEST_F(TestBirthday, getDay) {
	EXPECT_EQ(0, getAge());
	setYears(1982);
	setMonth(BirthDay::MONTH::Type::APRIL);
	setNumOfDay(BirthDay::NUM_OF_DAY::Type::_16);
	EXPECT_EQ(getDay(), BirthDay::DAYS::Type::FRIDAY);
}

TEST_F(TestBirthday, getAge) {
	EXPECT_EQ(BirthDay::DAYS::Type::UNKNOWN, getDay());
	setYears(1982);
	setMonth(BirthDay::MONTH::Type::APRIL);
	setNumOfDay(BirthDay::NUM_OF_DAY::Type::_16);
	std::time_t now = std::time(nullptr);
	std::tm nowTm = *std::gmtime(&now);
	EXPECT_EQ(getAge(), nowTm.tm_year - 82);
}

TEST_F(TestBirthday, getDayString) {
	EXPECT_EQ(BirthDay::DAYS_NAME[static_cast<unsigned short>(BirthDay::DAYS::Type::UNKNOWN)], getDayString());
}

TEST_F(TestBirthday, get_setNumOfDay) {
	EXPECT_EQ(BirthDay::NUM_OF_DAY::Type::UNKNOWN, getNumOfDay());
	for(const auto dayE: ::BirthDay::NUM_OF_DAY::All) {
		setNumOfDay(dayE);
		EXPECT_EQ(dayE, getNumOfDay());
	}
}

TEST_F(TestBirthday, get_setYears) {

	EXPECT_EQ(0, getYears());
	for(unsigned int yearE = 1900; yearE < 4000; ++yearE) {
		setYears(yearE);
		EXPECT_EQ(yearE, getYears());
	}
}

TEST_F(TestBirthday, operatorStream) {
	std::stringstream ss;
	ss << *this;
	EXPECT_EQ(ss.str(), "Unknown Unknown Unknown 0");
	setYears(1982);
	setMonth(BirthDay::MONTH::Type::APRIL);
	setNumOfDay(BirthDay::NUM_OF_DAY::Type::_16);
	ss.str("");
	ss.clear();
	ss << *this;
	EXPECT_EQ(ss.str(), "Friday 16 April 1982");
}

TEST_F(TestBirthday, operatorEquality) {
	BirthDay::Birthday birthDay;
	EXPECT_TRUE(*this == birthDay);
	setYears(1982);
	setMonth(BirthDay::MONTH::Type::APRIL);
	setNumOfDay(BirthDay::NUM_OF_DAY::Type::_16);
	EXPECT_FALSE(*this == birthDay);
}

TEST_F(TestBirthday, operatorNotEquality) {
	BirthDay::Birthday birthDay;
	EXPECT_FALSE(*this != birthDay);
	setYears(1982);
	setMonth(BirthDay::MONTH::Type::APRIL);
	setNumOfDay(BirthDay::NUM_OF_DAY::Type::_16);
	EXPECT_TRUE(*this != birthDay);
}
