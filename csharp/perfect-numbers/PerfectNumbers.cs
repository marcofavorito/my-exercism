using System;

public enum Classification
{
    Perfect,
    Abundant,
    Deficient
}

public static class PerfectNumbers
{
    public static Classification Classify(int number)
    {
        if (number <= 0) throw new ArgumentOutOfRangeException();
        int sum = 0;
        int limit = number;
        for (int i = 1; i < limit; i++){
            if (number % i == 0) {
                sum += i;
                if (limit == number && i != 1) limit = number/i + 1;
            }
        }

        if (sum > number) return Classification.Abundant;
        else if (sum == number) return Classification.Perfect;
        else return Classification.Deficient;
    }
}
