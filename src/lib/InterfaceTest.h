/*
 * InterfaceTest.h
 *
 *  Created on: 3 mars 2018
 *      Author: omar
 */

#ifndef LIB_INTERFACETEST_H_
#define LIB_INTERFACETEST_H_

#include <map>
#include <string>

// C++11 or least
template<typename T>
using MyIter = std::map<int, T>;

// C++98
//template<typename T>
//struct MyIter {
//	typename std::map<int, T> type;
//};

class NotFound: public std::exception
{
private:
	std::string msg = "";

public:
	NotFound()
	{
	}
	NotFound(std::string msg): msg(msg)
	{
	}
	const char * what () const throw () override
	{
		return msg.c_str();
	}
};

class AlreadyExist: public std::exception
{
private:
	std::string _msg = "";

public:
	AlreadyExist()
	{
	}

	AlreadyExist(std::string msg): _msg(msg)
	{
	}
	const char * what () const throw () override
	{
		return _msg.c_str();
	}
};

template<class T>
class InterfaceTest
{
public:
	InterfaceTest()
	{

	}
	virtual ~InterfaceTest()
	{
		clean();
	}

	void clean()
	{
		for (typename MyIter<T*>::iterator it=mapOfT.begin(); it!=mapOfT.end(); it++) {
			delete(it->second);
		}
		mapOfT.clear();
	}

	virtual void insert(int i, T* t)
	{
		if (mapOfT.find(i) != mapOfT.end()) {
			throw AlreadyExist();
		}
		mapOfT.insert(std::make_pair(i, t));
	}
	virtual T* getT(int i)
	{
		typename MyIter<T*>::const_iterator it = mapOfT.find(i);
		if (it != mapOfT.end()) {
			return it->second;
		}
		throw NotFound();
	}

	virtual void drop(int i) {
		if (mapOfT.find(i) == mapOfT.end()) {
			throw NotFound();
		}
		delete(mapOfT[i]);
		mapOfT.erase(i);
	}

protected:
	MyIter<T*> mapOfT;
};

#endif /* LIB_INTERFACETEST_H_ */
