cmake_minimum_required(VERSION 3.10)
project(CookingGame)

set(CMAKE_CXX_STANDARD 17)

# Find SDL2
# find_package(PkgConfig REQUIRED)
# pkg_check_modules(SLD2 REQUIRED sdl2)

add_executable(cooking_game src/main.cpp src/Game.cpp)

# Link SDL2
# target_link_libraries(cooking_game ${SDL2_LIBRARIES})
# target_include_directories(cooking_game PRIVATE ${SDL2_INCLUDE_DIRS})
# target_compile_options(cooking_game PRIVATE ${SDL2_CFLAGS_OTHER})

# Quick fix SDL2 Link
target_link_libraries(cooking_game SDL2)

