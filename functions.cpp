struct complex *factor(double k,double N)
{
    struct complex *p1=(struct complex*)malloc(sizeof(struct complex));
    p1->a=cos((k/N)*PI);
    p1->b=sin((k/N)*PI);

    return p1;

}
int print_complex(struct complex *p1)
{
    if(p1->b<=0.000000000001&&p1->b>=-0.000000000001)
    {
        printf("%lG\n",p1->a);
        exit(0);
     }
    if(p1->a<=0.000000000001&&p1->a>=-0.000000000001)
    {
        printf("%lGi\n",p1->b);
        exit(0);
     }
    if(p1->b<0)printf("%lG%lGi\n",p1->a,p1->b);
    else
    printf("%lG+%lGi\n",p1->a,p1->b);
    return 0;

}
int bit_size(int m)
{
    int i;
    int n;
    unsigned int k=~0<<31;
    for(i=0;i<=31;i++)
    {
        k=~0<<31;
        k>>=i;
        if((m&k)!=0)
        {
            n=32-i;
            break;
        }
    }

    return n;

}
int bit_order(int m,int n)
{
    int i;
    unsigned int k=1;
    unsigned int l=0;
    int d=0;
    for(i=0;i<=(n+1)/2-1;i++)
    {
        l=0;
        l=(k<<i)&m;
        l<<=n+1-(i+1)-(i+1);
        d=d|l;

    }
    for(i=(n+1)/2-1;i<=n;i++)
    {
        l=0;
        l=(k<<i)&m;
        l>>=i+1-(n+1-(i+1));
        d=d|l;

    }
    return d;
}
struct data * create_data_table(int m)
{
    int i;
    struct data*p1,*p3;
    struct data *p2=(struct data *)malloc(sizeof(struct data));
    p3=p2;
    p2->number=m;
    for(i=1;i<=m;i++)
    {
    p1=p2;
    p2=(struct data *)malloc(sizeof(struct data));
    p1->next=p2;
    }
    return p3;
}
int init_data_table(struct data *p1,double *a)
{
    int i;
    struct data *p2=p1;
    for(i=0;i<p1->number;i++)
    {
        p2=p2->next;
        p2->value=0;
    }
    p2=p1;
    for(i=0;i<p1->number;i++)
    {
        p2=p2->next;
        p2->number=bit_order(i,bit_size(p1->number-1));
    }
    p2=p1;
    for(i=0;i<p1->number;i++)
    {
        p2=p2->next;
        p2->value=a[p2->number];
    }
    return 0;
}
int print_data_table(struct data *p1)
{
    int i;
    struct data *p2=p1;
    for(i=0;i<p1->number;i++)
    {
        p2=p2->next;
        printf("%d\t%lG\n",p2->number,p2->value);
    }
    return 0;
}
struct complex_table * create_complex_table(int m)
{
    int i;
    struct complex_table*p1,*p3;
    struct complex_table *p2=(struct complex_table *)malloc(sizeof(struct complex_table));
    p3=p2;
    p2->number=m;
    for(i=1;i<=m;i++)
    {
    p1=p2;
    p2=(struct complex_table *)malloc(sizeof(struct complex_table));
    p1->next=p2;
    }
    return p3;
}
int init_complex_table(struct complex_table *p1)
{
    int i;
    struct complex_table *p2=p1;
    for(i=0;i<p1->number;i++)
    {
        p2=p2->next;
        p2->a=0;
        p2->b=0;
    }
    p2=p1;
    for(i=0;i<p1->number;i++)
    {
        p2=p2->next;
        p2->number=bit_order(i,bit_size(p1->number-1));
    }

    return 0;
}
int print_compex_table(struct complex_table *p1)
{
    int i;
    struct complex_table *p2=p1;
    for(i=0;i<p1->number;i++)
    {
        p2=p2->next;
        printf("%d\t%lG+%lGi\n",p2->number,p2->a,p2->b);
    }
    return 0;
}
struct complex_table *data_table_to_complex_table(struct data*p1)
{
    int i;
    struct data *p3=p1;
    struct complex_table *p2=create_complex_table(p1->number);
    struct complex_table *p4=p2;
    init_complex_table(p2);
    for(i=0;i<p1->number;i++)
    {
        p2=p2->next;
        p3=p3->next;
        p2->number=p3->number;
        p2->a=p3->value;
    }
    return p4;
}
struct complex_table *climb_complex_table(struct complex_table *p1)
{
    struct complex_table *p2=create_complex_table(p1->number);
    struct complex_table *temp=create_complex_table(p1->number);


}
