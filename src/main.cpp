/*
    filename: main.cpp
    author: Sitanshu Shrestha at (bit.ly/sitanshu)
    licence: BSD 3-Clause License
*/

#include "enc/sha526.hpp"

#include "iostream"

int main(int argc, char **argv) {
    std::cout << "usr: " << argv[1] << " pwd: " << argv[2] << " = " << SHA256(argv[1], argv[2]) << "\n";
    return 0;
}