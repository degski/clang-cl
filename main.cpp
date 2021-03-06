
// MIT License
//
// Copyright (c) 2018 degski
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include <process.h> // _wsystem
#include <cstdlib>
#include <string>
#include "short_alloc.h" // https://howardhinnant.github.io/stack_alloc.html

#if defined ( _DEBUG )
template<typename CharType, std::size_t Size>
using stack_string_allocator = short_alloc<CharType, Size, alignof ( std::max_align_t )>;
#else
template<typename CharType, std::size_t Size>
using stack_string_allocator = short_alloc<CharType, Size, alignof ( CharType )>;
#endif
template<typename CharType, std::size_t Size>
using basic_stack_string = std::basic_string<CharType, std::char_traits<CharType>, stack_string_allocator<CharType, Size>>;


int wmain ( const int argc, const wchar_t * argv [ ] ) {

    using stack_string = basic_stack_string<wchar_t, 2048u>;

    stack_string::allocator_type::arena_type allocator;
    stack_string command { L"\"C:\\Program Files\\LLVM\\bin\\clang-cl.exe\" -fuse-ld=lld -flto=thin", allocator };

    for ( int i = 1; i < argc; ++i ) {
        command += L' ';
        command += argv [ i ];
    }

    return _wsystem ( command.c_str ( ) );
}
