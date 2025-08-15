#include <stdio.h>

int main(int argc, char *argv[]) {
    int num1 = 100;
    char *str = "Hello, World!";
    // 在C语言中，小数默认都是double类型，如果不显示指定为float类型，那么编译器也会自动转化，最好写成float num2 = 3.14f;
    float num2 = 3.1415;

    printf("Integer: %d\n", num1);
    printf("String: %s\n", str);
    // 这里打印出来了num2占用的内存地址，可以看出来确实把这个变量当成了float类型来处理
    printf("sizeof num2: %ld\n", sizeof(num2));
    printf("Float: %.2f\n", num2);

    double num3 = 6.66;
    // 这里可以看出来num3作为double类型，确实占用了更多的内存空间，8个字节
    printf("sizeof double: %ld\n", sizeof(num3));
}