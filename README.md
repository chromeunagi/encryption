# Encryption
My implementation of some basic cryptography functions.

# Genkey
Samples /dev/urandom to create a key of the provided length. Compile with:

    gcc -o genkey genkey.c

To create a key, input a length and a target output filepath, e.g.

    ./genkey 4096 mycoolkey.priv
    
# Completed
*   Key generation
*   Parity calculator

# In progress
*   General feistel cipher
*   Different modes of operation
