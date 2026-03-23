cmake_minimum_required(VERSION 3.24)

project(PI)

# Global C++ settings
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Fetch raylib
include(cmake/raylib.cmake)

# Set subdirectories
add_subdirectory(Task2_SpriteStruct)
add_subdirectory(Task3_DiceGame)
add_subdirectory(Task4_PlantClasses)
add_subdirectory(Task5_CustomArray)
add_subdirectory(Task6_VehicleSimulator)
add_subdirectory(Task7_RaylibSprite)
add_subdirectory(Task8_LevelClass)
