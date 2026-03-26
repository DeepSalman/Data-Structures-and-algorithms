class Solution:
    def sortEvenOdd(self, nums: list[int]) -> list[int]:
        arrEven=[]
        arrOdd=[]
        arrRes=[]

        for i in range(len(nums)):
            if i%2==0:
                arrEven.append(nums[i])
            else:
                arrOdd.append(nums[i])

        arrEven=sorted(arrEven)
        arrOdd=sorted(arrOdd,reverse=True)
        evenIndex,oddIndex=0,0
        for i in range(len(nums)):
            if i%2==0:
                arrRes.append(arrEven[evenIndex])
                evenIndex+=1
            else:
                arrRes.append(arrOdd[oddIndex])
                oddIndex+=1
        return arrRes
    


sol = Solution()

input_list = [16,17,4,18,1,20,5,12]
result = sol.sortEvenOdd(input_list)

print(result)

        