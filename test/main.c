#include <assert.h>
#include <math.h>
#include <stddef.h>

#include "../include/dist.h"

void assert_in_delta(double exp, double act, double delta) {
    if (isinf(exp)) {
      assert(exp == act);
    } else {
      assert(fabs(exp - act) < delta);
    }
}

void test_normal_pdf() {
    double inputs[] = {-INFINITY, -3.0, -2.0, -1.0, 0.0, 1.0, 2.0, 3.0, INFINITY};
    double expected[] = {0.0, 0.00443, 0.05399, 0.24197, 0.39894, 0.24197, 0.05399, 0.00443, 0.0};
    for (size_t i = 0; i < sizeof(inputs) / sizeof(double); i++) {
        assert_in_delta(normal_pdf(inputs[i], 0, 1), expected[i], 0.00001);
    }
}

void test_normal_pdf_mean_std_dev() {
    double inputs[] = {-INFINITY, -3.0, -2.0, -1.0, 0.0, 1.0, 2.0, 3.0, INFINITY};
    double expected[] = {0.0, 0.027, 0.06476, 0.12099, 0.17603, 0.19947, 0.17603, 0.12099, 0.0};
    for (size_t i = 0; i < sizeof(inputs) / sizeof(double); i++) {
        assert_in_delta(normal_pdf(inputs[i], 1, 2), expected[i], 0.00001);
    }
}

void test_normal_pdf_infinite_mean() {
    assert_in_delta(normal_pdf(0, -INFINITY, 1), 0, 0.00001);
    assert_in_delta(normal_pdf(0, INFINITY, 1), 0, 0.00001);
}

void test_normal_pdf_infinite_std_dev() {
    assert_in_delta(normal_pdf(0, 0, INFINITY), 0, 0.00001);
}

void test_normal_pdf_nan() {
    assert(isnan(normal_pdf(NAN, 0.0, 1.0)));
    assert(isnan(normal_pdf(0.0, NAN, 1.0)));
    assert(isnan(normal_pdf(0.0, 0.0, NAN)));
}

void test_normal_cdf() {
    double inputs[] = {-INFINITY, -3.0, -2.0, -1.0, 0.0, 1.0, 2.0, 3.0, INFINITY};
    double expected[] = {0.0, 0.00135, 0.02275, 0.15866, 0.5, 0.84134, 0.97725, 0.99865, 1.0};
    for (size_t i = 0; i < sizeof(inputs) / sizeof(double); i++) {
        assert_in_delta(normal_cdf(inputs[i], 0, 1), expected[i], 0.00001);
    }
}

void test_normal_cdf_mean_std_dev() {
    double inputs[] = {-INFINITY, -3.0, -2.0, -1.0, 0.0, 1.0, 2.0, 3.0, INFINITY};
    double expected[] = {0.0, 0.02275, 0.06681, 0.15866, 0.30854, 0.5, 0.69146, 0.84134, 1.0};
    for (size_t i = 0; i < sizeof(inputs) / sizeof(double); i++) {
        assert_in_delta(normal_cdf(inputs[i], 1, 2), expected[i], 0.00001);
    }
}

void test_normal_cdf_infinite_mean() {
    assert_in_delta(normal_cdf(1, -INFINITY, 1), 1, 0.00001);
    assert_in_delta(normal_cdf(1, INFINITY, 1), 0, 0.00001);
}

void test_normal_cdf_infinite_std_dev() {
    assert_in_delta(normal_cdf(1, 0, INFINITY), 0.5, 0.00001);
}

void test_normal_cdf_nan() {
    assert(isnan(normal_cdf(NAN, 0.0, 1.0)));
    assert(isnan(normal_cdf(0.0, NAN, 1.0)));
    assert(isnan(normal_cdf(0.0, 0.0, NAN)));
}

void test_normal_ppf() {
    double inputs[] = {0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0};
    double expected[] = {-INFINITY, -1.28155, -0.84162, -0.5244, -0.25335, 0.0, 0.25335, 0.5244, 0.84162, 1.28155, INFINITY};
    for (size_t i = 0; i < sizeof(inputs) / sizeof(double); i++) {
        assert_in_delta(normal_ppf(inputs[i], 0, 1), expected[i], 0.0002);
    }
}

void test_normal_ppf_mean_std_dev() {
    double inputs[] = {0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0};
    double expected[] = {-INFINITY, -1.5631, -0.68324, -0.0488, 0.49331, 1.0, 1.50669, 2.0488, 2.68324, 3.5631, INFINITY};
    for (size_t i = 0; i < sizeof(inputs) / sizeof(double); i++) {
        assert_in_delta(normal_ppf(inputs[i], 1, 2), expected[i], 0.0004);
    }
}

