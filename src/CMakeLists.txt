cmake_minimum_required (VERSION 3.21.0)

add_compile_options(-Wall -Wextra -Wpedantic -Wshadow -Wfloat-equal -Wconversion -Wsign-conversion)

Include(FetchContent)

FetchContent_Declare(
  cpputils
  GIT_REPOSITORY https://github.com/alessandro90/cpputils
  GIT_TAG        master
)

FetchContent_MakeAvailable(cpputils)

include_directories(${cpputils_SOURCE_DIR}/src/include)

add_executable(${PROJECT_NAME} main.cpp)
# target_link_libraries(${PROJECT_NAME} cpputils)
