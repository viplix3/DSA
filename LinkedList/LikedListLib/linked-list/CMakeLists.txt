add_library(
	linked-list-ops
	src/linked_list.hpp
	src/linked_list.cpp
)

target_include_directories(linked-list-ops PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")