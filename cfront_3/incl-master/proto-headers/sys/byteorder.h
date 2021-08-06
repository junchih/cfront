#usedby svr4 solaris sgi-svr4

/* in /usr/include/sys/byteorder.h, the conversion functions
   are defined in assembler (which is not acceptable to cfront) */

#ifndef _SYS_BYTEORDER_H
#define _SYS_BYTEORDER_H

#if !defined(vax) && !defined(ntohl) && !defined(lint) && !defined(i386)
/* big-endian */
#define ntohl(x) (x)
#define htonl(x) (x)
#define ntohs(x) (x)
#define htons(x) (x)

#elif defined(i386)

inline unsigned long
ntohl(unsigned long nl) {
	return (((nl<<24)&0xFF000000) +
		((nl<<8)&0xFF0000) +
		((nl>>8)&0xFF00) +
		((nl>>24)&0xFF));
}
inline unsigned long
htonl(unsigned long hl) {
	return (((hl<<24)&0xFF000000) +
		((hl<<8)&0xFF0000) +
		((hl>>8)&0xFF00) +
		((hl>>24)&0xFF));
}

inline unsigned short
ntohs(unsigned short ns) {
	return (((ns<<8)&0xFF00) +
		((ns>>8)&0xFF));
}
inline unsigned short
htons(unsigned short hs) {
	return (((hs<<8)&0xFF00) +
		((hs>>8)&0xFF));
}

#elif !defined(ntohl)

extern "C" {
	unsigned long ntohl(unsigned long);
	unsigned long htonl(unsigned long);
	unsigned short ntohs(unsigned short);
	unsigned short htons(unsigned short);
}

#endif

#endif



