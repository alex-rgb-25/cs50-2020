select name from people
where id IN
(select person_id from directors
where movie_id in
 (select DISTINCT movie_id from ratings where rating>=9.0));