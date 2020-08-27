//------------------------Recursive------------------

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
            if((root->left)!=nullptr)
                helper(root->left);
            v.push_back(root->val);
            if((root->right)!=nullptr)
                helper(root->right);
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
     helper(root);
     return v;
    }
};


//-------------------------Iterative--------------------

class Solution {
public:
  
    vector<int> inorderTraversal(TreeNode* root) {
     vector<int>v;
        stack<TreeNode*>st;
        TreeNode* ptr=root;
        while(ptr || !st.empty())
        {
            while(ptr!=nullptr)
            {
                st.push(ptr);
                ptr=ptr->left;
            }
            ptr=st.top();
            st.pop();
            v.push_back(ptr->val);
            ptr=ptr->right;
        }
        return v;
    }
};