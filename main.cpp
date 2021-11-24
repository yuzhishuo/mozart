#include <iostream>
#include <string>

#include <edit_distance.hpp>

using namespace mozart;
using namespace std;

int main(int, char**) {

    string str0 = "eeba";
    string str1 = "abca";
    string str2;
    string str3;

    std::cout << EditDistanceHelp::CalcPath(str0, str1, str2, str3) << std::endl;
    std::cout << str0 << " " << str1 << "  " << str2 << "  " << str3 << std::endl;
}
