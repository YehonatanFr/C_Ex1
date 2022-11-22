#include <stdio.h>
#include "NumClass.h" 
#include <math.h>

int isArmstrong(int num)
{
    int sum = 0, count = CounterDig(num), temp = num, LastDig = 0;
    while(temp !=0)
    {
        LastDig = temp%10;
        temp = temp /10;
        sum = sum +(HelpArmstrong(LastDig, count));
    }

    if(sum == num)
    {
        return 1;
    }

    return 0;
}

int isPalindrome(int num)
{
    int newNum = reverse(num); 
    while(num != 0)
    {
        int temp1 = num%10, temp2 = newNum%10;
        if(temp1 != temp2)
        {
            return 0;
        }
        num = num/10;
    }
    return 1;
}

int CounterDig(int num)
{
    int count = 0;
    while(num != 0)
    {
        count++;
        num = num/10;
    }
    return count;
}

int reverse(int num)
{
    int newNum = 0, temp = num, LastDig = 0, Digit = CounterDig(num);
    while(temp != 0)
    {
        LastDig = temp%10;
        newNum = newNum + LastDig*pow(10,Digit);
        temp = temp/10;
        Digit--;
    }  
    return newNum;  
}

int HelpArmstrong(int num, int Dig)
{
    if(Dig == 0)
    {
        return 1;
    }
    return num*HelpArmstrong(num,--Dig);
}



int main()
{
    int num = 156;
    // int num1 = isPrime(num);
    // printf("\nIf the number is prime: %d \n", num1);
    // int num3 = pow1(2,5);
    // printf("\n%d\n", num3);
    // int num2 = isPalindrome(num);
    // if(num2)
    //     printf("\nThe number is Palindrome: %d \n", num);
    // else
    //     printf("\nThe number is not Palindrome: %d \n", num);

    // int num3 = isArmstrong(num);
    // if(num3)
    //     printf("\nThe number is Armstrong: %d \n", num);
    // else
    //     printf("\nThe number is not Armstrong: %d \n", num);
    int num4 = reverse(num);
    printf("\nreverse of nuber: %d\n", num4);
}