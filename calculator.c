#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>

#define _GNU_SIURSE

#include <getopt.h>

int main(int argc, char *argv[])
{
  printf("This is a calculator\n");
  printf("Enter /h for help.\n");
  printf("Please enter sum(num1, num2, num3, ... , numn); ,and press enter.\n");

  int opt;
    struct option longopts[] = {
      {"initilalize", 0, NULL, 'i'},
      {"file", 1, NULL, 'f'},
      {"list", 0, NULL, 'l'},
      {"restart", 0, NULL, 'r'},
      {0, 0, 0, 0}
    };

    while((opt = getopt_long(argc, argv, ":if:lr", longopts, NULL)) != -1) {
      switch(opt) {
        case 'i':
        case 'l':
        case 'r':
        printf("option: %c\n", opt);
        break;
        case 'f':
        printf("filename: %s\n", optarg);
        break;
        case ':':
        printf("option needs a value\n");
        break;
        case '?':
        printf("unknown option: %c\n", optopt);
        break;
      }
    }

    for(; optind < argc; optind++)
        printf("argument: %s\n", argv[optind]);

    double sum, v;

    sum = 0;
    while(scanf("%lf", &v) == 1)
        printf("\t%.2f\n", sum += v);

    return 0;
}
