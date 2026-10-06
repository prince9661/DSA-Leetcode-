# Write your MySQL query statement below

select s.student_id, s.student_name, su.subject_name, count(e.subject_name) attended_exams  from students s 
cross join subjects su
left join examinations e on s.student_id =  e.student_id and su.subject_name = e.subject_name
GROUP BY su.subject_name, s.student_id
ORDER BY s.student_id, su.subject_name