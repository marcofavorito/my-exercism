using System;
using System.Text.RegularExpressions;

public static class Bob
{
    
    static bool isYelled(string statement) =>
       (new Regex(@"[a-z]|^[^A-Za-z]*$|[a-z][A-Z]|[A-Z][a-z]", RegexOptions.Compiled))
        .Matches(statement).Count == 0;

    static bool isNothing(string statement) => 
        new Regex(@"^[^A-Za-z0-9]*$", RegexOptions.Compiled).Matches(statement).Count != 0;

    static bool isQuestion(string statement) =>
        statement.Length > 0 && statement[statement.Length - 1] == '?';

    public static string Response(string statement)
    {
        string s = statement.TrimStart().TrimEnd();
        bool yelled = isYelled(s);
        bool nothing = isNothing(s);
        bool question = isQuestion(s);
        if (question && yelled) return "Calm down, I know what I'm doing!";
        if (question && !yelled) return "Sure.";
        if (nothing) return "Fine. Be that way!";
        if (yelled) return "Whoa, chill out!";
        return "Whatever.";

    }
}

