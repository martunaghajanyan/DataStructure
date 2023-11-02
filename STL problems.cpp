#include <iostream>
#include <deque>
#include <vector>

std::deque<int> firstEven(std::deque<int>& deq)
{
  std::deque<int> result;
  for (auto it = deq.rbegin(); it != deq.rend(); ++it)
  {
    if (*it % 2 == 0)
    {
      result.push_front(*it);
    }
    else
    {
      result.push_back(*it);
    }
  }
  return result;
}

std::deque<int> addElem(std::deque<int>& deq,          
                        std::vector<int>&vec)
{
  for(int i = 0;i < vec.size();++i)
  {
    deq.push_back(vec[i]);
  } 
  return deq;
}


int main() 
  {
  std::deque<int> deq= {1,2,3,4,5,6};
  std::deque<int> result = firstEven(deq);
  for (auto it = result.begin(); it != result.end(); ++it)
  {
    std::cout << *it << " ";
  }

    std::cout << std::endl;
    
    std::deque<int> deq1 = {1,2,3,4};
    std::vector<int> vec ={5,6,7};
    std::deque<int> result1 = addElem(deq1,vec);
    for(auto it = result1.begin(); it != result1.end(); ++it){
      std::cout << *it << " ";
    }
    std::cout << std::endl;
}