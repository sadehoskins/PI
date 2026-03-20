# Task 4: Plant class (console only)
add_executable(Task4_PlantClasses
    src/main.cpp
    src/plant.h
    src/plant.cpp
 "src/tree.h")

target_include_directories(Task4_PlantClasses PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)
