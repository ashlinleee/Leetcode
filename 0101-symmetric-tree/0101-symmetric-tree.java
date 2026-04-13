class Solution {
    public boolean isSymmetric(TreeNode root) {
        return isMirror(root, root);
    }

    boolean isMirror(TreeNode t1, TreeNode t2) {
        // both null → symmetric
        if (t1 == null && t2 == null) return true;

        // one null → not symmetric
        if (t1 == null || t2 == null) return false;

        // values not equal → not symmetric
        if (t1.val != t2.val) return false;

        // check mirror condition
        return isMirror(t1.left, t2.right) &&
               isMirror(t1.right, t2.left);
    }
}