FROM ubuntu:22.04
ENV DEBIAN_FRONTEND=noninteractive
RUN apt-get update && apt-get install -y \
    sudo \
    apt-utils \
    repo \
    git \
    ssh \
    make \
    gcc \
    libssl-dev \
    liblz4-tool \
    expect \
    g++ \
    patchelf \
    chrpath \
    gawk \
    texinfo \
    diffstat \
    binfmt-support \
    qemu-user-static \
    live-build \
    bison \
    flex \
    fakeroot \
    cmake \
    unzip \
    device-tree-compiler \
    python3-pip \
    libncurses-dev \ 
    python2 \
    universal-ctags
RUN apt-get clean && rm -rf /var/lib/apt/lists/*
RUN mkdir -p /sdk
WORKDIR /sdk
VOLUME ["/sdk"]