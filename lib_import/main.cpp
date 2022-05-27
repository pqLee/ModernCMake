#include "bar.h"
#include "foo.h"
#include "dep.h"
#include <iostream>
using namespace std;

int main( int argc, char **argv )
{
	// std::cout << "dep() : " << dep() << std::endl;
	// std::cout << "foo() : " << foo() << std::endl;
	std::cout << "bar() : " << bar() << std::endl;
	return 0;
}
