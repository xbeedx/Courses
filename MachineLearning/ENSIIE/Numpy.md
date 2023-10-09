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
