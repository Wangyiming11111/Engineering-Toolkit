#include <stdio.h>
#include <math.h>
#include "unitconv.h"
#include "fileio.h"

void unit_converter_menu(void) {
    int opt;
    printf("\n--- UNIT CONVERTER ---\n");
    printf("1) dBm -> mW\n");
    printf("2) mW -> dBm\n");
    printf("3) Hz -> rad/s\n");
    printf("4) rad/s -> Hz\n");
    printf("0) Back\n");
    printf("Select: ");

    if (scanf("%d", &opt) != 1) return;
    if (opt == 0) return;

    double in, out;
    char buffer[128];

    switch (opt) {
        case 1:
            printf("Enter dBm: ");
            scanf("%lf", &in);
            out = dbm_to_mw(in);
            printf("%.3f dBm = %.6f mW\n", in, out);
            snprintf(buffer, sizeof(buffer), "%.3f dBm = %.6f mW", in, out);
            save_result("dBm_to_mW", buffer);
            break;

        case 2:
            printf("Enter mW: ");
            scanf("%lf", &in);
            out = mw_to_dbm(in);
            printf("%.6f mW = %.3f dBm\n", in, out);
            snprintf(buffer, sizeof(buffer), "%.6f mW = %.3f dBm", in, out);
            save_result("mW_to_dBm", buffer);
            break;

        case 3:
            printf("Enter Hz: ");
            scanf("%lf", &in);
            out = hz_to_rad(in);
            printf("%.3f Hz = %.3f rad/s\n", in, out);
            break;

        case 4:
            printf("Enter rad/s: ");
            scanf("%lf", &in);
            out = rad_to_hz(in);
            printf("%.3f rad/s = %.3f Hz\n", in, out);
            break;

        default:
            printf("Invalid option.\n");
    }
}

double dbm_to_mw(double dbm) { return pow(10.0, dbm / 10.0); }
double mw_to_dbm(double mw) { return 10.0 * log10(mw); }
double hz_to_rad(double hz) { return hz * 2.0 * M_PI; }
double rad_to_hz(double rad) { return rad / (2.0 * M_PI); }
