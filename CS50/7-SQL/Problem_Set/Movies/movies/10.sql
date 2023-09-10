SELECT name
FROM directors
INNER JOIN movies ON movies.id = directors.movie_id
INNER JOIN people ON people.id = directors.person_id
INNER JOIN ratings ON ratings.movie_id = movies.id
WHERE rating >= 9.0;