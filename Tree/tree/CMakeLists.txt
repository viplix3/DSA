add_library(
	tree-ops
	src/tree.cpp
	src/tree_traversal.cpp
)

target_include_directories(tree-ops PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")