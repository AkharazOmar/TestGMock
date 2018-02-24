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

TEST_F(TestPersonFixture, PersonPointer)
{
	Person * fPerson = new Person();
	fPerson->setFirstName("First");
	fPerson->setLastName("Person");

	Person * sPerson = fPerson;

	sPerson->setFirstName("Second");

	std::cout << "First pointer: " << fPerson << std::endl;
	std::cout << "Second pointer: " << sPerson << std::endl;
	std::cout << "First pointer &: " << &fPerson << std::endl;
	std::cout << "Second pointer &: " << &sPerson << std::endl;
	std::cout << *fPerson << std::endl;

	std::vector<Person*> persons;
	std::map<std::string, Person* > mapPersons;
	persons.push_back(fPerson);
	mapPersons.insert(std::pair<std::string, Person*>(fPerson->getLastName(), fPerson));

	for (Person * p: persons) {
		std::cout << "Pointer 1: " << p << std::endl;
		std::cout << "Address 1: " << &p << std::endl;
		std::cout << "Value 1: \n" << *p << std::endl;
	}
	Person * tPerson = new Person();
	tPerson->setFirstName("Third");
	tPerson->setLastName("Person");

	Person * pInVector = persons[0];
	*pInVector = *tPerson;
	delete tPerson;
	for (Person * p: persons) {
		std::cout << "Pointer 2: " << p << std::endl;
		std::cout << "Address 2: " << &p << std::endl;
		std::cout << "Value 2: \n" << *p << std::endl;
	}

	std::cout << "First pointer: " << fPerson << std::endl;
	std::cout << "First pointer &: " << &fPerson << std::endl;
	std::cout << *fPerson << std::endl;

	Person* fourthPerson = new Person();
	fourthPerson->setFirstName("Fourth");
	fourthPerson->setLastName("Person");

	for(std::map<std::string, Person*>::const_iterator pIt = mapPersons.cbegin(); pIt != mapPersons.cend(); ++pIt) {
		std::cout << "key: " << pIt->first << std::endl;
		std::cout << "Pointer Map1: " << pIt->second << std::endl;
		std::cout << "Address MAP1: " << &(pIt->second) << std::endl;
		std::cout << "Value 2: \n" << *(pIt->second) << std::endl;
	}

	*(mapPersons["Person"]) = *fourthPerson;

	for(std::map<std::string, Person*>::const_iterator pIt = mapPersons.cbegin(); pIt != mapPersons.cend(); ++pIt) {
		std::cout << "key: " << pIt->first << std::endl;
		std::cout << "Pointer Map2: " << pIt->second << std::endl;
		std::cout << "Address MAP2: " << &(pIt->second) << std::endl;
		std::cout << "Value 2: \n" << *(pIt->second) << std::endl;
	}
	for (Person * p: persons) {
		std::cout << "Pointer 3: " << p << std::endl;
		std::cout << "Address 3: " << &p << std::endl;
		std::cout << "Value 3: \n" << *p << std::endl;
	}

}
