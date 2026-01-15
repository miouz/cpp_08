#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>

template<typename T>
typename T::iterator easyFind(T& container, const int toFind)
{
	typename T::iterator	found = std::find(container.begin(), container.end(), toFind);
	return found;
}

#endif // !EASYFIND_HPP
