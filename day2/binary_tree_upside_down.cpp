/**
 * Definition of TreeNode:
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left, right;
 *     public TreeNode(int val) {
 *         this.val = val;
 *         this.left = this.right = null;
 *     }
 * }
 */

public class Solution {
    /**
     * @param root: the root of binary tree
     * @return: new root
     */
     TreeNode nr;
     public Solution(){
         nr=null;
     }
     TreeNode solve(TreeNode root){
         if(root==null) return null;

         solve(root.left);
         if(nr==null){
             nr=root;
             return nr;
         }
         root.left.left=root.right;
         root.left.right=root;
         root.left=null;
         root.right=null;
         return nr;
     }
    public TreeNode upsideDownBinaryTree(TreeNode root) {
        // write your code here
        
        return solve(root);
        
    }
}