#ifndef FUNCS_H
#define FUNCS_H


void menu_item_1(void);
void menu_item_2(void);
void menu_item_3(void);
void menu_item_4(void);


double dbm_to_mw(double dbm);
double mw_to_dbm(double mw);
double hz_to_rad(double hz);
double rad_to_hz(double rad);


double rc_tau(double R, double C);
double rc_fc(double R, double C);


double calc_rms(double *x, int n);
double calc_ptp(double *x, int n);
double calc_peak(double *x, int n);

void save_result(const char *label, const char *data);

#endif
