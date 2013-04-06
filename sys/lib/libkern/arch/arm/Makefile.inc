#	$NetBSD: Makefile.inc,v 1.11 2012/10/10 02:15:31 christos Exp $

SRCS+=	byte_swap_2.S byte_swap_4.S
SRCS+=	ffs.S
SRCS+=	divsi3.S clzsi2.S modsi3.S umodsi3.S
SRCS+=	memcmp.S memcpy.S memset.S memmove.S strcmp.S strncmp.S

.if ${MACHINE_ARCH} == "earm" || ${MACHINE_ARCH} == "earmeb"
SRCS+=	__aeabi_ldivmod.S __aeabi_uldivmod.S __aeabi_lcmp.c __aeabi_ulcmp.c
.endif