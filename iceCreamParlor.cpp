#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the whatFlavors function below.
void whatFlavors(vector<int> cost, int money) {
    int size = cost.size();
    vector<int> foo(size, 0);
    for (int i=0; i<size; i++){
        foo[i] = cost[i];
    }
    sort(cost.begin(), cost.end());
    
    int a = 0, b= 0;
    for (int i = 0, j = cost.size()-1; i <= j;){
        if (cost[i] + cost[j] == money){
            a = cost[i];
            b = cost[j];
            break;
        }
        else if (cost[i] + cost[j] > money)
            j--;
        else if (cost[i] + cost[j] < money)
            i++; 
            // 2 3 4 5 7
            // case 1 : same numbers -> replace already used entries with -1
            // case 2 : compare indexes before printing 
    }
    int c, d;
    for (int i = 0; i<size; i++){
        if (foo[i] == a){
            foo[i] = -1;
            c= i+1;
            break;
        }
    }
    for (int i = 0; i<size; i++){
        if (foo[i] == b){
            foo[i] = -1;
            d= i+1;
            break;
        }
    }
    if (c < d? cout<<c<<' '<<d<<endl:cout<<d<<' '<<c<<endl);
}

int main()
{
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int money;
        cin >> money;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string cost_temp_temp;
        getline(cin, cost_temp_temp);

        vector<string> cost_temp = split_string(cost_temp_temp);

        vector<int> cost(n);

        for (int i = 0; i < n; i++) {
            int cost_item = stoi(cost_temp[i]);

            cost[i] = cost_item;
        }

        whatFlavors(cost, money);
    }

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
