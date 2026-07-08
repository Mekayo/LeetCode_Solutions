SELECT query_name,
        ROUND(AVG(rating / position), 2) as quality,
        ROUND(SUM(rating <3) / count(*) * 100, 2) as poor_query_percentage
FROM Queries
GROUP BY query_name