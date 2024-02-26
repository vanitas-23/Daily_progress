/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 
 */
class Solution {
    boolean value=true;
    public boolean isSameTree(TreeNode ptr, TreeNode qtr) {
        if(ptr==null && qtr==null)
            return true;
        if(ptr==null || qtr==null)
        return false;
         traverse(ptr,qtr);
         return value;
    }
    public void traverse(TreeNode p,TreeNode q){
        if(p==null && q==null)
        return;
        if(p==null || q==null){
        value=false;
        return;
        }
        traverse(p.left,q.left);
        if(p.val!=q.val){
            value=false;
            return;
        }
         traverse(p.right,q.right);
    }
}


