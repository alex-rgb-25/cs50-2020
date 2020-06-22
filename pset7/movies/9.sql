select name from people
where id IN
 (select DISTINCT person_id from stars where movie_id IN
 (select id from movies where year = 2004))
 order by birth;