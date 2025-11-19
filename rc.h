#ifndef RC_H
#define RC_H

void rc_helper_menu(void);

/* exposed for tests */
double rc_tau(double R, double C);
double rc_fc(double R, double C);

#endif