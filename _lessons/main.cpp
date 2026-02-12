#include <iostream>

int main(){
    bool fl_even = true;
    int    x;
    
    while (std::cin >> x && x != 0)
       fl_even &= ((x & 1) == 0);

    std::cout << (fl_even == true ? "even" : "no") << std::endl;
    return (0);
}