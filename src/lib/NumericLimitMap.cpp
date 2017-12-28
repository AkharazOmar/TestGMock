/*
 * NumericLimitMap.cpp
 *
 *  Created on: 25/12/2017
 *      Author: omar
 */

#include "NumericLimitMap.h"


namespace Numeric {

const std::map<NumericLimitMap::NUMERIC_TYPE, std::string> NumericLimitMap::NUMERIC_NAME = {
		std::pair<NumericLimitMap::NUMERIC_TYPE, std::string>(NumericLimitMap::NUMERIC_TYPE::INT, "int"),
		std::pair<NumericLimitMap::NUMERIC_TYPE, std::string>(NumericLimitMap::NUMERIC_TYPE::FLOAT, "float"),
		std::pair<NumericLimitMap::NUMERIC_TYPE, std::string>(NumericLimitMap::NUMERIC_TYPE::DOUBLE, "double"),
		std::pair<NumericLimitMap::NUMERIC_TYPE, std::string>(NumericLimitMap::NUMERIC_TYPE::LONG, "long")
};

NumericLimitMap::NumericLimitMap():
	std::map<std::string, NumericLimit*>()
{
	this->insert(
			std::pair<std::string, NumericLimit*>(
					NUMERIC_NAME.at(NUMERIC_TYPE::INT), new NumericLimitInt));
	this->insert(
			std::pair<std::string, NumericLimit*>(
					NUMERIC_NAME.at(NUMERIC_TYPE::FLOAT), new NumericLimitFloat));
	this->insert(
			std::pair<std::string, NumericLimit*>(
					NUMERIC_NAME.at(NUMERIC_TYPE::DOUBLE), new NumericLimitDouble));
	this->insert(
			std::pair<std::string, NumericLimit*>(
					NUMERIC_NAME.at(NUMERIC_TYPE::LONG), new NumericLimitLong));
}

NumericLimitMap::~NumericLimitMap()
{
	for(
			std::map<std::string, NumericLimit*>::iterator iter=begin();
			iter!=end(); ++iter) {
		delete iter->second;
	}
}

} /* namespace Numeric */
