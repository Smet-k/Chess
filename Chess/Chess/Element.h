#ifndef Element_h
#define Element_h


#include <iostream>

template<class T>
class Element
{
public:
	Element<T>* next;
	T value;

};

#endif