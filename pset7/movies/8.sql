select name
from people
where id IN
 (select person_id from stars where movie_id=(select id
 from movies where title = "Toy Story"));