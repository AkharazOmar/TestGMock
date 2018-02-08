/*
 * XMLTree.h
 *
 *  Created on: 8 févr. 2018
 *      Author: omar
 */

#ifndef LIB_XMLTREE_H_
#define LIB_XMLTREE_H_

#include <iostream>
#include <string>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>

using boost::property_tree::ptree;
using boost::property_tree::write_xml;
using boost::property_tree::xml_writer_settings;

namespace Numeric {

class XMLTree {
public:
	XMLTree();
	explicit XMLTree(std::string path, std::string root="CONFIG");
	virtual ~XMLTree();

	virtual bool create();
	virtual bool save();

protected:
	ptree tree;
	std::string _root = "CONFIG";
	std::string _path = "/tmp/XMLTree.xml";
};

}
#endif /* LIB_XMLTREE_H_ */
