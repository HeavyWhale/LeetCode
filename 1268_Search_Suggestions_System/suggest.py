class Solution:
    # Assuming word[:pos] == searchWord[:pos] is True and 
    # only test if searchWord[pos:] is a prefix of word[pos:]
    def matching_from_pos(word: str, searchWord: str, pos: int) -> bool:
        if len(word) < len(searchWord):
            return False
        for i in range(pos, len(searchWord)):
            if word[i] != searchWord[i]:
                return False
        return True
    
    def suggestedProducts(self, products: list[str], searchWord: str) -> list[list[str]]:
        products.sort()
        result = []
        for i in range(1, len(searchWord)+1):
            pref = searchWord[:i]
            products = list(filter(lambda x: Solution.matching_from_pos(x, pref, i-1), products))
            result.append(products[:3])
        return result

products = ["bags","baggage","banner","box","cloths"]
searchWord = "bags"
s = Solution()
print(s.suggestedProducts(products, searchWord))
