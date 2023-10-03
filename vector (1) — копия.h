#include <iostream>
#include <initializer_list>


 template <typename Vector>

 class VectorIterator
{
  public:
    using ValueType = typename Vector::ValueType;
    using PointerType = ValueType*;
    using ReferenceType = ValueType&;

  public:
    VectorIterator(PointerType _ptr):ptr(_ptr){}


    VectorIterator& operator++()
    {
      ptr+=1;
      return *this;
    }

    VectorIterator& operator--()
    {
     ptr-=1;
     return *this;
    }

    ReferenceType operator[](std::size_t i)
    {
      return *(ptr + i);
    }

    ReferenceType operator*()
    {
      return *ptr;
    }
    PointerType operator->()
    {
    return ptr;
    }


    bool operator==(const VectorIterator& obj) const
    {
      return ptr == obj.ptr;
    }

    bool operator!=(const VectorIterator& obj1)const
    {
      return ptr != obj1.ptr;
    }

  private:
  PointerType ptr;

};
template <typename T>

class Vector 
{
private:
  int size;
  int cap;
  T *arr;

public:
using ValueType = T;
using iterator = VectorIterator<Vector<T>>;

public:
  Vector() 
  {
    size = 1;
    cap = 1;
    arr = new T[cap];
  }
   Vector(std::initializer_list<T> init_list) {
    size = init_list.size();
    cap = 3 * size;
    arr = new T[cap];

    int i = 0;
    for (const T &value : init_list) 
    {
      arr[i++] = value;
    }
  }

  Vector(int _size) 
  {
    size = _size;
    cap = 2 * size;
    arr = new T[cap];
    for (int i = 0; i < size; ++i) 
    {
      arr[i] = 0;
    }
  }
  Vector(int _size, T _elem) 
  {
    size = _size;
    cap = 2 * size;
    arr = new T[cap];
    for (int i = 0; i < size; ++i) 
    {
      arr[i] = _elem;
    }
  }
  

  Vector(const Vector &v) 
  {
    size = v.size;
    cap = v.cap;
    for (int i = 0; i < v.size; ++i) 
    {
      arr[i] = v[i];
    }
  }
  ~Vector() { delete[] arr; }

  T at(int index);

  int get_size();

  int get_capacity();

  void push_back(T el);

  void pop_back();

  T front();

  T back();

  bool empty();

  void print();



  iterator find(iterator begin,iterator end,const T& elem)
  {
    for(; begin !=end;++begin)
    {
      if(*begin == elem)
      {
        return begin;
      }
    }
    return end;
  }

  T operator[](std::size_t index)
  {
   
    if(index < 0 || index >= size)
    {
    throw std::out_of_range("index out of range");
    } 
    return arr[index];
  }


  iterator begin()
  {
   return VectorIterator<Vector>(arr);
  }

  iterator end()
  {
   return VectorIterator<Vector>(arr + size);
  }
};
template <typename T>

T Vector<T>::at(int index) 
{
  return arr[index - 1];
}
template <typename T> int Vector<T>::get_size() 
{ 
  return size; 
}

template <typename T> int Vector<T>::get_capacity() 
{ 
  return cap; 
}

template <typename T> void Vector<T>::push_back(T elem) {
  if (size == cap) {
    T *v = new T[2 * cap];
    for (int i = 0; i < size; ++i) {
      v[i] = arr[i];
    }

    delete[] arr;
    arr = v;
  }

  arr[size] = elem;
  ++size;
  cap = 2 * cap;
}
template <typename T> void Vector<T>::pop_back() {
  --size; 
}

template <typename T>

T Vector<T>::front() 
{
  return arr[0];
}
template <typename T>

T Vector<T>::back() {
  return arr[size - 1];
}
template <typename T>

bool Vector<T>::empty() {
  if (size == 0) {
    return true;
  }
  return false;
}
template <typename T>

void Vector<T>::print() 
{
  for (int i = 0; i < size; ++i) 
  {
    std::cout << arr[i] << " ";
  }
}

