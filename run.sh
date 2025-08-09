set -e

cmake -B .build/ -DCMAKE_BUILD_TYPE=Debug

make -j 6 -C .build

cd .build

./SimpFighter

cd ..
