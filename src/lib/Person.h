/*
 * Person.h
 *
 *  Created on: 17 déc. 2017
 *      Author: omar
 */

#ifndef LIB_PERSON_H_
#define LIB_PERSON_H_

#include <iostream>
#include <string>

#include "Birthday.h"

class Person {


public:
	enum class SEXE: unsigned short {
		UNKNOWN,
		MAN,
		WOMAN
	};

	Person();
	virtual ~Person();

	explicit Person(const Person& prs);
	Person& operator=(const Person& prs);

	virtual unsigned short getAge() const;
	virtual const std::string& getFirstName() const;
	virtual const std::string& getLastName() const;
	virtual SEXE sexe() const;
	virtual const std::string& sexeStr() const;
	virtual const std::string& nationality() const;
	virtual const ::BirthDay::Birthday& getBirthDay() const;

	virtual const Person& getFather() const;
	virtual const Person& getMother() const;
	virtual const std::string& cityBirth() const;

	virtual void setBirthDay(const ::BirthDay::Birthday& birthDay) {
		if (_birthDay  != nullptr) {
			delete _birthDay;
		}
		_birthDay = new BirthDay::Birthday(birthDay);
	}

	virtual void setCityBirth(const std::string& cityBirth = "UNKNOWN") {
		_cityBirth = cityBirth;
	}

	virtual void setFirstName(const std::string& firstName = "UNKNOWN") {
		_firstName = firstName;
	}

	virtual void setLastName(const std::string& lastName = "UNKNOWN") {
		_lastName = lastName;
	}

	virtual void setNationality(const std::string& nationality = "UNKNOWN") {
		_nationality = nationality;
	}

	virtual void setSexe(const Person::SEXE& sexe) {
		_sexe = sexe;
	}

	virtual void setFather(const Person& father) {
		std::cerr << father << std::endl;
		this->_father = new Person(father);
	}

	virtual void setMother(const Person& mother) {
		this->_mother = new Person(mother);
	}

	friend std::ostream& operator<<(std::ostream& os, const Person& prs);
	friend bool operator==(const Person& lprs, const Person& rprs);
	friend bool operator!=(const Person& lprs, const Person& rprs);
	friend bool operator<(const Person& lprs, const Person& rprs);
	friend bool operator>(const Person& lprs, const Person& rprs);
	friend bool operator>=(const Person& lprs, const Person& rprs);
	friend bool operator<=(const Person& lprs, const Person& rprs);

protected:

	std::string _firstName = "UNKNOWN",
	_lastName = "UNKNOWN",
	_nationality = "UNKNOWN",
	_cityBirth = "UNKNOWN";
	Person::SEXE _sexe = Person::SEXE::UNKNOWN;
	Person* _father = nullptr;
	Person*_mother = nullptr;
	::BirthDay::Birthday* _birthDay = nullptr;
	static const std::vector<std::string> SEXE_NAME;

	void copyPrs(const Person& prs);
};

#endif /* LIB_PERSON_H_ */