void test_students_t_pdf_one() {
    double inputs[] = {-INFINITY, -3.0, -2.0, -1.0, 0.0, 1.0, 2.0, 3.0, INFINITY};
    double expected[] = {0.0, 0.03183, 0.06366, 0.15915, 0.31831, 0.15915, 0.06366, 0.03183, 0.0};
    for (size_t i = 0; i < sizeof(inputs) / sizeof(double); i++) {
        assert_in_delta(students_t_pdf(inputs[i], 1), expected[i], 0.00001);
    }
}

void test_students_t_pdf_two() {
    double inputs[] = {-INFINITY, -3.0, -2.0, -1.0, 0.0, 1.0, 2.0, 3.0, INFINITY};
    double expected[] = {0.0, 0.02741, 0.06804, 0.19245, 0.35355, 0.19245, 0.06804, 0.02741, 0.0};
    for (size_t i = 0; i < sizeof(inputs) / sizeof(double); i++) {
        assert_in_delta(students_t_pdf(inputs[i], 2), expected[i], 0.00001);
    }
}

void test_students_t_pdf_thirty() {
    double inputs[] = {-INFINITY, -3.0, -2.0, -1.0, 0.0, 1.0, 2.0, 3.0, INFINITY};
    double expected[] = {0.0, 0.00678, 0.05685, 0.23799, 0.39563, 0.23799, 0.05685, 0.00678, 0.0};
    for (size_t i = 0; i < sizeof(inputs) / sizeof(double); i++) {
        assert_in_delta(students_t_pdf(inputs[i], 30), expected[i], 0.00001);
    }
}

void test_students_t_pdf_non_integer() {
    double inputs[] = {-INFINITY, -3.0, -2.0, -1.0, 0.0, 1.0, 2.0, 3.0, INFINITY};
    double expected[] = {0.0, 0.02504, 0.06796, 0.2008, 0.36181, 0.2008, 0.06796, 0.02504, 0.0};
    for (size_t i = 0; i < sizeof(inputs) / sizeof(double); i++) {
        assert_in_delta(students_t_pdf(inputs[i], 2.5), expected[i], 0.00001);
    }
}

void test_students_t_pdf_infinity() {
    double inputs[] = {-INFINITY, -3.0, -2.0, -1.0, 0.0, 1.0, 2.0, 3.0, INFINITY};
    double expected[] = {0.0, 0.00443, 0.05399, 0.24197, 0.39894, 0.24197, 0.05399, 0.00443, 0.0};
    for (size_t i = 0; i < sizeof(inputs) / sizeof(double); i++) {
        assert_in_delta(students_t_pdf(inputs[i], INFINITY), expected[i], 0.00001);
    }
}

void test_students_t_pdf_less_than_one() {
    double inputs[] = {-INFINITY, -3.0, -2.0, -1.0, 0.0, 1.0, 2.0, 3.0, INFINITY};
    double expected[] = {0.0, 0.02963, 0.0519, 0.1183, 0.26968, 0.1183, 0.0519, 0.02963, 0.0};
    for (size_t i = 0; i < sizeof(inputs) / sizeof(double); i++) {
        assert_in_delta(students_t_pdf(inputs[i], 0.5), expected[i], 0.00001);
    }
}

void test_students_t_pdf_nan() {
    assert(isnan(students_t_pdf(NAN, 1)));
    // TODO uncomment in 0.2.0
    // assert(isnan(students_t_pdf(0.0, NAN)));
}

void test_students_t_cdf_one() {
    double inputs[] = {-INFINITY, -3.0, -2.0, -1.0, 0.0, 1.0, 2.0, 3.0, INFINITY};
    double expected[] = {0.0, 0.10242, 0.14758, 0.25, 0.5, 0.75, 0.85242, 0.89758, 1.0};
    for (size_t i = 0; i < sizeof(inputs) / sizeof(double); i++) {
        assert_in_delta(students_t_cdf(inputs[i], 1), expected[i], 0.00001);
    }
}

void test_students_t_cdf_two() {
    double inputs[] = {-INFINITY, -3.0, -2.0, -1.0, 0.0, 1.0, 2.0, 3.0, INFINITY};
    double expected[] = {0.0, 0.04773, 0.09175, 0.21132, 0.5, 0.78868, 0.90825, 0.95227, 1.0};
    for (size_t i = 0; i < sizeof(inputs) / sizeof(double); i++) {
        assert_in_delta(students_t_cdf(inputs[i], 2), expected[i], 0.00001);
    }
}

void test_students_t_cdf_thirty() {
    double inputs[] = {-INFINITY, -3.0, -2.0, -1.0, 0.0, 1.0, 2.0, 3.0, INFINITY};
    double expected[] = {0.0, 0.00269, 0.02731, 0.16265, 0.5, 0.83735, 0.97269, 0.99731, 1.0};
    for (size_t i = 0; i < sizeof(inputs) / sizeof(double); i++) {
        assert_in_delta(students_t_cdf(inputs[i], 30), expected[i], 0.00001);
    }
}

