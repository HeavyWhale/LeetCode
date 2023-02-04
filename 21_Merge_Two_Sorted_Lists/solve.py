'''
    merge two ascending lists into an ascending one
'''
def mergeTwoAscLists(l1: list[int], l2: list[int]) -> list[int]:
    result = []
    i, j = 0, 0

    while i < len(l1) or j < len(l2):
        if i >= len(l1):
            result.extend(l2[j:])
            break
        if j >= len(l2):
            result.extend(l1[i:])
            break
        v1, v2 = l1[i], l2[j]
        if v1 <= v2:
            result.append(v1)
            i += 1
        else:
            result.append(v2)
            j += 1
    
    return result

l1 = [1,3,5,7]
l2 = [2,3,4,5]
print(mergeTwoAscLists(l1, l2))
