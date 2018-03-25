/*
 * GroupPersons.h
 *
 *  Created on: 3 mars 2018
 *      Author: omar
 */

#ifndef LIB_GROUPPERSONS_H_
#define LIB_GROUPPERSONS_H_

#include "InterfaceTest.h"
#include "Person.h"

class GroupPersons: public InterfaceTest<Person> {
public:
	GroupPersons();
	virtual ~GroupPersons();
};

#endif /* LIB_GROUPPERSONS_H_ */
