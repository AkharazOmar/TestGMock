/*
 * TestXMLTree.cpp
 *
 *  Created on: 8 févr. 2018
 *      Author: omar
 */

#include "../../src/lib/XMLTree.h"

#include <gtest/gtest.h>

TEST(TestXMLTree, all)
{
	Numeric::XMLTree xml;
	xml.create();
	xml.save();
}

