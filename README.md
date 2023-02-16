# cpp-unit-testing-frameworks-demo

![cpp-cmake-project-template](https://github.com/dstrebkov/cpp-unit-testing-frameworks-demo/actions/workflows/cmake.yml/badge.svg?event=push)
![language](https://img.shields.io/github/languages/top/dstrebkov/cpp-unit-testing-frameworks-demo)
![repo size](https://img.shields.io/github/repo-size/dstrebkov/cpp-unit-testing-frameworks-demo)

Sample CMake-based C++ application that demonstrates setup and basic usage of several Unit Testing Frameworks for C++.

## Contents

- library configured with [Boost.Test](https://github.com/boostorg/test) ([boost-1.81.0](https://github.com/boostorg/test/releases/tag/boost-1.81.0)) for unit testing;
- library configured with [Catch2 v3](https://github.com/catchorg/Catch2) ([v3.2.0](https://github.com/catchorg/Catch2/releases/tag/v3.2.0)) for unit testing & [FakeIt](https://github.com/eranpeer/FakeIt) ([2.3.2](https://github.com/eranpeer/FakeIt/releases/tag/2.3.2)) for mocking;
- library configured with [Criterion](https://github.com/Snaipe/Criterion) ([v2.4.1](https://github.com/Snaipe/Criterion/releases/tag/v2.4.1)) for unit testing & [trompeloeil](https://github.com/rollbear/trompeloeil) ([v43](https://github.com/rollbear/trompeloeil/releases/tag/v43)) for mocking;
- library configured with [Doctest](https://github.com/doctest/doctest) ([v2.4.9](https://github.com/doctest/doctest/releases/tag/v2.4.9)) for unit testing & [FakeIt](https://github.com/eranpeer/FakeIt) ([2.3.2](https://github.com/eranpeer/FakeIt/releases/tag/2.3.2)) for mocking;
- library configured with [GoogleTest](https://github.com/google/googletest) ([v1.13.0](https://github.com/google/googletest/releases/tag/v1.13.0)) for unit testing and mocking;
- library configured with [lest](https://github.com/martinmoene/lest) ([1.35.1](https://github.com/martinmoene/lest/releases/tag/v1.35.1)) for unit testing & [trompeloeil](https://github.com/rollbear/trompeloeil) ([v43](https://github.com/rollbear/trompeloeil/releases/tag/v43)) for mocking;
- application that links with them to run some code.

All unit testing frameworks except **Criterion** are obtained as sources from GitHub using CMake's functions `FetchContent_Declare()` and `FetchContent_MakeAvailable()`.

#### Criterion
Criterion framework is added to the project as Linux release binaries taken from GitHub via `FetchContent_Declare()` and `FetchContent_Populate()` since that framework has migrated from CMake to [Meson build system](https://mesonbuild.com/) since `v2.4.0` on February, 2022. Criterion binaries are available for Linux platform only - in case of other platform (i.e. Windows) corresponding library `factorial_criterion` would not be built.

#### Boost.Test
Support of the library that uses Boost.Test (`factorial_boost`) is currently under conditional compilation and is disabled by default.
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

Placeholder `XXX` on depicted structure below stands for the name of the used unit testing framework.

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
├── factorial_XXX              # XXX-based static library
│   ├── include                # XXX-based library includes
│   │   └── factorial.h        # XXX-based library header
│   ├── src                    # XXX-based library sources
│   │   └── factorial.cpp      # XXX-based library source
│   ├── test/                  # XXX-based library tests
│   │   ├── factorial_test.cpp # Tests for XXX-based library
│   │   └── CMakeLists.txt     # Compile script for tests of XXX-based library
│   └── CMakeLists.txt         # XXX-based library compile script
│
├── .....
│
└── CMakeLists.txt             # Main compile script
```

## Useful Links

* [Boost.Test Documentation](https://www.boost.org/doc/libs/1_81_0/libs/test/doc/html/index.html)
* [Catch2 v3 Tutorial](https://github.com/catchorg/Catch2/blob/devel/docs/tutorial.md#top)
* [Doctest Tutorial](https://github.com/doctest/doctest/blob/master/doc/markdown/tutorial.md)
* [FakeIt Quickstart](https://github.com/eranpeer/FakeIt/wiki/Quickstart)
* [Googletest Primer](https://google.github.io/googletest/primer.html)
* [lest Usage](https://github.com/martinmoene/lest#usage)
* [trompeloeil Introduction](https://playfulprogramming.blogspot.com/2014/12/introducing-trompeloeil-c-mocking.html)
* [Criterion Documentation](https://readthedocs.org/projects/criterion/downloads/pdf/latest/)
