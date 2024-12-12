SELECT *
FROM Users
WHERE mail REGEXP '^[a-zA-Z][a-zA-Z\\d_\.\-]*@leetcode\\.com$'