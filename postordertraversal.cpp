/****************RECURSIVE*********************************************/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int>v;
    void helper(TreeNode* root)
    {
        if(root!=nullptr)
        {
        if(root->left!=nullptr)
        helper(root->left);
        if(root->right!=nullptr)
        helper(root->right);
        v.push_back(root->val);
        }
    }
    vector<int> postorderTraversal(TreeNode* root) {
       helper(root);
        return v;
    }
};


/**************************ITERATIVE********************************/

class Solution {
public:
    vector<int>v;
   
    vector<int> postorderTraversal(TreeNode* root) {
       stack<TreeNode*>st;
        TreeNode* ptr=root;
        TreeNode* last=NULL;
        while(ptr || !st.empty())
        {
            if(ptr!=nullptr)
            {
                st.push(ptr);
                ptr=ptr->left;
            }
            else
            {
                TreeNode* node= st.top();;
            if(node->right &&  last!=(node->right))
                    ptr=node->right;
            else
            {
            v.push_back(node->val);
                last=node;
            st.pop();
                
            }
            }
        }
        return v;
    }
};