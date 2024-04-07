# Introduction to Data Science with Python


## Getting Started

- Python External link, version 3.8 or higher.
- Pandas External link, any version that's compatible with your version of Python.
- Numpy External link, any version that's compatible with your version of Python.


# Introduction to regression

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

# Error Evaluation and Model Comparison

## Error Evaluation

Estimate $\hat{y}$ for $k=1$

The difference between the true values and the predictions is called the residual.

For each observation $(x_n,y_n)$, the absolute residual $r_i = |y_i - \hat{y_i}|$ quantify the error at each observation.

In order to quantify how well a model performs, we aggregate the errors and we call that the loss or error or cost function.

A common loss function for quantitative outcomes is the Mean Squared Error (MSE): 

$MSE = 1/n\sum(y_i - \hat{y_i})^2$

Cost usually refers to the total loss where loss refers to a single training point.

The square Root of the Mean of the Squared Errors (RMSE) is also commonly used.

$RMSE =  \sqrt{MSE} = \sqrt{\frac{1}{n}\sum(y_i - \hat{y_i})^2}$

## Model Fitness

We will use the simplest model:

$\hat{y} = \bar{y} = 1/n\sum y_i$ 

as the worst possible model and:

$\hat{y} = y_i$

as the best possible model.

$R-squared = 1 - \frac{\sum{(\hat{y_i} - yi)^2},2}{\sum{(\bar{y_i} - yi)^2}}$

- If our model is as good as the mean value, $\bar{y}$ then $R-squared = 0$.

- If our model is perfect, then $R-squared = 1$.

$R^2$ can be negative if the model is worse than the average.

## KNN - Real Estate 

How to handle categorical variables in KNN?

A solution is to get the Hamming distance, calculating the difference between categories.

## Exploratory Data Analusis

What happens if your R-squared value is low, but you expected there to be a connection between the variables you're measuring? Sometimes just looking at a single number isn't enough.

Using a simple straight line might not be complex enough to capture the relationship between the variables.

The correlation coefficient assumes a linear relationship.

# Linear Models

Note that in the building of our kNN model for prediction (non-parametric), we did not compute a closed form for $\hat{f}$.

What if we ask the question, "how much more sales do we expect if we double the TV advertising budget?"

We can build a model by first assuming a simple form of $f$: 

$f(x) = \beta_0 + \beta_1X$

where $\beta_0$ is the intercept and $\beta_1$ is the slope. It then follow that our estimate is:

$\hat{Y} = \hat{f}(x) = \hat{\beta_0} + \hat{\beta_1}X$

where $\hat{\beta_0}$ and $\hat{\beta_1}$ are the estimates of $\beta_0$ and $\beta_1$, respectively, which we compute using bservations.

## Estimate of the regression coefficients

For a given data set we can darw different lines, but which one is the best?

To decide which is the best line, we can do the same as we did with the kNN model. We estimate the error for every model by looking at the residuals, the difference between the exact value of $y$ and the predicted $y$. As shown in the plot below, the regression or model line, predicted sales, is the slanted line in green and the residuals to the exact values of sales are the vertical red lines.

As before, for each observation $(x_n,y_n)$, the absolute residual $r_i = |y_i - \hat{y_i}|$ quantify the error at each observation.

Again, we aggregate and use the Mean Squared Error, MSE, as our loss function.

$L(\beta_0 , \beta_1) = \frac{1}{n}\sum(y_i - \hat{y_i})^2$

The difference from the kNN model is that there is a specific formula for the $\hat{y}$, which is the linear model.

We choose the $\beta_0$ and $\beta_1$ that minimize the loss function.

The the values of $\beta_0$ and $\beta_1$ should be:

$\hat{\beta_0}, \hat{\beta_1}=\arg \min L(\beta_0,\beta_1)$

We call this "fitting" or "training" the model.

# Introduction Sckikit-Learn

We can do the model training using the scikit-learn library. 

First we import the linear regression module

```python
from sklearn.linear_model import LinearRegression
```

We use pandas and the method read_csv to read the advertising data and assign it to a data frame which we call df

```python
df = pd.read_csv('Advertising.csv')
```

We take the TV column and the sales column and assign the series to $X$ and $y$.

```python
X = df[['TV']]
y = df['sales']
```

