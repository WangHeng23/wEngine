project(engine)

file(GLOB_RECURSE SRC "src/*.cpp")
file(GLOB_RECURSE HEADERS "include/*.hpp")

add_library(${PROJECT_NAME} STATIC ${SRC} ${HEADERS})

target_include_directories(${PROJECT_NAME} PUBLIC ./include)
target_link_libraries(${PROJECT_NAME} PUBLIC spdlog glfw Vulkan::Vulkan)
target_precompile_headers(${PROJECT_NAME} PUBLIC "include/pch.hpp")