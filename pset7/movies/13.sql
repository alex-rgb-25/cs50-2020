select distinct name from people where name is not 'Kevin Bacon' and id in
(select person_id from stars where movie_id in
(select movie_id from stars where person_id in
(select id from people where name is 'Kevin Bacon' and birth= 1958)))
intersect
select distinct name from people where id and name is not 'Kevin Bacon' in
(select person_id from stars where movie_id in
(select movie_id from stars where person_id in
(select id from people where name is not 'Kevin Bacon')))
order by name