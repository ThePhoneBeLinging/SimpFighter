set -e

cmake -B .build/

make -j 6 -C .build

cd .build

./SimpFighter

cd ..
