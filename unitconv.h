#ifndef UNITCONV_H
#define UNITCONV_H

void unit_converter_menu(void);

/* exposed functions for testing */
double dbm_to_mw(double dbm);
double mw_to_dbm(double mw);
double hz_to_rad(double hz);
double rad_to_hz(double rad);

#endif
