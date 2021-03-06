#include "spongent.h"
#include "spongewrap.h"

int spongent_wrap(void* key,
                  void* ad, unsigned int ad_len,
                  void* body, unsigned int body_len,
                  void* cipher, void* tag)
{
    HashReturn rv;

    rv = SpongentWrap((const BitSequence*) key,
                      (const BitSequence*) ad, (DataLength) ad_len * 8,
                      (const BitSequence*) body, (DataLength) body_len * 8,
                      (BitSequence*) cipher, (BitSequence*) tag,
                      /*unwrap=*/ false);

    return rv;
}

int spongent_unwrap(void* key,
                    void* ad, unsigned int ad_len,
                    void* cipher, unsigned int cipher_len,
                    void* body, void* tag)
{
    HashReturn rv;

    rv = SpongentUnwrap((const BitSequence*) key,
                        (const BitSequence*) ad, (DataLength) ad_len * 8,
                        (const BitSequence*) cipher, (DataLength) cipher_len * 8,
                        (BitSequence*) body, (BitSequence*) tag);

    return rv;
}

int spongent_mac(void* key,
                 void* msg, unsigned int msg_len,
                 void* mac)
{
    HashReturn rv;

    rv = SpongentMac(   (const BitSequence*) key,
                        (const BitSequence*) msg, (DataLength) msg_len * 8,
                        (BitSequence*) mac);

    return rv;
}
