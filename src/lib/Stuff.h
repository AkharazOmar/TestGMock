/*!**************************************************
 * c++17
 *
 * Author: Omar AKHARAZ
 *
 * Some test C++17
 */
#include <iostream>
#include <boost/type_index.hpp>


using boost::typeindex::type_id_with_cvr;


template<typename T>
void f_value(T param)
{
	std::cout << "f_value: T " << type_id_with_cvr<T>().pretty_name() << std::endl;
	std::cout << "f_value: param " << type_id_with_cvr<decltype(param)>().pretty_name() << std::endl;
	param = 3;
	std::cout << "Param: " << param << std::endl;
}


template<typename T>
void f_ref(T& param)
{
	std::cout << "f_ref: T " << type_id_with_cvr<T>().pretty_name() << std::endl;
	std::cout << "f_ref: param  " << type_id_with_cvr<decltype(param)>().pretty_name() << std::endl;
	param = 4;
	std::cout << "Param: " << param << std::endl;
}

template<typename T>
void f_ref_no_change(T& param)
{
	std::cout << "f_ref_no_change: T " << type_id_with_cvr<T>().pretty_name() << std::endl;
	std::cout << "f_ref_no_change: param " << type_id_with_cvr<decltype(param)>().pretty_name() << std::endl;
	// param = 4;
	std::cout << "Param: " << param << std::endl;
}

template<typename T>
void f_ref_const(const T& param)
{
	std::cout << "f_ref_const:  T " << type_id_with_cvr<T>().pretty_name() << std::endl;
	std::cout << "f_ref_const:  param " << type_id_with_cvr<decltype(param)>().pretty_name() << std::endl;
	// param = 4; // impossible to change const ref
	std::cout << "Param: " << param << std::endl;
}

template<typename T>
void f_pointer(T* param)
{
	std::cout << "f_pointer:  T " << type_id_with_cvr<T>().pretty_name() << std::endl;
	std::cout << "f_pointer:  param " << type_id_with_cvr<decltype(param)>().pretty_name() << std::endl;
	// param = 4; // impossible to change const ref
	std::cout << "Param: " << *param << std::endl;

//	if (type_id_with_cvr<decltype(param)>().pretty_name().find("const") == std::string::npos) {
//		std::cout << "FIXME FIXME FIXME ..." << std::endl;
//		*param = 88;
//		std::cout << "Param: " << *param << std::endl;
//	}
}

template<typename T>
void f_pointer_const(const T* param)
{
	std::cout << "f_pointer_const:  T " << type_id_with_cvr<T>().pretty_name() << std::endl;
	std::cout << "f_pointer_const:  param " << type_id_with_cvr<decltype(param)>().pretty_name() << std::endl;
	// param = 4; // impossible to change const ref
	std::cout << "Param: " << *param << std::endl;
}

template<typename T>
void f_ref_universel(T&& param)
{
	std::cout << "f_ref_universel: T " << type_id_with_cvr<T>().pretty_name() << std::endl;
	std::cout << "f_ref_universel: param  " << type_id_with_cvr<decltype(param)>().pretty_name() << std::endl;
	// param = 4;
	std::cout << "Param: " << param << std::endl;
//	if (type_id_with_cvr<decltype(param)>().pretty_name().find("const") == std::string::npos) {
//		std::cout << "FIXME FIXME FIXME ..." << std::endl;
//		param = 88;
//		std::cout << "Param: " << param << std::endl;
//	}
}
