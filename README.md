# Note-Recognition

Small project by a mentoree group the detects the notes that you give it.

## Build

The project should build on windows/mac/linux.

### Windows

You need to pass the root location of your Qt install as the cmake variable `CMAKE_PREFIX_PATH`. For example, on my machine, my Qt install is `C:/Qt/5.12.0/msvc2017_64`. To call cmake with that path you'd pass `-DCMAKE_PREFIX_PATH=C:/Qt/5.12.0/msvc2017_64` to cmake.

## General

These are general build instructions for both linux and windows.

```
mkdir build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Debug
cmake --build .

# to format:
tools/format.bash
# to lint:
tools/lint-clang.bash
# to run:
bin/noter-gui
```
