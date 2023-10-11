import numpy as np

## EXERCICE :
## Calculer une approximation de $\pi$ par la formule de Wallis sans boucle `for` avec Numpy


n = 10000000

i_values = np.arange(1, n + 1)
terms = (4 * i_values ** 2) / (4 * i_values ** 2 - 1)
pi_approx = 2 * np.prod(terms)

print(pi_approx)