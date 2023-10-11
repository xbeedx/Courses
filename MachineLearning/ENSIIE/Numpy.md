# Numpy

* `numpy` est un module utilisé dans presque tous les projets de calcul numérique sous Python
   * Il fournit des structures de données performantes pour la manipulation de vecteurs, matrices et tenseurs plus généraux
   * `numpy` est écrit en C et en Fortran d'où ses performances élevées lorsque les calculs sont vectorisés (formulés comme des opérations sur des vecteurs/matrices)

```py
import numpy as np
```

## *Arrays* `numpy`

Dans la terminologie `numpy`, vecteurs, matrices et autres tenseurs sont appelés *arrays*.

## Création d'*arrays* `numpy`

Plusieurs possibilités:

 * a partir de listes ou n-uplets Python
 * en utilisant des fonctions dédiées, telles que `arange`, `linspace`, etc.
 * par chargement à partir de fichiers

### A partir de listes

Au moyen de la fonction `numpy.array` :
```py
# un vecteur: l'argument de la fonction est une liste Python
v = np.array([1, 3, 2, 4, 6, 8,4,4322])
print(v)
print(type(v))
```

Pour définir une matrice (array de dimension 2 pour numpy):
```py
# une matrice: l'argument est une liste emboitée
M = np.array([[1, 2], [3, 4]])
print(M)
```

Les objets `v` et `M` sont tous deux du type `ndarray` (fourni par `numpy`)

`v` et `M` ne diffèrent que par leur taille, que l'on peut obtenir via la propriété `shape` :
```py
v.shape
M.shape
```

Pour obtenir le nombre d'éléments d'un *array* :
```py
v.size
```

On peut aussi utiliser `numpy.shape` et `numpy.size`
```py
np.shape(M)
np.size(M)
```

Les *arrays* ont un type qu'on obtient via `dtype`:
```py
print(M)
print(M.dtype)
```

### Utilisation de fonction de génération d'*arrays*

#### arange
```py
# create a range
x = np.arange(0, 10, 2) # arguments: start, stop, step
x
```

#### linspace
```py
# avec linspace, le début et la fin SONT inclus
np.linspace(0, 10, 25)
```

#### Données aléatoires

il existe pas mal de génerateur pour avoir des nombres aléatoires
```py
from random import randint
print(randint(0, 9))
```

```py
from random import uniform

# uniform gives you a floating-point value
frand = uniform(0, 10)
print(frand)
```

```py
#Important : pour respecter un tirage dans une gaussienne
from random import gauss
mu, sigma = 4, 1 # mean and standard deviation
print(gauss(mu,sigma))
```

```py
from numpy import random

# tirage uniforme dans [0,1]
random.rand(5,5)  # ou np.random.rand

# tirage suivant une loi normale standard
random.randn(5,5)

# ou une loi normale custom
mu, sigma = 4, 1 # mean and standard deviation
print( np.random.normal(mu, sigma, 10))
```

Affichage de l'histogramme des tirages
```py
a = random.randn(10000)
hh = plt.hist(a, 40)
```

#### diag
```py
# une matrice diagonale
np.diag([1,2,3])
```

```py
# diagonale avec décalage par rapport à la diagonale principale
np.diag([1,2,3], k=-1)
```

#### zeros et ones

```py
np.zeros((3,), dtype=int)  # attention zeros(3,3) est FAUX
```

```py
np.ones((3,3)) *5
```


## Manipulation d'*arrays*

### Indexation

```py
# v est un vecteur, il n'a qu'une seule dimension -> un seul indice
v[0]
# M est une matrice, ou un array à 2 dimensions -> deux indices
M[1,1]
```


## *Slicing* ou accès par tranches

*Slicing* fait référence à la syntaxe `M[start:stop:step]` pour extraire une partie d'un *array* :

```py
A = np.array([1,2,3,4,5])
A[1:3]
```

## Extraction de données à partir d'*arrays* et création d'*arrays*

#### where

Un masque binaire peut être converti en indices de positions avec `where`

```py
x = np.arange(0, 10, 0.5)
print(x)
mask = (x > 5) * (x < 7.5)
print(mask)
indices = np.where(mask)
indices
```

#### diag

Extraire la diagonale ou une sous-diagonale d'un *array* :
```py
print(A)
np.diag(A)
```

## Algèbre linéaire

La performance des programmes écrit en Python/Numpy dépend de la capacité à vectoriser les calculs (les écrire comme des opérations sur des vecteurs/matrices) en évitant au maximum les boucles `for/while`

### Opérations scalaires

On peut effectuer les opérations arithmétiques habituelles pour multiplier, additionner, soustraire et diviser des *arrays* avec/par des scalaires :

```py
v1 = np.arange(0, 5)
v1 * 2
v1 + 2
```

### Visualiser des matrices

```py
C = random.rand(30,20)

plt.figure()
plt.imshow(C, interpolation='nearest')
plt.colorbar()
plt.show()
```

### Opérations terme-à-terme sur les *arrays*

Les opérations par défaut sont des opérations **terme-à-terme** :

