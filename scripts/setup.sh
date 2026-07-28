#!/bin/bash

set -e

echo "=====Installing build-essential, gdb, cmake======"
sudo apt update
sudo apt install -y build-essential gdb cmake

echo "=====Verifying installations===="
echo "gcc --version"
gcc --version
echo "g++ --version"
g++ --version
echo "make --version"
make --version
echo "cmake --version"
cmake --version
echo "gdb --version"
gdb --version
echo "==== Verified ===="


echo "====Installing perf, htop, tcpdump, sar===="
sudo apt install -y htop tcpdump sysstat linux-tools-common linux-tools-generic linux-tools-$(uname -r)
echo "perf --version"
perf --version
echo "htop --version"
htop --version
echo "tcpdump --version"
tcpdump --version
echo "sar -V"
sar -V

echo "====Verified perf, htop, tcpdump, sar===="
