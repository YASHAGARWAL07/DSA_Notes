#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_set>
#include<stack>
using namespace std;
int main(){
    vector<int>arr(5,0);
    arr[0] = 5;
    arr[1] = 4;
    // arr.push_back(10);
    // arr.push_back(10);
    // arr.push_back(9);
    // arr.push_back(10);
    // arr.push_back(50);
    // arr.pop_back();
    // arr.pop_back();
        cout<<count(arr.begin(),arr.end(),10);
    // sort(arr.begin(),arr.end());
    // reverse(arr.begin(),arr.end());
    // for(int x:arr){
    //     cout<<x<<" ";
// }

// pair<int,int>p = {1,3};
// cout<<p.first<<" "<<p.second;

// unordered_set<int>s = {1,2,3,2,3,56,6,7,2,5};
// for(int x:s)
// cout<<x<<" ";
// map<string,int>mp;
// mp["apple"] = 2;
// mp["banana"] = 3;
// for(auto x:mp)
// cout<<x.first<<" "<<x.second<<" ";

// stack<int>st;
// st.push(10);
// st.push(20);
// st.push(30);
// st.push(40);
// st.pop();
// st.pop();

// while(!st.empty()){
//     cout<<st.top()<<" ";
//     st.pop();
// }
}