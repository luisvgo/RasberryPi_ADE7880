/*
 * m16c_endianness.h
 *
 *  Created on: Feb 23, 2015
 *      Author: oops
 */

#ifndef M16C_ENDIANNESS_H_
#define M16C_ENDIANNESS_H_


/**
 *  \defgroup m16c_driver_endianness	m16c Network Communications Endianness byte level
 *  @{
 */
#ifndef 	LITTLE_ENDIAN
#define 	LITTLE_ENDIAN				0
#endif
#ifndef		BIG_ENDIAN
#define 	BIG_ENDIAN					1
#endif
/// Define the system's endianness according to the system
#ifndef 	BYTE_ORDER
#define 	BYTE_ORDER					LITTLE_ENDIAN
#endif

/// Convert 16-bit quantity from host byte order to network byte order.
/// This macro is primarily used for converting constants from host
/// byte order to network byte order. For converting variables to
/// network byte order, use the htons() function instead.
#ifndef HTONS
// BYTE_ORDER == BIG_ENDIAN
#   if BYTE_ORDER == BIG_ENDIAN
#      define HTONS(n) (n)
// BYTE_ORDER == LITTLE_ENDIAN
#   else
#      define HTONS(n) (uint16_t)((((uint16_t) (n) & 0xff00) >> 8) \
								| (((uint16_t) (n) & 0x00ff) << 8))
#   endif
#else
#error "HTONS already defined!"
#endif /* HTONS */


/// Convert 16-bit quantity from host byte order to network byte order.
/// This function is primarily used for converting variables from host
/// byte order to network byte order. For converting constants to
/// network byte order, use the HTONS() macro instead.
#ifndef htons
uint16_t htons(uint16_t val);
#endif /* htons */
#ifndef ntohs
#define ntohs htons
#endif


/// Convert 32-bit quantity from host byte order to network byte order.
/// This macro is primarily used for converting constants from host
/// byte order to network byte order. For converting variables to
/// network byte order, use the htons() function instead.
#ifndef HTONL
/* BYTE_ORDER == BIG_ENDIAN */
#   if BYTE_ORDER == BIG_ENDIAN
#      define HTONL(n) (n)
/* BYTE_ORDER == LITTLE_ENDIAN */
#   else
#      define HTONL(n) (uint32_t)((((uint32_t) (n) & 0xff000000) >> 24) \
								| (((uint32_t) (n) & 0x00ff0000) >> 8)  \
								| (((uint32_t) (n) & 0x0000ff00) << 8)  \
								| (((uint32_t) (n) & 0x000000ff) << 24))
#   endif
#else
#error "HTONL already defined!"
#endif /* HTONL */


/// Convert 32-bit quantity from host byte order to network byte order.
/// This function is primarily used for converting variables from host
/// byte order to network byte order. For converting constants to
/// network byte order, use the HTONS() macro instead.
#ifndef htonl
uint32_t htonl(uint32_t val);
#endif /* htonl */
#ifndef ntohl
#define ntohl htonl
#endif

/**@}*/



#endif /* M16C_ENDIANNESS_H_ */
