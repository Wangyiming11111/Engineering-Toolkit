#ifndef SIGNAL_H
#define SIGNAL_H

void signal_analyzer_menu(void);

/* exposed for tests */
double calc_rms(double *x, int n);
double calc_peak(double *x, int n);
double calc_ptp(double *x, int n);

#endif
