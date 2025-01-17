# dist.h

PDF, CDF, and percent-point/quantile functions for the normal and Student’s t distributions

[![Build Status](https://github.com/ankane/dist.h/actions/workflows/build.yml/badge.svg)](https://github.com/ankane/dist.h/actions)

## Installation

Add [the header](https://raw.githubusercontent.com/ankane/dist.h/v0.3.1/include/dist.h) to your project.

There is also support for CMake and FetchContent:

```cmake
include(FetchContent)

FetchContent_Declare(dist GIT_REPOSITORY https://github.com/ankane/dist.h.git GIT_TAG v0.3.1)
FetchContent_MakeAvailable(dist)

target_link_libraries(app PRIVATE dist::dist)
```

## Getting Started

Include the header

```cpp
#include "dist.h"
```

- [Normal](#normal)
- [Student’s t](#students-t)

### Normal

```c
normal_pdf(x, mean, std_dev);
normal_cdf(x, mean, std_dev);
normal_ppf(p, mean, std_dev);
```

### Student’s t

```c
students_t_pdf(x, df);
students_t_cdf(x, df);
students_t_ppf(p, df);
```

## References

- [Algorithm AS 241: The Percentage Points of the Normal Distribution](https://www.jstor.org/stable/2347330)
- [Algorithm 395: Student’s t-distribution](https://dl.acm.org/doi/10.1145/355598.355599)
- [Algorithm 396: Student’s t-quantiles](https://dl.acm.org/doi/10.1145/355598.355600)

## History

View the [changelog](https://github.com/ankane/dist.h/blob/master/CHANGELOG.md)

## Contributing

Everyone is encouraged to help improve this project. Here are a few ways you can help:

- [Report bugs](https://github.com/ankane/dist.h/issues)
- Fix bugs and [submit pull requests](https://github.com/ankane/dist.h/pulls)
- Write, clarify, or fix documentation
- Suggest or add new features

To get started with development:

```sh
git clone https://github.com/ankane/dist.h.git
cd dist.h
gcc -Wall -Wextra -Werror -o test/main test/main.c -lm
test/main
```
