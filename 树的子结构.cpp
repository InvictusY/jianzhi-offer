/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        bool result = false;
        if(pRoot1!=nullptr && pRoot2!=nullptr)
        {
            if(pRoot1->val == pRoot2->val)
            {
                result = DoseTree1HasTree2(pRoot1, pRoot2);
            }
            if(!result)
            {
                result = HasSubtree(pRoot1->left, pRoot2);
            }
            if(!result)
            {
                result = HasSubtree(pRoot1->right, pRoot2);
            }
        }
        return result;
    }
    bool DoseTree1HasTree2(TreeNode* node1, TreeNode* node2)
    {
        if(node2==nullptr)
            return true;
        if(node1==nullptr)
            return false;
        if(node1->val != node2->val)
            return false;
        return DoseTree1HasTree2(node1->left, node2->left) && DoseTree1HasTree2(node1->right, node2->right);
    }
};