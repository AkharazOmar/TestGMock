/*
 * TestPerson.cpp
 *
 *  Created on: 19/12/2017
 *      Author: omar
 */

#include "TestPerson.h"
#include <iostream>
#include "../../src/lib/utils.h"

TEST_F(TestPersonFixture, PersonFirstnameTest)
{
	EXPECT_EQ(getFirstName(), "UNKNOWN");
	setFirstName("Firstname");
	EXPECT_EQ(getFirstName(), "Firstname");
}

TEST_F(TestPersonFixture, PersonLastnameTest)
{
	EXPECT_EQ(getLastName(), "UNKNOWN");
	setLastName("Lastname");
	EXPECT_EQ(getLastName(), "Lastname");
}

TEST_F(TestPersonFixture, OperatorEqual)
{
	Person operEqual;
	EXPECT_FALSE(operEqual == *this);
	EXPECT_TRUE(operEqual != *this);
	Person origin;
	origin.setFirstName("MyFirstname");
	origin.setLastName("MyLastname");
	origin.setBirthDay(
			BirthDay::Birthday(
					BirthDay::NUM_OF_DAY::Type::_1,
					BirthDay::MONTH::Type::JANUARY,
					2000)
	);
	origin.setCityBirth("Paris");
	origin.setNationality("France");
	origin.setSexe(Person::SEXE::MAN);
	operEqual = origin;
}

// TEST_F(TestPersonFixture, DISABLED_PersonTestBirthDayMock)
TEST_F(TestPersonFixture, PersonTestBirthDayMock)
{
	EXPECT_CALL(*_mockBirthDay, getDayString())
			.Times(AtLeast(2))
			.WillOnce(Return("SATURDAY"))
			.WillOnce(Return("SUNDAY"))
			.WillRepeatedly(Return("MONDAY"));

	EXPECT_EQ(_birthDay->getDayString(), "SATURDAY");
	EXPECT_EQ(getBirthDay().getDayString(), "SUNDAY");
	EXPECT_EQ(getBirthDay().getDayString(), "MONDAY");
	EXPECT_EQ(getBirthDay().getDayString(), "MONDAY");
}
