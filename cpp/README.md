
# Usage
- compile
```bash
mkdir build
cd build
cmake -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Release ..
make -j8
```
- run the executable file
```bash
cd ../bin
./<your program>
```


# Struture
``` bash
.
├─app       # test file
├─bin       # binary output
├─conf
├─include   # head file
|   ├─LinkedList.hpp
|   └─...
├─src       # source file
└─tools # Download from release
    ├─cmake-3.20.1-windows-x86_64   # cmake
    └─mingw64                       # mingw 64
```

# Interesting C++
- [linkedlist](app/test-linkedlist.cpp) : a Data Structure
- [C++ Memory shallow copy](app/memory_shallow_copy.cpp) & [C++ Memory deep copy](app/memory_deep_copy.cpp)
- [reference](app/reference.cpp)


# Clang-Format
## Download
In [LLVM](https://llvm.org/builds/) official website, 
choose corresponding **Clang-Format** [Release](https://releases.llvm.org/) for your OS in **Other builds**. 

Then, you can download LLVM in this [page](https://releases.llvm.org/download.html) or in [Github Release](https://github.com/llvm/llvm-project.git)

when installing LLVM, 
in page `Install Options`, select if add LLVM to the system
- [ ] Do not add LLVM to the system PATH
- [x] Add LLVM to the system PATH for all user
- [ ] Add LLVM to the system PATH for current user

## Usage
use `clang-format ` with parameter `-style` and `-i`
- `-style` LLVM、Google、Chromium、Mozilla、WebKit or file(.clang-format)
- `-i`
```
clang-format -style=LLVM -i test.c
```

or you can edit your custom format file [`.clang-format`](.clang-format), 
```
clang-format -i test.c
```

see [Clang documentation](https://clang.llvm.org/docs/ClangFormat.html) for more detail of using Clang-Format

# git
in file `.git/config`
```bash
[remote "origin"]
	url = https://github.com/<用户名>/<仓库名字>.git
	fetch = +refs/heads/*:refs/remotes/origin/*
```


# Code style guide
see [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html)