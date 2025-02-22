/*
Class BTNode is used to store a node in binary tree, described on the following:

class BTNode {
    public: 
        int val; 
        BTNode *left; 
        BTNode *right; 
        BTNode() {
            this->left = this->right = NULL;
        } 
        BTNode(int val) {
            this->val = val;
            this->left = this->right = NULL;
        } 
        BTNode(int val, BTNode*& left, BTNode*& right) {
            this->val = val;
            this->left = left;
            this->right = right;
        } 
};
Where val is the value of node (integer, in segment [0,9]), left and right are the pointers to the left node and right node of it, respectively.

Request: Implement function:

int sumDigitPath(BTNode* root);
Where root is the root node of given binary tree (this tree has between 2 and 100000 elements). This function returns the sum of all digit path numbers of this binary tree (the result may be large, so you must use mod 27022001 before returning).

More information:

- A path is called as digit path if it is a path from the root node to the leaf node of the binary tree.

- Each digit path represents a number in order, each node's val of this path is a digit of this number, while root's val is the first digit.

Example:

Given a binary tree in the following:

SumDigitPath

All of the digit paths are 3-5, 3-2-1, 3-2-4; and the number reprensted by them are 35, 321, 324, respectively. The sum of them (after mod 27022001) is 680.

Note: In this exercise, the libraries iostream, queue, stack, utility and using namespace std are used. You can write helper functions; however, you are not allowed to use other libraries.

For example:

Test	Result
int arr[] = {-1,0,0,2,2};
int value[] = {3,5,2,1,4};
BTNode* root = BTNode::createTree(arr, arr + sizeof(arr)/sizeof(int), value);
cout << sumDigitPath(root);
680
int arr[] = {-1,0,0};
int value[] = {1,2,3};
BTNode* root = BTNode::createTree(arr, arr + sizeof(arr)/sizeof(int), value);
cout << sumDigitPath(root);
25
*/
class BTNode {
    public: 
        int val; 
        BTNode *left; 
        BTNode *right; 
        BTNode() {
            this->left = this->right = NULL;
        } 
        BTNode(int val) {
            this->val = val;
            this->left = this->right = NULL;
        } 
        BTNode(int val, BTNode*& left, BTNode*& right) {
            this->val = val;
            this->left = left;
            this->right = right;
        } 
};

int sumDigitPath(BTNode* root) {
    if (!root) {
        return 0;
    }
    int mod = 27022001;
    int ans = 0;
    stack<pair<BTNode*, int>> stk; // stack to store pairs of nodes and their path numbers
    stk.push(make_pair(root, root->val));
    while (!stk.empty()) {
        BTNode* node = stk.top().first;
        int num = stk.top().second;
        stk.pop();
        if (!node->left && !node->right) { // leaf node, add path number to the answer
            ans = (ans + num) % mod;
            continue;
        }
        if (node->left) {
            stk.push(make_pair(node->left, (num * 10 + node->left->val) % mod));
        }
        if (node->right) {
            stk.push(make_pair(node->right, (num * 10 + node->right->val) % mod));
        }
    }
    return ans;
}
