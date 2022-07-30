#include <iostream>
#include <tuple>

int main(void) {
  {
    std::tuple<int, std::string, char> tuple_test;
    tuple_test = std::make_tuple<int, std::string, char>(1, "hello", 'c');
    std::cout << std::get<0>(tuple_test) << std::endl;
    std::cout << std::get<1>(tuple_test) << std::endl;
    std::cout << std::get<2>(tuple_test) << std::endl;
  }

  {
    std::tuple<int, int> tuple_test(1, 2);
    std::cout << std::get<0>(tuple_test) << std::endl;
    std::cout << std::get<1>(tuple_test) << std::endl;
    // std::cout << std::get<1>(tuple_test) << std::endl; // build error
  }

  {
    std::tuple<int, std::string> tuple_test(1, "hello");
    std::string str;
    int num;
    std::tie(num, str) = tuple_test;  // 解包
    std::cout << num << std::endl;
    std::cout << str << std::endl;
  }

  {
    std::tuple<int, std::string> tuple_test(1, "hello");
    std::string str;
    std::tie(std::ignore, str) = tuple_test;  // 解包
    std::cout << str << std::endl;
  }
  return 0;
}