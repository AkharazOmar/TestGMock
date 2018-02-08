/*
 * XMLTree.cpp
 *
 *  Created on: 8 févr. 2018
 *      Author: omar
 */

#include "XMLTree.h"

namespace Numeric {

XMLTree::XMLTree()
{
	// TODO Auto-generated constructor stub

}

XMLTree::~XMLTree()
{
	// TODO Auto-generated destructor stub
}

XMLTree::XMLTree(std::string path, std::string root):
		_path(path), _root(root)
{
}

bool XMLTree::create()
{
	ptree& root = tree.add(_root, "");
	ptree& filters = root.add("filters", "");
	auto filterList = {"filter1", "filter2", "filter3"};
	for(auto filterName: filterList) {
		auto& filter = filters.add("filter", "");
		filter.add("providerName", filterName);
		filter.add("sessionId", 1);
		filter.add("network", 65535);
	}
	return true;
}

bool XMLTree::save()
{
	write_xml(
			_path,
			tree,
			std::locale(),
			xml_writer_settings<std::string>(' ', 4)
			);
	return true;
}
} /* namespace Numeric */
