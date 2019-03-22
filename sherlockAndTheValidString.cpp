#include <bits/stdc++.h>

using namespace std;

// Complete the isValid function below.
string isValid(string s) {
    vector<int> foo(26, 0);
    for (int i=0; i<s.length(); i++){
        foo[s[i]-'a']++;
    }
    int count = 0, index = 0;
    for (int i = 0; i<foo.size(); i++){
        if (foo[i] && index == 0){
            index = foo[i];
        }
        else if (foo[i] && index !=0){
            if (foo[i] !=index)
                count++;
        }
    }

    if(count < 2)
        return "YES";
    else
        return "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
