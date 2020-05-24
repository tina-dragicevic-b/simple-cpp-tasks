#include <iostream>
#include<vector>
#include<string>
#include<algorithm>
#include <cctype>
using namespace std;


string longest_sub(const string& s1, const string& s2)
{
	int s1_len = s1.length();
	int s2_len = s2.length();

	int mat[10][10];

	int max = 0;

	string rez("");

	for (int i = 0; i < s1_len; i++)
	{
		for (int j = 0; j < s2_len; j++)
		{
			if (s1[i] == s2[j])
			{
				if (i == 0 || j == 0)
				{
					mat[i][j] = 1;
				}
				else
					mat[i][j] = mat[i - 1][j - 1] + 1;
				if (mat[i][j] > max)
				{
					max = mat[i][j];
					rez = ((s1.substr((i - max + 1), (i + 1))));
				}
				else if (mat[i][j] == max)
				{
					rez = ((s1.substr((i - max + 1), (i + 1))));
				}
			}
			else
				mat[i][j] = 0;
		}
	}
	return rez;

}

int main()
{
	string s1("najjaci");
	string s2("Knajjveci");

	cout << longest_sub(s1, s2) << endl;


}