void test_students_t_cdf_non_integer() {
    double inputs[] = {-INFINITY, -3.0, -2.0, -1.0, 0.0, 1.0, 2.0, 3.0, INFINITY};
    double expected[] = {0.0, 0.03629, 0.0787, 0.20203, 0.5, 0.79797, 0.9213, 0.96371, 1.0};
    for (size_t i = 0; i < sizeof(inputs) / sizeof(double); i++) {
        assert_in_delta(students_t_cdf(inputs[i], 2.5), expected[i], 0.00005);
    }
}

void test_students_t_cdf_infinity() {
    double inputs[] = {-INFINITY, -3.0, -2.0, -1.0, 0.0, 1.0, 2.0, 3.0, INFINITY};
    double expected[] = {0.0, 0.00135, 0.02275, 0.15866, 0.5, 0.84134, 0.97725, 0.99865, 1.0};
    for (size_t i = 0; i < sizeof(inputs) / sizeof(double); i++) {
        assert_in_delta(students_t_cdf(inputs[i], INFINITY), expected[i], 0.00001);
    }
}

void test_students_t_cdf_nan() {
    assert(isnan(students_t_cdf(NAN, 1)));
    // TODO uncomment in 0.2.0
    // assert(isnan(students_t_cdf(0.0, NAN)));
}

void test_students_t_ppf_one() {
    double inputs[] = {0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0};
    double expected[] = {-INFINITY, -3.07768, -1.37638, -0.72654, -0.32492, 0.0, 0.32492, 0.72654, 1.37638, 3.07768, INFINITY};
    for (size_t i = 0; i < sizeof(inputs) / sizeof(double); i++) {
        assert_in_delta(students_t_ppf(inputs[i], 1), expected[i], 0.00001);
    }
}

void test_students_t_ppf_two() {
    double inputs[] = {0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0};
    double expected[] = {-INFINITY, -1.88562, -1.06066, -0.61721, -0.28868, 0.0, 0.28868, 0.61721, 1.06066, 1.88562, INFINITY};
    for (size_t i = 0; i < sizeof(inputs) / sizeof(double); i++) {
        assert_in_delta(students_t_ppf(inputs[i], 2), expected[i], 0.00001);
    }
}

void test_students_t_ppf_thirty() {
    double inputs[] = {0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0};
    double expected[] = {-INFINITY, -1.31042, -0.85377, -0.53002, -0.25561, 0.0, 0.25561, 0.53002, 0.85377, 1.31042, INFINITY};
    for (size_t i = 0; i < sizeof(inputs) / sizeof(double); i++) {
        assert_in_delta(students_t_ppf(inputs[i], 30), expected[i], 0.0002);
    }
}

void test_students_t_ppf_non_integer() {
    double inputs[] = {0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0};
    double expected[] = {-INFINITY, -1.73025, -1.01016, -0.59731, -0.28146, 0.0, 0.28146, 0.59731, 1.01016, 1.73025, INFINITY};
    for (size_t i = 0; i < sizeof(inputs) / sizeof(double); i++) {
        assert_in_delta(students_t_ppf(inputs[i], 2.5), expected[i], 0.0002);
    }
}

void test_students_t_ppf_infinity() {
    double inputs[] = {0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0};
    double expected[] = {-INFINITY, -1.28155, -0.84162, -0.5244, -0.25335, 0.0, 0.25335, 0.5244, 0.84162, 1.28155, INFINITY};
    for (size_t i = 0; i < sizeof(inputs) / sizeof(double); i++) {
        assert_in_delta(students_t_ppf(inputs[i], INFINITY), expected[i], 0.0002);
    }
}

int main() {
    test_normal_pdf();
    test_normal_pdf_mean_std_dev();
    test_normal_pdf_infinite_mean();
    test_normal_pdf_infinite_std_dev();
    test_normal_pdf_nan();

    test_normal_cdf();
    test_normal_cdf_mean_std_dev();
    test_normal_cdf_infinite_mean();
    test_normal_cdf_infinite_std_dev();
    test_normal_cdf_nan();

    test_normal_ppf();
    test_normal_ppf_mean_std_dev();

    test_students_t_pdf_one();
    test_students_t_pdf_two();
    test_students_t_pdf_thirty();
    test_students_t_pdf_non_integer();
    test_students_t_pdf_infinity();
    test_students_t_pdf_less_than_one();
    test_students_t_pdf_nan();

    test_students_t_cdf_one();
    test_students_t_cdf_two();
    test_students_t_cdf_thirty();
    test_students_t_cdf_non_integer();
    test_students_t_cdf_infinity();
    test_students_t_cdf_nan();

    test_students_t_ppf_one();
    test_students_t_ppf_two();
    test_students_t_ppf_thirty();
    test_students_t_ppf_non_integer();
    test_students_t_ppf_infinity();

    return 0;
}
