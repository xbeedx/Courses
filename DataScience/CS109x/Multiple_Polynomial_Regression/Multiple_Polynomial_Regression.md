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

Note that we can also use sklearn's StandardScaler() to standardize our data.

### Normalization vs Standardization

Standardization implies a Gaussian (or Normal) distribution. It can be more helpful when the data also follows a Gaussian distribution. Most data does follow a Gaussian distribution but this is not necessarily true. Standardization is also less impacted by outliers since there is no predefined range of features.

Normalization is recommended for data that already has a fixed range. Such as a survey question with values that can only be between 1 and 10. Data that does not follow a Gaussian distribution may work better with Normalization as well. Normalization is more vulnerable to outliers than standardization.

However, these are just rules of thumb to provided you with some intuition. It is often fine to simply try both and figure out what works best for your data.

# Multicolinearity

Collinearity and multicollinearity refer to the case in which two or more predictors are correlated. As one predictor increases or decreases, the other one always follows it.

One question we may have is, "how are these predictors related to one another?" This is an important to know as high multicolinearity can complicate the interpretation of our model's parameters as we'll see

Pairplot is a common visualization method for exploring possible correlations between our predictors.

The off-diagonal subplots contain scatter plots showing how pairs of predictors are related. On the diagonal we have histograms displaying the distribution of values in our data for each predictor

One way to think about this problem is that several coefficients contain the same information. Diagnostic methods like the pairplot can help us identity multicolinearity and remove redundant predictors, giving us a more interpretable model.

# Polynomial Regression

## Fitting non-linear data

Multi-linear models can fit large datasets with many predictors. However the relationship between predictor and target isn't always linear.

We want a model: $y = f_\beta(x)$ 

where $f$ is a non-linear function and $\beta$ is a vector of the parameters of $f$.

## Polynomial Regression

The simplest non-linear model we can consider, for a response Y and a predictor X, is a polynomial model of degree M,

$y= \beta_0 + \beta_1x + \beta_2x^2 + ... + \beta_Mx^M$

Just as in the case of linear regression [with cross terms], polynomial regression is a special case of linear regression - we treat each $x^M$ as a separate predictor. Thus, we can write the design matrix as:

$X = \begin{bmatrix} 1 & x_1 & x_1^2 & ... & x_1^M \\ 1 & x_2 & x_2^2 & ... & x_2^M \\ ... & ... & ... & ... & ... \\ 1 & x_n & x_n^2 & ... & x_n^M \end{bmatrix}$

This looks a lot like multi-linear regression, where the predictors are powers of x!

## Model Training

Given a dataset $(x_1, y_1), ..., (x_n, y_n)$  to find the optimal polynomial model:
$y= \beta_0 + \beta_1x + \beta_2x^2 + ... + \beta_Mx^M$:

1. We transform the data by adding new predictors:
$\tilde{x} = [1, \tilde{x_1},...,\tilde{x_M}]$

2. We find the parameters $(\beta_0,\beta_1)$  by minimizing the $MSE$ using vector calculus as in multi-linear regression:

$\hat\beta = (\tilde{X}^T\tilde{X})^{-1}\tilde{X}^Ty$

## Polynomial Regression Example

Fitting a polynomial model requires choosing a degree. We want to use a degree high enough to be able to fit to the complexities of our data. However, if we use a polynomial degree too high we will overfit to our training data. This means that the model has fit to the noise in the training data and predictions will not generalize to new data. Consider the following plots:

![](https://courses.edx.org/assets/courseware/v1/d779c3493d1f26c93fcde55155972ac4/asset-v1:HarvardX+CS109x+1T2022+type@asset+block/7_Multi-linear_regression_slide6_Light.svg)

Degree 1 is underfitting. The degree is too low, the model cannot fit the trend. The line cuts directly through the center of the data without following the curve at all. Note that using a polynomial degree of 1 is equivalent to just using simple linear regression without polynomials.

Degree 50 is overfitting. The degree is too high, the model fits all the noisy data points. The line is jagged as the model predictions overcompensate for small changes in the data.

Degree 2 is a good fit for this data. We want a model that fits the trend and ignores the noise. The line flows smoothly through the approximate center of the data points.

## Feature Scaling

Do we need to scale out features for polynomial regression?

Linear regression, $Y = X\beta$, is invariant under scaling. If $X$ is multiplied by some number $\lambda$, then $\beta$ is divided by $\lambda$ and the $MSE$ will be identical.

However, if the range of $X$ is small or large, then we run into troubles. Consider a polynomial degree of 20 and the maximum or minimum value of any predictor is large or small. Those numbers to the 20th power will be problematic. They may even be bigger than the biggest number Python can handle.

It is always a good idea to scale $X$  when considering a polynomial regression:

$X_{std} = \frac{X - \bar{X}}{\sigma_X}$ 

$X_{norm} = \frac{X - X_{min}}{X_{max} - X_{min}}$

For standardization, note that we can use sklearn's StandardScaler() to do this.
For normalization, note that we can use sklearn's MinMaxScaler() to do this.

## Evaluation: Training Error

Just because we found the model that minimizes the squared error it doesn't mean that it's a good model. We investigate the $R^2$ , but we also need to look at the data. For instance, in this first graph the MSE is high due to noise in the data.

![](https://courses.edx.org/assets/courseware/v1/f7b525772a2ed17897aa16d19f579c01/asset-v1:HarvardX+CS109x+1T2022+type@asset+block/7_Multi-linear_regression_slide10a_Light.svg)

In these next graphs the MSE is high in all four models, but the models are not equal! Examining the data directly will tell us as much about our model's fit as the MSE.

![](https://courses.edx.org/assets/courseware/v1/b3121339c830d77e8168dd97b383caa3/asset-v1:HarvardX+CS109x+3T2023a+type@asset+block/7_Multi-linear_regression_slide10b_Light.svg)

## Evaluation: Test Error

We need to evaluate the fitted model on our new data, data that the model did not train on. This is the test data.

![](https://courses.edx.org/assets/courseware/v1/d657901c90354b420907c98c9aadbdde/asset-v1:HarvardX+CS109x+1T2022+type@asset+block/7_Multi-linear_regression_slide11_Light.svg)

The training MSE here is 2.0 where the test MSE is 12.3. The training data contains a strange point – an outlier – which confuses the model.

Fitting to meaningless patterns in the training is called overfitting.

## Evaluation: Model Interpretation

For linear models it’s important to interpret the parameters

![](https://courses.edx.org/assets/courseware/v1/3b4c5b5d5cd472922d66a2f36d857ad3/asset-v1:HarvardX+CS109x+1T2022+type@asset+block/7_Multi-linear_regression_slide12_Light.svg)

In the left-hand graph, the MSE of the model is very small. But the slope is -0.05. That means the larger the budget the less the sales, which seems unlikely.

In the right-hand graph, the MSE is very small, but the intercept is -0.5, which means that for very small budget we will have negative sales, which is impossible.