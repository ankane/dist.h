# dist.h

PDF, CDF, and percent-point/quantile functions for the normal and Student’s t distributions

[![Build Status](https://github.com/ankane/dist.h/workflows/build/badge.svg?branch=master)](https://github.com/ankane/dist.h/actions)

## Installation

Add [the header](https://raw.githubusercontent.com/ankane/dist.h/v0.1.1/include/dist.h) to your project and include it

```cpp
#include "dist.h"
```

## Getting Started

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

- [A handy approximation for the error function and its inverse](https://drive.google.com/file/d/0B2Mt7luZYBrwZlctV3A3eF82VGM/view?resourcekey=0-UQpPhwZgzP0sF4LHBDlLtg)
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
gcc -o test/main test/main.c -lm
test/main
```
