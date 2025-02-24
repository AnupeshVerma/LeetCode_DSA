SELECT
    (SELECT product_name FROM Product WHERE product_id = s.product_id),
    s.year,
    s.price
FROM Sales AS s;
