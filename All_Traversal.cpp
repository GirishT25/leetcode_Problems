#include<iostream>
#include <vector>
using namespace std ;

class Solution{
  vector<int> prePostInorder_Traversal(TreeNode* root){
  stack<pair<TreeNode* , int>> st;
  vector<int> inor ,pre , post;
  st.push({root , 1});

  if(root ==NULL) return -1;

  while(!st.empty()){
    auto  it = st.top();
    st.pop();

    if(it.second == 1){
        pre.push_back(it.first->val)
        it.second++;
        st.push(it);
        
        if(it.first->left != NULL){
            st.push({it.first->left , 1});

        }
    }
    else if(it.second == 2){
     inor.push_back({it.first -> val});
     it.second++;
     st.push(it);

     if(it.first->left !=NULL){
      st.push({it.first->val , 1});

     }
    }

    else{
        post.push_back({it.first->val , 1})
    }
  }

  }

};

int main(){

    return 0;
 }