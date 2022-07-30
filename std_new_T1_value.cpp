#include <functional>
#include <iostream>

#include "mem_trace/mem_trace.h"

template <class T1, class T2>
inline void _construct(T1* p, T2&& value) {
  new (p) T1(value);  // placement new. invoke ctor of T1
}

struct std_new_T1_value {
  std_new_T1_value() { std::cout << "std_new_T1_value" << std::endl; }
  ~std_new_T1_value() { std::cout << "~std_new_T1_value" << std::endl; }
  std_new_T1_value(std_new_T1_value&& val) {
    std::cout << "move std_new_T1_value" << std::endl;
    num = std::move(val.num);
  }
  std_new_T1_value(const std_new_T1_value& val) {
    std::cout << "copy std_new_T1_value" << std::endl;
    num = std::move(val.num);
  }
  int num = 0;
};

int main(void) {
  mem_trace_init();

  {
    std_new_T1_value val;
    val.num = 1;

    std_new_T1_value* value = new std_new_T1_value();
    std::cout << value->num << std::endl;

    _construct(value, std::ref(val));
    std::cout << value->num << std::endl;

    // call destroy
    value->~std_new_T1_value();
    
    // free memery
    free(value);

    // call move construct
    std_new_T1_value v = std::move(val);
  }
  return 0;
}