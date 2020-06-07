cmake_minimum_required(VERSION 3.12)

project(Invaders)


file(GLOB_RECURSE Invaders_SRC

	"src/*.h"
	"src/*.cpp"
)

add_executable(${PROJECT_NAME} ${Invaders_SRC})


find_package(SDL2 REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2 SDL2::SDL2main)


target_include_directories(${PROJECT_NAME} PRIVATE ${SDL2_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE ${SDL2_LIBRARIES})


