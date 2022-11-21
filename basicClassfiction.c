# include "<Numclass.h>"

int isPrime(int num)
{
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

int isStrong(int num)
{
    int sum =0, lastDigit = 0, temp = num;
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

int factorial(int num)
{
    if(num == 1)
    {
        return 1;
    }
    return num*factorial(num-1);
}