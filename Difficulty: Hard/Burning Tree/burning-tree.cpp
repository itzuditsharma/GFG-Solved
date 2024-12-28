//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node *buildTree(string str) {
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
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
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

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
// User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    int minTime(map<Node*, Node*> &child_parent, Node* target){
        queue<Node*> q;
        q.push(target);
        unordered_map<Node*, bool> visited;
        visited[target] = true;
        int maxi = 0;
        
        while(!q.empty()){
            int size = q.size();
            int flag = 0;
            
            for(int i = 0; i < size; i++){
                Node* node = q.front();
                q.pop();
                
                if(node -> left && visited[node -> left] == false){
                    flag = 1;
                    q.push(node -> left);
                    visited[node -> left] = true;
                }
                
                if(node -> right && visited[node -> right] == false){
                    flag = 1;
                    q.push(node -> right);
                    visited[node->right] = true;
                }
                
                if(child_parent[node] && visited[child_parent[node]] == false){
                    flag = 1;
                    q.push(child_parent[node]);
                    visited[child_parent[node]] = true;
                }
                
            }
            if(flag == 1) maxi++;
        }
        return maxi;
    }
  
    // Function maps childs to parent nodes and also gives us the node that has target value 
    Node* mapChildParent(Node* root, map<Node*, Node*> &child_parent, int target){
        queue<Node*>q;
        q.push(root);
        Node* res;
        while(!q.empty()){
            Node* node = q.front();
            q.pop();
            
            if(node -> data == target) res = node;
            
            if(node -> left){
                child_parent[node -> left] = node;
                q.push(node -> left);
            }
            if(node -> right){
                child_parent[node -> right] = node;
                q.push(node -> right);
            }
        }
        return res;
    }
  
    int minTime(Node* root, int target) {
        map<Node*, Node*> child_parent;
        Node* target_node = mapChildParent(root, child_parent, target);
        int maxi = minTime(child_parent, target_node);
        return maxi;
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin >> target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout << obj.minTime(root, target) << "\n";

        cin.ignore();

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends