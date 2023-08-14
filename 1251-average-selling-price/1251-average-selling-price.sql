# Write your MySQL query statement below


Select p.product_id, round(sum(p.price*us.units)*1.0 / sum(us.units), 2) as average_price 
FROM Prices as p
LEFT JOIN
UnitsSold as us 
ON us.product_id = p.product_id AND us.purchase_date BETWEEN p.start_date AND p.end_date
GROUP BY p.product_id;