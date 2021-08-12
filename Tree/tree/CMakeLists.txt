add_library(
	tree-ops
	src/tree.cpp
	src/tree.h
)

target_include_directories(tree-ops PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")