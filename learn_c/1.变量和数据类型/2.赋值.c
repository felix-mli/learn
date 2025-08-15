#include <stdio.h>

int main(int argc, char *argv[]) {
    // 这里实际上是没有给a赋值的，a此时的值是随机的
    int a, b =10;
    printf("a = %d, b = %d\n", a, b); // 输出 ： a = 24018, b = 10

    int num1 = 10;
    int num2 = 20;
    
    int *ptr1, ptr2;
    ptr1 = &num1;
    ptr2 = &num2;

    printf("ptr1 = %p, ptr2 = %p\n", ptr1, ptr2); // 输出 ： ptr1 = 0x7ffeff3c3bfc, ptr2 = 0xff3c3c00
    // 这里可以看到似乎丢失了高位地址，所以其实前面定义的ptr2是一个普通的int类型变量，而ptr1是一个指针类型变量

    return 0;
}