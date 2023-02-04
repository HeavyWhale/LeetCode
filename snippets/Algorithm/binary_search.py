class BinarySearch:
    def find_first_occ(nums, target):
        if not nums:
            return -1
        
        # We find the target value by narrowing the range [start, end].
        # Note nums[start, end] does not necessarily contain the target value.
        start, end = 0, len(nums) - 1
        while start + 1 < end:          # exit when start and end are adjacent
            mid = (start + end) // 2
            
            if nums[mid] < target:
                start = mid
            elif nums[mid] == target:
                end = mid               # always narrow down to the left part
            else:
                end = mid
        
        if nums[start] == target:       # check left start point first
            return start
        if nums[end] == target:
            return end
        
        return -1

    def find_last_occ(nums, target):
        if not nums:
            return -1
        
        # we find the target value by narrowing the range [start, end]
        start, end = 0, len(nums) - 1
        while start + 1 < end:          # exit when start and end are adjacent
            mid = (start + end) // 2
            
            if nums[mid] < target:
                start = mid
            elif nums[mid] == target:
                start = mid             # always narrow down to the right part
            else:
                end = mid
        
        if nums[end] == target:         # check right end point first
            return end
        if nums[start] == target:
            return start
        
        return -1

    def find_lower_closest(nums, target):
        """
        Find the right-most index where its value <= target. If there is
        none, return -1.

        This function can also serve the purpose of finding the insert 
        position of a new value (at the front), regardless of whether 
        there are duplicates.
        """
        if not nums:
            return -1

        start, end = 0, len(nums) - 1
        while start + 1 < end:
            mid = (start + end) // 2

            if nums[mid] < target:
                start = mid
            elif nums[mid] == target:
                start = mid   # always go to right part
            else:
                end = mid

        if nums[end] <= target:
            return end
        if nums[start] <= target:
            return start
        
        return -1

    def find_upper_closest(nums, target):
        """
        Find the left-most index where its value >= target. If there is
        none, return -1.

        This function can also serve the purpose of finding the insert 
        position of a new value (at the rear), regardless of whether 
        there are duplicates.
        """
        if not nums:
            return -1
        
        start, end = 0, len(nums) - 1
        while start + 1 < end:
            mid = (start + end) // 2

            if nums[mid] < target:
                start = mid
            elif nums[mid] == target:
                end = mid   # always go to left part
            else:
                end = mid

        if nums[start] >= target:
            return start
        if nums[end] >= target:
            return end
        
        return -1

