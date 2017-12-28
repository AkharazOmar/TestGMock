/*
 * TestBirthday.h
 *
 *  Created on: 19 déc. 2017
 *      Author: omar
 */

#ifndef LIB_TESTBIRTHDAY_H_
#define LIB_TESTBIRTHDAY_H_
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "../../src/lib/Birthday.h"

using ::testing::Return;


class MockBirthday : public ::BirthDay::Birthday {
public:
	// MOCK_CONST_METHOD0(getDay, ::BirthDay::DAYS());
	MOCK_CONST_METHOD0(getDayString, std::string());
};


class TestBirthday: public testing::Test, public BirthDay::Birthday
{
public:
	TestBirthday() {

	}

	virtual ~TestBirthday() {

	}

	virtual void SetUp() {

	}

	virtual void TearDown() {

	}
};



#endif /* LIB_TESTBIRTHDAY_H_ */
