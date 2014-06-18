#include "stdio.h"
#include "time.h"
#include "stdlib.h"
#include "math.h"
#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164
struct complex //a+b*i
{
    double a;
    double b;

};
struct bit
{
    unsigned a:1;
    unsigned b:1;
    unsigned c:1;

};
struct data
{
    int number;
    double value;
    struct data *next;
};
struct complex_table //a+b*i
{
    int number;
    double a;
    double b;
    struct complex_table *next;
};
#include"functions.cpp"
