SELECT COUNT(*) FROM movies
INNER JOIN ratings ON id = movie_id
WHERE rating = 10.0;