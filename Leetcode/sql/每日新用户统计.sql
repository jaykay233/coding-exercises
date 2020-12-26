-- Write your MySQL query statement below

select a.login_date, sum(a.cnt) as user_count from 
(
    select user_id, 1 as cnt, min(activity_date) as login_date from Traffic where activity='login' group by user_id
) a where datediff('2019-06-30',a.login_date) <= 90 group by a.login_date; 
