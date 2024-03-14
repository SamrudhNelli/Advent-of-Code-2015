#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>

using namespace std;

int main()
{
	fstream Fin;
	string S[1002];
	int temp,w[1002],l[1002],h[1002],Total=0;
	Fin.open("input.txt", ios::in);
	for (int i = 1; i < 1001; i++) 
	{
		getline(Fin, S[i]);
		temp = S[i][0]-48;
		if (S[i][1] == 'x')
		{
			l[i] = temp;
			temp = S[i][2]-48;
			if (S[i][3] == 'x')
			{
				w[i] = temp;
				temp = S[i][4]-48;
				if (S[i][5] == NULL)
					h[i] = temp;
				else
					h[i] = temp * 10 + S[i][5]-48;
			}
			else
			{
				w[i] = (S[i][2] - 48) * 10 + (S[i][3] - 48);
				temp = S[i][5] - 48;
				if (S[i][6] == NULL)
					h[i] = temp;
				else
					h[i] = temp * 10 + S[i][6]-48;
			}

		}
		else
		{
			l[i] = (S[i][0] - 48) * 10 + (S[i][1] - 48);
			temp = S[i][3] - 48;
			if (S[i][4] == 'x')
			{
				w[i] = temp;
				temp = S[i][5]-48;
				if (S[i][6] == NULL)
					h[i] = temp;
				else
					h[i] = temp * 10 + S[i][6]-48;

			}
			else
			{
				w[i] = temp * 10 + S[i][4]-48;
				temp = S[i][6]-48;
				if (S[i][7] == NULL)
					h[i] = temp;
				else
					h[i] = temp * 10 + S[i][7]-48;

			}
		}
		// temp = l[i] * h[i];
		// int temp_1 = h[i] * w[i];
		// int temp_2 = w[i] * l[i];
		// int temp_3 = min(temp_1, temp);
		// Total += (2 * temp + 2 * temp_1 + 2 * temp_2 + min(temp_3, temp_2));
		// cout << Total << "\t" << min(temp_3, temp_2) << endl;

		temp = min(l[i], h[i]);
		int temp_1 = min(temp, w[i]);
		int temp_2 = max(l[i], h[i]);
		int temp_3 = max(temp_2, w[i]);
		Total += ((2 * (temp_1 + ((l[i] + h[i] + w[i]) - temp_1 - temp_3)))+l[i]*h[i]*w[i]);
		cout << Total << endl;


		


	}

	return 0;
	
}
