
#include <iostream>
#include <vector>
#include <algorithm>
template<typename T>
bool isEqual(std::vector<T> const &v1, std::vector<T> const &v2)
{
    return (v1.size() == v2.size() &&
            std::equal(v1.begin(), v1.end(), v2.begin()));
}
 
int main()
{
    std::vector<int> v1 = { 1, 2, 5, 3, 4, 5 };
    std::vector<int> v2 = { 1, 2, 3, 5, 4, 5 };
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    if (isEqual(v1, v2)) {
        std::cout << "Both vectors are equal";
    }
    else {
        std::cout << "Both vectors are not equal";
    }
 
    return 0;
}
