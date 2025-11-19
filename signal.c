#include <stdio.h>
#include <math.h>
#include "signal.h"
#include "fileio.h"

double calc_rms(double *x, int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) sum += x[i] * x[i];
    return sqrt(sum / n);
}

double calc_peak(double *x, int n) {
    double peak = x[0];
    for (int i = 1; i < n; i++)
        if (x[i] > peak) peak = x[i];
    return peak;
}

double calc_ptp(double *x, int n) {
    double max = x[0], min = x[0];
    for (int i = 1; i < n; i++) {
        if (x[i] > max) max = x[i];
        if (x[i] < min) min = x[i];
    }
    return max - min;
}

void signal_analyzer_menu(void) {
    int n;
    printf("\n--- SIGNAL ANALYZER ---\n");
    printf("How many samples (max 50)? ");
    scanf("%d", &n);

    if (n < 1 || n > 50) {
        printf("Invalid sample count.\n");
        return;
    }

    double x[50];
    for (int i = 0; i < n; i++) {
        printf("x[%d] = ", i);
        scanf("%lf", &x[i]);
    }

    double rms = calc_rms(x, n);
    double peak = calc_peak(x, n);
    double ptp = calc_ptp(x, n);

    printf("\nRMS = %f\n", rms);
    printf("Peak = %f\n", peak);
    printf("Peak-to-Peak = %f\n", ptp);

    char buffer[128];
    snprintf(buffer, sizeof(buffer),
             "RMS=%f, Peak=%f, PTP=%f", rms, peak, ptp);

    save_result("Signal_Analyzer", buffer);
}
