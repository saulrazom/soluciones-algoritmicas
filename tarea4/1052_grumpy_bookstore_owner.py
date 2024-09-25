class Solution:
    def maxSatisfied(self, customers: List[int], grumpy: List[int], minutes: int) -> int:
        total = 0
        maxG = 0
        acum = 0

        for i in range(minutes - 1):
            acum += customers[i] if grumpy[i] else 0

        for i in range(len(customers)):
            if(not grumpy[i]):
                total += customers[i]

            if((i + minutes - 1) < len(customers) and grumpy[i + minutes - 1] == 1):
                acum += customers[i + minutes - 1]

            if(grumpy[i]):
                maxG = acum if acum > maxG else maxG
                acum -= customers[i]

        return total + maxG

                
            