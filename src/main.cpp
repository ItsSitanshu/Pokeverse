/*
    filename: main.cpp
    author: Sitanshu Shrestha at (bit.ly/sitanshu)
    licence: BSD 3-Clause License
*/

#include "sha526.hpp"

#include "iostream"

int main(int argc, char **argv) {
    std::cout << argv[1] << " = " << SHA256(argv[1]) << "\n";
    return 0;
}