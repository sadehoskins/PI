# Task 8: Level Class (raylib)
add_executable(Task8_LevelClass
    src/main.cpp
    src/level.h
    src/level.cpp
    # Reuse sprite class task 7
    ${CMAKE_SOURCE_DIR}/Task7_RaylibSprite/src/sprite.h
    ${CMAKE_SOURCE_DIR}/Task7_RaylibSprite/src/sprite.cpp
)

target_include_directories(Task8_LevelClass PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/Task7_RaylibSprite/src
)

target_link_libraries(Task8_LevelClass PRIVATE raylib)

add_custom_command(TARGET Task8_LevelClass POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/assets
    $<TARGET_FILE_DIR:Task8_LevelClass>/assets
)

