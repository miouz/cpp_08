#ifndef SPAN_HPP
#define SPAN_HPP

#include<set>
#include <stdexcept>
#include<iterator>

class Span
{
	private:
	std::multiset<int> elements_;
	unsigned int	N_;
	public:
	Span();
	Span(unsigned int N);
	Span(const Span& other);
	Span& operator=(const Span& other);
	~Span();

	int		shortestSpan() const;
	int		longestSpan() const;
	void	addNumber(int num);
	template<typename typeIterator>
	void	addNumber(typeIterator& begin, typeIterator& end)
	{
		if (std::distance(begin, end) + elements_.size() > N_)
			throw std::runtime_error("can't add number: more than max size");
		elements_.insert(begin, end);
	}
};

#endif // !SPAN_HPP
