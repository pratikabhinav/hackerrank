#include <bits/stdc++.h>

using namespace std;

// Complete the substrCount function below.
long substrCount(int n, string s) {
    int result = 0;
    int i = 0;
    int sameChar[n] = {0};
    while (i<n){
        int sameCharCount = 1;
        int j = i + 1;

        while (s[i] == s[j] && j <n){
            sameCharCount++, j++;
        }
        result += (sameCharCount * (sameCharCount+1) / 2);

        sameChar[i] = sameCharCount;

        i = j;
    }

    for (int j = 1; j < n; j++){
        if (s[j]==s[j-1])
            sameChar[j]=sameChar[j-1];

        if (j>0 && j < (n-1) & s[j-1] == s[j+1] && s[j] != s[j-1]){
            result += min(sameChar[j-1], sameChar[j+1]);
        }
    }
    return result;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    long result = substrCount(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}
