#ifndef CRYPTOGRAPHY_H
#define CRYPTOGRAPHY_H

typedef uint8_t u8;

void generate_keypair(u8 *publicKey, u8 *privatekey);
void x25519_generate_sharedKey(u8 *out, const u8 *publicKey, const u8 *privatekey);

#endif