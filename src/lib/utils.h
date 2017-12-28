/*
 * utils.h
 *
 *  Created on: 24/12/2017
 *      Author: omar
 */

#ifndef LIB_UTILS_H_
#define LIB_UTILS_H_
#include <iostream>
#include <sstream>
#include <string>


class NumericLimit {
public:

	virtual ~NumericLimit() {
		try {

		} catch (std::exception& e) {
			std::cerr << "Error raise when try to destroy NumericLimit object." << std::endl;
			std::cerr << e.what() << std::endl;
		}
	}
	virtual std::ostringstream max() = 0;
	virtual std::ostringstream min() = 0;
};

class NumericLimitInt: public NumericLimit {
public:
	virtual std::ostringstream min() override;
	virtual std::ostringstream max() override;
};

class NumericLimitDouble: public NumericLimit {
public:
	virtual std::ostringstream min() override;
	virtual std::ostringstream max() override;
};

class NumericLimitFloat: public NumericLimit {
public:
	virtual std::ostringstream min() override;
	virtual std::ostringstream max() override;
};

class NumericLimitLong: public NumericLimit {
public:
	virtual std::ostringstream min() override;
	virtual std::ostringstream max() override;
};


//std::tuple<std::string, std::string> numericLimitsInt()
//{
//	return std::make_tuple(std::to_string(std::numeric_limits<int>::min()), std::to_string(std::numeric_limits<int>::max()));
//}
//
//
//std::tuple<std::string, std::string> numericLimitsDouble()
//{
//	return std::make_tuple(std::to_string(std::numeric_limits<double>::min()), std::to_string(std::numeric_limits<double>::max()));
//}
//
//std::tuple<std::string, std::string> numericLimitsFloat()
//{
//	return std::make_tuple(std::to_string(std::numeric_limits<float>::min()), std::to_string(std::numeric_limits<float>::max()));
//}
//
//std::ostringstream numericLimitsLong()
//{
//	std::ostringstream osMin;
//	osMin << "Min: " << std::numeric_limits<long>::min() << " Max: " << std::numeric_limits<long>::max();
//	return osMin;
//}
//
//std::ostringstream numericLimitsDouble()
//{
//	std::ostringstream osMin;
//	osMin << "Min: " << std::numeric_limits<double>::min() << " Max: " << std::numeric_limits<double>::max();
//	return osMin;
//}

// typedef std::tuple<std::string, std::string> (*pFunc)();


// std::cout << "Max double : " << std::get<1>((*funMap["double"])()) << std::endl;
//	std::cout << "Min double : " << std::get<0>((*funMap["double"])()) << std::endl;
//	std::cout << "Max float : " << std::get<1>((*funMap["float"])()) << std::endl;
//	std::cout << "Min float : " << std::get<0>((*funMap["float"])()) << std::endl;
//	std::cout << "Max long : " << std::get<1>((*funMap["long"])()) << std::endl;
//	std::cout << "Min long : " << std::get<0>((*funMap["long"])()) << std::endl;
#endif /* LIB_UTILS_H_ */
