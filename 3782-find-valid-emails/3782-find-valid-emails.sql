SELECT user_id, email
FROM Users
WHERE email ~'^[a-zA-Z0-9\_]+@[a-zA-Z]+\.com'