#include <stdio.h>
#include "bit_ops.h"

/* Returns the Nth bit of X. Assumes 0 <= N <= 31. */
unsigned get_bit(unsigned x, unsigned n) {
    /* Shift the nth bit to the least significant position and then perform bitwise AND with 1 */
    return (x >> n) & 1;
}

/* Set the nth bit of the value of x to v. Assumes 0 <= N <= 31, and V is 0 or 1 */
void set_bit(unsigned *x, unsigned n, unsigned v) {
    /* Create a mask with the nth bit set */
    unsigned int tmp = 1 << n;

    /* Clear the nth bit of x */
    *x &= ~tmp;

    /* Set the nth bit of x to v */
    *x |= (v << n);
}

/* Flips the Nth bit in X. Assumes 0 <= N <= 31. */
void flip_bit(unsigned *x, unsigned n) {
    /* XOR with a mask with the nth bit set to toggle the bit */
    *x ^= (1 << n);
}
