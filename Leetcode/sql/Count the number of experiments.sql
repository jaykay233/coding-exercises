select
    p.platform,
    en.experiment_name,
    count(e.experiment_id) as num_experiments
from
(
    select 'Android' as platform
    union all
    select 'IOS'
    union all
    select 'Web'
) p 
cross join
(
    select 'Reading' as experiment_name
    union all
    select 'Sports'
    union all
    select 'Programming'
) en
left join experiments e on
    p.platform=e.platform and 
    en.experiment_name = e.experiment_name
group by p.platform, en.experiment_name;
