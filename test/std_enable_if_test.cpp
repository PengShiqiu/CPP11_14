#include <iostream>

// 返回值enable_if 模板特化
// 编译时确定代码实例分支
template <typename T>
typename std::enable_if<(sizeof(T) > 2), void>::type TestFunc(T&& num) {
  std::cout << "sizeof > 2:" << sizeof(num) << std::endl;
}
template <typename T>
typename std::enable_if<!(sizeof(T) > 2), int>::type TestFunc(T&& num) {
  std::cout << "sizeof < 2:" << sizeof(num) << std::endl;
  return 0;
}


// 模板列表中enable_if
template <typename T,
          typename = typename std::enable_if<(sizeof(T) > 2), void>::type>
void TestTemplate(T&& num) {
  std::cout << "TestTemplate sizeof > 2:" << sizeof(num) << std::endl;
}
template <typename T,
          typename = typename std::enable_if<!(sizeof(T) > 2), void>::type>
int TestTemplate(T&& num) {
  std::cout << "TestTemplate sizeof < 2:" << sizeof(num) << std::endl;
  return 0;
}

int main(void) {
  std::enable_if<(1 > 0), int>::type* test_enable_if;
  std::cout << std::is_same<std::remove_pointer<decltype(test_enable_if)>::type,
                            int>::value
            << std::endl;

  TestFunc<int>(123);
  int ret = TestFunc<char>(12);
  TestTemplate<int>(123);
  ret = TestTemplate<char>(12);
  return 0;
}