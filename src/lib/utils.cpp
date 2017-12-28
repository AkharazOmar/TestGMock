/*
 * utils.cpp
 *
 *  Created on: 24/12/2017
 *      Author: omar
 */
#include "utils.h"
#include <limits>


std::ostringstream NumericLimitInt::min() {
	std::ostringstream os;
	os << std::numeric_limits<int>::min();
	return os;
}

std::ostringstream NumericLimitInt::max() {
	std::ostringstream os;
	os << std::numeric_limits<int>::max();
	return os;
}

std::ostringstream NumericLimitDouble::min() {
	std::ostringstream os;
	os << std::numeric_limits<double>::min();
	return os;
}

std::ostringstream NumericLimitDouble::max() {
	std::ostringstream os;
	os << std::numeric_limits<double>::max();
	return os;
}

std::ostringstream NumericLimitFloat::min() {
	std::ostringstream os;
	os << std::numeric_limits<float>::min();
	return os;
}

std::ostringstream NumericLimitFloat::max() {
	std::ostringstream os;
	os << std::numeric_limits<float>::max();
	return os;
}

std::ostringstream NumericLimitLong::min() {
	std::ostringstream os;
	os << std::numeric_limits<long>::min();
	return os;
}

std::ostringstream NumericLimitLong::max() {
	std::ostringstream os;
	os << std::numeric_limits<long>::max();
	return os;
}
