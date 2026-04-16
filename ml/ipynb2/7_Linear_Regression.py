import numpy as np
import pandas as pd

from sklearn.datasets import load_iris
from sklearn.model_selection import train_test_split, KFold, StratifiedKFold
from sklearn.linear_model import LinearRegression
from sklearn.metrics import mean_squared_error, r2_score
from sklearn.utils import resample

iris = load_iris()
df = pd.DataFrame(iris.data, columns=iris.feature_names)

X = df[['sepal length (cm)', 'sepal width (cm)', 'petal width (cm)']]
y = df['petal length (cm)']

model = LinearRegression()

results = []

X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2)

model.fit(X_train, y_train)
pred = model.predict(X_test)

results.append([
    "Holdout Split",
    mean_squared_error(y_test, pred),
    r2_score(y_test, pred)
])

kf = KFold(n_splits=5)

mse_list, r2_list = [], []

for train, test in kf.split(X):
    model.fit(X.iloc[train], y.iloc[train])
    pred = model.predict(X.iloc[test])

    mse_list.append(mean_squared_error(y.iloc[test], pred))
    r2_list.append(r2_score(y.iloc[test], pred))

results.append([
    "K-Fold",
    np.mean(mse_list),
    np.mean(r2_list)
])

y_binned = pd.cut(y, bins=3, labels=False)
skf = StratifiedKFold(n_splits=5)

mse_list, r2_list = [], []

for train, test in skf.split(X, y_binned):
    model.fit(X.iloc[train], y.iloc[train])
    pred = model.predict(X.iloc[test])

    mse_list.append(mean_squared_error(y.iloc[test], pred))
    r2_list.append(r2_score(y.iloc[test], pred))

results.append([
    "Stratified K-Fold",
    np.mean(mse_list),
    np.mean(r2_list)
])

mse_list, r2_list = [], []

for i in range(5):
    X_boot, y_boot = resample(X, y)

    model.fit(X_boot, y_boot)
    pred = model.predict(X)

    mse_list.append(mean_squared_error(y, pred))
    r2_list.append(r2_score(y, pred))

results.append([
    "Bootstrap",
    np.mean(mse_list),
    np.mean(r2_list)
])

df_result = pd.DataFrame(results, columns=[
    "Validation", "MSE", "R2 Score"
])

print(df_result)
