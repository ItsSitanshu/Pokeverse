# !/bin/sh

if [ "$1" == "-c" ]; then
    rm -rf build/CMakeFiles
else
    ls
    cat LICENCE
    cmake -B build
    cd build
    make
fi

if [ "$1" == "-d" ]; then
    ./Pokeverse
elif [ "$1" == "-s" ]; then
    ./Server
fi