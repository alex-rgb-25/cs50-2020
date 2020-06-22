select movies.title, ratings.rating from movies
inner join ratings on movies.id=ratings.movie_id
where movies.year=2010 AND rating IS NOT NULL
order by rating desc, title;