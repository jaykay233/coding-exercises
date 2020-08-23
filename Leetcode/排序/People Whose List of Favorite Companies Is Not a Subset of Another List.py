class Solution(object):
    def peopleIndexes(self,favoriteCompanies):
        """
        :type favoriteCompanies: List[List[str]]
        :rtype: List[int]
        """
        A = favoriteCompanies
        location = {tuple(val):idx for idx,val in enumerate(A)}
        A.sort(key=lambda x:len(x))
        res = []
        for i in range(len(A)):
            for j in range(i+1,len(A)):
                if set(A[i]) & set(A[j]) == set(A[i]):
                    break 
            else:
                res.append(location[tuple(A[i])])
        res.sort() 
        return res 