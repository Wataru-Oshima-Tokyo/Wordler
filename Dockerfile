FROM ubuntu:latest
LABEL title="C++ Analysis"
LABEL version=0.1
ENV CXXFLAGS=-std=c++11
ENV WORKDIR=/usr/src
WORKDIR /usr/src

# Install dependencies
RUN apt-get update && \
    DEBIAN_FRONTEND=noninteractive \
    apt-get install -y \
            build-essential \
            g++ \
            cmake \
            git-all \
            pmccabe \
            cccc

# Get source
COPY . ./

# Run static analysis
CMD pmccabe *.cpp -v && \
    cccc --lang=c++ --outdir=report *.cpp
