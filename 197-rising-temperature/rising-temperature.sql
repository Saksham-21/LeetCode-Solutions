select w2.id from Weather w1, Weather w2 where w2.temperature>w1.temperature AND DATEDIFF(w2.recordDate,w1.recordDate)=1


-- SELECT w2.id
-- FROM Weather w1
-- JOIN Weather w2 
--   ON w2.recordDate = w1.recordDate + INTERVAL 1 DAY
-- WHERE w2.temperature > w1.temperature;
