class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        # Initialize an empty set to hold unique triplets
        res = set()

        # Split nums into three lists: negative numbers, positive numbers, and zeros
        n, p, z = [], [], []
        for num in nums:
            if num > 0:
                p.append(num)
            elif num < 0:
                n.append(num)
            else:
                z.append(num)

        # Create sets for negative and positive numbers for faster lookup
        N, P = set(n), set(p)

        # Check pairs of positive and negative numbers
        # Case (-num, 0, num) if num exists in both negative and positive lists
        if z:
            for num in P:
                if -num in N:
                    res.add((-num, 0, num))

        # Check for triplet of zeros
        if len(z) >= 3:
            res.add((0, 0, 0))

        # Check pairs of negative numbers and their complement in positive list
        for i in range(len(n)):
            for j in range(i + 1, len(n)):
                target = -1 * (n[i] + n[j])
                if target in P:
                    res.add(tuple(sorted([n[i], n[j], target])))

        # Check pairs of positive numbers and their complement in negative list
        for i in range(len(p)):
            for j in range(i + 1, len(p)):
                target = -1 * (p[i] + p[j])
                if target in N:
                    res.add(tuple(sorted([p[i], p[j], target])))

        # Convert set of triplets to a sorted list of lists
        return [list(triplet) for triplet in res]
