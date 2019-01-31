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
    
    public static bool isYelled(string statement) =>
        isNotYelledRegex.Matches(statement).Count == 0;

    public static bool isNothing(string statement) => 
        nothingRegex.Matches(statement).Count != 0;

    public static bool isQuestion(string statement) =>
        statement.Length > 0 && statement[statement.Length - 1] == '?';

    public static string Response(string statement)
    {
        string s = statement.TrimStart().TrimEnd();
        bool yelled = isYelled(s);
        bool nothing = isNothing(s);
        bool question = isQuestion(s);
        if (question && yelled) return YELL_QUESTION;
        else if (question && !yelled) return QUESTION;
        else if (nothing) return ADDRESS;
        else if (yelled) return YELL;
        else return ANYTHING;

    }
}
