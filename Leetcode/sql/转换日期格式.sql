-- https://leetcode-cn.com/problems/convert-date-format/solution/mysql-ri-qi-ge-shi-hua-date_formathan-sh-lvf0/
SELECT DATE_FORMAT(day, '%W, %M %e, %Y') AS 'day'
FROM Days