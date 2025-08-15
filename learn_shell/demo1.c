#include "unistd.h"
#include "getopt.h"
#include "stdio.h"
#include "stdlib.h"

int main(int argc, char* argv[]) {
    char *optstring = "a:b:";
    int sum = 0;
    int start = 0;
    int end = 0;
    int opt;

    while((opt = getopt(argc, argv, optstring)) != -1) {
        switch(opt) {
            case 'a':
                start = atoi(optarg);
                break;
            case 'b':
                end = atoi(optarg);
                break;
        }
    }

    if (start < 0 || end < 0 || start > end) {
        fprintf(stderr, "Invalid range: start=%d, end=%d\n", start, end);
        return 1;
    }

    for (size_t i = start; i <= end; i++)
    {
        sum += i;
    }

    printf("Sum from %d to %d is: %d\n", start, end, sum);
    return 0;
}