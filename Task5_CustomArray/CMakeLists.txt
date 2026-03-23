# Task 5: Custom Dynamic Array (console only)
add_executable(Task5_CustomArray
    src/main.cpp
    src/my_cpp_array.h
    src/my_cpp_array.cpp)
 

target_include_directories(Task5_CustomArray PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)
