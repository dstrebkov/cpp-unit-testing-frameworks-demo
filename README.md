# cpp-unit-testing-frameworks-demo

![cpp-cmake-project-template](https://github.com/dstrebkov/cpp-unit-testing-frameworks-demo/actions/workflows/cmake.yml/badge.svg?event=push)
![language](https://img.shields.io/github/languages/top/dstrebkov/cpp-unit-testing-frameworks-demo)
![repo size](https://img.shields.io/github/repo-size/dstrebkov/cpp-unit-testing-frameworks-demo)

Sample CMake-based C++ application that links against several static libraries configured with several unit
testing frameworks.

## Contents

- library configured with [Catch2 v3](https://github.com/catchorg/Catch2) ([v3.2.0](https://github.com/catchorg/Catch2/releases/tag/v3.2.0)) for unit testing & [FakeIt](https://github.com/eranpeer/FakeIt) ([2.3.2](https://github.com/eranpeer/FakeIt/releases/tag/2.3.2)) for mocking;
- library configured with [GoogleTest](https://github.com/google/googletest) ([v1.13.0](https://github.com/google/googletest/releases/tag/v1.13.0)) for unit testing and mocking;
- library configured with [Doctest](https://github.com/doctest/doctest) ([v2.4.9](https://github.com/doctest/doctest/releases/tag/v2.4.9)) for unit testing & [FakeIt](https://github.com/eranpeer/FakeIt) ([2.3.2](https://github.com/eranpeer/FakeIt/releases/tag/2.3.2)) for mocking;
- library configured with [Boost.Test](https://github.com/boostorg/test) ([boost-1.81.0](https://github.com/boostorg/test/releases/tag/boost-1.81.0)) for unit testing;
- application that links with them to run some code.

Project's 3-rd party dependencies (_GoogleTest_, _Catch2 v3_, _FakeIt_, _Doctest_, _Boost_) are obtained from GitHub
using CMake's functions `FetchContent_Declare()` and `FetchContent_MakeAvailable()`.

Support of the library that uses Boost.Test is currently under conditional compilation and is disabled by default.
Check instructions below on how it could be enabled, but that would require time consuming fetching of Boost sources
and its building.

## Instructions

Start by doing:

```
mkdir cmake-build
cd cmake-build/
```

Next, if ***not*** using Boost.Test-based demo library, execute:

```
cmake ..
make
```

Otherwise, execute:

```
cmake -DBUILD_FACTORIAL_BOOST_TEST_LIB=ON ..
make
```

Run `app_factorial` application:

```
cd app_factorial/
./app_factorial
```

Run unit tests (called from `cmake-build` folder):

```
cd ..
ctest
```

## Project structure

```
.
│
├── app_factorial/             # Facorial application binary
│   ├── include                # Application includes (empty)
│   ├── src                    # Application sources
│   │   └── main.cpp           # Main entry of the sample factorial application
│   ├── test/                  # Application test folder (empty)
│   └── CMakeLists.txt         # Compile script for application
│
├── factorial_boost            # Boost.Test-based static library
│   ├── include                # Boost.Test-based library includes
│   │   └── factorial.h        # Boost.Test-based library header
│   ├── src                    # Boost.Test-based library sources
│   │   └── factorial.cpp      # Boost.Test-based library source
│   ├── test/                  # Boost.Test-based library tests
│   │   ├── factorial_test.cpp # Tests for Boost.Test-based library
│   │   └── CMakeLists.txt     # Compile script for tests of Boost.Test-based library
│   └── CMakeLists.txt         # Boost.Test-based library compile script
│
├── factorial_catch2           # Catch2-based static library
│   ├── include                # Catch2-based library includes
│   │   └── factorial.h        # Catch2-based library header
│   ├── src                    # Catch2-based library sources
│   │   └── factorial.cpp      # Catch2-based library source
│   ├── test/                  # Catch2-based library tests
│   │   ├── factorial_test.cpp # Tests for Catch2-based library
│   │   └── CMakeLists.txt     # Compile script for tests of Catch2-based library
│   └── CMakeLists.txt         # Catch2-based library compile script
│
├── factorial_doctest          # Doctest-based static library
│   ├── include                # Doctest-based library includes
│   │   └── factorial.h        # Doctest-based library header
│   ├── src                    # Doctest-based library sources
│   │   └── factorial.cpp      # Doctest-based library source
│   ├── test/                  # Doctest-based library tests
│   │   ├── factorial_test.cpp # Tests for Doctest-based library
│   │   └── CMakeLists.txt     # Compile script for tests of Doctest-based library
│   └── CMakeLists.txt         # Doctest-based library compile script
│
├── factorial_gtest            # GTest-based static library
│   ├── include                # GTest-based library includes
│   │   └── factorial.h        # GTest-based library header
│   ├── src                    # GTest-based library sources
│   │   └── factorial.cpp      # GTest-based library source
│   ├── test/                  # GTest-based library tests
│   │   ├── factorial_test.cpp # Tests for GTest-based library
│   │   └── CMakeLists.txt     # Compile script for tests of GTest-based library
│   └── CMakeLists.txt         # GTest-based library compile script
│
└── CMakeLists.txt             # Main compile script
```

## Useful Links

* [Boost.Test Documentation](https://www.boost.org/doc/libs/1_81_0/libs/test/doc/html/index.html)
* [Catch2 v3 Tutorial](https://github.com/catchorg/Catch2/blob/devel/docs/tutorial.md#top)
* [Doctest Tutorial](https://github.com/doctest/doctest/blob/master/doc/markdown/tutorial.md)
* [FakeIt Quickstart](https://github.com/eranpeer/FakeIt/wiki/Quickstart)
* [Googletest Primer](https://google.github.io/googletest/primer.html)

