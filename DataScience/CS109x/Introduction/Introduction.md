# Introduction to Data Science with Python


## Getting Started

- Python External link, version 3.8 or higher.
- Pandas External link, any version that's compatible with your version of Python.
- Numpy External link, any version that's compatible with your version of Python.


## Linear regression

ISLP:   
    - Introduction pages 1 to 14 
    - Simple Linear Regression - Pages 61 to 64

### Introduction to regression

Predict one variable using another (or a set of other) variables.

### Response vs Predcitor variables

There is an asymmetry in many of these problems: 
    - The variable we would like to predict may be more difficult to measure, is more important than the other(s), or maybe directly or indirectly influenced by other varibles.

Thus, we'd liek to define two categories of variables: 
    - Variables whose value we want to predict => outcome/response variable/dependent variable => Y
    - Variables whose values we use to make our prediction => Predictors/Features/Covariates => X / data matrix
        => n observations for p predictors 

Capital letters mean matrices and lowercase letters mean vectors.

=> X.shape (n,p)
=> Y.shape (n,1) or (n,)


### Conencting with Pandas 

df[['x']] returns a pd.DataFrame object
df['x'] returns a pd.Series object 


### True vs Statistical Model 

We will assume that the response variable, Y, relates to the predictors, X, through some unknown function, f(X), which expresses an underlying rule for relating Y to X and a random amount ε (unrelated to X) that describes the difference Y from the rule f(X). 

$$
Y = f(X) + \epsilon
$$


### Prediction vs Estimation 

When we use a set of measurements, $(x_{i1}, ..., x_{ip})$ to predict a value for the response variable, we denote the predicted value by; 
$$
\hat{y_i} = \hat{f}(x_{i1}, ..., x_{ip})
$$

the hat denotes an estimate.

For some problems, what's important is obtaining $\hat{f}$, our estimate of $f$. These are called inference problems. 

For some problems, we don't care about the specific form of $f$, we just want to make our predictions $\hat{y}$'s as close to the observed values $y$'s as possible. These are called prediciton problems. 

### Statistical Model 

A simple idea is to take the mean of all $y$'s: $1/n\sum y_i$

### k-Nearest neighbors - kNN

What is $\hat{y_q}$ at some $x_q$?

Find distances to all other points $D(x_q,x_i)$.

Find the nearest neighbor, $(x_p,y_p)$.

Predict $\hat{y_q} = y_p$.

Generalizing, we take the k nearest neighbors, find the y values and average them. We measure the distance to all other points and find the k nearest neighbors and take the average of the y values of the k nearest neighbors.

kNN is a non-parametric learning algorithm, meaning that there is no assumptions about the underlying data distribution. The k-Nearest Neighbor Algorithm can be described more formally. Given a dataset $D = (X_1,y_1),..., (X_n,y_n)$, for every new $X$:


1. Find the k-number of observations in $D$ most similar to $X$:
 $(X^{(n_1)},y^{(n_1)}),..., (X^{(n_k)},y^{(n_k)})$
 <br>These are called the k-nearest neighbors of $x$.

2. Average the output of the k-nearest neighbors of $x$:
 $\hat{y}=1/K\sum y^{(n_k)}$

## Data Typing 

\<data frame>
\<series>
\<numpy array>

Every column in a \<data frame> is a \<series>.
Selecting multiple columns returns a \<data frame>.

## Spaghetti Preditions 

When plotting prediction lines values must be order. 

Make a copy of your data set and sort the data before plotting.

Or user linspace:
numpy.linspace(start, stop, num=50, endpoint=True, retstep=False, dtype=None, axis=0)
x1 = nb.linspace(0, 10, 500, endpoint=True)

linspace creates an array of ordered and evenly spaced values. 
It also allows to see predictions where there may be gaps in the data. 