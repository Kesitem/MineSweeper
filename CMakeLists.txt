cmake_minimum_required(VERSION 3.10)

project(MineSweeper VERSION 0.0.1
                  DESCRIPTION "A simple MineSweeper clone"
                  LANGUAGES CXX)

find_package(SDL3 CONFIG REQUIRED)

# List files
set(SRCS
    main.cpp
)


add_executable(${PROJECT_NAME} ${SRCS})

# Set C++17 feature
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_20)

target_link_libraries(${PROJECT_NAME} PRIVATE SDL3::SDL3)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
                   ${CMAKE_CURRENT_SOURCE_DIR}/data $<TARGET_FILE_DIR:${PROJECT_NAME}>/data)
