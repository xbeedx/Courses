SELECT title, rating
FROM movies
INNER JOIN ratings ON id = movie_id
WHERE year = 2010 AND rating IS NOT NULL
ORDER BY rating DESC, title;
