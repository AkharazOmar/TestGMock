/*
 * TestPerson.cpp
 *
 *  Created on: 19/12/2017
 *      Author: omar
 */

#include <iostream>
#include <boost/type_index.hpp>

#include "TestPerson.h"
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

TEST_F(TestPersonFixture, CopyConstructor)
{

	using boost::typeindex::type_id_with_cvr;

	decltype(auto) mother = std::make_unique<Person>();
	decltype(auto) father = std::make_unique<Person>();
	mother->setFirstName("Mother");
	mother->setLastName("My");

	father->setFirstName("Father");
	father->setLastName("My");


	Person origin(*this);
	origin.setBirthDay(
			BirthDay::Birthday(
					BirthDay::NUM_OF_DAY::Type::_1,
					BirthDay::MONTH::Type::JANUARY,
					2000)
	);
	origin.setFirstName("MyFirstname");
	origin.setLastName("MyLastname");
	origin.setFather(*father);
	origin.setMother(*mother);
	auto coP(origin);
	EXPECT_TRUE(coP == origin);

	origin.setBirthDay(
			BirthDay::Birthday(
					BirthDay::NUM_OF_DAY::Type::_2,
					BirthDay::MONTH::Type::JANUARY,
					2000)
	);
	EXPECT_TRUE(coP != origin);

	std::cout << " type of coP: " << type_id_with_cvr<decltype(coP)>().pretty_name() << std::endl;
	std::cout << " type of coP2: " << type_id_with_cvr<decltype(origin)>().pretty_name() << std::endl;
//
//	std::cout << "cop :  " << coP << std::endl;
//	std::cout << "cop* :  " << coP << std::endl;
//
//	std::cout << "cop2 :  " << origin << std::endl;
}

TEST_F(TestPersonFixture, OperatorEqual)
{
	Person operEqual;
	EXPECT_FALSE(operEqual == *this);
	EXPECT_TRUE(operEqual != *this);
	Person origin;
	EXPECT_TRUE(operEqual == origin);
	EXPECT_FALSE(operEqual != origin);
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
	EXPECT_TRUE(operEqual == origin);
	EXPECT_FALSE(operEqual != origin);
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
