#!/bin/bash

cd build
if ninja; then
cd src
./App
fi
