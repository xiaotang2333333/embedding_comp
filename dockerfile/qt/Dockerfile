# 基础镜像
FROM ubuntu:24.04

# 安装基础工具和多架构支持
RUN apt-get update && apt-get install -y \
    gnupg2 \
    lsb-release \
    ca-certificates \
    apt-transport-https \
    software-properties-common \
    && rm -rf /var/lib/apt/lists/*

# 配置x86_64仓库（仅用于获取交叉编译工具链）
RUN mkdir -p /etc/apt/sources.list.d/ && \
    cat > /etc/apt/sources.list.d/ubuntu-x86.list <<'EOF'
deb [arch=amd64] https://mirrors.tuna.tsinghua.edu.cn/ubuntu noble main restricted
deb [arch=amd64] https://mirrors.tuna.tsinghua.edu.cn/ubuntu noble-updates main restricted
deb [arch=amd64] https://mirrors.tuna.tsinghua.edu.cn/ubuntu noble-backports main restricted
deb [arch=amd64] http://security.ubuntu.com/ubuntu/ noble-security main restricted
EOF

# 安装交叉编译工具链
RUN apt-get update && apt-get install -y \
    build-essential \
    wget \
    git \
    pkg-config \
    cmake \
    g++-aarch64-linux-gnu \
    gcc-aarch64-linux-gnu \
    binutils-aarch64-linux-gnu \
    qemu-user-static \
    && rm -rf /var/lib/apt/lists/*

# 配置交叉编译环境变量
ENV CROSS_COMPILE=aarch64-linux-gnu-
ENV CC=aarch64-linux-gnu-gcc
ENV CXX=aarch64-linux-gnu-g++
ENV PKG_CONFIG_PATH=/usr/lib/aarch64-linux-gnu/pkgconfig
ENV PATH="/usr/lib/aarch64-linux-gnu/bin:${PATH}"

# 验证工具链
RUN ${CC} --version && \
    ${CXX} --version

# 设置工作目录
WORKDIR /workspace

# 默认启动命令
CMD ["/bin/bash"]