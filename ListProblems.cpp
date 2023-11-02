#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>
#include <deque>

std::size_t binaryToDecimal(std::list<int>& binary)
{
  std::size_t decimal = 0;
  std::size_t temp = 1;
  for (auto it = binary.rbegin(); it != binary.rend(); ++it)
  {
    decimal += *it * temp;
    temp *= 2;
  }
  return decimal;
}

  int middleElem(std::list<int>& ls)
  {
    auto middle = std::next(ls.begin(),ls.size() / 2);
    return *middle;
    
  }

void removeKvalues(std::list<int>& ls, int k)
{
  for(auto it = ls.begin(); it != ls.end();++it)
  {
    if(*it == k)
    {
      it = ls.erase(it);
    }
  }    
}

bool isSimetric(std::list<int>& ls)
{
  auto it = ls.begin();
  auto it2 = ls.rbegin();
  while(it != ls.end())
  {
    if(*it != *it2)
    {
      return false;
    }
    else
    {
      ++it;
      ++it2;
    }
  }
    return true;
  
}

bool isSorted(std::list<int>& ls)
{
  for(auto it = ls.begin();it!=ls.end();++it)
  {
    if(*it > *std::next(it))
    {
      return false;
    }
  }
  return true;
  
}

int main() 
{
  std::list<int> list{1,0,1,0};
  bool result = binaryToDecimal(list);
  std::cout << result << std::endl;

  std::list<int> list1{4,3,4,1};
  auto result1 = middleElem(list1);
  std::cout << result1 << std::endl;

  std::list<int> list2{1,2,3,4,3};
  removeKvalues(list2, 3);
  
  for(auto it = list2.begin();it!=list2.end();++it)
  {
    std::cout << *it;
  }

  std::cout << std::endl;

  std::list<int> list4{1,2,3,2,5};
  auto result4 = isSimetric(list4);
  std::cout << result4 << std::endl;

  std::list<int> list5{1,2,3,4,5,3,4};
  bool result5 = isSorted(list5);
  std::cout << result5;
  
  return 0;
}