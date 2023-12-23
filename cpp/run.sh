#!/bin/bash
if cmake . -B build -GNinja -DCMAKE_CXX_COMPILER="g++"; then
	cd build
	if ninja; then
		cd src
		./App
	fi
fi
