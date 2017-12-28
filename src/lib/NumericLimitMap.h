/*
 * NumericLimitMap.h
 *
 *  Created on: 25/12/2017
 *      Author: omar
 */

#ifndef LIB_NUMERICLIMITMAP_H_
#define LIB_NUMERICLIMITMAP_H_

#include <map>
#include "utils.h"


namespace Numeric {

class NumericLimitMap: public std::map<std::string, NumericLimit*> {
public:
	enum NUMERIC_TYPE: unsigned short {
		INT,
		FLOAT,
		DOUBLE,
		LONG
	};

	static const std::map<NUMERIC_TYPE, std::string> NUMERIC_NAME;
	NumericLimitMap();
	virtual ~NumericLimitMap();

};

} /* namespace Numeric */

#endif /* LIB_NUMERICLIMITMAP_H_ */
