#!/bin/bash

apt-get -y install pmccabe
pmccabe -v *.cpp
make clean && make