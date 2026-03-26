class Solution:
    def sortEvenOdd(self, nums: List[int]) -> List[int]:
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
        evenindx,oddindx=0,0
        for i in range(len(nums)):
            if i%2==0:
                arrRes.append(arrEven[evenindx])
                evenindx+=1
            else:
                arrRes.append(arrOdd[oddindx])
                oddindx+=1
        return arrRes


        