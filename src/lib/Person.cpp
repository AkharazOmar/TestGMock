/*
 * Person.cpp
 *
 *  Created on: 17 déc. 2017
 *      Author: omar
 */

#include "Person.h"

const std::vector<std::string> Person::SEXE_NAME = {
		"UNKNOWN",
		"Man",
		"Woman"
};

Person::Person()
{

}

Person::~Person()
{
	try {
		if (_father) {
			delete _father;
		}
		if (_mother) {
			delete _mother;
		}
		if (_birthDay) {
			delete _birthDay;
		}
	} catch (const std::exception& e) {
		std::cerr << "[Person] Exception throw in destructor: " << e.what() << std::endl;
	}
}

void Person::copyPrs(const Person& prs) {
	_firstName = prs._firstName;
	_lastName = prs._lastName;
	_cityBirth = prs._cityBirth;
	_sexe = prs.sexe();
	_nationality = prs.nationality();

	if (prs._birthDay) {
		_birthDay = prs._birthDay;
	}
	if (prs._father) {
		_father = new Person(*prs._father);
	}
	if (prs._mother) {
		_mother = new Person(*prs._mother);
	}
}

Person::Person(const Person& prs)
{
	copyPrs(prs);
}

Person& Person::operator=(const Person& prs)
{
	if (*this != prs) {
		copyPrs(prs);
	}
	return *this;
}

unsigned short Person::getAge() const
{
	return _birthDay->getAge();
}

const std::string& Person::getFirstName() const
{
	return _firstName;
}

const std::string& Person::getLastName() const
{
	return _lastName;
}

Person::SEXE Person::sexe() const
{
	return _sexe;
}

const std::string& Person::sexeStr() const
{
	return SEXE_NAME.at(static_cast<unsigned short>(sexe()));
}

const std::string& Person::nationality() const
{
	return _nationality;
}

const Person& Person::getFather() const
{
	return *_father;
}

const Person& Person::getMother() const
{
	return *_mother;
}

const std::string& Person::cityBirth() const
{
	return _cityBirth;
}

const ::BirthDay::Birthday& Person::getBirthDay() const
{
	return *_birthDay;
}

std::ostream& operator<<(std::ostream& os, const Person& prs)
{
	os << "FistName: " << prs.getFirstName() << std::endl
			<< "LastName: " << prs.getLastName() << std::endl
			<< "Sexe: " << prs.sexeStr() << std::endl
			<< "Nationality: " << prs.nationality() << std::endl
			<< "City birth: " << prs.cityBirth() << std::endl;
	if (prs._birthDay) {
		os << "Age: " << prs.getAge() <<std::endl
			<< "Birthday: " << prs._birthDay << std::endl;
	} else {
		os << "Birthday is not defined." << std::endl;
	}
	return os;
}

bool operator==(const Person& lprs, const Person& rprs)
{
	if (lprs._birthDay && rprs._birthDay) {
		return (lprs.getFirstName() == rprs.getFirstName()) &&
				(lprs.getLastName() == rprs.getLastName()) &&
				(lprs.getBirthDay() == rprs.getBirthDay());
	} else if (lprs._birthDay == nullptr && rprs._birthDay == nullptr) {
		return (lprs.getFirstName() == rprs.getFirstName()) &&
				(lprs.getLastName() == rprs.getLastName());
	}
	return false;
}

bool operator!=(const Person& lprs, const Person& rprs)
{
	return !(lprs == rprs);
}

bool operator<(const Person& lprs, const Person& rprs)
{
	return true;
}

bool operator>(const Person& lprs, const Person& rprs)
{
	return !(lprs < rprs);
}

bool operator>=(const Person& lprs, const Person& rprs)
{
	return true;
}

bool operator<=(const Person& lprs, const Person& rprs)
{
	return false;
}
