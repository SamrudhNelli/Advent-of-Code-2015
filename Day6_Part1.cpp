#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>

using namespace std;

int read_num(int x, int y, string S)
{
	if (y - x == 3)
		return (S[x]-48) * 100 + (S[x + 1]-48) * 10 + S[x+2]-48;
	if (y - x == 2)
		return (S[x]-48) * 10 + S[x + 1]-48;
	else if (y - x == 1)
		return S[x]-48;
	else
		exit(-1);

}

int instruction(int temp,string S)
{
	if (temp == 7)
	{
		char s[6];
		for (int j = 0; j < 6; j++)
			s[j] = S[j];
		if (strcmp(s, "toggle") >= 0)
		{
			return -1;
			cout << s <<"\t"<<S<< endl;
		}
	}
	else
	{
		char s[8];
		for (int j = 0; j < 8; j++)
			s[j] = S[j];
		if (strcmp(s, "turn on") > 0)
			return 1;
		else
			return 0;
	}
}

int main()
{
	fstream Fin;
	Fin.open("input.txt", ios::in);
	bool light_is_on[1000][1000];
	int light_on_count = 0;
	for (int i = 0; i < 1000; i++)
		for (int j = 0; j < 1000; j++)
			light_is_on[i][j] = false;
	for (int i = 1; i < 301; i++)
	{
		string S;
		getline(Fin,S);
		int j = 0, x1 = 0, y1 = 0, x2 = 0, y2 = 0,light_on_count=0;
		while (!isdigit(S[j]))
			j++;
		int k = j;
		int temp = j;
		while (S[k] != ',')
			k++;
		x1 = read_num(j, k, S);
		j = k + 1;
		k = j;
		while (S[k] != ' ')
			k++;
		y1 = read_num(j, k, S);
		j = k;
		while (!isdigit(S[j]))
			j++;
		k = j;
		while (S[k] != ',')
			k++;
		x2 = read_num(j, k, S);
		j = k + 1;
		k = j;
		while (S[k] != NULL)
			k++;
		y2 = read_num(j, k, S);
		switch (instruction(temp, S))
		{
		case 0:for (int i = x1; i <= x2; i++)
				for (int j = y1; j <= y2; j++)
					light_is_on[i][j] = false;
			break;
		case 1:for (int i = x1; i <= x2; i++)
				for (int j = y1; j <= y2; j++)
					light_is_on[i][j] = true;
			break;
		case -1:for (int i = x1; i <= x2; i++)
			     for (int j = y1; j <= y2; j++)
				light_is_on[i][j] = not light_is_on[i][j];
			break;
		default:
			cout << i << endl << temp;
			exit(-1);
		}
		for (int i = 0; i < 1000; i++)
			for (int j = 0; j < 1000; j++)
				if (light_is_on[i][j])
					light_on_count += 1;
		printf("%d lights are lit..\n", light_on_count);
	}
	return 0;
}