
# clang-cl

A simple wrapper around `clang-cl.exe`, adding `-fuse-ld=lld -flto=thin` as default arguments and forward thereafter the passed in arguments to `clang-cl.exe` proper, effectively making `lld` and `thin-lto` the default when using `clang-cl.exe`. It assumes the default location for the installation of LLVM.
