#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>

using namespace std;

int main()
{
	fstream Fin;
	string S[1000];
	int nice_count = 0;
	Fin.open("input.txt", ios::in);
	for (int i = 0; i < 1000; i++)
	{
		getline(Fin, S[i]);
		bool repeat_condition = false, has_doublepair = false;
		for (int j = 0; j < size(S[i]); j++)
		{
			if (not repeat_condition && j < S[i].size() - 2)
				if (S[i][j] == S[i][j + 2])
					repeat_condition = true;
			if (not has_doublepair)
				for (int k = j + 2; k < S[i].size() - 1; k++)
					if (S[i][j] == S[i][k] && S[i][j + 1] == S[i][k + 1])
						has_doublepair = true;
		}
		printf("Has repeating letters with a letter in between? = %s\nHas a pair of letters occur multiple times? = %s\n", repeat_condition ? "True" : "False", has_doublepair ? "True" : "False");
		if (repeat_condition && has_doublepair)
			nice_count += 1;
	}
	printf("Nice count = %d", nice_count);
	return 0;

}