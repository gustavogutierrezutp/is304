FROM ubuntu:24.04

RUN apt-get update && apt-get install -y \
    build-essential \
    clang \
    lldb \
    gdb \
    cmake \
    curl \
    && rm -rf /var/lib/apt/lists/*

# Optional tools
RUN apt-get update && apt-get install -y git vim clang-format

RUN apt-get install -y  python3-venv python3-pip

RUN apt-get install -y python3-networkx python3-matplotlib

RUN apt-get install -y x11-apps