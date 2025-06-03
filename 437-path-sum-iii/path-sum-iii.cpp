class Solution {
public:
    int countPathsFromNode(TreeNode* node, long long currentSum, int targetSum) {
        if (!node) return 0;

        int count = 0;
        currentSum += node->val;

        if (currentSum == targetSum) {
            count++;
        }

        count += countPathsFromNode(node->left, currentSum, targetSum);
        count += countPathsFromNode(node->right, currentSum, targetSum);

        return count;
    }

    int pathSum(TreeNode* root, int targetSum) {
        if (!root) return 0;

        int pathsFromRoot = countPathsFromNode(root, 0, targetSum);

        int pathsOnLeft = pathSum(root->left, targetSum);
        int pathsOnRight = pathSum(root->right, targetSum);

        return pathsFromRoot + pathsOnLeft + pathsOnRight;
    }
};
