
# clang-cl

A simple wrappr around clang-cl.exe, adding `-fuse-ld=lld -flto=thin` as default arguments and forwarding thereafter the passed in arguments. It assumes the default location for the installation of LLVM.
