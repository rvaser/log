# Log

Log is a c++ header-only library for program logging.

## Dependencies

Application uses following software:

1. gcc 4.8+ or clang 3.4+
2. cmake 3.2+

## Installation

To install Log run the following commands:

```bash
git clone https://github.com/rvaser/log.git log
cd log
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
make install
```

After installation, the required header will be copied to path. You can also add Log via `cmake` by adding following commands to your CMakeLists.txt file: `add_subdirectory(vendor/log EXCLUDE_FROM_ALL)` and `target_link_libraries(your_exe log)`.

## Usage

For details on how to use the logger in your code, please look at the examples bellow:

```cpp
int main(int argc, char** argv) {
    log::Logger logger;

    // begin logging from this time point
    logger();
    ...
    // print elapsed time from last time point
    logger("Message");

    // print elapsed time in form of a progress bar (restarts itself after 20 calls)
    while (...) {
        logger["Progress bar message"];
    }
    ...
    return 0;
    // destructor prints the total elapsed time
}
```

## Contact information

For additional information, help and bug reports please send an email to one of the following: robert.vaser@fer.hr

## Acknowledgment

This work has been supported in part by Croatian Science Foundation under the projects UIP-2013-11-7353 and IP-2018-01-5886.
