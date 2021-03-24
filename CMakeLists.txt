cmake_minimum_required(VERSION 3.17)
project(BinaryTree___Copy)

set(CMAKE_CXX_STANDARD 14)

include_directories(BinaryTree)

add_executable(BinaryTree___Copy
        BinaryTree/BST.cpp
        BinaryTree/BST.h
        BinaryTree/main.cpp BinaryTree/RoyalEngineerAlt.cpp BinaryTree/RoyalEngineerAlt.h BinaryTree/RoyalEngineerAlgorithm.cpp BinaryTree/RoyalEngineerAlgorithm.h)
