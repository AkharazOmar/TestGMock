/*
 * NumericLimitMap_test.cpp
 *
 *  Created on: 25/12/2017
 *      Author: omar
 */
#include "TestNumericLimitMap.h"

namespace Numeric {

TEST_F(TestNumericLimitMap, testIntMinMax) {
	EXPECT_EQ(
			std::stoi(
					nMap[Numeric::NumericLimitMap::NUMERIC_NAME.at(Numeric::NumericLimitMap::INT)]->min().str()),
			std::numeric_limits<int>::min());
	EXPECT_EQ(
			std::stoi(
					nMap[Numeric::NumericLimitMap::NUMERIC_NAME.at(Numeric::NumericLimitMap::INT)]->max().str()),
			std::numeric_limits<int>::max());
}

TEST_F(TestNumericLimitMap, testDoubleMinMax) {
	std::ostringstream strs;
	strs << std::numeric_limits<double>::min();
	EXPECT_EQ(
			nMap[Numeric::NumericLimitMap::NUMERIC_NAME.at(Numeric::NumericLimitMap::DOUBLE)]->min().str(),
			strs.str());
	strs.str("");
	strs.clear();
	strs << std::numeric_limits<double>::max();
	EXPECT_EQ(
			nMap[Numeric::NumericLimitMap::NUMERIC_NAME.at(Numeric::NumericLimitMap::DOUBLE)]->max().str(),
			strs.str());
}

TEST_F(TestNumericLimitMap, testLongMinMax) {
	std::ostringstream strs;
	strs << std::numeric_limits<long>::min();
	EXPECT_EQ(
			nMap[Numeric::NumericLimitMap::NUMERIC_NAME.at(Numeric::NumericLimitMap::LONG)]->min().str(),
			strs.str());
	strs.str("");
	strs.clear();
	strs << std::numeric_limits<long>::max();
	EXPECT_EQ(
			nMap[Numeric::NumericLimitMap::NUMERIC_NAME.at(Numeric::NumericLimitMap::LONG)]->max().str(),
			strs.str());
}

TEST_F(TestNumericLimitMap, testFloatMinMax) {
	std::ostringstream strs;
	strs << std::numeric_limits<float>::min();
	EXPECT_EQ(
			nMap[Numeric::NumericLimitMap::NUMERIC_NAME.at(Numeric::NumericLimitMap::FLOAT)]->min().str(),
			strs.str());
	strs.str("");
	strs.clear();
	strs << std::numeric_limits<float>::max();
	EXPECT_EQ(
			nMap[Numeric::NumericLimitMap::NUMERIC_NAME.at(Numeric::NumericLimitMap::FLOAT)]->max().str(),
			strs.str());
}

} /* namespace Numeric */