We instantiate the model by using linear regression and call it reg
    
```python
reg = LinearRegression()
```

We use now that model to fit the data by passing the data $X$ and $y$

```python
reg.fit(X,y)
```

Once we have fitted the model we can use the same variable, reg, to take the attribute coefficients to see the slope and intercept. The underscore is used to see the slope.

```python
reg.coef_
reg.intercept_
```

We can use the method predict to predict at any given $x$ what would be the value of $y$

```python
reg.predict(np.array([[100]]))
```

What is happening behind the scenes? This code is hiding a lot of things, and we should investigate what's happening at the .fit method in order to understand how we find the $\beta_0$ and $\beta_1$ that minimizes the loss function.

## Calculus Review 
### Derivative function 

First we have to review some concepts. A derivative is the instantaneous rate of change or slope of a single valued function given. Given a function $f(x)$ the derivative can be defined as the slope as the two points come closer to each other where the difference is 0:

$f'(x)=\frac{df}{dx} = \lim_{h \to 0} \frac{f(x+h) - f(x)}{h}$

### Partial Derivatives

Another concept is the partial derivative. The partial derivative is for a function that depends on two or more variables. The rate of change of a function with respect to one variable while the other is fixed is called a partial derivative.

For a function $f$, the partial derivative is written as
$$\frac{\partial f}{\partial x_i}$$

So, we have a function that depends on $x_{1}$ and $x_{2}$ the partial derivative of f with respect to $x_{1}$ is the slope when $x_{2}$ is kept fixed and the partial derivative of f with respect to $x_{2}$ is the slope when $x_{1}$ is kept fixed.

$$ 
f(x_{1},x_{2}) = \frac{\partial f}{\partial x_1} for x_1 
\frac{\partial f}{\partial x_2} for x_2
$$

## Optimization 

n our simple linear regression, our loss functions depend on $\beta_0$ and $\beta_1$. To minimize a loss function, we need to determine the rate of change of the function with respect to one variable with the others held fixed.

The global minima or maxima of the loss function $L(\beta_0,\beta_1)$ must occur at a point where the gradient (slope) is equal to zero, so the partial derivatives here must be equal to zero.

$\triangledown = [\frac{\partial f}{\partial x_1},\frac{\partial f}{\partial x_2}] = 0$

There are three ways we can do this:

- Brute force: Try every combination of $\beta_0$ and $\beta_1$ and find where both partial derivatives are equal to 0
- Exact: Solving the above equations only works for rare cases. Since there are 2 equations and 2 unknowns in our example, it is solvable.
- Greedy Algorithm: Gradient descent will be discussed later


### Partial derivative example

For our linear regression, we are going to solve it analytically exactly. We start with the loss function that depends on $\beta_0$,$\beta_1$  and want the partial derivatives with respect to $\beta_0$ and $\beta_1$

If $L(\beta_0,\beta_1) = (y - (\beta_1x+ \beta_0))^2$
then what are $\frac{\partial L}{\partial \beta_0}$ and $\frac{\partial L}{\partial \beta_1}$?

We need the chain rule to solve this. The chain rule says that if a function depends on another function that depends on a variable, the partial derivative of the original function with respect to the variable is the product of two partial derivatives. The first is the partial derivative of the function with the intermediate function multiplied by the partial derivative of the intermediate function with respect to that variable.

We can use that chain rule to derive the partial derivatives of the loss function with respect to $\beta_0$ and the partial derivative of the loss function with respect to $\beta_1$

If $L(\beta_0,\beta_1) = (y - (\beta_1x+ \beta_0))^2$
then what is $\frac{\partial L}{\partial \beta}$

$\frac{\partial L(f(\beta_0))}{\partial \beta_0} = \frac{\partial L}{\partial f}\frac{\partial f}{\partial \beta_0}$

#### $\frac{\partial L}{\partial \beta_0}$

We can use some algebra 

If $L(\beta_0,\beta_1) = (y - (\beta_1x+ \beta_0))^2$
then what is $\frac{\partial L}{\partial \beta_0}$

$L = (y - (\beta_1x+ \beta_0))^2$

where $f = y - (\beta_1x+ \beta_0)$ and $L = f^2$

