# Write your MySQL query statement below
-- Problem: Find customers who placed the highest number of orders
SELECT customer_number
FROM Orders
GROUP BY customer_number
HAVING COUNT(*) = (
   SELECT MAX(order_count)
   FROM (SELECT customer_number, COUNT(*) AS order_count FROM Orders GROUP BY customer_number) AS subquery
);