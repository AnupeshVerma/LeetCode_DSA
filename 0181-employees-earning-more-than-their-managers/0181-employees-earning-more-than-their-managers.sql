
###### METHOD 1 ######

# SELECT e1.name as 'Employee'
# FROM Employee as e1
# WHERE e1.salary > (SELECT salary 
#                    FROM Employee AS e2
#                    WHERE e2.id = e1.managerId);
                   
                   
###### METHOD 2 ######
SELECT e1.name as 'Employee'
FROM Employee AS e1, Employee AS e2
WHERE e1.managerId = e2.id AND e1.salary > e2.salary;