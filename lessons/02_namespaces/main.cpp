#include <iostream>

namespace Foo {
	int i = 2;
}

namespace Bar {
	int i = 5;
}

void	print(void) {
	std::cout << Foo::i << std::endl;
	std::cout << Bar::i << std::endl;
}

int	main(void) {
	::print();
	return 0;
}