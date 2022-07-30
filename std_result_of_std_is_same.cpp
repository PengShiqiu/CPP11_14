#include <functional>
#include <iostream>
#include <type_traits>

int fn(int) { return int(); }  // function
int fnstr(std::string) { return int(); }
typedef int (&fn_ref)(int);  // function reference
typedef int (*fn_ptr)(int);  // function pointer
struct fn_class {
  int operator()(int i) { return i; }
};  // function-like class

int main() {
  typedef decltype(fn(1)) A;                                       // int
  typedef std::result_of<decltype(fnstr)&(std::string)>::type A1;  // int
  typedef std::result_of<fn_ref(int)>::type B;                     // int
  typedef std::result_of<fn_ptr(int)>::type C;                     // int
  typedef std::result_of<fn_class(int)>::type D;                   // int

  auto lamba = [] { return true; };

  // why ? decltype(lamba)&()
  typedef std::result_of<decltype(lamba)&()>::type F;  // int
  std::cout << std::boolalpha;
  std::cout << "typedefs of int:" << std::endl;

  std::cout << "A: " << std::is_same<int, A>::value << std::endl;
  std::cout << "A1: " << std::is_same<int, A1>::value << std::endl;
  std::cout << "B: " << std::is_same<int, B>::value << std::endl;
  std::cout << "C: " << std::is_same<int, C>::value << std::endl;
  std::cout << "D: " << std::is_same<int, D>::value << std::endl;
  std::cout << "F: " << std::is_same<void, F>::value << std::endl;
  return 0;
}