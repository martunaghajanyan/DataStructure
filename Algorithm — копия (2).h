#include "vector.h"

template <typename iterator>

void sort(iterator first, iterator last) {
  for (iterator i = first; i != last; ++i) {
    for (iterator j = first; j != last; ++j) {
      if (i != j && *i < *j) {
        typename iterator::ValueType temp = *i;
        *i = *j;
        *j = temp;
      }
    }
  }
}

template <typename iterator>

typename iterator::ValueType maxValue(iterator first, iterator last) {
  typename iterator::ValueType largest = *first;
  for (iterator it = first; it != last; ++it) {

    if (largest < *it) {
      largest = *it;
    }
  }
  return largest;
}

template <typename iterator>

typename iterator::ValueType minValue(iterator first, iterator last) {
  typename iterator::ValueType smallest = *first;
  for (iterator it = first; it != last; ++it) {

    if (smallest > *it) {
      smallest = *it;
    }
  }
  return smallest;
}
template <typename iterator>

int count(iterator first, iterator last, typename iterator::ValueType elem) 
{
  int counter = 0;

  for (iterator it = first; it != last; ++it) 
  {
    if (elem == *it) 
    {
      ++counter;
    }
  }
  return counter;
}

template <typename iterator>

void Reverse(iterator first, iterator last) 
{
  for (iterator it = first; it != --last; ++it) 
  {
    typename iterator::ValueType temp = *it;
    *it = *last;
    *last = temp;
  }
}
