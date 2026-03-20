cmake_minimum_required(VERSION 3.24)

project(PI)

# Global C++ settings (all tasks)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Fetch raylib (once for all tasks)
include(cmake/raylib.cmake)

# Add each task as a subdirectory
# Uncomment as you create each task
add_subdirectory(Task2_SpriteStruct)
add_subdirectory(Task3_DiceGame)
add_subdirectory(Task4_PlantClasses)
# add_subdirectory(Task5_CustomArray)
# add_subdirectory(Task6_VehicleSim)
# add_subdirectory(Task7_RaylibSprite)
# add_subdirectory(Task8_LevelClass)
