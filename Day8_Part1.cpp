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
        int count = 0;
        getline(Fin, S);
        for (int i = 0; i < S.size(); i++)
        {
            if (S[i] == '"')
            {

            }
            else if (S[i] == '\\')
            {
                if (S[i + 1] == '\\')
                {
                    count += 1;
                    i++;
                }
                else if (S[i + 1] == 'x')
                {
                    count += 1;
                    i += 3;
                }
                else
                {
                    count += 1;
                    i++;
                }
            }
            else
                count += 1;
           
        }
        sum += S.size() - count;
        printf("\nSize of string = %d\nNo. of characters = %d\nCount = %d\t Iteration No. %d\n", S.size(), count,sum, i);
    }
    return 0;

    }


    
