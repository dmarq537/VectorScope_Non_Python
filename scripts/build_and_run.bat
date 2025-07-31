@echo off
mkdir ..\build 2>NUL
pushd ..\build
cmake ..
cmake --build .
vectorscope.exe
popd
pushd ..\frontend
npm install
npm run dev
popd
