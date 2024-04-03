class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        # Check if the lengths of the strings are equal
        if len(s) != len(t):
            return False  

        # Initialize mappings from s to t and t to s
        mapST, mapTS = {}, {}

        # Iterate through each character in the strings
        for i in range(len(s)):
            c1, c2 = s[i], t[i]  

            # Check if current characters have been mapped differently
            if (c1 in mapST and mapST[c1] != c2) or (c2 in mapTS and mapTS[c2] != c1):
                return False  

            # Update mappings from s to t and t to s
            mapST[c1] = c2
            mapTS[c2] = c1

        return True

