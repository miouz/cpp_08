#ifndef MUTANT_STACK_HPP
#define MUTANT_STACK_HPP

#include <stack>
#include <iterator>
template<typename T>
class MutantStack: public std::stack<T>
{
	public:
	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;

	iterator	begin() {return this->c.begin();};
	iterator	end() {return this->c.end();};
	const_iterator	cbegin() const {return this->c.cbegin();};
	const_iterator	cend() const {return this->c.cend();};
};

#endif // !MUTANT_STACK_HPP
