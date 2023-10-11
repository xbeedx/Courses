import numpy as np                    
import matplotlib.pyplot as plt      

# Chargement des données disponible dans le package sklearn
from sklearn.datasets import load_digits

digits = load_digits()
X, y = digits.data, digits.target

print(X.dtype)
print(X.shape)
print(y.shape)


print("Nombre de pixels : ")
#code
print("Nombre d'observations : ")
#code
print("Nombre de classes : ")
#code


idx_to_test = 532
#affichage de la ligne correspondante
#code
#affichage de la classe
#code