# Use Alpine Linux, a minimal lightweight Linux distribution
FROM alpine:latest

# Install the build-base package which includes g++, libc-dev, make, and other essential build tools
RUN apk add --no-cache build-base git clang clang-extra-tools zsh

# Set the working directory
WORKDIR /app

# Default command to run the shell, modify as needed to compile and build C++ code
CMD ["/bin/zsh"]
