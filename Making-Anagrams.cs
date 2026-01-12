using System.CodeDom.Compiler;
using System.Collections.Generic;
using System.Collections;
using System.ComponentModel;
using System.Diagnostics.CodeAnalysis;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Runtime.Serialization;
using System.Text.RegularExpressions;
using System.Text;
using System;

class Result
{

    /*
     * Complete the 'makingAnagrams' function below.
     *
     * The function is expected to return an INTEGER.
     * The function accepts following parameters:
     *  1. STRING s1
     *  2. STRING s2
     */

    public static int makingAnagrams(string s1, string s2)
    {
        int[] cnt = new int[26];

        foreach (char c in s1) {
            cnt[c - 'a']++;
        }

        foreach (char c in s2) {
            cnt[c - 'a']--;
        }

        int deletions = 0;
        foreach (int x in cnt) {
            deletions += Math.Abs(x);
        }

        return deletions;
    }
}


class Solution
{
    public static void Main(string[] args)
    {
        TextWriter textWriter = new StreamWriter(@System.Environment.GetEnvironmentVariable("OUTPUT_PATH"), true);

        string s1 = Console.ReadLine();

        string s2 = Console.ReadLine();

        int result = Result.makingAnagrams(s1, s2);

        textWriter.WriteLine(result);

        textWriter.Flush();
        textWriter.Close();
    }
}
