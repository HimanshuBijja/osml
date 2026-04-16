import numpy as np
import pandas as pd

from sklearn.datasets import load_iris
from sklearn.model_selection import train_test_split, KFold, StratifiedKFold
from sklearn.tree import DecisionTreeClassifier
from sklearn.metrics import accuracy_score, precision_score, recall_score, f1_score
from sklearn.utils import resample

iris = load_iris()
X = iris.data
y = iris.target

dt = DecisionTreeClassifier()

results = []

X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2)

dt.fit(X_train, y_train)
pred = dt.predict(X_test)

results.append([
    "Holdout Split",
    accuracy_score(y_test, pred),
    precision_score(y_test, pred, average='macro'),
    recall_score(y_test, pred, average='macro'),
    f1_score(y_test, pred, average='macro')
])

kf = KFold(n_splits=5)

acc, pre, rec, f1 = [], [], [], []

for train, test in kf.split(X):
    dt.fit(X[train], y[train])
    pred = dt.predict(X[test])

    acc.append(accuracy_score(y[test], pred))
    pre.append(precision_score(y[test], pred, average='macro'))
    rec.append(recall_score(y[test], pred, average='macro'))
    f1.append(f1_score(y[test], pred, average='macro'))

results.append([
    "K-Fold",
    np.mean(acc),
    np.mean(pre),
    np.mean(rec),
    np.mean(f1)
])

skf = StratifiedKFold(n_splits=5)

acc, pre, rec, f1 = [], [], [], []

for train, test in skf.split(X, y):
    dt.fit(X[train], y[train])
    pred = dt.predict(X[test])

    acc.append(accuracy_score(y[test], pred))
    pre.append(precision_score(y[test], pred, average='macro'))
    rec.append(recall_score(y[test], pred, average='macro'))
    f1.append(f1_score(y[test], pred, average='macro'))

results.append([
    "Stratified K-Fold",
    np.mean(acc),
    np.mean(pre),
    np.mean(rec),
    np.mean(f1)
])

acc, pre, rec, f1 = [], [], [], []

for i in range(5):
    X_boot, y_boot = resample(X, y)
    dt.fit(X_boot, y_boot)

    pred = dt.predict(X)

    acc.append(accuracy_score(y, pred))
    pre.append(precision_score(y, pred, average='macro'))
    rec.append(recall_score(y, pred, average='macro'))
    f1.append(f1_score(y, pred, average='macro'))

results.append([
    "Bootstrap",
    np.mean(acc),
    np.mean(pre),
    np.mean(rec),
    np.mean(f1)
])

df = pd.DataFrame(results, columns=[
    "Validation", "Accuracy", "Precision", "Recall", "F1-Score"
])

print(df)
