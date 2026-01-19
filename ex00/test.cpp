#include "test.hpp"
#include <list>
#include <vector>
#include <deque>

template<typename T>
void printContainer(T& container)
{
	for (typename T::iterator it = container.begin(); it != container.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void testEx00()
{
	{
	int intArray[5] = {1, 908, -43, 56, -43};

	PRINT_HEADER("VECTOR CONTAINER OF INT");
	std::vector<int>intVec(intArray, intArray + 5);
	PRINT_SUBHEADER("vector container contains: ");
	printContainer(intVec);
	
	PRINT_SUBHEADER("occurence presents 1 time");
	std::vector<int>::iterator found = easyFind(intVec, 908);
	std::cout << *found << std::endl;

	PRINT_SUBHEADER("occurence presents 2 times");
	std::vector<int>::iterator found1 = easyFind(intVec, -43);
	std::cout << "after founded " << *found1 <<" is " << *(++found1) << std::endl;

	PRINT_SUBHEADER("occurence presents 0 time");
	std::vector<int>::iterator found2 = easyFind(intVec, -4);
	if (found2 == intVec.end())
		std::cout << "didn't find 100 because found2's value is vector's end: "<< *found2 << std::endl;
	}

	{
	PRINT_HEADER("DEQUE CONTAINER OF INT");
	std::deque<int> intDeq;
	intDeq.push_back(1);
	intDeq.push_back(908);
	intDeq.push_back(56);
	intDeq.push_back(-43);
	intDeq.insert(intDeq.begin() + 2, -43);
	PRINT_SUBHEADER("deque container contains: ");
	printContainer(intDeq);
	
	PRINT_SUBHEADER("occurence presents 1 time");
	std::deque<int>::iterator found1 = easyFind(intDeq, 908);
	std::cout << *found1 << std::endl;

	PRINT_SUBHEADER("occurence presents 2 times");
	std::deque<int>::iterator found2 = easyFind(intDeq, -43);
	std::cout << "after founded " << *found2 <<" is " << *(++found2)<< std::endl;

	PRINT_SUBHEADER("occurence presents 0 times");
	std::deque<int>::iterator found = easyFind(intDeq, -4);
	if (found == intDeq.end())
		std::cout << "didn't find -4 because found's value is vector's end: "<< *found << std::endl;
	}

	{
	PRINT_HEADER("LIST CONTAINER OF INT");
	std::list<int> intList;
	intList.push_back(1);
	intList.push_back(908);
	intList.push_back(56);
	intList.push_back(-43);
	std::list<int>::iterator it = intList.begin();
	it++;
	it++;
	intList.insert(it, -43);
	PRINT_SUBHEADER("list container contains: ");
	printContainer(intList);

	PRINT_SUBHEADER("occurence presents 1 time");
	std::list<int>::iterator found1 = easyFind(intList, 908);
	std::cout << *found1 << std::endl;

	PRINT_SUBHEADER("occurence presents 2 times");
	std::list<int>::iterator found2 = easyFind(intList, -43);
	std::cout << "after found " << *found2 <<" is " << *(++found2)<< std::endl;

	PRINT_SUBHEADER("occurence presents 0 times");
	std::list<int>::iterator found = easyFind(intList, -4);
	if (found == intList.end())
		std::cout << "didn't find -4 because found's value is vector's end: "<< *found << std::endl;
	}
}
