#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>

using namespace std;

bool continous_letter(char x, char y)
{
	string s;
	s += x;
	s += y;
	if(s=="pq" || s=="cd"|| s=="ab"||s=="xy")
		return true;
	else
		return false;
}

int main()
{
	string S[1000];
	fstream Fin;
	int nice_count = 0;
	Fin.open("input.txt", ios::in);
	for (int i = 0; i < 1000; i++)
	{
		getline(Fin, S[i]);
		int vowel_count = 0; 
		bool repeat2_count = false, has_continous_letters = false;
		for (int j = 0; j < S[i].size(); j++)
		{
			switch (S[i][j])
			{
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':vowel_count += 1;
			}
			if (j != size(S[i]) - 1 && not repeat2_count)
			{
				if (S[i][j] == S[i][j + 1])
					repeat2_count = true;
			}
			if (not has_continous_letters)
				has_continous_letters = continous_letter(S[i][j], S[i][j + 1]);
		}
		if (repeat2_count && vowel_count > 2 && not has_continous_letters)
			nice_count += 1;
		printf("Vowel count is %d\nHas Repeated letter? = %s\nHas Continous letters? = %s\n", vowel_count, repeat2_count ? "True" : "False", has_continous_letters ? "True" : "False");
	}
	printf("Nice count is %d", nice_count);
	return 0;
}