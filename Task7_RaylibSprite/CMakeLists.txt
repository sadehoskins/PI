# Task 7: Raylib Sprite Class (needs raylib)
add_executable(Task7_RaylibSprite
    src/main.cpp
    src/sprite.h
    src/sprite.cpp
)

target_include_directories(Task7_RaylibSprite PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# Link raylib (fetched at root level)
target_link_libraries(Task7_RaylibSprite PRIVATE raylib)

# Copy assets to build directory
add_custom_command(TARGET Task7_RaylibSprite POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/assets
    $<TARGET_FILE_DIR:Task7_RaylibSprite>/assets
)

