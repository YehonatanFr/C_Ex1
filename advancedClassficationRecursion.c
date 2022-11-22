#include <stdio.h>
#include <math.h>
#include "NumClass.h" 

int power(int base, int exponent)
{
    int result =1;
    for (int i = exponent; i>0; i--)
    {
        result = result * base;
    }
    return result;
}

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

// int main()
// {
//     int num = 565;
//     // int num1 = isPrime(num);
//     // printf("\nIf the number is prime: %d \n", num1);
//     int num3 = power(4,3);
//     printf("%d\n", num3);
//     int num2 = isPalindrome(num);
//     if(num2)
//         printf("\nThe number is Palindrome: %d \n", num);
//     else
//         printf("\nThe number is not Palindrome: %d \n", num);

//     int num4 = isArmstrong(num);

//     if(num4)
//         printf("\nThe number is Armstrong: %d \n", num);
//     else
//         printf("\nThe number is not Armstrong: %d \n", num);

//     int num7 = reverse(num);
//     printf("\nreverse of nuber: %d\n", num7);

//     int num5 = CounterDig(num);
//     printf("\n counters digit: %d\n", num5);

//     int num6 = checkIsArmstrong(num, 3);
//     printf("check is armstrong: %d\n",num6);
// }