$\frac{\partial L}{\partial \beta_0} = \frac{\partial L}{\partial f}\frac{\partial f}{\partial \beta_0}$

$L = f^2$

$\frac{\partial L}{\partial f} = 2f$

$f = y - (\beta_1x+ \beta_0)$

$\frac{\partial f}{\partial \beta_0} = -1$

$\frac{\partial L}{\partial \beta_0} = \frac{\partial L}{\partial f}\frac{\partial f}{\partial \beta_0} = -2f = -2(y - \beta_1x + \beta_0)$

#### $\frac{\partial L}{\partial \beta_1}$

We can use the same algebra used for $\beta_0$ to find $\frac{\partial L}{\partial \beta_1}$ 

If $L(\beta_0,\beta_1) = (y - (\beta_1x+ \beta_0))^2$
then what is $\frac{\partial L}{\partial \beta_1}$

$L = (y - (\beta_1x+ \beta_0))^2$

where $f = y - (\beta_1x+ \beta_0)$ 

$\frac{\partial L}{\partial \beta_1} = \frac{\partial L}{\partial f}\frac{\partial f}{\partial \beta_0}$

$L = f^2$

$\frac{\partial L}{\partial f} = 2f$

$f = y - (\beta_1x+ \beta_0)$

$\frac{\partial f}{\partial \beta_1} = -x$

$\frac{\partial L}{\partial \beta_1} = \frac{\partial L}{\partial f}\frac{\partial f}{\partial \beta_1} = -2f = -2(y - \beta_1x + \beta_0)$

## Optimization 

In order to minimize the loss function, we end up with two equations, one being the partial derivative with respect to $\beta_0$ and the other with respect to $\beta_1$. Where the partial derivatives are zero, minimizes the loss function.

$\triangledown = [\frac{\partial f}{\partial x_1},\frac{\partial f}{\partial x_2}] = 0$

$\frac{\partial L}{\partial \beta_0} = -2(y - \beta_1x + \beta_0) = 0$

$\frac{\partial L}{\partial \beta_1} = -2x(y - \beta_1x + \beta_0) = 0$

Putting it through the algebraic machine, we get the values of $\beta_0$ and $\beta_1$ that minimize the loss function.

$\hat\beta_1 = \frac{\sum(x_i - \bar{x})(y_i - \bar{y})}{\sum(x_i - \bar{x})^2}$

$\hat\beta_0 = \bar{y} - \hat\beta_1\bar{x}$

## Summary: Estimate of the regression coefficients

We use MSE as our loss function,

$L(\beta_0 , \beta_1) = \frac{1}{n}\sum(y_i - \hat{y_i})^2 = \frac{1}{n}\sum(y_i - [\beta_1x_i - \beta_0])^2$

We choose $\beta_0$ and $\beta_1$ to minimize the predictive errors made by our model. i.e. minimize our loss function.

Then the optimal values for $\beta_0$ and $\beta_1$ should be:

$\hat{\beta_0}, \hat{\beta_1}=\arg \min L(\beta_0,\beta_1)$

Remember, we call this fitting or training the model.

## Estimate of the regression coefficients: analytical solution

We calculate the partial derivatives and equate them to zero. Using algebra we find the values of $\beta_0$ and $\beta_1$.

Finding the exact solution only works in rare cases. Linear regression is one of these rare cases.

Take the gradient of the loss function and find the values of $\beta_0$ and $\beta_1$ where the gradient is zero:

$\triangledown = [\frac{\partial f}{\partial x_1},\frac{\partial f}{\partial x_2}] = 0$

$\begin{bmatrix} -\sum x_i(y_i - \beta_1x_i - \beta_0) \\ -\sum(y_i - \beta_1x_i - \beta_0) \end{bmatrix} = 0$

$\begin{bmatrix}-x_i\\-1\end{bmatrix} = 0$

$\hat\beta_1 = \frac{\sum(x_i - \bar{x})(y_i - \bar{y})}{\sum(x_i - \bar{x})^2}$

$\hat\beta_0 = \bar{y} - \hat\beta_1\bar{x}$

where $\bar y$ and $\bar x$ are sample means.

The line which uses the $\beta_0$ and $\beta_1$ 

$\hat{Y} = \hat{\beta_0} + \hat{\beta_1}X$

is called the regression line.