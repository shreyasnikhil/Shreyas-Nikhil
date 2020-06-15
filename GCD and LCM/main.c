#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void main()
{
    int x,y,a,b,t,gcd,lcm;
    printf("Enter two numbers : ");
    scanf("%d%d",&x,&y);
    a=x;
    b=y;
    while(b!=0)
    {
        t=b;
        b=a%b;
        a=t;
    }
    gcd=a;
    lcm=(x*y)/gcd;
    printf("GCD = %d\nLCM = %d",gcd,lcm);
    getch();
}
