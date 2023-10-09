print("Compter le nombre d'occurences de chaque charactère dans la chaîne de caractères \"HelLo WorLd!!\" On renverra un dictionaire qui à la lettre associe son nombre d'occurences.")

s = "HelLo WorLd!!"
dico ={}

dico = {char: s.count(char) for char in set(s.lower())}

print(dico)

print("-----------------------------------------------------------------------------",end="\n\n")


print("Ecrire un code de codage et de décodage")

code = {'e':'a', 'l':'m', 'o':'e'}
s = 'Hello world!'
print("s = 'Hello world!'")

# s_code = 'Hamme wermd!'

s_code = ''.join(code[c] if c in code else c for c in s)

print(s_code)
       
decode = {v: k for k, v in code.items()}

s_uncode = ''.join(decode[c] if c in decode else c for c in s_code)

print(s_uncode)

print("-----------------------------------------------------------------------------",end="\n\n")


print("Calculer une approximation de $\pi$ par la formule de Wallis")
n=10000
pi= 4/3.
for i in range(2,n):
    pi *= (4 * (i**2))/((4. * (i**2))-1)
print("pi",pi*2)

