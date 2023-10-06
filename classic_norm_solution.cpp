#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve()
{
    int n, s;
    cin >> n >> s;
    vector<int> arr(n);
    for(auto& e : arr)
    {
        cin >> e;
    }
    int count = 0;
    
    sort(arr.begin(), arr.end());
    //COUNTER
    map<int, int> counter;
    for(auto e : arr) counter[e]++;
    //CALCULATION
    for(int i=0; i<n-1; i++)
    {
        int low = i, high = n-1;
        while(low <= high)
        {
            int mid = (low + high) / 2;
            if(s < arr[mid] + arr[i])
            {
                high = mid - 1;
            }
            else if(arr[i] + arr[mid] == s)
            {
                count += counter[arr[mid]];
                break;
            }
            else
            {
                low = mid + 1;
            }
        }
    }
    
    cout << count << endl;
}

int main() {
    // your code goes here
    ll t;
    //cin>>t;
    t = 1;
    while(t--){
        solve();
    }
    
    return 0;
}
