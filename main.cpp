#include "header.h"



int main()
{
    double line[8]={1,2,3,4,5,6,7,8};
    struct data *test;
    struct complex_table *test2;
    //print_complex(factor(-1,2));
    //printf("%G\n",cos(PI/2));
    //printf("%d\n",bit_size(8));
    //printf("%x\n",(~0<<31)>>1);
    //printf("%d\n",bit_order(15,4));

    //init_data_table(test=create_data_table(8),line);
    //print_data_table(test);
    init_complex_table(test2=create_complex_table(8));
    print_compex_table(test2);
    return 0;
}

