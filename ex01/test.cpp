#include "test.hpp"

void testEx01()
{
	int array[4] = {0, 7, 3890, -56};
	{
	PRINT_HEADER("TEST FOR SPAN CLASS");
	Span span4(4);
	span4.addNumber(array, array + sizeof(array)/sizeof(int));
	span4.printElements();
	
	PRINT_SUBHEADER("test for copy constructor's deep copy");
	Span span4Copy(span4);
	span4Copy.printElements();
	
	PRINT_SUBHEADER("test for = operator's deep copy");
	Span span0 = span4;
	span0.printElements();
	}


	PRINT_HEADER("TEST FOR ADDNUMBER");
	PRINT_SUBHEADER("add 1 number exceed max capacity");
	PRINT_SUBHEADER("add 10 numbers exceed max capacity");
	PRINT_SUBHEADER("add 10 numbers successfully");
	PRINT_SUBHEADER("add 10 000 numbers successfully once");


	PRINT_HEADER("TEST FOR SHORTEST SPAN");
	PRINT_SUBHEADER("empty element can't find shortest span");
	PRINT_SUBHEADER("only 1 element can't find shortest span");


	PRINT_HEADER("TEST FOR LONGEST SPAN");
	PRINT_SUBHEADER("empty element can't find longest span");
	PRINT_SUBHEADER("only 1 element can't find longest span");
}
