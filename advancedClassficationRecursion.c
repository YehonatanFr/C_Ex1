#include <math.h>
#include "NumClass.h" 

//Pow function
int power(int base, int exponent)
{
    int result =1;
    for (int i = exponent; i>0; i--)
    {
        result = result * base;
    }
    return result;
}

//Reverse the number
int reverse(int num)
{
    int newNum = 0, temp = num, Digit = CounterDig(num)-1;
    while(temp != 0)
    {
        newNum = newNum + temp%10*power(10,Digit);
        temp = temp/10;
        Digit--;
    }  
    return newNum;  
}

//Count the digits of the number
int CounterDig(int num)
{
    int count = 0;
    while(num!=0)
    {
        count++;
        num = num/10;

    }
    return count;
}

//The help recursion function
int checkIsArmstrong(int num, int Digits)
{
    if(num == 0)
    {
        return 0;
    }
    return (power(num%10,Digits) + checkIsArmstrong(num/10, Digits));
}

int isPalindrome(int num)
{
    int newNum = reverse(num);
    if(checkIsPalindrome(newNum, num))
        return 1;
    return 0;
}

//The help recursion function
int checkIsPalindrome(int reverse, int num)
{
    if(num == 0)
    {
        return 1;
    } 
    if((num%10) != (reverse%10))
    {
        return 0;
    }
    else
    {
        return checkIsPalindrome(reverse/10, num/10);
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

