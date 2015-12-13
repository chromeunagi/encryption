#include <stdlib.h>
#include <stdio.h>

#include "string.h"

/**
 * Runs the data through a 4-round feistel cipher
 * The key should be twice as long as the data chunk.
 */
void feistel(void *data, int size, int chunk_size, FILE *key) {
  // read key in
  // split data key into chunks
}

/**
 * Perform one round of a feistel cipher.
 * L_i = R_{i-1}
 * R_i = L_{i-1} xor F(K_{i-1}, R_{i-1})
 */
void feistel_round(void *data, void *key, int size) {
  // split into L and R
  //
}

/**
 * Placeholder for a better function. Right now, this function returns chunk
 * xor key.
 *
 * It's the responsibility of the caller to free this function's return.
 */
unsigned char * temp_function(unsigned char *chunk, unsigned char *key, int length) {
  if (length % 8 != 0) {
    fprintf(stderr, "Invalid input to feistel. Length not divisible by 8.");
    exit(1);
  }

  int i;
  unsigned char *buf;
  unsigned char chunk_piece, key_piece;

  buf = (unsigned char *)malloc(length);

  for (i = 0; i < length / 8; i++) {
    chunk_piece = *(chunk + 8 * i);
    key_piece = *(key + 8 * i);
    memset(buf + 8 * i, chunk_piece ^ key_piece, 1);
  }

  return buf;
}

int parity_naive(unsigned char *data, int length) {
  int i, j, number_of_ones = 0;
  unsigned char current_byte;

  for (i = 0; i < length; i++) {
    current_byte = *(data + i);
    for (j = 0; j < 8; j++) {
      number_of_ones = number_of_ones + ((current_byte >> j) & 0x1);
    }
  }
  return number_of_ones % 2;
}

/* TODO */
int parity (unsigned char *data, int length) {
  if (length == 0) {
    return 0;
  } else if (length == 1) {
    return parity_naive(data, 1);
  } else {
    int left_length, right_length;
    unsigned char *right_data, *left_data;

    left_length = length / 2;
    right_length = length - left_length;

    left_data = data;
    right_data = data + left_length;

    return parity(left_data, left_length) ^ parity(right_data, right_length);
  }
}

int main(int argc, char const *argv[]) {
  /* code */

  char *word = "caaaaatta";
  char letter;
  int i, result;

  for (i = 0; i < strlen(word); i++) {
    letter = word[i];
    result = parity_naive((unsigned char *)(&letter), 1);
    fprintf(stdout, "%c: %d\n", letter, result);
  }

  fprintf(stdout, "final: %d\n", parity_naive(
    (unsigned char *)(word),
    strlen(word)));

  return 0;
}
