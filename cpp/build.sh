rm -rf bin
mkdir build
cd build 

rm ./CMakeCache.txt

cmake .. 
make -j8

cd ../bin
# ./test
./memory_deep_copy
