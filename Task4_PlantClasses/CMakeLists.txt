# Task 4: Plant class (console only)
add_executable(Task4_PlantClasses
    src/main.cpp
    src/plant.h
    src/plant.cpp
    src/tree.h
    src/tree.cpp
    src/flower.h
    src/flower.cpp
    src/shrub.h
    src/shrub.cpp
    src/grass.h
    src/grass.cpp)

target_include_directories(Task4_PlantClasses PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)
