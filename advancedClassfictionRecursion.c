#include <stdio.h>
#include <math.h>
#include "NumClass.h" 


int reverse(int num)
{
    int newNum = 0, temp = num, LastDig = 0, Digit = CounterDig(num);
    while(temp != 0)
    {
        Digit--;
        LastDig = temp%10;
        temp = temp/10;
        newNum = newNum + LastDig*pow(10,Digit);
    }  
    return newNum;  
}

int CounterDig(int num)
{
    int count = 0, temp = 0;
    while(num!=0)
    {
        count++;
        temp = num%10;
        num = num/10;

    }
    return count;
}

int checkIsArmstrong(int num, int Digits)
{
    if(num == 0)
    {
        return 0;
    }
    return (pow(num%10,Digits) + checkIsArmstrong(num/10, Digits));
}

int isPalindrome(int num)
{
    int newNum = reverse(num);
    if(num == 0)
    {
        return 1;
    } 
    if((num%10) != (newNum%10))
    {
        return 0;
    }
    else
    {
        return isPalindrome(num/10);
    }
    return 1;

}

int isArmstrong(int num)
{
    int Dig = CounterDig(num);
    if((checkIsArmstrong(num, Dig)) == num)
    {
        return 1;
    }
    return 0;
}


int main()
{
    int num1 = 407, num3=reverse(num1);
    int num2=isArmstrong(num1);
    printf("If armstrong: %d ",num2);
    printf("The reverxe: %d", num3);
}
