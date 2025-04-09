#include<iostream>
using namespace std ;
int main(){
         
    int n ;
         cin>>n;
         int a[n];
         int b[n];
         int temp[n] , temp1;
         temp[0] = a[0];

         for(int i = 0; i < n ; i++  ){
            cin>> a[i];
            temp[i+1] = a[i+1];
         }
         for (int i = 0; i< n ; i++){
            cout<<temp[i];
         }
    return 0;
 }