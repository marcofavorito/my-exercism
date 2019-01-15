using System;
using System.Text.RegularExpressions;

public static class Bob
{
    
    public static string QUESTION = "Sure."; 
    public static string YELL = "Whoa, chill out!";
    public static string YELL_QUESTION = "Calm down, I know what I'm doing!";
    public static string ADDRESS = "Fine. Be that way!";
    public static string ANYTHING = "Whatever.";

    public static Regex isNotYelledRegex = 
        new Regex(@"[a-z]|^[^A-Za-z]*$|[a-z][A-Z]|[A-Z][a-z]", RegexOptions.Compiled);
    public static Regex nothingRegex = new Regex(@"^[^A-Za-z0-9]*$", RegexOptions.Compiled);
    
    public static bool isYelled(string statement){
        return isNotYelledRegex.Matches(statement).Count == 0;
    }

    public static bool isNothing(string statement){
        return nothingRegex.Matches(statement).Count != 0;
    }

    public static string Response(string statement)
    {
        string s = statement.TrimStart().TrimEnd();
        if (s.Length > 0 && s[s.Length - 1] == '?'){
            if(isYelled(s)) return YELL_QUESTION;
            else return QUESTION;
        }
        else if (isNothing(s)) return ADDRESS;
        else{
            if(isYelled(s)) return YELL;
            else return ANYTHING;
        }

    }
}
