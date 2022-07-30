
cmake_minimum_required (VERSION 3.8)
project (test)
INCLUDE_DIRECTORIES(${include_directories})

add_executable (std_tuple_test std_tuple_test.cpp)
target_link_libraries(std_tuple_test)

add_executable (std_result_of_std_is_same std_result_of_std_is_same.cpp)
target_link_libraries(std_result_of_std_is_same)

add_executable (std_new_T1_value std_new_T1_value.cpp)
target_link_libraries(std_new_T1_value mem_trace)