#include<iostream>
#include<vector>
using namespace std ;
struct Node{
    public :
        int data;
        Node* next;
        Node* back;
    public :
    Node(int data1 , Node* next1 , Node* back1){
        data = data1;
        next = next1;
        back = back1;
    }
    public:

    Node(int data1){
        data = data1;
        next = NULL;
        back = NULL;
    }
};
Node* ArraytoDLList(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i = 1 ; i < arr.size() ; i++){
        Node* temp = new Node(arr[i] , NULL , prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}
Node* print(Node* head){
    Node* temp = head;
    while(temp!= NULL){
        cout<<temp->data<< " ";
        temp =  temp->next;
    }
    cout<<endl;
}
int main(){
    vector<int> arr = {2 , 5 , 8 , 9};
    Node* head = ArraytoDLList(arr);
    print(head);
return 0;
 }