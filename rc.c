#include <stdio.h>
#include <math.h>
#include "rc.h"
#include "fileio.h"

double rc_tau(double R, double C) {
    return R * C;
}

double rc_fc(double R, double C) {
    return 1.0 / (2.0 * M_PI * R * C);
}

void rc_helper_menu(void) {
    double R, C;
    char buffer[128];

    printf("\n--- RC CIRCUIT HELPER ---\n");
    printf("Enter R (ohms): ");
    if (scanf("%lf", &R) != 1) return;

    printf("Enter C (farads): ");
    if (scanf("%lf", &C) != 1) return;

    double tau = rc_tau(R, C);
    double fc = rc_fc(R, C);

    printf("\nTime constant τ = %g s\n", tau);
    printf("Cutoff frequency fc = %g Hz\n", fc);

    snprintf(buffer, sizeof(buffer),
             "R=%g, C=%g, tau=%g, fc=%g", R, C, tau, fc);

    save_result("RC_Helper", buffer);
}
