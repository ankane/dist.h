## 0.3.0 (2022-08-28)

- Improved accuracy of `normal_ppf` and `students_t_ppf`
- Return `NAN` for invalid inputs

## 0.2.1 (2022-07-31)

- Added support for `df` between zero and one to `students_t_pdf`
- Fixed bug with `students_t_cdf` when `x` is infinite or NaN
- Fixed bug with `students_t_*` functions when `df` is infinity

## 0.2.0 (2022-07-26)

- Added support for non-integer degrees of freedom
- Improved accuracy of `normal_cdf` and `students_t_cdf`
- Fixed bug with `normal_*` functions when `std_dev` is not one

## 0.1.1 (2022-03-19)

- Removed need for `_USE_MATH_DEFINES`

## 0.1.0 (2022-01-03)

- First release
