SELECT name
FROM stars
INNER JOIN movies ON movies.id = movie_id
INNER JOIN people ON people.id = person_id
WHERE title = 'Toy Story';