"""
Definition of Interval:
class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end
"""

class Solution:
    def canAttendMeetings(self, intervals: List[Interval]) -> bool:
        
        # i have to use a lambda function because these are objects if not then i can just use sort()
        intervals.sort(key=lambda x: x.start)
        # then i can compare the end and thstart starting from the first i
        i = 1
        while i < len(intervals):

            if intervals[i].start < intervals[i-1].end:
                return False
            i += 1

        return True