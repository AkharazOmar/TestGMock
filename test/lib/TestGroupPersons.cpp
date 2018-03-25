/*
 * GroupPersons_test.cpp
 *
 *  Created on: 3 mars 2018
 *      Author: omar
 */

#include "TestGroupPersons.h"


TEST_F(TestGroupPersonsFixture, AddPerson)
{
	auto p = new Person();
	EXPECT_ANY_THROW(insert(0, p));
	insert(5, p);
	auto retV = getT(5);
	EXPECT_EQ(retV, p);
}

TEST_F(TestGroupPersonsFixture, getT)
{
	std::cout << "HELLO WORLD getPerson" << std::endl;
	auto p = getT(0);
	EXPECT_EQ(p->getFirstName(), "First");
	EXPECT_ANY_THROW(getT(5));
//	auto per = getT(5);
//	std::cout << per->getFirstName() << std::endl;
}
