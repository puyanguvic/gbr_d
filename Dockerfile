FROM ubuntu:22.04

RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    libcap-dev \
    libpcap-dev

WORKDIR /app
COPY . .

RUN mkdir -p build && cd build && cmake .. && make


CMD ["./build/gbr_daemon"]
