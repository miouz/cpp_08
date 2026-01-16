#include "Span.hpp"

static const unsigned int MIN_ELEMENTS_FOR_SPAN = 2;

Span::Span():elements_(std::multiset<int>()), N_(0){}

Span::Span(unsigned int maxSize): elements_(std::multiset<int>()), N_(maxSize){}

Span::Span(const Span& other): elements_(other.elements_), N_(other.N_) {}

Span& Span::operator=(const Span& other)
{
	if (this == &other)
		return (*this);
	elements_ = other.elements_;
	N_ = other.N_;
	return *this;
}

Span::~Span(){}

void Span::addNumber(int number)
{
	if (elements_.size() + 1 > N_)
		throw std::runtime_error("can't add number: more than max size");
	elements_.insert(number);
}

int	Span::shortestSpan() const
{
	if (elements_.size() < MIN_ELEMENTS_FOR_SPAN)
		throw std::runtime_error("can't find shortestSpan: need minimum 2 numbers stored");
	std::multiset<int>::iterator smaller = elements_.begin();
	std::multiset<int>::iterator bigger = smaller;
	std::advance(bigger, 1);
	int	shortestSpan = *bigger - *smaller;
	while (bigger != elements_.end())
	{
		int newSpan = *bigger - *smaller;
		shortestSpan = std::min(newSpan, shortestSpan);
		smaller++;
		bigger++;
	}
	return shortestSpan;
}

int	Span::longestSpan() const
{
	if (elements_.size() < MIN_ELEMENTS_FOR_SPAN)
		throw std::runtime_error("can't find longestSpan: need minium 2 numbers stored");
	return (*elements_.rbegin() - *elements_.begin());
}

