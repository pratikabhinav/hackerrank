#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);
//using GeeksForGeeks solution from //https://www.geeksforgeeks.org/minimum-time-required-produce-m-items/
long findItems(vector<long> arr, long n, long temp) 
{ 
    long ans = 0; 
    for (long i = 0; i < n; i++) 
        ans += (temp/arr[i]); 
    return ans; 
} 
  
// Binary search to find minimum time required 
// to produce M items. 
long bs(vector<long> arr, long n, long m, long high) 
{ 
    long low = 1; 
  
    // Doing binary search to find minimum 
    // time. 
    while (low < high) 
    { 
        // Finding the middle value. 
        long mid = (low+high)>>1; 
  
        // Calculate number of items to 
        // be produce in mid sec. 
        long itm = findItems(arr, n, mid); 
  
        // If items produce is less than 
        // required, set low = mid + 1. 
        if (itm < m) 
            low = mid+1; 
  
        //  Else set high = mid. 
        else
            high = mid; 
    }
    return high; 
}  

// Complete the mlongime function below.
long mlongime(vector<long> machines, long goal) {
    long maxval = LONG_MIN; 
    long n = machines.size();
  
    // Finding the maximum time in the array. 
    for (long i = 0; i < n; i++) 
        maxval = max(maxval, machines[i]); 
  
    return bs(machines, n, goal, maxval*goal); 
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nGoal_temp;
    getline(cin, nGoal_temp);

    vector<string> nGoal = split_string(nGoal_temp);

    long n = stoi(nGoal[0]);

    long goal = stol(nGoal[1]);

    string machines_temp_temp;
    getline(cin, machines_temp_temp);

    vector<string> machines_temp = split_string(machines_temp_temp);

    vector<long> machines(n);

    for (long i = 0; i < n; i++) {
        long machines_item = stol(machines_temp[i]);

        machines[i] = machines_item;
    }

    long ans = mlongime(machines, goal);

    fout << ans << "\n";

    fout.close();

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
