#ifndef VOYAGER_MD5_H
#define VOYAGER_MD5_H
/*
 * MD5, derived from the RSA Data Security, Inc. MD5 Message-Digest
 * Algorithm (see md5.c).
 */

#ifndef MD5_UINT4
#define MD5_UINT4 unsigned long /* 32 bit on 68k */
#endif
typedef MD5_UINT4 UINT4;

typedef struct {
	UINT4 buf[ 4 ];				/* scratch buffer */
	UINT4 i[ 2 ];				/* number of _bits_ handled mod 2^64 */
	unsigned char in[ 64 ];		/* input buffer */
} MD5_CTX;

/* message digest of inlen bytes at in, 16 bytes to out */
void voy_calcmd5( const void *in, int inlen, unsigned char *out );

#endif /* VOYAGER_MD5_H */
