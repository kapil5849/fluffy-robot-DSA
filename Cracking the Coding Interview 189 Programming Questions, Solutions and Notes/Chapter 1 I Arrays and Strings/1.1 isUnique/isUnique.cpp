#include<bits/stdc++.h>
using namespace std;

// approach 1
// bool isUnique(const string & s){
//     for(int i=0;i<s.length();i++){
//         for(int j=i+1;j<s.length();j++){
//             if(s[i]==s[j]){
//                 return false;
//             }
//         }
//     }
//     return true;
// }

// approach 2
// bool isUnique(const string & s){
//     unordered_map<char,int> mpp;
//     for(char c:s){
//         int cnt = mpp[c];
//         if(cnt>0){
//             return false;
//         }
//         else{
//             mpp[c]=1;
//         }
//     }
//     return true;
// }

// approach 3
// bool isUnique(const string & s){
//     int bit_vector = 0;
//     for (char c : s) {
//     int bit = 1 << (c - 'a'); // 2^(c-'a')
//     if ((bit_vector & bit) != 0) {
//       return false;
//     } else {
//       bit_vector = bit_vector | bit;
//     }
//   }
//   return true;
// }

// approach 4
bool isUnique(const string & s){
  unordered_set<char> mpp;
  for(char c:s){
    if(mpp.find(c)!=mpp.end()){
      return false;
    }else{
      mpp.insert(c);
    }
  }
  return true;
}

int main(){
    string s;
    cin>>s;
    cout<<isUnique(s)<<endl;
    return 0;
}