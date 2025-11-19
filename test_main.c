#include <assert.h>
#include <stdio.h>
#include "../unitconv.h"
#include "../rc.h"
#include "../signal.h"

int main(void) {
    /* Unit converter tests */
    assert(dbm_to_mw(0) == 1.0);
    assert((int)hz_to_rad(1) == 6);

    /* RC tests */
    assert(rc_tau(1000, 0.001) == 1.0);
    assert((int)rc_fc(1000, 0.000001) == 159);

    /* Signal tests */
    double x[3] = {1, -1, 1};
    assert((int)calc_rms(x, 3) == 1);
    assert(calc_peak(x, 3) == 1);

    printf("All tests passed.\n");
    return 0;
}
