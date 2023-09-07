/*SQL Equivalent of python's range function. Note that this is computationally highly intensive,
  so this might be not the optimal solution for large queries.
*/
WITH RecursiveRange AS (
    SELECT start_num AS num
    UNION ALL
    SELECT num + 1
    FROM RecursiveRange
    WHERE num < end_num  -- N is the desired end number in the range
)

