//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

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
        if (i >= ip.size()) break;
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
/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
    public:
        int check(Node *root, int &max_sum, Node *head) {
        if(root == NULL)
            return 0;
            
        int left_sum = check(root->left, max_sum, head);
        int right_sum = check(root->right, max_sum, head);
        
        if(root->left != NULL && root->right != NULL) {
            max_sum = max(left_sum + right_sum + root->data, max_sum);
        }
        
        if(root == head) {
            if(root->left != NULL && root->right == NULL)
                max_sum = max(left_sum + root->data, max_sum);
            else if(root->left == NULL && root->right != NULL)
                max_sum = max(right_sum + root->data, max_sum);
        }
        
        if(root->left == NULL && root->right != NULL)
            return right_sum + root->data;
            
        if(root->left != NULL && root->right == NULL)
            return left_sum + root->data;
        
        return max(left_sum, right_sum) + root->data;
    }
    
    int maxPathSum(Node* root)
    {
        if(root == NULL)
            return 0;
            
        int max_sum = INT_MIN;
        check(root, max_sum, root);
        return max_sum;
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        Solution ob;
        cout << ob.maxPathSum(root) << "\n";
    }
    return 0;
}
// } Driver Code Ends