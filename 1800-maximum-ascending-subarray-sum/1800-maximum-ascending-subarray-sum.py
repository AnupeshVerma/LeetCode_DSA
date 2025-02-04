class Solution:
    def maxAscendingSum(self, nums: List[int]) -> int:
        n = len(nums)
        maxSum = nums[0]

        tempSum = nums[0]
        for i in range(1, n):
            if(nums[i] > nums[i-1]):
                tempSum += nums[i]
                maxSum = max(maxSum, tempSum)
            else:
                tempSum = nums[i]
        return maxSum