//{ Driver Code Starts
// C++ program to find predecessor and successor in a BST
#include "bits/stdc++.h"
using namespace std;

// BST Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};


// } Driver Code Ends

/* BST Node
class Node
{
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    void predecessor(Node *root, Node *&pre, Node *&suc, int key){
        Node* curr = root;
        while(curr){
            if(curr -> data < key){
                pre = curr;
                curr = curr -> right;
            }else{
                curr = curr -> left;
            }
        }
    }
    
    void successor(Node *root, Node *&pre, Node *&suc, int key){
        Node* curr = root;
        while(curr){
            if(curr -> data > key){
                suc = curr;
                curr = curr -> left;
            }else{
                curr = curr -> right;
            }
        }
    }
  
    void findPreSuc(Node *root, Node *&pre, Node *&suc, int key) {
        // code here
        pre = NULL;
        suc = NULL;
        
        predecessor(root, pre, suc, key);
        successor(root, pre, suc, key);
    }
};


//{ Driver Code Starts.

Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

// Driver program to test above functions
int main() {

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        getline(cin, s);
        int k = stoi(s);
        Node *pre = NULL, *succ = NULL;
        Solution ob;
        ob.findPreSuc(root, pre, succ, k);
        (pre != NULL) ? cout << pre->data : cout << -1;
        cout << " ";
        (succ != NULL) ? cout << succ->data : cout << -1;
        cout << endl;
        // inOrderTraversal(root);
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends