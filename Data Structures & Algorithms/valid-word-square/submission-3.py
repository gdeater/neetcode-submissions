class Solution:
    def validWordSquare(self, words: List[str]) -> bool:
        row, col = 0, 0
        bucket = ""
        words_bucket = []

        for i in words:
            if len(i) >= col:
                col = len(i) 

        for columm in range(col):
            bucket = ""
            for word in words:
                if row < len(word):
                    bucket += word[row]
            words_bucket.append(bucket)
            row += 1
        return words_bucket == words  

        