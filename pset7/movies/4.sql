SELECT count(title) from movies
where id IN (select movie_id from ratings where rating = 10.0);