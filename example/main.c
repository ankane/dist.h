#include <stdio.h>

#include "dist.h"

int main() {
    printf("normal_pdf(0, 0, 1) = %f\n", normal_pdf(0, 0, 1));
    printf("normal_cdf(0, 0, 1) = %f\n", normal_cdf(0, 0, 1));
    printf("normal_ppf(0.5, 0, 1) = %f\n", normal_ppf(0.5, 0, 1));

    return 0;
}
