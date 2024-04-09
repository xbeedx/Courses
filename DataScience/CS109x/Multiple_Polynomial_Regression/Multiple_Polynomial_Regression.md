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