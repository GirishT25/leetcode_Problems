#include <bits/stdc++.h> 
vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{ int j;
	vector <int> ans;
 vector <int>  vis(m , 0)  ; 

	for(int i = 0; i < n ; i++ ){
		for(int j = 0 ; j < m ; j++){
			if(arr1[i] == arr2[j] && vis[j] == 0){
				ans.push_back(arr1[i]);
				vis[j] = 1;
				break;
			}
			
		}
	}
	return ans;

}

//optimal code 


#include <bits/stdc++.h> 
vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
  int i = 0 , j = 0  ;
vector <int> ans;
while(  i < n &&  j < m){
    if(arr1[i] > arr2[j]){
		j++;
	}
	else if(arr2[j] > arr1[i] ){
		i++;
	}
	else{
		ans.push_back(arr1[i]);
		i++;
		j++;
	}
  }
  return ans;

}