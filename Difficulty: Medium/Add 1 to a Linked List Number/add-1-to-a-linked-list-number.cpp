//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data % 10;
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends

// User function template for C++

/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    Node* reverseLL(Node* head){
        if(head == NULL || head -> next == NULL){
            return head;
        }
        
        Node* new_head = reverseLL(head->next);
        Node* front = head -> next;
        front -> next = head;
        head -> next = NULL;
        
        return new_head;
    }
  
    Node* addOne(Node* head) {
        head = reverseLL(head);
        Node* temp = head;
        int carry = 1;
        
        while(temp != NULL){
            temp->data = temp->data + carry;
            if(temp -> data < 10){
                carry = 0;
                break;
            } else{
                temp->data = 0;
                carry = 1;
            }
            temp = temp -> next;
        }
        
        if(carry == 1){
            head = reverseLL(head);
            Node* node = new Node(carry);
            node -> next = head;
            return node;
        }else{
            return reverseLL(head);
        }
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends