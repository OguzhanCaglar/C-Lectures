int mypow(int base, int exp)
{
    int r = 1;

    if(exp == 0)
    {
        return 1;
    }

    for(int i = 1; i <= exp; i++)
    {
        r *= base; // r = r * base;
    }

    return r;
}