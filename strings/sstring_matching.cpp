//28. Find the Index of the First Occurrence in a String
//Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

#include<iostream>
using namespace std;

    int check_matching(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        for(int i = 0; i<= n-m;i++){
        int first = i, second = 0;

        while(second < needle.size()){
            if(haystack[first] !=needle[second]){
                break;
            }
            else first++ , second ++;
        }
        if(second == m)
        return first - second;
        }
        return -1;
    }

    int main(){
        string s1 = "sadbutsad";
        string s2 = "sad";
        cout << check_matching(s1,s2)<<endl;

        string s3 = "leetcode";
        string s4 = "leeto";
        cout<< check_matching(s3,s4) <<endl;
        return 0;
};

