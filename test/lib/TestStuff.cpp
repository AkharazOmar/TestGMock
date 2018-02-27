/*
 * TestStuff.cpp
 *
 *  Created on: 4 févr. 2018
 *      Author: omar
 */

#include "../../src/lib/Stuff.h"

#include <gtest/gtest.h>
#include <vector>
#include <tuple>
#include <boost/type_index.hpp>


using boost::typeindex::type_id_with_cvr;


TEST(TestStuff, aTemplate)
{
	// rvalue
	f_value(3);
	f_ref_const(3);
	// impossible de lier la référence d'une l-valeur non constante de type « int& » à une r-valeur de type « int »
	// f_ref(3);
	// impossible de lier la référence d'une l-valeur non constante de type « int& » à une r-valeur de type « int »
	// f_ref_no_change(3);

	// lvalue
	int x = 0;
	f_value(x);
	std::cout << "x: " << x << std::endl;
	f_ref_const(x);
	std::cout << "x: " << x << std::endl;
	f_ref(x);
	std::cout << "x: " << x << std::endl;
	f_ref_no_change(x);
	std::cout << "x: " << x << std::endl;

	const  int cx = x;
	f_value(cx);
	std::cout << "cx: " << cx << std::endl;
	f_ref_const(cx);
	std::cout << "cx: " << cx << std::endl;
	f_ref_no_change(cx); // impossible. Can't change const
	std::cout << "cx: " << cx << std::endl;

	const int& rcx = x;
	f_value(rcx);
	std::cout << "rcx: " << rcx << std::endl;
	f_ref_const(rcx);
	std::cout << "rcx: " << rcx << std::endl;
	f_ref_no_change(rcx); // impossible. Can't change const
	std::cout << "rcx: " << rcx << std::endl;

	// f_pointer(10);
	f_pointer(&x);
	std::cout << "x: " << x << std::endl;
	f_pointer(&cx);
	f_pointer(&rcx);

	f_pointer_const(&x);

	f_pointer_const(&cx);
	f_pointer_const(&rcx);

	// universel ref
	f_ref_universel(2);
	f_ref_universel(x);
	f_ref_universel(cx);
	f_ref_universel(rcx);

	// f_value_bis
	const char* const cPtr = "Point const char const";
	f_value_bis(cPtr);
	std::cout << "cPtr: " << cPtr << std::endl;
}

TEST(TestStuff, initialisationUniform)
{
	std::vector<int> vAccolade{1,2,3};
	std::cout << "vAccolade: " << type_id_with_cvr<decltype(vAccolade)>().pretty_name() << std::endl;

	const std::vector<int> vAccoladeConst{4,5,6};
	std::cout << "vAccoladeConst: " << type_id_with_cvr<decltype(vAccoladeConst)>().pretty_name() << std::endl;

	for(auto i: vAccolade) {
		std::cout << "vector accolade: " << i << std::endl;
	}
	vAccolade.push_back(4);
	vAccolade[1] = 9;
	for(auto i: vAccolade) {
		std::cout << "vector accolade: " << i << std::endl;
	}

	for(auto i: vAccoladeConst) {
		std::cout << "vector accolade const: " << i << std::endl;
	}
	// Error: vAccoladeConst.push_back(7);
	// Error: vAccoladeConst[0] = 1;
	auto tuP = std::make_tuple(1, 2, "Hello world");

	std::cout << "tuP: " << type_id_with_cvr<decltype(tuP)>().pretty_name() << std::endl;
	std::cout << "1: " << std::get<0>(tuP) << std::endl;
	std::cout << "2: " << std::get<1>(tuP) << std::endl;
	std::cout << "3: " << std::get<2>(tuP) << std::endl;

	auto whatIA = {1,2,3};
	std::cout << "whatIA: " << type_id_with_cvr<decltype(whatIA)>().pretty_name() << std::endl;
	for(auto i: whatIA) {
		std::cout << "whatIA: " << i << std::endl;
	}
	auto whatIANow = static_cast<std::vector<int>>(std::initializer_list<int>({1,2,3}));
	std::cout << "whatIANow: " << type_id_with_cvr<decltype(whatIANow)>().pretty_name() << std::endl;
	for(auto i: whatIANow) {
		std::cout << "whatIA: " << i << std::endl;
	}

	std::initializer_list<int> list = {1,2,3};
	for(auto i: list) {
		std::cout << "list: " << i << std::endl;
	}

}
