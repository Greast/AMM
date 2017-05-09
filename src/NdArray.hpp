#include <iostream>
#include <vector>
#include <numeric>
#include <string>
#include <functional>

template<typename T>
T product(T v) {
  return v;
}
template<typename T, typename... Args>
T product(T first, Args... args) {
  return first * adder(args...);
}
namespace nd{
  template<typename T, size_t ... sizes>
  class NdArray{
    std::array<T, product<sizes>()> data;
    NdArray();
    NdArray(T fill);
    template<typename Functor>
    NdArray(Functor lambda);
    virtual T& operator[](size_t i);
    virtual T& operator[](std::array<size_t, sizeof...(sizes)> i);
  };
  template<typename T>
  class NdArray<T>{

  };
}
