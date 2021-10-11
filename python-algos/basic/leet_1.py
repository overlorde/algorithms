class solution:
    def twoSum(self,nums,target):
        l = len(nums)
        sol = []
        for i in range(l):
            for j in range(i+1,l):
                if(nums[i]+nums[j]==target):
                    sol.append(i)
                    sol.append(j)
        return sol

x = solution()

print(x.twoSum([1,2,3,4,5],9))
