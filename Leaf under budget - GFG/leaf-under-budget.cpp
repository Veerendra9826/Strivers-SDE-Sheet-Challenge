//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void printInorder(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}
Node *buildTree(string str)
{
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
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

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
        if (currVal != "N")
        {

            // Create the right child for the current node
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
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution
{
public:
   // Helper function to calculate the count of leaf nodes within budget
void calculateLeafCount(Node* root, unordered_map<int, int>& levelLeafCount, int* maxLevel, int level) {
    if (root != NULL) {
        // Update the maximum level encountered so far
        *maxLevel = max(*maxLevel, level);

        // Check if the current node is a leaf node
        if (root->left == NULL && root->right == NULL)
            levelLeafCount[level]++; // Increment the count of leaf nodes at level 'level'

        // Recursively traverse the left and right subtrees
        calculateLeafCount(root->left, levelLeafCount, maxLevel, level + 1);
        calculateLeafCount(root->right, levelLeafCount, maxLevel, level + 1);
    }
}

// Function to get the maximum count of leaf nodes that can be visited within budget k
int getCount(Node* root, int k) {
    unordered_map<int, int> levelLeafCount;
    int totalCount = 0;
    int maxLevel = INT_MIN;

    // Calculate the maximum level encountered and count of leaf nodes at each level
    calculateLeafCount(root, levelLeafCount, &maxLevel, 1);

    // Iterate over levels from 1 to the maximum level encountered
    for (int level = 1; level <= maxLevel;) {
        if (levelLeafCount[level] > 0) {
            if (k >= level) {
                k -= level;
            } else {
                return totalCount; // Return the current count if the remaining budget is not sufficient
            }

            levelLeafCount[level]--; // Decrement the count of leaf nodes at level 'level'
            totalCount++; // Increment the overall count of leaf nodes visited
        } else {
            level++; // Move to the next level if there are no leaf nodes at the current level
        }
    }

    return totalCount; // Return the final count of leaf nodes visited
}

};

//{ Driver Code Starts.

int main()
{
    int t;
    scanf("%d", &t);
    cin.ignore();
    while (t--)
    {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        int k;
        cin >> k;
        cin.ignore();
        Solution obj;
        int res = obj.getCount(root, k);
        cout << res << "\n";
    }
    return 0;
}

// } Driver Code Ends