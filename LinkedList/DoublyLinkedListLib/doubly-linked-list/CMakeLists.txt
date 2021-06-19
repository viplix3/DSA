add_library(
	doubly-linked-list-ops
	src/doubly_linked_list.hpp
	src/doubly_linked_list.cpp
)

target_include_directories(doubly-linked-list-ops PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")