#include<iostream>
#include<vector>
using namespace std ;
struct Node {
  public:
  int data;
  Node* next;
  Node(int data1 , Node*next1){
    data = data1;
    next = next1;
  }


  public:
    Node(int data1){
        data = data1;
        next = nullptr;
    }

};
Node* ArraytoList(vector<int> &arr){
    Node* head =  new Node(arr[0]);
    Node* mover = head;
    for(int i = 1 ; i < arr.size() ; i++ ){
        Node * temp = new Node(arr[i]);
        mover -> next = temp;
        mover = temp;
    }
    return head;
}
Node* print(Node* head){
    
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}
// Remove the head form the list
// Node* removeHead(Node* head){
//     if(head == NULL) return head;
//     Node* temp = head;
//     head= head->next;
//     free(temp);
//     return head;
// }
// Remocve the tail node
Node* removeTail(Node* head){
    if(head == NULL || head->next == NULL) return NULL;
    Node* temp = head;
    while(temp->next->next != NULL){
          temp= temp->next;
    }
    free(temp->next);
    temp->next =NULL;
    return head;
}
int main(){
    vector<int> arr = {2 , 5 , 8 , 9};
    Node* head = ArraytoList(arr);
    print(head);
    // head = removeHead(head);
    head = removeTail(head);
    print(head);

return 0;
 }