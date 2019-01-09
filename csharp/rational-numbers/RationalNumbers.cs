using System;
using System.Diagnostics;

public static class RealNumberExtension
{
    public static double Expreal(this int realNumber, RationalNumber r)
    {
      return r.Expreal(realNumber);
    }
}

public static class Utils{
    public static int gcd(int a, int b){
      if (b == 0) return Math.Abs(a);
      else return gcd(b, a - b*(a/b));
    }
    
    public static int lcm(int a, int b){
      return Math.Abs(a * b) / gcd(a, b);
    }

}


public struct RationalNumber
{ 
    
    public int n;
    public int d;

    public RationalNumber(int numerator, int denominator)
    {
      this.n = Math.Abs(numerator) * Math.Sign(numerator) * Math.Sign(denominator);
      this.d = Math.Abs(denominator);
    }

    public RationalNumber Add(RationalNumber r)
    {
      int lcm = Utils.lcm(this.d, r.d);
      int num = this.n*lcm/this.d + r.n*lcm/r.d;
      return (new RationalNumber(num, lcm).Reduce()); 
    }

    public static RationalNumber operator +(RationalNumber r1, RationalNumber r2)
    {
      return r1.Add(r2);
    }

    public RationalNumber Sub(RationalNumber r)
    {
      return this.Add(new RationalNumber(-r.n, r.d));
    }

    public static RationalNumber operator -(RationalNumber r1, RationalNumber r2)
    {
      return r1.Sub(r2);
    }

    public RationalNumber Mul(RationalNumber r)
    {
      return (new RationalNumber(this.n * r.n, this.d * r.d)).Reduce();
    }

    public static RationalNumber operator *(RationalNumber r1, RationalNumber r2)
    {
      return r1.Mul(r2);
    }

    public RationalNumber Div(RationalNumber r)
    {
      return this.Mul(new RationalNumber(r.d, r.n));
    }

    public static RationalNumber operator /(RationalNumber r1, RationalNumber r2)
    {
      return r1.Div(r2);
    }

    public RationalNumber Abs()
    {
      return new RationalNumber(Math.Abs(this.n), Math.Abs(this.d));
    }

    public RationalNumber Reduce()
    {
      int gcd = Utils.gcd(this.n, this.d);
      return new RationalNumber(this.n/gcd, this.d/gcd);
    }

    public RationalNumber Exprational(int power)
    {
      return new RationalNumber((int) Math.Pow(this.n, power), (int) Math.Pow(this.d, power));
    }

    public double Expreal(int baseNumber)
    {
      return Math.Pow(baseNumber, (double) this.n / this.d);
    }
}
