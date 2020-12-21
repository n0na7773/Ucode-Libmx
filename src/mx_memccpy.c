#include "../inc/libmx.h"

void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n){
    unsigned char *dst1 = dst;
    const char *src1 = src;
    for(size_t i = 0; i < n; ++i){
        dst1[i] = src1[i];
        if(src1[i] == (unsigned char)c) return (void*)&(dst1[i + 1]);

		if (((const unsigned char *)src)[i] == (unsigned char)c) {
			((unsigned char *)dst)[i] = ((const unsigned char *)src)[i];
			return (void *)&(((unsigned char *)dst)[i + 1]);
		} else
			((unsigned char *)dst)[i] = ((const unsigned char *)src)[i];
	}
	return NULL;
}
