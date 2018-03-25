/*
 * TestGroupPerson.h
 *
 *  Created on: 3 mars 2018
 *      Author: omar
 */

#ifndef LIB_TESTGROUPPERSONS_H_
#define LIB_TESTGROUPPERSONS_H_

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <memory>
#include <map>

#include "../../src/lib/GroupPersons.h"

using ::testing::Return;
using ::testing::AtLeast;


class TestGroupPersonsFixture: public testing::Test, public GroupPersons
{
public:
	TestGroupPersonsFixture() {

	}

	virtual ~TestGroupPersonsFixture() {

	}

	virtual void SetUp() {
		auto person1 = new Person();
		person1->setFirstName("First");
		person1->setLastName("First");
		insert(0, person1);
		auto person2 = new Person();
		person2->setFirstName("Second");
		person2->setLastName("Second");
		insert(1, person2);
		auto person3 = new Person();
		person3->setFirstName("Third");
		person3->setLastName("Third");
		insert(3, person3);
		auto person4 = new Person();
		person4->setFirstName("Fourth");
		person4->setLastName("Fourth");
		insert(4, person4);
	}

	virtual void TearDown() {
		// clean();
	}
};

#endif /* LIB_TESTGROUPPERSONS_H_ */
