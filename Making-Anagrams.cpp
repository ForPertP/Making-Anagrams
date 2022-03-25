#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'makingAnagrams' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING s1
 *  2. STRING s2
 */

int makingAnagrams(string s1, string s2) 
{
    int count = 0;
    std::vector<int> freq1(26);
    std::vector<int> freq2(26);
    
    for (int i = 0; i < s1.size(); ++i) freq1[s1[i]-'a']++;
    for (int i = 0; i < s2.size(); ++i) freq2[s2[i]-'a']++;
    for (int i = 0; i < 26; ++i)
        count += (std::max(freq1[i], freq2[i]) - std::min(freq1[i], freq2[i]));
        
    return count;
}

int makingAnagrams2(string s1, string s2)
{
    int count = 0;
    std::vector<int> temp(26);
    
    for (int i = 0, j = 0; i < s1.length() || j < s2.length(); ++i, ++j) 
    {            
        if (i < s1.length())
        {
            temp[s1.at(i) - 'a']++;
        }
        if (j < s2.length())
        {
            temp[s2.at(j) - 'a']--;
        }
    }
    
    for (int i = 0; i < 26; ++i)
    {
        count += std::abs(temp[i]);
    }
    
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s1;
    getline(cin, s1);

    string s2;
    getline(cin, s2);

    int result = makingAnagrams(s1, s2);

    fout << result << "\n";

    fout.close();

    return 0;
}
