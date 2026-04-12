SELECT 
    p.product_id,
    CASE
        WHEN SUM(u.units) IS NULL THEN 0
        ELSE ROUND(1.0*SUM(p.price * u.units) / SUM(u.units), 2)
    END AS average_price
FROM Prices p
LEFT JOIN UnitsSold u ON u.product_id = p.product_id 
AND purchase_date BETWEEN p.start_date AND p.end_date
GROUP BY p.product_id