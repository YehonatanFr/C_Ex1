#include "NumClass.h" 


int isArmstrong(int num)
{
    int sum = 0, count = CounterDig(num), temp = num, LastDig;
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
    int count = 0, temp = 0;
    while(num!=0)
    {
        temp = num%10;
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
        temp = temp/10;
        newNum = newNum + temp*Digit;
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
    return num*HelpArmstrong(num,Dig-1);
}