class TestBinarySearch:

    # --- test_find_first_occ ---
    def test_find_first_occ_REGULAR(self):
        nums = [-1,0,3,4]
        assert BinarySearch.find_first_occ(nums, -1) == 0
        assert BinarySearch.find_first_occ(nums, 0) == 1
        assert BinarySearch.find_first_occ(nums, 3) == 2
        assert BinarySearch.find_first_occ(nums, 4) == 3
        assert BinarySearch.find_first_occ(nums, 5) == -1
        assert BinarySearch.find_first_occ(nums, -2) == -1

    def test_find_first_occ_REPEAT(self):
        nums = [1,1,1,1,1]
        assert BinarySearch.find_first_occ(nums, 1) == 0
        assert BinarySearch.find_first_occ(nums, 0) == -1
        assert BinarySearch.find_first_occ(nums, 2) == -1

        nums.pop() # pop 1
        assert BinarySearch.find_first_occ(nums, 1) == 0

        nums.pop() # pop 1
        assert BinarySearch.find_first_occ(nums, 1) == 0

        nums.pop() # pop 1
        assert BinarySearch.find_first_occ(nums, 1) == 0

        nums.pop() # pop 1
        assert BinarySearch.find_first_occ(nums, 1) == 0

        nums.pop() # pop 1
        assert BinarySearch.find_first_occ(nums, 1) == -1

    def test_find_first_occ_COMPLEX(self):
        nums = [-1,2,2,2,3]
        assert BinarySearch.find_first_occ(nums, 2) == 1
        assert BinarySearch.find_first_occ(nums, 3) == 4

        nums.pop()  # pop 3
        assert BinarySearch.find_first_occ(nums, 2) == 1

        nums.pop()  # pop 2
        assert BinarySearch.find_first_occ(nums, 2) == 1
        
        nums.pop()  # pop 2
        assert BinarySearch.find_first_occ(nums, 2) == 1
        
        nums.pop()  # pop 2
        assert BinarySearch.find_first_occ(nums, 2) == -1
        assert BinarySearch.find_first_occ(nums, -1) == 0
    
    # --- test_find_last_occ ---

    def test_find_last_occ_REGULAR(self):
        nums = [-1,0,3,4]
        assert BinarySearch.find_last_occ(nums, -1) == 0
        assert BinarySearch.find_last_occ(nums, 0) == 1
        assert BinarySearch.find_last_occ(nums, 3) == 2
        assert BinarySearch.find_last_occ(nums, 4) == 3
        assert BinarySearch.find_last_occ(nums, 5) == -1
        assert BinarySearch.find_last_occ(nums, -2) == -1

    def test_find_last_occ_REPEAT(self):
        nums = [1,1,1,1,1]
        assert BinarySearch.find_last_occ(nums, 1) == 4
        assert BinarySearch.find_last_occ(nums, 0) == -1
        assert BinarySearch.find_last_occ(nums, 2) == -1

        nums.pop() # pop 1
        assert BinarySearch.find_last_occ(nums, 1) == 3

        nums.pop() # pop 1
        assert BinarySearch.find_last_occ(nums, 1) == 2

        nums.pop() # pop 1
        assert BinarySearch.find_last_occ(nums, 1) == 1

        nums.pop() # pop 1
        assert BinarySearch.find_last_occ(nums, 1) == 0

        nums.pop() # pop 1
        assert BinarySearch.find_last_occ(nums, 1) == -1

    def test_find_last_occ_COMPLEX(self):
        nums = [-1,2,2,2,3]
        assert BinarySearch.find_last_occ(nums, 2) == 3
        assert BinarySearch.find_last_occ(nums, 3) == 4

        nums.pop()  # pop 3
        assert BinarySearch.find_last_occ(nums, 2) == 3

        nums.pop()  # pop 2
        assert BinarySearch.find_last_occ(nums, 2) == 2
        
        nums.pop()  # pop 2
        assert BinarySearch.find_last_occ(nums, 2) == 1
        
        nums.pop()  # pop 2
        assert BinarySearch.find_last_occ(nums, 2) == -1
        assert BinarySearch.find_last_occ(nums, -1) == 0

    # --- test_find_lower_closest ---

    def test_find_lower_closest_REGULAR(self):
        nums = [-1,0,3,4]
        assert BinarySearch.find_lower_closest(nums, -2) == -1
        assert BinarySearch.find_lower_closest(nums, -1) == 0
        assert BinarySearch.find_lower_closest(nums, 0) == 1
        assert BinarySearch.find_lower_closest(nums, 1) == 1
        assert BinarySearch.find_lower_closest(nums, 2) == 1
        assert BinarySearch.find_lower_closest(nums, 3) == 2
        assert BinarySearch.find_lower_closest(nums, 4) == 3
        assert BinarySearch.find_lower_closest(nums, 5) == 3
        assert BinarySearch.find_lower_closest(nums, 6) == 3

    def test_find_lower_closest_REPEAT(self):
        nums = [1,1,1,1,1]
        assert BinarySearch.find_lower_closest(nums, 0) == -1
        assert BinarySearch.find_lower_closest(nums, 1) == 4
        assert BinarySearch.find_lower_closest(nums, 2) == 4
        assert BinarySearch.find_lower_closest(nums, 3) == 4

        nums.pop() # pop 1
        assert BinarySearch.find_lower_closest(nums, 1) == 3

        nums.pop() # pop 1
        assert BinarySearch.find_lower_closest(nums, 1) == 2

        nums.pop() # pop 1
        assert BinarySearch.find_lower_closest(nums, 1) == 1

        nums.pop() # pop 1
        assert BinarySearch.find_lower_closest(nums, 1) == 0

        nums.pop() # pop 1
        assert BinarySearch.find_lower_closest(nums, 1) == -1

    def test_find_lower_closest_COMPLEX(self):
        nums = [-1,0,2,2,2,3]
        assert BinarySearch.find_lower_closest(nums, 1) == 1
        assert BinarySearch.find_lower_closest(nums, 2) == 4
        assert BinarySearch.find_lower_closest(nums, 3) == 5

        nums.pop()  # pop 3
        assert BinarySearch.find_lower_closest(nums, 1) == 1
        assert BinarySearch.find_lower_closest(nums, 2) == 4
        assert BinarySearch.find_lower_closest(nums, 3) == 4

        nums.pop()  # pop 2
        assert BinarySearch.find_lower_closest(nums, 1) == 1
        assert BinarySearch.find_lower_closest(nums, 2) == 3
        assert BinarySearch.find_lower_closest(nums, 3) == 3
        
        nums.pop()  # pop 2
        assert BinarySearch.find_lower_closest(nums, 1) == 1
        assert BinarySearch.find_lower_closest(nums, 2) == 2
        assert BinarySearch.find_lower_closest(nums, 3) == 2
        
        nums.pop()  # pop 2
        assert BinarySearch.find_lower_closest(nums, -1) == 0
        assert BinarySearch.find_lower_closest(nums, 1) == 1
        assert BinarySearch.find_lower_closest(nums, 2) == 1
        assert BinarySearch.find_lower_closest(nums, 3) == 1

    def test_find_lower_closest_COMPLEX_2(self):
        nums = [-1,0,2,2,2,3,3]
        assert BinarySearch.find_lower_closest(nums, 1) == 1
        assert BinarySearch.find_lower_closest(nums, 2) == 4
        assert BinarySearch.find_lower_closest(nums, 3) == 6

        nums.pop(-3)  # pop 2
        assert BinarySearch.find_lower_closest(nums, 1) == 1
        assert BinarySearch.find_lower_closest(nums, 2) == 3
        assert BinarySearch.find_lower_closest(nums, 3) == 5

        nums.pop(-3)  # pop 2
        assert BinarySearch.find_lower_closest(nums, 2) == 2
        assert BinarySearch.find_lower_closest(nums, 3) == 4
        
        nums.pop(-3)  # pop 2
        assert BinarySearch.find_lower_closest(nums, 2) == 1
        assert BinarySearch.find_lower_closest(nums, 3) == 3
        
        nums.pop(-3)  # pop 0
        assert BinarySearch.find_lower_closest(nums, 2) == 0
        assert BinarySearch.find_lower_closest(nums, -1) == 0
        assert BinarySearch.find_lower_closest(nums, 3) == 2

    # --- test_find_upper_closest ---

    def test_find_upper_closest_REGULAR(self):
        nums = [-1,0,3,4]
        assert BinarySearch.find_upper_closest(nums, -2) == 0
        assert BinarySearch.find_upper_closest(nums, -1) == 0
        assert BinarySearch.find_upper_closest(nums, 0) == 1
        assert BinarySearch.find_upper_closest(nums, 1) == 2
        assert BinarySearch.find_upper_closest(nums, 2) == 2
        assert BinarySearch.find_upper_closest(nums, 3) == 2
        assert BinarySearch.find_upper_closest(nums, 4) == 3
        assert BinarySearch.find_upper_closest(nums, 5) == -1
        assert BinarySearch.find_upper_closest(nums, 6) == -1

    def test_find_upper_closest_REPEAT(self):
        nums = [1,1,1,1,1]
        assert BinarySearch.find_upper_closest(nums, 0) == 0
        assert BinarySearch.find_upper_closest(nums, 1) == 0
        assert BinarySearch.find_upper_closest(nums, 2) == -1
        assert BinarySearch.find_upper_closest(nums, 3) == -1

        nums.pop() # pop 1
        assert BinarySearch.find_upper_closest(nums, 1) == 0

        nums.pop() # pop 1
        assert BinarySearch.find_upper_closest(nums, 1) == 0

        nums.pop() # pop 1
        assert BinarySearch.find_upper_closest(nums, 1) == 0

        nums.pop() # pop 1
        assert BinarySearch.find_upper_closest(nums, 1) == 0

        nums.pop() # pop 1
        assert BinarySearch.find_upper_closest(nums, 1) == -1

    def test_find_upper_closest_COMPLEX(self):
        nums = [-1,0,2,2,2,3]
        assert BinarySearch.find_upper_closest(nums, 1) == 2
        assert BinarySearch.find_upper_closest(nums, 2) == 2
        assert BinarySearch.find_upper_closest(nums, 3) == 5

        nums.pop()  # pop 3
        assert BinarySearch.find_upper_closest(nums, 1) == 2
        assert BinarySearch.find_upper_closest(nums, 2) == 2
        assert BinarySearch.find_upper_closest(nums, 3) == -1

        nums.pop()  # pop 2
        assert BinarySearch.find_upper_closest(nums, 1) == 2
        assert BinarySearch.find_upper_closest(nums, 2) == 2
        assert BinarySearch.find_upper_closest(nums, 3) == -1
        
        nums.pop()  # pop 2
        assert BinarySearch.find_upper_closest(nums, 1) == 2
        assert BinarySearch.find_upper_closest(nums, 2) == 2
        assert BinarySearch.find_upper_closest(nums, 3) == -1
        
        nums.pop()  # pop 2
        assert BinarySearch.find_upper_closest(nums, -1) == 0
        assert BinarySearch.find_upper_closest(nums, 1) == -1
        assert BinarySearch.find_upper_closest(nums, 2) == -1
        assert BinarySearch.find_upper_closest(nums, 3) == -1

    def test_find_upper_closest_COMPLEX_2(self):
        nums = [-1,0,2,2,2,3,3]
        assert BinarySearch.find_upper_closest(nums, 1) == 2
        assert BinarySearch.find_upper_closest(nums, 2) == 2
        assert BinarySearch.find_upper_closest(nums, 3) == 5

        nums.pop(-3)  # pop 2
        assert BinarySearch.find_upper_closest(nums, 1) == 2
        assert BinarySearch.find_upper_closest(nums, 2) == 2
        assert BinarySearch.find_upper_closest(nums, 3) == 4

        nums.pop(-3)  # pop 2
        assert BinarySearch.find_upper_closest(nums, 2) == 2
        assert BinarySearch.find_upper_closest(nums, 3) == 3
        
        nums.pop(-3)  # pop 2
        assert BinarySearch.find_upper_closest(nums, 2) == 2
        assert BinarySearch.find_upper_closest(nums, 3) == 2
        
        nums.pop(-3)  # pop 0
        assert BinarySearch.find_upper_closest(nums, 2) == 1
        assert BinarySearch.find_upper_closest(nums, -1) == 0
        assert BinarySearch.find_upper_closest(nums, 3) == 1
