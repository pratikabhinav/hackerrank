#include <bits/stdc++.h>

using namespace std;

// Complete the isBalanced function below.
string isBalanced(string s) {
    stack<char> brak;
    unordered_map<char, char> map = {{'(', ')'}, {'[',']'},{'{','}'}};
    int len = s.size();
    char a;
    for (int i=0;i<len;i++){
        a = s[i];
        if (map.count(a)){
            brak.push(a);
        }
        else if (brak.empty() || map.at(brak.top()) != a){
            return "NO";
        }
        else {
            brak.pop();
        }
    }

    return (brak.empty()?"YES":"NO");
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
