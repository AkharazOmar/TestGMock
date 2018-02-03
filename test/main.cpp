/*
 * main.cpp
 *
 *  Created on: 19/12/2017
 *      Author: omar
 */

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "lib/TestBirthday.h"
#include "lib/TestPerson.h"
#include "lib/TestNumericLimitMap.h"


int main( int argc, char *argv[] )
{
	testing::GTEST_FLAG(throw_on_failure) = false;
    testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}
