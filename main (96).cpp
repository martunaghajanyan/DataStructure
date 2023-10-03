#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

bool polindrom( const std::vector<std::string>& str)
{
  for(int i = 0; i < (str.size()) / 2;++i)
  {
    if(str[i] == str[str.size()- i -1])
    {
      return true;
    }
  }
  return false;
}

template <typename iterator>

bool followEachOther(iterator begin,iterator end)
{
  sort(begin,end);
  for(;begin!=end; ++begin)
  {
    if(*(begin + 1) - (*begin) != 1)
    {
      return false;
    }
  }
  return true;
}

int main() 
{
  std::vector<std::string> v = {"abba"};
  
  std::cout<<polindrom(v)<<std::endl;

  std::vector<int> v1 = {12,9,10,11};
  std::cout<<followEachOther(v1.begin(),v1.end());
}