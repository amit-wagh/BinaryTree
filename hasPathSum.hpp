/*
*** Given the root of a binary tree and an integer targetSum, return true 
*** if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.
*/

//Recursive Solution : 
class Solution final {
public:
    auto hasPathSum(TreeNode const *root, int const sum) const -> bool {
        if ( root == nullptr ) return false;
        
        if ( root->val == sum && root->left == nullptr && root->right == nullptr ) 
          return true;
      
        auto const remainingsum = sum - root->val;
        return hasPathSum( root->left,  remainingsum ) || 
               hasPathSum( root->right, remainingsum );
    }
};

//Iterative Solution : 
class Solution final {
public:
    auto hasPathSum(TreeNode const *root, int const sum) const -> bool {
      if ( root == nullptr ) return false;
      stack<pair<const TreeNode*, const int>> tracker;

      tracker.push( {root, sum} );

      while( tracker.empty() == false ) {
        auto const [ node, remaining ] = tracker.top(); tracker.pop();

        if ( node->val   == remaining && 
             node->left  == nullptr.  && 
             node->right == nullptr ) {
          return true;
        }

        if( node->right != nullptr ) {
          tracker.push( {node->right, remaining - node->val} );
        }

        if( node->left != nullptr ) {
          tracker.push( {node->left, remaining - node->val} );
        }
      }
      return false;  
    }
};
