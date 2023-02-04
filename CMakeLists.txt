cmake_minimum_required(VERSION 3.0.0)
project(name VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(name 

src/attacks/attack.cpp

src/game/box.cpp
src/game/heart.cpp

src/rendering/rendering.cpp

src/starting-ending.cpp

main.cpp

)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

target_link_libraries(name ${SDL2_LIBRARIES})