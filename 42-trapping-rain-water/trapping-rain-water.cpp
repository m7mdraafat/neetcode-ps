class Solution {
public:
    int trap(vector<int>& height) {
        // if maxLeft < maxRight
        // water at left is determined by maxLeft (it's the bottleneck)
        // process left, move left ->
    
        // if maxRight <= maxLeft
        // water at right is determined by maxRight (it's the bottleneck)
        // process right, <= right

        int left = 0, right = height.size() - 1; 
        int maxLeft = 0, maxRight = 0;
        int water = 0;

        while (left < right) {
            if (height[left] < height[right]) {
                maxLeft = max(maxLeft, height[left]);
                water += maxLeft - height[left];
                left++;
            } else {
                maxRight = max(maxRight, height[right]);
                water += maxRight - height[right];
                right--;
            }
        }

        return water; 
    }
};