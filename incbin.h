#ifndef __INCBIN_H
#define __INCBIN_H

#define STR2(x) #x
#define STR(x) 	STR2(x)

#define INCBIN(name, file, section_name, align_size) \
    __asm__( \
"	.section	" STR(section_name) "\n" \
"	.global		" STR(name) "\n" \
"	.type		" STR(name) ", @object\n" \
"	.global		" STR(name) "_start\n" \
"	.type		" STR(name) "_start, @object\n" \
"	.global		" STR(name) "_end\n" \
"	.type		" STR(name) "_end, @object\n" \
"	.align		" STR(align_size) "\n" \
	STR(name) ":\n" \
	STR(name) "_start:\n" \
"	.incbin		\"" file "\"\n" \
	STR(name) "_end:\n" \
"	.size		" STR(name) ", . -" STR(name) "\n"\
    ); \
    extern const __attribute__((aligned(align_size))) void *name; \
    extern const void* name ## _start, name ## _end;

#define SIZEOF(name) (int)((char*)&name ## _end - (char*)&name ## _start)
#define ARRAYOF(name) ((char*)&name)

#endif // __INCBIN_H
