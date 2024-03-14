#include <fstream>
#include <stdio.h>
#include <string>

using namespace std;

int main()
{
    fstream Fin;
    int sum = 0;
    Fin.open("input.txt", ios::in);
    for (int i = 0; i < 300; i++)
    {
        string S;
        int count = 2; // Count refers to no. of characters in the new string 
        getline(Fin, S);
        for (int i = 0; i < S.size(); i++)
        {
            if (S[i] == '"')
            {
                count += 2;
            }
            else if (S[i] == '\\')
            {
                count += 2;

            }
            else
                count += 1;

        }
        sum += count - S.size();
        printf("\nSize of string = %d\nNo. of characters = %d\nCount = %d\t Iteration No. %d\n", S.size(), count, sum, i);
    }
    return 0;

}



