// Header guard to prevent double inclusion
#ifndef MFREE_H
#define MFREE_H

// @TODO

// Function declarations
/**
 * @brief Frees memory for all given chunks.
 *
 * @param chunks array of pointers to be free'd.
 * @param length length of the chunks array.
 */
void mfree(void *chunks[], unsigned long long length);

#endif  // MAIN_H
