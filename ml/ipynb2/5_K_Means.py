import numpy as np
import pandas as pd

from sklearn.datasets import load_iris
from sklearn.model_selection import train_test_split, KFold, StratifiedKFold
from sklearn.cluster import KMeans
from sklearn.metrics import accuracy_score, precision_score, recall_score, f1_score
from sklearn.utils import resample
from scipy.stats import mode

iris = load_iris()
X = iris.data
y = iris.target

def map_clusters(y_true, y_pred):
    labels = np.zeros_like(y_pred)
    for i in range(len(np.unique(y_pred))):
        mask = (y_pred == i)
        labels[mask] = mode(y_true[mask], keepdims=True)[0]
    return labels

results = []

X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2)

kmeans = KMeans(n_clusters=3, random_state=42)
kmeans.fit(X_train)

pred = kmeans.predict(X_test)
pred = map_clusters(y_test, pred)

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
    kmeans = KMeans(n_clusters=3, random_state=42)
    kmeans.fit(X[train])

    pred = kmeans.predict(X[test])
    pred = map_clusters(y[test], pred)

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
    kmeans = KMeans(n_clusters=3, random_state=42)
    kmeans.fit(X[train])

    pred = kmeans.predict(X[test])
    pred = map_clusters(y[test], pred)

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

    kmeans = KMeans(n_clusters=3, random_state=42)
    kmeans.fit(X_boot)

    pred = kmeans.predict(X)
    pred = map_clusters(y, pred)

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
