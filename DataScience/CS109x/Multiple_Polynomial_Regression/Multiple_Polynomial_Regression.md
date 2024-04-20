#  Multilinear Regression

We want our models to take in lots of data as they make their predictions.

In practice, it is unlikely that any respons variable, Y, depends solely on one predictor, x. Rather, we expect that it is a function of multiple predictors, $f(X_1, ..., X_j)$.

$Y= y_1, ..., y_n$

$X = X_1, ..., X_j$

$X_j = x_{1j}, ..., x_{nj}$

In this case we can still assume a simple form for $f$ - a multiliner form:

$f(X_1, ..., X_j) = \beta_0 + \beta_1X_1 + ... + \beta_jX_j$

Hence, $\hat f$, has the form:

$\hat f(X_1, ..., X_j) = \hat \beta_0 + \hat \beta_1X_1 + ... + \hat \beta_jX_j$

# Least Squares Derivation

## Definition: Transpose of a Matrix

Given a 3x2 matrix:

$X = \begin{bmatrix} x_{11} &x _{12} \\ x_{21} & x_{22} \\ ... & ... \end{bmatrix}$

The trnaspsoe of X is:

$X^T = \begin{bmatrix} x_{11} & x_{21} & ... \\ x_{12} & x_{22} & ... \end{bmatrix}$

In transpose, rows become columns and columns become rows.

$X = \begin{bmatrix} x_{11} & x_{12} & x_{13} \\ x_{21} & x_{22} & x_{23} \\ x_{31} & x_{32} & x_{33} \end{bmatrix}$

$X^T = \begin{bmatrix} x_{11} & x_{21} & x_{31} \\ x_{12} & x_{22} & x_{32} \\ x_{13} & x_{23} & x_{33} \end{bmatrix}$

Use np.transpose() or ndarray.T

##  Definition: Inverse of a Matrix

- When we multiply a number by its reciprocal we get 1.

$n * \frac{1}{n} = 1$

- When we multiply a matrix by its inverse we get the identity matrix:

$A * A^{-1} = I$

numpy.linalg.inv() is used to calculate the inverse of a matrix. (if it exists)

# Multiple Linear Regression

The model takes a simple algebraic form: $Y = X\beta$

we will again use the MSE as our loss function, which can be expressed in vector notation as:

$$
MSE(\beta)= \frac{1}{n} ||Y-X\beta||^2
            = \frac{1}{n} \sum_{i=1}^{n} (y_i - x_{i1}\beta_1 - x_{i2}\beta_2)^2
$$

Taking the derivative of the loss i.e. MSE with respect to the model parameter  gives:
$$
\frac{\partial L}{\partial \beta} = -2X^T(Y-X\beta)
$$

For optimization, we set the values of the partial derivative to zero, i.e.

$\frac{\partial L}{\partial \beta} = 0 => -2X^T(Y-X\beta)=0$

$=> X^T(Y-X\beta)=0$

Optimization of the previous equation gives:
$X^TX\beta =X^TY$

Multiplying both sides with $(X^TX)^{-1}$, we get:

$(X^TX)^{-1}X^TX\beta =(X^TX)^{-1}X^TY$

Thus, we get:

$\beta = (X^TX)^{-1}X^TY$

Backtracking this equation to fit the model optimization problem, we have: 

$\hat \beta = (X^TX)^{-1}X^TY = \arg \min MSE(\beta)$

# Multilinear Techniques

## Qualitative predictors 

So far, we assumed that all variables are quantitatives. But in practice, often we have qualitative variables.

## Binary Variables

If the predictor takes only two values, then we can create and indicator or a dummy variable that takes only two possible numerical values. 

$$
x_i = \begin{cases} 1 & \text{if ith observation is in category A} \\ 0 & \text{if ith observation is in category B} \end{cases}
$$

we then use the variable as a predictor in the regression equation:

$$
y_i = \beta_0 + \beta_1x_1 = \begin{cases} \beta_0 + \beta_1 & \text{if ith observation is in category A} \\ \beta_0 & \text{if ith observation is in category B} \end{cases}
$$

- $\beta_0$ is the mean of the response variable for the observations in category B 
- $\beta_0 + \beta_1$ is the mean of the response variable for the observations in category A.
- $\beta_1$ is the difference in the means of the response variable between the two categories.

## More than two levels: One Hot Encoding

If the qualitative predictor has more than two levels, we can create additional dummy variables.

$$
x_{i1} = \begin{cases} 1 & \text{if ith observation is in category A} \\ 0 & \text{otherwise} \end{cases}
$$
$$
x_{i2} = \begin{cases} 1 & \text{if ith observation is in category B} \\ 0 & \text{otherwise} \end{cases}
$$

We then use the variables as predictors in the regression equation:

$$
y_i = \beta_0 + \beta_1x_{i1} + \beta_2x_{i2} = \begin{cases} \beta_0 + \beta_1 & \text{if ith observation is in category A} \\ \beta_0 + \beta_2 & \text{if ith observation is in category B} \\ \beta_0 & \text{if ith observation is in category C} \end{cases}
$$

- $\beta_0$ is the mean of the response variable for the observations in category C
- $\beta_1$ is the difference in the means of the response variable between the two categories A and C
- $\beta_2$ is the difference in the means of the response variable between the two categories B and C

# Interpreting Coefficients & Feature Importance

With a KNN model it is difficult to understand exactly what the relationship is between a feature and the response. But for linear models we can begin to understand this relationship by interpreting the model parameters!

Recall that these model parameters are the beta coefficients we learn when we fit our model.

When we have a large number of predictors: $X_1, ..., X_p$, there will be a large number of model parameters, $\beta_0,\beta_1, ..., \beta_p$.

Looking at all values of $\beta_i$ as a list of numbers is impractical, so we visualize these values in a feature importance graph.

The feature importance graph above shows which predictors have the most impact on the model’s prediction. Not only does it tell use about the magnitude of their impact but the sign on the parameter also tells us the direction of the relationship. We'll see in later sections however that such a naïve approach to coefficient interpretation may not be giving us the whole story. But this is a good place to start!

# Feature Scaling - Normalization and Standardization


## Normalization

Normalization, sometimes called Min-Max scaling, transforms the features to a predefined range. Typically, we normalize to between 0 and 1. This sets 0 for the lowest value in our data for that variable, sets 1 for the highest, and all other values to be a proportional float between 0 and 1. The formula for normalization is as follows:

$$
X_{norm} = \frac{X - X_{min}}{X_{max} - X_{min}}
$$

Note that we can also use sklearn's MinMaxScaler() to normalize our data.

## Standardization

Standardization transforms the features by subtracting the mean and dividing by the standard deviation. This sets the new mean to 0 with a standard deviation of 1.

$$
X_{std} = \frac{X - \bar{X}}{\sigma_X}
$$

