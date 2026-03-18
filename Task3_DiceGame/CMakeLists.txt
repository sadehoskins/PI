# Task 3: Dice Game (console only)
add_executable(Task3_DiceGame
    src/main.cpp
    src/dice.h
    src/dice.cpp
    src/dice_game.h
    src/dice_game.cpp
)

target_include_directories(Task3_DiceGame PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)
