#include <stdio.h>



long long modular_exponentiation(long long base, long long exponent, long long mod) 
{
    long long result = 1;
    base = base % mod;
    while (exponent > 0)
    {
        if (exponent % 2 == 1) 
        {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exponent = exponent / 2;
    }
    return result;
}


int last_two_digits_optimized(long long K, long long N)
{
    long long cycle_length = 100;
    long long full_cycles = K / cycle_length;
    long long remainder = K % cycle_length;

  
    long long sum_full_cycle = 0;
    for (long long i = 1; i <= cycle_length; i++) 
    {
        sum_full_cycle = (sum_full_cycle + modular_exponentiation(i, N, 100)) % 100;
    }

   
    
    long long total = (full_cycles * sum_full_cycle) % 100;
    for (long long i = 1; i <= remainder; i++) 
    {
        total = (total + modular_exponentiation(i, N, 100)) % 100;
    }

    return (int)total;
}

int main()
{
    int T;
    scanf("%d", &T); 

    while (T--)
    {
        long long K, N;
        scanf("%lld %lld", &K, &N);
        
        
        
        
        int result = last_two_digits_optimized(K, N);

        
        printf("%02d\n", result);
    }

    return 0;
}