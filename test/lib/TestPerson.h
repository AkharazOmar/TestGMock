/*
 * TestPerson.h
 *
 *  Created on: 19 déc. 2017
 *      Author: omar
 */

#ifndef LIB_TESTPERSON_H_
#define LIB_TESTPERSON_H_
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "TestBirthday.h"
#include "../../src/lib/Person.h"

using ::testing::Return;
using ::testing::AtLeast;

class TestPersonFixture: public testing::Test, public Person
{
public:
	TestPersonFixture() {
		_mockBirthDay = new MockBirthday();
		_birthDay = _mockBirthDay;
	}

	virtual ~TestPersonFixture() {

	}
	virtual void SetUp() {

	}

	virtual void TearDown() {

	}
protected:
	MockBirthday* _mockBirthDay;

};

#endif /* LIB_TESTPERSON_H_ */
