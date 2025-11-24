#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
#include <string.h>
#include "funcs.h"


double dbm_to_mw(double dbm) { return pow(10.0, dbm / 10.0); }
double mw_to_dbm(double mw) { return 10.0 * log10(mw); }
double hz_to_rad(double hz) { return hz * 2 * M_PI; }
double rad_to_hz(double rad) { return rad / (2 * M_PI); }

double rc_tau(double R, double C) { return R * C; }
double rc_fc(double R, double C) { return 1.0 / (2 * M_PI * R * C); }


double calc_rms(double *x, int n) {
    double sum = 0;
    for (int i = 0; i < n; i++)
        sum += x[i] * x[i];
    return sqrt(sum / n);
}

double calc_peak(double *x, int n) {
    double max = x[0];
    for (int i = 1; i < n; i++)
        if (x[i] > max) max = x[i];
    return max;
}

double calc_ptp(double *x, int n) {
    double max = x[0], min = x[0];
    for (int i = 1; i < n; i++) {
        if (x[i] > max) max = x[i];
        if (x[i] < min) min = x[i];
    }
    return max - min;
}

void save_result(const char *label, const char *data) {
    char ch;
    printf("Save to results.csv? (y/n): ");
    while (getchar() != '\n');
    ch = getchar();

    if (ch == 'y' || ch == 'Y') {
        FILE *f = fopen("results.csv", "a");
        if (!f) {
            printf("Error opening results.csv\n");
            return;
        }
        fprintf(f, "%s,%s\n", label, data);
        fclose(f);
        printf("Saved successfully.\n");
    }
}


void menu_item_1(void) {
    int choice;
    double in, out;
    char buf[128];

    printf("\n--- UNIT CONVERTER ---\n");
    printf("1) dBm → mW\n");
    printf("2) mW → dBm\n");
    printf("3) Hz → rad/s\n");
    printf("4) rad/s → Hz\n");
    printf("Select: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter dBm: ");
            scanf("%lf", &in);
            out = dbm_to_mw(in);
            printf("%lf dBm = %lf mW\n", in, out);
            snprintf(buf, sizeof(buf), "%lf dBm = %lf mW", in, out);
            save_result("dBm_to_mW", buf);
            break;

        case 2:
            printf("Enter mW: ");
            scanf("%lf", &in);
            out = mw_to_dbm(in);
            printf("%lf mW = %lf dBm\n", in, out);
            snprintf(buf, sizeof(buf), "%lf mW = %lf dBm", in, out);
            save_result("mW_to_dBm", buf);
            break;

        case 3:
            printf("Enter Hz: ");
            scanf("%lf", &in);
            out = hz_to_rad(in);
            printf("%lf Hz = %lf rad/s\n", in, out);
            break;

        case 4:
            printf("Enter rad/s: ");
            scanf("%lf", &in);
            out = rad_to_hz(in);
            printf("%lf rad/s = %lf Hz\n", in, out);
            break;
    }
}

void menu_item_2(void) {
    double R, C;
    double tau, fc;
    char buf[128];

    printf("\n--- RC HELPER ---\n");
    printf("Enter R (ohm): ");
    scanf("%lf", &R);
    printf("Enter C (F): ");
    scanf("%lf", &C);

    tau = rc_tau(R, C);
    fc = rc_fc(R, C);

    printf("Tau = %g seconds\n", tau);
    printf("Cutoff frequency = %g Hz\n", fc);

    snprintf(buf, sizeof(buf), "R=%g,C=%g,tau=%g,fc=%g", R, C, tau, fc);
    save_result("RC_Helper", buf);
}

void menu_item_3(void) {
    int n;
    double x[50];

    printf("\n--- SIGNAL ANALYZER ---\n");
    printf("Number of samples (max 50): ");
    scanf("%d", &n);

    if (n < 1 || n > 50) {
        printf("Invalid size.\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        printf("x[%d] = ", i);
        scanf("%lf", &x[i]);
    }

    printf("RMS = %lf\n", calc_rms(x, n));
    printf("Peak = %lf\n", calc_peak(x, n));
    printf("Peak-to-peak = %lf\n", calc_ptp(x, n));
}

void menu_item_4(void) {
    printf("\n--- ABOUT ---\n");
    printf("Engineering Toolkit v1.0\n");
    printf("Built for ELEC2645 Unit 2 Project\n");
}
