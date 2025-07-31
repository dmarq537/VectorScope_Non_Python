#!/bin/bash
set -e
# Build C++ backend
mkdir -p ../build
cd ../build
cmake ..
cmake --build .
./vectorscope &
# Start React frontend
cd ../frontend
npm install
npm run dev
