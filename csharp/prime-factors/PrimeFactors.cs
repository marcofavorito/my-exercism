using System;
using System.Collections.Generic;

public static class PrimeFactors
{
    public static int[] Factors(long number)
    {
      List<int> factors = new List<int>();
      long temp = number;

      while (temp % 2 == 0){
        temp /= 2;
        factors.Add(2);
      }
      
      int p = 3;
      double nSqrt = Math.Sqrt(temp);
      for (; p <= nSqrt; p+=2){
        while (temp % p == 0){
          factors.Add(p);
          temp /= p;
        }
        
      }

      if (temp > 2){
        factors.Add((int)temp);
      }

      return factors.ToArray();

    }
}
