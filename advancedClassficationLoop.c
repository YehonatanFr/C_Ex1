#include "NumClass.h" 
#include <math.h>

//check if number is armstrong
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

//Check if number is palindrome
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

//Count the digits of the number
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

//Reverse the number
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

//Help function for the armstrong function
int HelpArmstrong(int num, int Dig)
{
    if(Dig == 0)
    {
        return 1;
    }
    return num*HelpArmstrong(num,--Dig);
}
