#include <iostream>
#include "Algorithm.h"

int main() 
{
  Vector<int> v(4,3);
  std::cout<<"My vector is "<<std::endl;
  v.print();
  
  std::cout<<std::endl;
  std::cout<<"The size is "<<v.get_size()<<std::endl;
  std::cout<<"The capicity is "<<v.get_capacity()<<std::endl;
  
  v.push_back(7);
  v.push_back(1);
  
  std::cout<<"after pushing my vector is"<<std::endl;
  
  v.print();
  std::cout<<std::endl;
 
  v.pop_back();
  std::cout<<"after poping my vector is "<<std::endl;
 
  v.print();
  std::cout<<std::endl;
  std::cout<<"First elem of my vector is "<<v.front();
  std::cout<<std::endl;
  std::cout<<"Last elem of my vector is  "<<v.back();
  std::cout<<std::endl;
  std::cout<<v.empty()<<std::endl;


  for(Vector<int>::iterator it = v.begin();it != v.end();++it)
  {
    std::cout<<*it<<" ";
  }
  std::cout<<"\n";
  
  for(int elem:v)
  {
    std::cout<<elem<<" ";
  }
  
  std::cout<<std::endl;

  Vector<int> v1(5,3);
      try
        {
          std::cout<<v1[11];
        }
      catch(const std::out_of_range& err)
      {
      std::cerr<<"error = "<<err.what()<<std::endl;
      }


  Vector<int> v2(7,6);
  v2.push_back(8);
  
  v2.find(v2.begin(),v2.end(),8);
  
  Vector<int>::iterator it = v2.find(v2.begin(),v2.end(),8);
  std::cout << *it<<std::endl;
  


Vector<int> v3(4,3);
  v3.push_back(8);
  v3.push_back(12);
  v3.push_back(3);
  v3.push_back(13);

  sort(v3.begin(),v3.end());
  for(int elem : v3)
    std::cout<<elem<<" ";
  std::cout<<"\n";

  
  Vector<int> v4={14,45,0,-4,10,3,2,5};
  std::cout<<"v4 vector  -";
  for(int elem : v4)
  {
    std::cout<<elem<<" ";
  }
  std::cout << std::endl;
  sort(v4.begin(),v4.end());
  std::cout<< "v4 Vector after sorting - ";
  for(int elem : v2)
    std::cout<< elem <<" ";
  
std::cout<<"\n";
  Vector<int> v5 = {12,34,56};
  auto max = maxValue(v5.begin(),v5.end());
  std::cout<<"max value of v5 vector is - "<< max;

  std::cout<<std::endl;

  auto min = minValue(v5.begin(),v5.end());
  std::cout<<"min value of v5 vector is - "<< min;
  
  std::cout<<std::endl;
  
  Vector<int> v6 (6,3);
  v6.push_back(5);
  v6.push_back(5);
  std::cout<<count(v6.begin(),v6.end(),5)<<std::endl;


   Vector<int> v7 = {1,3,4,2,1,4,1};
   int a = count(v7.begin(),v7.end(),1);
   std::cout<< a <<std::endl;

    Vector<int> v8 = {-2,12,8,9,2};
    std::cout<<"v8 vector is - ";

    for(int elem : v8)
    {
      std::cout<<elem<<" ";
    }
    std::cout<<std::endl;
  
  Reverse(v8.begin(),v8.end());
  std::cout<<"reversed v8 is - ";
  
    for(int elem : v8)
    {
      std::cout<<elem<<" ";
    }
  return 0; 
}