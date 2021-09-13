//
// Created by Eric Li on 2021/9/13.
//

#include "alloc.h"
#include "stdio.h"

// page 83

/* size of available space */
#define ALLOCSIZE 10000
/* storage for alloc */
static char allocbuf[ALLOCSIZE];
/* next free position */
// 这句 相当于 
// `static char* allocp = &allocbuf[0];` 
// 将 allocp 定义为 字符类型指针（char*）,并将它初始化为 allocbuf 的 起始地址。
static char *allocp = allocbuf;

/* return pointer to n characters */
char *alloc(int n) {
    if (allocbuf + ALLOCSIZE - allocp >= n) {
        /* it fits */
        allocp += n;
        return allocp - n; /* old p */
    } else {
        /* not enough room */
        // C语言保证:
        // 0永远不是有效的数据地址，因此，返回值0可用来表示发生了异常事件。
        // 在本例中，返回值0表示没有足够的空闲空间可供分配。
        return 0;
    }

}

/* free storage pointed to by p */
void afree(char *p) {
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE) allocp = p;
}

int test_alloc() {
    allocp[0] = 'a';
    allocp[1] = 'b';

    printf("allocbuf: %s,%ld,%lu\n", allocbuf, allocbuf, sizeof(allocbuf));
    printf("allocp: %s,%ld,%lu\n", allocp, allocp, sizeof(allocp));
    printf("allocbuf - allocp: %ld\n\n", allocbuf - allocp);

    alloc(20);
    
    printf("allocbuf: %s,%ld,%lu\n", allocbuf, allocbuf, sizeof(allocbuf));
    printf("allocp: %s,%ld,%lu\n", allocp, allocp, sizeof(allocp));
    printf("allocbuf - allocp: %ld\n\n", allocbuf - allocp);

    return 0;
}

