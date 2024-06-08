# Use the official Ubuntu 20.04 image
FROM ubuntu:20.04

# Avoid interactive prompts during package installation
ENV DEBIAN_FRONTEND=noninteractive

# Install required packages
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    gdb \
    git \
    wget \
    curl \
    sudo \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

# Create a non-root user and add to sudoers
RUN groupadd -g 1000 vscode \
    && useradd -u 1000 -g vscode -m vscode \
    && echo 'vscode ALL=(ALL) NOPASSWD:ALL' >> /etc/sudoers.d/nopasswd \
    && chmod 0440 /etc/sudoers.d/nopasswd

# Set the user to vscode
USER vscode

# Set the working directory
WORKDIR /workspace
