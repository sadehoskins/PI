# cmake/raylib.cmake
# Local raylib

set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(BUILD_GAMES OFF CACHE BOOL "" FORCE)

# Local path raylib
add_subdirectory("C:/Users/sadeh/Documents/Dev/raylib-5.5" "${CMAKE_BINARY_DIR}/raylib-build")