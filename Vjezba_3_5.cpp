 #include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <vector>
using namespace std;


bool is_samoglasnik(const char& ch)
{
    string samoglasnici("aeiouAEIOU");

    for (unsigned int i = 0; i < samoglasnici.length(); i++)
    {
        if (ch == samoglasnici[i])
        {
            return true;
        }
    }
    return false;
}

void rules(string& tmp)
{
    
    string s1("");
    unsigned int j = 0;

    if (is_samoglasnik(tmp[0]))
    {

        tmp = tmp + "hay";
        return;
    }

    for (unsigned int i = 0; i < tmp.length(); i++)
    {
        if (is_samoglasnik(tmp[i]) == false)
        {
            s1[0] = tmp[i];
            tmp.erase(tmp.begin() + i);
            tmp.push_back(s1[0]);
            s1.erase(s1.begin(), s1.end()); //s1.erase(s1.begin(), s1.end());
            i--;
        }
        else
        {
            tmp = tmp + "ay";
            return;

        }
    }


}


string pig_latin(vector<char>& s)
{

    string tmp("");
    string rez("");
    char ch = '\0';

    for (unsigned int i = 0; i < s.size(); i++)
    {
        if (isspace(s[i]) && tmp.empty() == true)
        {
            continue;
        }
        else if (isalnum(s[i]))
        {
            tmp.push_back(s[i]);
        }
        else if (isalnum(s[i]) == false && s[i]!=' ')
        {
            ch = s[i];
        }
        else if (isspace(s[i]))
        {
            rules(tmp);
            rez = rez + tmp;
            rez = rez + ch;
            ch = '\0';
            rez = rez + ' ';
            tmp.erase(tmp.begin(), tmp.end());
        }
        
        

    }
    rules(tmp);
    rez = rez + tmp;
    if (s[s.size() - 1] != ch)
    {
        return rez;
    }
    rez = rez + ch;
    tmp.erase(tmp.begin(), tmp.end());
    return rez;

    
    
}

int main()
{

    cout << "Wright a sentance\n";

    string s1("");

    getline(cin, s1);

    vector<char> words(s1.begin(), s1.end());

    cout << pig_latin(words);

}


