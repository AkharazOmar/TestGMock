/*
 * TestStuff.cpp
 *
 *  Created on: 4 févr. 2018
 *      Author: omar
 */

#include "../../src/lib/Stuff.h"

#include <gtest/gtest.h>

TEST(TestStuff, all)
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
