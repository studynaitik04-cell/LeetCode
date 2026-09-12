int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* result = malloc(100 * sizeof(int));
    struct TreeNode* stack[100];
    int top = -1;
    int index = 0;

    struct TreeNode* current = root;

    while (current != NULL || top != -1) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }

        current = stack[top--];
        result[index++] = current->val;

        current = current->right;
    }

    *returnSize = index;
    return result;
}