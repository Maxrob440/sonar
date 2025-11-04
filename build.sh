cd build
cmake --build . --parallel

cd ..

ctest --test-dir build --output-on-failure
