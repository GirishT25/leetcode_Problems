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

Node* deleteHead(Node*  head){
    if(head == NULL || head->next == NULL){
        return NULL;
    }
    Node* prev = head;
    head = head->next;

    head->back = NULL;
    prev->next = NULL;
    
    free(prev);
return head;
}
Node* deleteTail(Node* head){
    if(head == NULL || head->next == NULL) return NULL;
    Node* tail = head;
    
    while(tail->next != NULL){
        tail = tail->next;
    }
        Node* prev = NULL;
        prev = tail->back;
        prev->next = NULL;
        tail->back = NULL;
    delete tail;
    return head;
    
}
Node* deleteKnode(Node* head , int k){
    if(head == NULL) return NULL;
    
    int cnt = 0;
    Node* knode = head;
    while(knode != NULL ){
        cnt++;
        if(cnt == k) break;
        knode = knode->next;
    }
    Node* prev = knode->back;
    Node* front = knode->next;
    if(prev == NULL && front == NULL) return NULL;
    else if(prev == NULL){
        return deleteHead(head);
    }
    else if(front == NULL ){
        return deleteTail(head);
    }
    prev->next = front;
    front->back = prev;
  
    knode->next = NULL;
    knode->back = NULL;
    delete knode;
return head;
}
// -----------------------------INSERT AT HEAD-----------------------------
Node* InsertatHead(Node* head , int val){
    if(head == NULL){
        Node* newNode = new Node(val ,NULL, NULL );
    }
    Node* newNode = new Node(val , head , NULL);
    head->back = newNode;
    return newNode;
}

// --------------------------INSERT BEFORE TAIL---------------------------------
Node* InsertBeforeTail(Node* head , int val){
    if(head == NULL){
        Node* newNode = new Node(val , NULL , NULL);
        return newNode;
    }
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    Node* prev = temp->back;
    Node* newNode = new Node(val , temp , prev);
    prev->next = newNode;
    temp->back = newNode;
return head;

}
//-------------------------------------INSERT AT K NODE-------------------------------------
Node* InsertkNode(Node* head , int val ,int k){
    if(k == 1){
        return InsertatHead(head ,val);

    }
    int cnt = 0 ;
    Node* temp = head;
    while(temp != NULL){
        cnt++;
        if(cnt == k) break;
        temp = temp->next;
    }
    Node* prev = temp->back;
    Node* newNode = new Node(val , temp , prev);
    prev->next = newNode;
    temp->back = newNode;
return head;
}
Node* ReverseDDL(Node* head ){
    if(head ==NULL || head->next == NULL) return head;
    Node* temp = NULL;
    Node* curr = head;

    while (curr != NULL) {
        // Swap next and back
        temp = curr->back;
        curr->back = curr->next;
        curr->next = temp;

        // Move to next node (which is now in back)
        curr = curr->back;
    }
   if (temp != NULL) {
        head = temp->back;
    }
    return head; // prev will be the new head of the reversed list
}

int main(){
    vector<int> arr = {2 , 5 , 8 , 9};
    Node* head = ArraytoDLList(arr);
    print(head);

    head = ReverseDDL(head);
    print(head);
return 0;
 }