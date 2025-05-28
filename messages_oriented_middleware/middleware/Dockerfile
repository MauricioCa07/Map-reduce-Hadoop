FROM ubuntu:latest


RUN apt-get update && apt-get install -y cmake build-essential git


WORKDIR /app


RUN git clone --recurse-submodules -b v1.70.0 --depth 1 --shallow-submodules https://github.com/grpc/grpc


RUN cd grpc && \
    mkdir -p cmake/build && \
    cd cmake/build && \
    cmake -DgRPC_INSTALL=ON \
          -DgRPC_BUILD_TESTS=OFF \
          -DCMAKE_CXX_STANDARD=17 \
          -DCMAKE_INSTALL_PREFIX=/usr/local \
          ../.. && \
    make -j 4 && \
    make install
