#include <bits/stdc++.h>

using namespace std;

// Complete the makeAnagram function below.
int makeAnagram(string a, string b) {
    int count = 0;
    vector<int> foo(26, 0);
    vector<int> zoo(26, 0);
    int lenA = a.size();
    int lenB = b.size();
    for (int i=0; i<lenA; i++){
        foo[a[i]-'a']++;
    }

    for (int i=0; i<lenB; i++){
        zoo[b[i]-'a']++;   
    }

    for (int i=0; i < foo.size(); i++){
        count += abs(foo[i] - zoo[i]);
    } 
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string a;
    getline(cin, a);

    string b;
    getline(cin, b);

    int res = makeAnagram(a, b);

    fout << res << "\n";

    fout.close();

    return 0;
}