```py
A = np.array([[n+m*10 for n in range(5)] for m in range(5)])
A * A # multiplication terme-à-terme
```

En multipliant des *arrays* de tailles compatibles, on obtient des multiplications terme-à-terme par ligne

### Algèbre matricielle

Comment faire des multiplications de matrices ? Deux façons :

 * en utilisant les fonctions `dot`; (recommandé)
 * en utiliser le type `matrix`. (à éviter)

```py
print(np.dot(A, A))  # multiplication matrice
print(A * A)  # multiplication élément par élément
```

Avec le type `matrix` de Numpy
```py
M = np.matrix(A)
v = np.matrix(v1).T # en faire un vecteur colonne
```

### Transformations d'*arrays* ou de matrices

 * Plus haut `.T` a été utilisé pour transposer l'objet matrice `v`
 * On peut aussi utiliser la fonction `transpose`

**Autres transformations :**

```py
C = np.matrix([[1j, 2j], [3j, 4j]])

np.conjugate(C)
```

Transposée conjuguée :
```py
C.H
```

Parties réelles et imaginaires :
```py
np.real(C) # same as: C.real
np.imag(C) # same as: C.imag
```

Argument et module :
```py
np.angle(C + 1)
np.abs(C)
```

### Caclul matriciel

### Analyse de données

Numpy propose des fonctions pour calculer certaines statistiques des données stockées dans des *arrays* :

```py
data = np.vander([1, 2, 3, 4])
print(data)
print(data.shape)
```

#### mean

```py
# np.mean(data)
print(np.mean(data, axis=0))

# la moyenne de la troisième colonne
np.mean(data[:,2])
```

#### variance et écart type

```py
np.var(data[:,2]), np.std(data[:,2]) 
```

#### min et max

```py
data.min(), data.max()
```

#### sum, prod, et trace

```py
data[:,2].sum(), data[:,2].prod()

# somme cumulée
np.cumsum(d)

# produit cumulé
np.cumprod(d + 1)

# équivalent à diag(A).sum()
np.trace(data)
```

### Calculs avec parties d'*arrays*

en utilisant l'indexation ou n'importe quelle méthode d'extraction de donnés à partir des *arrays*

```py
np.unique(data[:,3])

mask = data[:,1] == 4

np.mean(data[mask,3])
```

### Calculs aves données multi-dimensionnelles

Pour appliquer `min`, `max`, etc., par lignes ou colonnes :

```py
m = random.rand(3,4)

# max global
m.max()

# max dans chaque colonne
m.max(axis=0)

# max dans chaque ligne
m.max(axis=1)
```

Plusieurs autres méthodes des classes `array` et `matrix` acceptent l'argument (optional) `axis` keyword argument.

## Copy et "deep copy"

Pour des raisons de performance Python ne copie pas automatiquement les objets (par exemple passage par référence des paramètres de fonctions).

```py
A = np.array([[0,  2],[ 3,  4]])

# B = np.copy(A)
B = A.copy()
```

## Changement de forme et de taille, et concaténation des *arrays*

```py
n, m = A.shape  

B = A.reshape((1, n * m))
```

Pour transformer un *array* multi-dimmensionel en un vecteur. Mais cette fois-ci, une copie des données est créée :
```py
B = A.flatten()
```

### Ajouter une nouvelle dimension avec `newaxis`

par exemple pour convertir un vecteur en une matrice ligne ou colonne :

```py
# créer une matrice à une colonne à partir du vectuer v
v[:, np.newaxis]
``` 

### Concaténer, répéter des *arrays*

En utilisant les fonctions `repeat`, `tile`, `vstack`, `hstack`, et `concatenate`, on peut créer des vecteurs/matrices plus grandes à partir de vecteurs/matrices plus petites :

#### repeat et tile

```py
a = np.array([[1, 2], [3, 4]])

# répéter chaque élément 3 fois
np.repeat(a, 3) # résultat 1-d
```

Pour répéter la matrice, il faut utiliser `tile`
```py
# répéter la matrice 3 fois
np.tile(a, 3)
```

#### concatenate
```py
np.concatenate((a, b), axis=0)
```

## Itérer sur les éléments d'un *array*

 * Dans la mesure du possible, il faut éviter l'itération sur les éléments d'un *array* : c'est beaucoup plus lent que les opérations vectorisées

Pour obtenir les indices des éléments sur lesquels on itère (par exemple, pour pouvoir les modifier en même temps) on peut utiliser `enumerate` :
```py
for row_idx, row in enumerate(M):
    print("row_idx", row_idx, "row", row)
```

## Utilisation d'*arrays* dans des conditions

Losqu'on s'intéresse à des conditions sur tout on une partie d'un *array*, on peut utiliser `any` ou `all` :
```py
if (M > 5).any():
    print("au moins un élément de M est plus grand que 5")
else:
    print("aucun élément de M n'est plus grand que 5")

    if (M > 5).all():
    print("tous les éléments de M sont plus grands que 5")
else:
    print("tous les éléments de M sont plus petits que 5")
```

## *Type casting*

On peut créer une vue d'un autre type que l'original pour un *array*

```py
M2 = M.astype(float)
```

