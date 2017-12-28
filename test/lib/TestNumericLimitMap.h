/*
 * TestNumericLimitMap.h
 *
 *  Created on: 25 déc. 2017
 *      Author: omar
 */

#ifndef LIB_TESTNUMERICLIMITMAP_H_
#define LIB_TESTNUMERICLIMITMAP_H_

#include "../../src/lib/NumericLimitMap.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

using ::testing::Return;


class TestNumericLimitMap: public testing::Test
{
public:
	TestNumericLimitMap() {

	}

	Numeric::NumericLimitMap nMap;
};


#endif /* LIB_TESTNUMERICLIMITMAP_H_ */
