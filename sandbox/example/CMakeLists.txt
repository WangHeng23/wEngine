project(example)

file(GLOB_RECURSE SRC CONFIGURE_DEPENDS ./*.cpp)

add_executable(${PROJECT_NAME} ${SRC})

target_link_libraries(${PROJECT_NAME} PRIVATE engine)
target_precompile_headers(${PROJECT_NAME} REUSE_FROM engine)