
#include <iostream>
#include <string>
#include <algorithm>
 
bool isNumeric(std::string const &str)
{
    auto it = std::find_if(str.begin(), str.end(), [](char const &c) {
        return !std::isdigit(c);
    });
 
    return !str.empty() && it == str.end();
}
 
int main()
{
    std::string str = "100";
 
    std::cout << std::boolalpha << isNumeric(str) << std::endl;        // true
 
    return 0;
}