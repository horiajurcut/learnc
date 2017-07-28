rm -rf build

mkdir build
pushd build

gcc ../main.c ../chapters/*.c -o main.o

popd