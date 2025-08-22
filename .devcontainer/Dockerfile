FROM ubuntu:24.04

RUN apt-get update && apt-get install -y \
    build-essential \
    clang \
    lldb \
    gdb \
    cmake \
    curl \
    && rm -rf /var/lib/apt/lists/*

# Additional packages for development
RUN apt-get update && apt-get install -y git vim clang-format

# Install Ruby and Jekyll
RUN apt-get update && apt-get install -y ruby-full

RUN gem install bundler && \
    gem install --no-document jekyll:4.4.1 just-the-docs:0.10.1

ARG USERNAME=devuser
ARG USER_UID=1001
ARG USER_GID=1001

RUN groupadd --gid $USER_GID $USERNAME \
    && useradd --uid $USER_UID --gid $USER_GID -m $USERNAME \
    && apt-get update && apt-get install -y sudo \
    && echo "$USERNAME ALL=(ALL) NOPASSWD:ALL" > /etc/sudoers.d/$USERNAME \
    && chmod 0440 /etc/sudoers.d/$USERNAME

USER $USERNAME
CMD ["/bin/bash"]

# RUN apt-get install -y  python3-venv python3-pip

# RUN apt-get install -y python3-networkx python3-matplotlib

# RUN apt-get install -y x11-apps
