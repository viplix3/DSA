add_library(
	circular-linked-list-ops
	src/circular_linked_list.hpp
	src/circular_linked_list.cpp
)

target_include_directories(circular-linked-list-ops PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")