#include "NumClass.h" 

//Check if number is prime
int isPrime(int num)
{
    if(num ==1)
        return 1;
    if(num < 2)
    {
        return 0;
    }
    for(int i=2; i<num; i++)
    {
        if((num % i) == 0)
        {
         return 0;
        }
    }
    return 1;
}

//Check if number is strong number
int isStrong(int num)
{
    int sum =0, lastDigit = 0, temp = num;
    if(num == 0)
        return 0;
    while(temp != 0)
    {
        lastDigit = temp % 10;
        temp = temp/10;
        sum = sum + (factorial(lastDigit));
    }
    if(sum == num)
    {
        return 1;
    }
    return 0;
}

//return the factorial of number
int factorial(int num)
{
    int result =1;
    for(int i = num; i>1; i--)
    {
        result = result*i;
    }
    return result;
}


