
// C++ program to illustrate the
// implementation of multiset of
// pairs
#include <bits/stdc++.h>
using namespace std;
 
// Function to print multiset
// elements
void print(multiset<pair<int,
           int>> &multisetOfPairs)
{ 
  // Iterating over multiset of
  // pairs elements
  for (auto cuurentPair : multisetOfPairs)
  {
    // Each element is a tuple itself
    pair<int, int> pr = cuurentPair;
 
    // Printing pair elements
    cout << "[ " << pr.first << ' ' <<
             pr.second << " ]"<< '\n';
  }
}
 
// Driver code
int main()
{
  // Declaring a multiset of tuples
  multiset<pair<int,
  int>> multisetOfPairs;
 
  // Initializing a pair 
  pair<int, int> pair1;
  pair1 = make_pair(3, 100);
 
  // Initializing a pair
  pair<int, int> pair2;
  pair2 = make_pair(1, 4);
 
  // Initializing another pair
  pair<int, int> pair3;
  pair3 = make_pair(2, 12);
 
  // Initializing another pair
  pair<int, int> pair4;
  pair4 = make_pair(2, 8);
 
  // Initializing another pair
  pair<int, int> pair5;
  pair5 = make_pair(2, 10);
 
  // Inserting into multiset
  multisetOfPairs.insert(pair1);
  multisetOfPairs.insert(pair2);
  multisetOfPairs.insert(pair3);
  multisetOfPairs.insert(pair4);
  multisetOfPairs.insert(pair5);
 
  // Calling print function
  print(multisetOfPairs);
 
  return 0;
}