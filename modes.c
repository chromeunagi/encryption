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
 * Returns the xor of the data chunk and the key. They should be the same
 * length. The caller is responsible for freeing the return.
 */
unsigned char * xor_chunk(unsigned char *data, unsigned char * key,
  int length) {
    int offset;
    unsigned char *result;

    result = malloc(sizeof(unsigned char) * length);
    for (offset = 0; offset < length; offset++) {
      memset(result + offset, *(data + offset) ^ *(key + offset), 1);
    }
    return result;
  }

  /**
   * Split the data into key_len-sized chunks, and call xor_chunk
   * on each chunk. Returns the overall xor. Caller responsible
   * for freeing the return value.
   *
   * TODO
   *  1. deal with data whose data_len isn't a multiple of
   *     key_len. do this by padding the last chunk appropriately.
   *  2. deal with cases where key_len > data_len
   *  3. test
   */
  unsigned char * xor_data_with_key(unsigned char *data, unsigned char * key,
    int data_len, int key_len) {
      int offset, num_chunks;
      unsigned char *result, *current_chunk;

      // TODO: Remove this once this case is dealt with.
      if (key_len >= data_len || data_len % key_len != 0) {
        fprintf(stdout, "Error: data_len not a multiple of \
          key_len. Not supported yet.");
        return NULL;
      }

      result = malloc(sizeof(unsigned char) * data_len);
      num_chunks = data_len / key_len;

      for (offset = 0; offset < num_chunks; offset = offset + key_len) {
        current_chunk = xor_chunk(data + offset, key, key_len);
        memcpy(result + offset, current_chunk, key_len);
        free(current_chunk);
      }

      return result;
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

/* TODO finish + test*/
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

  return 0;
}
