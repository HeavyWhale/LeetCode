DEBUG = True
class Solution:
    # This doesn't work if there are duplicates in @words
    def WRONG_numMatchingSubseq(self, s: str, words: list[str]) -> int:
        # Return the position of @target_ch in @word starting from index @pos, if found;
        #    otherwise, -1
        def searchFromPos(word: str, pos: int, target_ch: str) -> int:
            for i in range(pos, len(word)):
                if word[i] == target_ch:
                    return i
            return -1
            
        last_pos = dict()
        for word in words:
            last_pos[word] = 0
        
        cnt = 0
        for ch in s:
            for word in words:
                found_at = searchFromPos(word, last_pos[word], ch)
                if found_at != -1:
                    last_pos[word] = found_at + 1
        
        for k, v in last_pos.items():
            if v == len(k):
                cnt += 1
        
        return cnt

    def SLOW_numMatchingSubseq(self, s: str, words: list[str]) -> int:
        count = 0
        d = dict()
        for i, ch in enumerate(s):
            if ch in d:
                d[ch].append(i)
            else:
                d[ch] = [1, i]

        for word in words:
            if DEBUG: print(d)
            isSubSeq = True
            prev_pos = -1
            for ch in word:
                if DEBUG:
                    print("ch =", ch)
                    print("prev_i =", prev_pos)
                if ch not in d:
                    isSubSeq = False
                    break
                for i in range(d[ch][0], len(d[ch])+1):
                    if i == len(d[ch]):
                        isSubSeq = False
                        break
                    cur_pos = d[ch][i]
                    if DEBUG:
                        print("cur_i =", cur_pos)
                    if cur_pos > prev_pos:
                        d[ch][0] = i
                        break
                if isSubSeq == False:
                    break
                prev_pos = cur_pos
                print("---")
            count += 1 if isSubSeq else 0
            print("=== count =", count)
            for v in d.values():
                v[0] = 1
        return count

    # ZMY's solution
    def numMatchingSubseq(self, s: str, words: list[str]) -> int:
        # a, bb, acd, ace
        # buckets[0], buckets[1], buckets[0], buckets[0]
        # step1: put all words into buckets according to the first ch
        buckets=[[] for _ in range(26)]
        for i in range(len(words)):
            idx=ord(words[i][0])-ord('a')
            buckets[idx].append([i,0])
            
        # step2: traverse the string s to find all subseq
        # abcde,    a, bb, acd, ace
        # bcde,     bb, cd, ce
        # cde,      b, cd, ce
        # de,       b, d, e
        # e,        b, e
        # '',       b
        
        # time complexity: O(N) N: sum of length of all words
        # space complexity: O(n) n: num of words
        cnt=0
        for i in range(len(s)):
            ch=s[i]
            idx=ord(s[i])-ord('a')
            old_bucket=buckets[idx] # a, acd, ace
            buckets[idx]=[] # add new modified word 
            
            for remain_word in old_bucket:
                x,y=remain_word
                if len(words[x])==y+1: # reach the end of the word
                    cnt+=1
                else: # process the next ch of the word
                    nxt_idx=ord(words[x][y+1])-ord('a') # acd->cd, put it into the buckets[2](c)
                    buckets[nxt_idx].append([x,y+1])
        return cnt

    def myver_numMatchingSubseq(self, s: str, words: list[str]) -> int:
        def charToInt(ch: str) -> int:
            return ord(ch)-ord('a')
        
        # Note: a tuple of (x, y) in buckets[z] indicates the following fact:
        #           There is a word w, which is equivalent to words[x],
        #           has a character w[y] such that charToInt(w[y]) == z
        #       i.e.,
        #           the buckets are labelled with the starting character 
        #           at postion y of word w, where w == words[x]
        buckets = [[] for _ in range(26)]
        for i, word in enumerate(words):
            buckets[charToInt(word[0])].append((i, 0))

        cnt = 0
        for ch in s:
            ch_order = charToInt(ch)
            old_bucket = buckets[ch_order]
            buckets[ch_order] = []

            for tuple in old_bucket:
                # Invariant: the corresponding words in tuples will
                #   all have char @ch at position @cur_ch_pos
                word_pos, cur_ch_pos = tuple
                word = words[word_pos]
                if cur_ch_pos == len(word) - 1: # reach the end of word
                    cnt += 1
                else: # process the next ch of the word
                    nxt_ch_pos = cur_ch_pos + 1
                    nxt_ch_order = charToInt( word[nxt_ch_pos] )
                    buckets[ nxt_ch_order ].append((word_pos, nxt_ch_pos))
        return cnt

s = "qlhxagxdqh"
words = ["qlhxagxdq","qlhxagxdq","lhyiftwtut","yfzwraahab"]
so = Solution()
print(so.numMatchingSubseq(s, words))

# print("#####################")

# s = "abcde"
# words = ["a","bb","acd","ace"]
# print(so.numMatchingSubseq(s, words))
