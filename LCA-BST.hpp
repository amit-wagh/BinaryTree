class Solution {
public:
    auto lowestCommonAncestorR(TreeNode* root, TreeNode* p, TreeNode* q) const noexcept( true ) -> TreeNode* {
       
        if( p->val > root->val && q->val > root->val ) {
            return lowestCommonAncestor( root->right, p, q );
        } else if( p->val < root->val && q->val < root->val ) {
            return lowestCommonAncestor( root->left, p, q );
        } else {
            return root;
        }   
    }
  
    auto lowestCommonAncestorI(TreeNode* root, TreeNode* p, TreeNode* q) const noexcept( true ) -> TreeNode* {
        auto node = root;
        while( node != nullptr ) 
        {
          if( p->val > node->val && q->val > node->val ) {
            node = node->right;
          } else if ( p->val < node->val && q->val < node->val ){
            node = node->left;
          } else {
            return node;
          }
        }
        
        return nullptr;
    }
};
