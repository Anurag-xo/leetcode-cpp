This code converts a sorted array into a balanced binary search tree (BST). Let's break it down in detail.

### Purpose
The purpose of this code is to take a sorted array of integers (`nums`) and create a balanced binary search tree (BST) from it. In a balanced BST, for each node:
- The left subtree contains nodes with values less than the node’s value.
- The right subtree contains nodes with values greater than the node’s value.
- The tree is balanced, meaning the depth of the left and right subtrees of every node differs by no more than one.

### Code Breakdown

Let's look at the code line by line.

#### Class Declaration
```cpp
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }
private:
    TreeNode* helper(vector<int>& nums, int left, int right) {
        if (left > right) return nullptr;
        int mid = left + (right - left) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root -> left = helper(nums, left, mid - 1);
        root -> right = helper(nums, mid + 1, right);
        return root;
    }
};
```

### Key Parts

1. **`TreeNode` Structure**:
   - This code assumes the existence of a `TreeNode` structure (class) with attributes `val` (the value of the node), `left` (pointer to the left child), and `right` (pointer to the right child). 
   - A new `TreeNode` is created using `TreeNode* root = new TreeNode(nums[mid]);`.

2. **Function `sortedArrayToBST`**:
   - This function is the main function that the user calls with the sorted array `nums`.
   - It returns the root of the balanced BST created from `nums`.
   - It calls a helper function `helper(nums, 0, nums.size() - 1)` to handle the recursive logic.

3. **Helper Function `helper`**:
   - **Parameters**: The `helper` function takes the array `nums`, a `left` index, and a `right` index, representing the current subarray to be converted into a BST subtree.
   - **Base Case**: `if (left > right) return nullptr;` — If `left` is greater than `right`, it means there are no elements in this range, so the function returns `nullptr`, indicating an empty subtree.
   - **Finding the Middle Element**: `int mid = left + (right - left) / 2;`
     - This line finds the middle element of the current subarray. This element will become the root of the subtree.
     - Using the middle element ensures the BST remains balanced.
   - **Creating the Root Node**: `TreeNode* root = new TreeNode(nums[mid]);`
     - A new `TreeNode` is created with the value `nums[mid]`, representing the root of this subtree.
   - **Recursive Construction of Left and Right Subtrees**:
     - `root -> left = helper(nums, left, mid - 1);`
       - This recursively constructs the left subtree from the left half of the current subarray (elements from `left` to `mid - 1`).
     - `root -> right = helper(nums, mid + 1, right);`
       - This recursively constructs the right subtree from the right half of the current subarray (elements from `mid + 1` to `right`).
   - **Returning the Root**: Finally, the root of the subtree is returned, which will be connected as either the left or right child of the parent node in the previous recursive call.

### How the Recursion Works

Each recursive call to `helper` breaks down the array further until each subarray has only one or no elements:
- If the subarray has one element, that element becomes a `TreeNode` with no children.
- If the subarray is empty (base case), `nullptr` is returned, meaning no subtree exists for that branch.

For example, given `nums = [-10, -3, 0, 5, 9]`:
1. The initial call to `helper(nums, 0, 4)` picks `0` (the middle element) as the root.
2. For the left subtree, it calls `helper(nums, 0, 1)`, which picks `-10` as the left child of `0`.
3. For the right subtree, it calls `helper(nums, 3, 4)`, which picks `5` as the right child of `0`.
4. The process continues recursively until all elements are placed in the tree.

### Example Walkthrough

With `nums = [-10, -3, 0, 5, 9]`, here’s a step-by-step breakdown of the recursive calls:

1. **First Call**:
   - `helper(nums, 0, 4)`:
   - `mid = 2` (value `0`).
   - `root = TreeNode(0)`.
   - Recurse on left half `helper(nums, 0, 1)`.
   - Recurse on right half `helper(nums, 3, 4)`.

2. **Left Subtree of 0**:
   - `helper(nums, 0, 1)`:
   - `mid = 0` (value `-10`).
   - `root = TreeNode(-10)`.
   - Recurse on left half `helper(nums, 0, -1)` — returns `nullptr`.
   - Recurse on right half `helper(nums, 1, 1)`.

3. **Right Subtree of -10**:
   - `helper(nums, 1, 1)`:
   - `mid = 1` (value `-3`).
   - `root = TreeNode(-3)`.
   - Recurse on left half `helper(nums, 1, 0)` — returns `nullptr`.
   - Recurse on right half `helper(nums, 2, 1)` — returns `nullptr`.

4. **Right Subtree of 0**:
   - `helper(nums, 3, 4)`:
   - `mid = 3` (value `5`).
   - `root = TreeNode(5)`.
   - Recurse on left half `helper(nums, 3, 2)` — returns `nullptr`.
   - Recurse on right half `helper(nums, 4, 4)`.

5. **Right Subtree of 5**:
   - `helper(nums, 4, 4)`:
   - `mid = 4` (value `9`).
   - `root = TreeNode(9)`.
   - Recurse on left half `helper(nums, 4, 3)` — returns `nullptr`.
   - Recurse on right half `helper(nums, 5, 4)` — returns `nullptr`.

### Final BST Structure

After all recursive calls, the BST structure is:
```
      0
     / \
   -10  5
     \   \
    -3    9
```

### Summary
- The `sortedArrayToBST` function initializes the recursive construction.
- The `helper` function recursively divides the array to find middle elements, ensuring balance.
- This approach ensures that the BST is as balanced as possible, with each node’s subtrees having nearly equal depth.
