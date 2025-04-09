#include<iostream>
#include<vector>
using namespace std ;
int main(){
   vector<int> a;
   a.push_back(10);
   a.emplace_back(20);
    cout<<a[0]<<" "<<a[1];
    cout<<endl;
vector<int> v(5 ,20);
for(int i = 0 ; i < 5 ; i++){   
    cout<<v[i]<<" ";
}
cout<<endl;
// v.pop_back();


cout<<endl;
// for(int i = 0 ; i < 5 ; i++){
//     v[i] = i+1;     
// }
// for(int i = 0 ; i < 5 ; i++){   
//     cout<<v[i]<<" ";
// }


    return 0;
 }