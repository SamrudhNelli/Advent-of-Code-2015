#pragma warning(disable : 4996)
#include <iostream>
#include "md5.h"
#include <string>
#include <stdio.h>

using namespace std;

int main(int argc, char* argv[])
{
    bool proceed = true;
    cout << "md5 of 'iwrupvqb': " << md5("iwrupvqb") << endl;
    int i=1;
    while (proceed)
    {
        char I[15];
        char S[50] = "iwrupvqb";
        sprintf(I, "%d", i);
        strcat(S,I);
        if (md5(S) < "00001")
        {
            cout <<i<<"\t"<< md5(S) << endl;
            proceed = false;
        }
        i++;
    }
    return 0;
}