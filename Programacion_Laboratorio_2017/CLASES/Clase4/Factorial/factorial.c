int factorial(int num)
{
    int result;
    if(num == 1)
    {
        return 1;
    }
    result = num * factorial(num - 1);
    return result;
}
