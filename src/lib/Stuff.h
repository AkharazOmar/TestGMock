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
void f(const T& param) {
	std::cout << type_id_with_cvr<T>().pretty_name() << std::endl;
	std::cout << type_id_with_cvr<decltype(param)>().pretty_name() << std::endl;
}


