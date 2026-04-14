class Solution {
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> result = new ArrayList<>();
        TreeNode curr = root;

        while (curr != null) {

            // Case 1: No left child
            if (curr.left == null) {
                result.add(curr.val);   // visit
                curr = curr.right;
            } 
            else {
                TreeNode prev = curr.left;

                // Find inorder predecessor
                while (prev.right != null && prev.right != curr) {
                    prev = prev.right;
                }

                // First time visit → create thread
                if (prev.right == null) {
                    prev.right = curr;
                    curr = curr.left;
                } 
                // Second time → remove thread + visit
                else {
                    prev.right = null;
                    result.add(curr.val);  // visit
                    curr = curr.right;
                }
            }
        }
        return result;
    }
}