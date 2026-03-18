# Task 2: Sprite Structure (console only, no raylib needed)
add_executable(Task2_SpriteStruct
    src/main.cpp
)

target_include_directories(Task2_SpriteStruct PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)
