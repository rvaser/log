# Logger

Logger is a c++ header-only library for program logging.

## Dependencies

Application uses following software:

1. gcc 4.8+ or clang 3.4+
2. cmake 3.2+

## Installation

To install Logger run the following commands:

```bash
git clone https://github.com/rvaser/logger.git logger
cd logger
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
make install
```

After installation, the required header will be copied to path. You can also add Logger via `cmake` by adding following commands to your `CMakeLists.txt` file: `add_subdirectory(vendor/logger EXCLUDE_FROM_ALL)` and `target_link_libraries(your_exe logger)`.

## Usage

For details on how to use the logger in your code, please look at the examples bellow:

```cpp
logger::Logger l;
...
// begin logging from this time point
l();
...
// print elapsed time from last time point
l("Message");

// print elapsed time in form of a progress bar (resets after 20 calls)
while (...) {
    l["Progress bar message"];
}
...
// print total elapsed time
l.total("Message");
```

## Contact information

For additional information, help and bug reports please send an email to one of the following: robert.vaser@fer.hr

## Acknowledgment

This work has been supported in part by Croatian Science Foundation under the projects UIP-2013-11-7353 and IP-2018-01-5886.
