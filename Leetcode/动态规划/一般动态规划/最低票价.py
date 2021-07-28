class Solution:
    def mincostTickets(self, days: List[int], costs: List[int]) -> int:
        @lru_cache(None) 
        def dp(i):                      #dp(i)表示返回days[0...end]旅行所需的最低消费
            if i>=end+1:return  0       #超出旅行计划，不再买票
            ans=0
                                        #ans=min(选择买一天票，选择买七天票，选择买30天票)
            if i in days:               #这天在旅行计划
                ans=min(dp(i+1)+costs[0], dp(i+7)+costs[1],dp(i+30)+costs[2]) 
            else:                       #这天不在旅行计划，可以不用花钱买票，直接进入下一天
                ans=dp(i+1)         
            return ans 

        end=days[-1]
        return dp(1)                    #从第一天开始

