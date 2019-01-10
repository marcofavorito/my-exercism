using System;

public static class ReverseString
{
    public static string Reverse(string input)
    {
      char[] array = input.ToCharArray();
      Array.Reverse(array);
      return new string(array);
    }
}
