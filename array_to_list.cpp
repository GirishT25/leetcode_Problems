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
//  ------------------------------ Remove the head form the list ---------------------------------
// Node* removeHead(Node* head){
//     if(head == NULL) return head;
//     Node* temp = head;
//     head= head->next;
//     free(temp);
//     return head;
// }

// ---------------------- Remove the tail node --------------------------------
// Node* removeTail(Node* head){
//     if(head == NULL || head->next == NULL) return NULL;
//     Node* temp = head;
//     while(temp->next->next != NULL){
//           temp= temp->next;
//     }
//     free(temp->next);
//     temp->next =NULL;
//     return head;
// }

// // ------------------------Remove k node ------------------
// Node* removek(Node* head , int k){
//     if(head == NULL) return head;
//     if(k == 1){
//         Node* temp = head;
//         temp->next = head;
//         free(temp);
//     }
//     int cnt = 0;
//     Node* temp = head;
//     Node* prev = NULL;
//     while(temp !=NULL){
//         cnt++;
//         if(cnt == k){
//             prev->next = prev->next->next;
//             free(temp);
//             break;
//         }
//         prev = temp;
//         temp = temp->next;
//     }
//     return head;
// }
// ----------------------INSERT AT HEAD ------------------------------------
Node* insertHead(Node* head , int val){
    return new Node(val , head); // return a new node at the start of the head where new node is created and the values are passed by the p
                                // parameters
}
Node* insertTail(Node* head, int val){
    if(head == NULL) {
        return new Node(val);
    }
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    Node* newNode = new Node(100);
    temp->next = newNode;
    return head;
}
// -------------------------INSERT AT K ---------------------------
// Node* insertKpoistion(Node* head , int k , int val){
//     if(head == NULL){
//         if(k == 1){
//             return new Node(val);
//         }
//         else{
//             return head;
//         }
//     }
//         if(k == 1){
//             return new Node(val , head);
//         }
//         int cnt = 0;
//         Node* temp = head;
//         while(temp !=NULL){
//             cnt++;
//             if(cnt == (k-1)){ // the k-1 is used to direct point to the k element because the linked list traversal upto n+1
//                 Node* newNode = new Node( val , temp->next);
//                 // newNode->next = temp->next; same as the pointing the 
//                 temp->next = newNode;
//                 break;
//             }
//             temp = temp->next;
//         }
//         return head;

// }
// --------------------------------------INSERT AT THE ELEMENT AFTER THE VALUE OF THE LINKED LIST -----------------------------------
Node* insertBeforePoistion(Node* head , int element , int val){
    if(head == NULL){
        return NULL;
    }
        if(head->data == val){
            return new Node(element , head);
        }
        
        Node* temp = head;
        while(temp->next !=NULL){
            if(temp->next->data == val){ 
                Node* newNode = new Node( element , temp->next->next);
                temp->next->next = newNode;
                break;
            }
            temp = temp->next;
        }
        return head;
}

int main(){
    vector<int> arr = {2 , 5 , 8 , 9};
    Node* head = ArraytoList(arr);
    print(head);
    // head = removeHead(head);
    head = insertBeforePoistion(head, 6, 5);
    print(head);
return 0;
 }