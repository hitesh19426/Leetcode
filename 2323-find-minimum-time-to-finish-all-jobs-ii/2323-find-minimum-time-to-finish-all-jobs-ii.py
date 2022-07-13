class Solution:
    def minimumTime(self, jobs: List[int], workers: List[int]) -> int:
        jobs.sort()
        workers.sort()
        
        ans = 0
        for i in range(0, len(jobs)):
            ans = max(ans, int(ceil(jobs[i]/workers[i])))
        return ans