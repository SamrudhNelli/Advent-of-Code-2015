#pragma warning(disable : 4996)
#include <iostream>
#include <iomanip>


using namespace std;

int main()
{
	int i, j, x = 0;   //b[41][100],a[100]
	long long int num = 3113322113, temp, digit = 0;
    char **S = new char *[51];
	for (int i = 0; i < 51; i++)
		S[i] = new char[10000000];
	strcpy(S[0], "3113322113");
	temp = num;
	/*while (temp > 0)
	{
		a[digit] = temp % 10;
		temp = temp / 10;
		digit++;
	}*/
	digit = 10;
	i = 0;
	for (int z = 0; z < 51; z++)
	{
		i = 0;
		j = 0;
		while (i < digit)
		{
			if (S[z][i + 1] == S[z][i])
			{
				int count = 1, k = i + 1;
				while (S[z][k] == S[z][i])
				{
					count += 1;
					k++;
				}
				S[z + 1][j] = count + '0';
				S[z + 1][j + 1] = S[z][i];
				j += 2;
				i += count;
			}
			else
			{
				S[z + 1][j] = '1';
				S[z + 1][j + 1] = S[z][i];
				j += 2;
				i++;
			}
		}
		S[z + 1][j] = '\0';
		digit = j;
		if (z > 1)
		{
			delete[] S[z - 2];
		}
		cout << "Iteration No. " << z + 1 << setw(10) <<"Digits :" << j << endl;
		//for (int x = 0; x < j; x++)
		//cout << S[z+1][x] << setw(5);
		//cout << endl << endl;
	}

	return 0;
}
