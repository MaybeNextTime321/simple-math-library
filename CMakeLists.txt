cmake_minimum_required(VERSION 3.8)
project(math)
add_library(math INTERFACE)


find_program(CLANG_FORMAT_PATH NAMES clang-format-21 clang-format-18 clang-format REQUIRED)
message(STATUS "Found clang-format: ${CLANG_FORMAT_PATH}")

file(GLOB_RECURSE CLANG_FORMAT_SRC CONFIGURE_DEPENDS
        *.h
        *.cpp
        *.hpp
)

add_custom_target(clang-format-fix
        COMMAND
            ${CLANG_FORMAT_PATH} -style=file -i ${CLANG_FORMAT_SRC}
        WORKING_DIRECTORY
            ${CMAKE_SOURCE_DIR}
        COMMENT
        "Formatting ${PROJECT_NAME} with ${CLANG_FORMAT_PATH} ..."
    )

add_dependencies(${PROJECT_NAME} clang-format-fix)

target_include_directories(math INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
