#include <stdio.h>
#include <stdint.h>

// 使用位运算实现一个“半加器”，用来算 1 + 1
uint32_t useless_adder(uint32_t a, uint32_t b) {
    while (b != 0) {
        uint32_t carry = (a & b) << 1; // 进位
        a = a ^ b;                     // 无进位相加
        b = carry;                     // 将进位加到下一次循环
    }
    return a;
}

int main() {
    // 1. 数组与指针的语法体操
    uint8_t arr[] = {0x01, 0x02, 0x03, 0x04};
    uint8_t *p = &arr[1];
    
    // 2. 一个极度绕口的强制类型转换（合法的指针欺骗）
    int *weird_ptr = (int *)&p;
    
    // 3. 利用复合字面量（C99特性）直接构造字符串并打印
    printf("%s\n", (const char*[]){"[System] Bypassing reality..." }[0]);
    
    // 4. 永远为真的条件判断，骗过编译器
    if (sizeof(uint32_t) == 4 && weird_ptr != NULL) {
        
        // 5. 调用那个花里胡哨的加法器，计算宇宙真理：1 + 1
        uint32_t result = useless_adder(1, 1);
        
        // 6. 用 goto 做一个毫无意义的跳转，并顺便打印废话
        if (result == 2) goto epic_win;
        
    } else {
        printf("How did you even compile this?!\n");
    }

    return 1; // 故意返回 1 表示异常

epic_win:
    // 7. 纯看心情输出的废话
    printf("The universe says: %d\n", useless_adder(1, 1));
    return 0;
}