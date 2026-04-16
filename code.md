# OS

## os/FCFS(FirstComeFirstServed).c

```c
#include <stdio.h>

int main() {
    int n, i;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n], wt[n], tat[n];

    printf("Enter Burst Time for each process:\n");
    for (i = 0; i < n; i++) {
        printf("P%d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    wt[0] = 0;
    for (i = 1; i < n; i++)
        wt[i] = wt[i - 1] + bt[i - 1];

    float avg_wt = 0, avg_tat = 0;

    printf("\nProcess\tBT\tWT\tTAT\n");
    for (i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        avg_wt += wt[i];
        avg_tat += tat[i];
        printf("P%d\t%d\t%d\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f\n", avg_wt / n);
    printf("Average Turnaround Time = %.2f\n", avg_tat / n);

    return 0;
}
```

## os/SJF(ShortestJobFirst).c

```c
#include <stdio.h>

int main() {
    int n, i, j, temp;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n], wt[n], tat[n], p[n];

    printf("Enter Burst Time for each process:\n");
    for (i = 0; i < n; i++) {
        p[i] = i + 1;
        printf("P%d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (bt[i] > bt[j]) {
                temp = bt[i]; bt[i] = bt[j]; bt[j] = temp;
                temp = p[i];  p[i]  = p[j];  p[j]  = temp;
            }
        }
    }

    wt[0] = 0;
    for (i = 1; i < n; i++)
        wt[i] = wt[i - 1] + bt[i - 1];

    float avg_wt = 0, avg_tat = 0;

    printf("\nProcess\tBT\tWT\tTAT\n");
    for (i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        avg_wt += wt[i];
        avg_tat += tat[i];
        printf("P%d\t%d\t%d\t%d\n", p[i], bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f\n", avg_wt / n);
    printf("Average Turnaround Time = %.2f\n", avg_tat / n);

    return 0;
}
```

## os/Priority Scheduling.c

```c
#include <stdio.h>

int main() {
    int n, i, j, temp;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n], pr[n], wt[n], tat[n], p[n];

    printf("Enter Burst Time and Priority for each process:\n");
    for (i = 0; i < n; i++) {
        p[i] = i + 1;
        printf("P%d BT: ", i + 1);
        scanf("%d", &bt[i]);
        printf("P%d Priority: ", i + 1);
        scanf("%d", &pr[i]);
    }

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (pr[i] > pr[j]) {
                temp = pr[i]; pr[i] = pr[j]; pr[j] = temp;
                temp = bt[i]; bt[i] = bt[j]; bt[j] = temp;
                temp = p[i];  p[i]  = p[j];  p[j]  = temp;
            }
        }
    }

    wt[0] = 0;
    for (i = 1; i < n; i++)
        wt[i] = wt[i - 1] + bt[i - 1];

    float avg_wt = 0, avg_tat = 0;

    printf("\nProcess\tPriority\tBT\tWT\tTAT\n");
    for (i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        avg_wt += wt[i];
        avg_tat += tat[i];
        printf("P%d\t%d\t\t%d\t%d\t%d\n", p[i], pr[i], bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f\n", avg_wt / n);
    printf("Average Turnaround Time = %.2f\n", avg_tat / n);

    return 0;
}
```

## os/round_robin.c

```c
#include <stdio.h>

int main() {
    int n, tq, i;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n], rem[n], wt[n], tat[n];

    printf("Enter Burst Time for each process:\n");
    for (i = 0; i < n; i++) {
        printf("P%d: ", i + 1);
        scanf("%d", &bt[i]);
        rem[i] = bt[i];
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    int time = 0;

    while (1) {
        int done = 1;

        for (i = 0; i < n; i++) {
            if (rem[i] > 0) {
                done = 0;
                if (rem[i] > tq) {
                    time += tq;
                    rem[i] -= tq;
                } else {
                    time += rem[i];
                    wt[i] = time - bt[i];
                    rem[i] = 0;
                }
            }
        }

        if (done)
            break;
    }

    float avg_wt = 0, avg_tat = 0;

    printf("\nProcess\tBT\tWT\tTAT\n");
    for (i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        avg_wt += wt[i];
        avg_tat += tat[i];
        printf("P%d\t%d\t%d\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f\n", avg_wt / n);
    printf("Average Turnaround Time = %.2f\n", avg_tat / n);

    return 0;
}
```

## os/Bankers_Algorithm_for_Deadlock.c

```c
#include <stdio.h>

int main() {
    int n, m, i, j, k;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resources: ");
    scanf("%d", &m);

    int alloc[n][m], max[n][m], need[n][m];
    int avail[m], finish[n], safeSeq[n];

    printf("Enter Allocation Matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);

    printf("Enter Maximum Matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &max[i][j]);

    printf("Enter Available Resources:\n");
    for (i = 0; i < m; i++)
        scanf("%d", &avail[i]);

    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    for (i = 0; i < n; i++)
        finish[i] = 0;

    int count = 0;

    while (count < n) {
        int found = 0;

        for (i = 0; i < n; i++) {
            if (finish[i] == 0) {
                for (j = 0; j < m; j++)
                    if (need[i][j] > avail[j])
                        break;

                if (j == m) {
                    for (k = 0; k < m; k++)
                        avail[k] += alloc[i][k];

                    safeSeq[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if (found == 0) {
            printf("System is in Deadlock (Unsafe State)\n");
            return 0;
        }
    }

    printf("System is in Safe State\nSafe Sequence: ");
    for (i = 0; i < n; i++)
        printf("P%d ", safeSeq[i]);
    printf("\n");

    return 0;
}
```

## os/Paging_Technique_of_Memory_Management..c

```c
#include <stdio.h>

int main() {
    int msize, psize, pages, n, i;

    printf("Enter size of main memory: ");
    scanf("%d", &msize);

    printf("Enter page size: ");
    scanf("%d", &psize);

    pages = msize / psize;
    printf("Total pages available = %d\n", pages);

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int process;
    for (i = 0; i < n; i++) {
        printf("Enter size of process %d: ", i + 1);
        scanf("%d", &process);

        int req = process / psize;
        if (process % psize != 0)
            req++;

        if (req <= pages) {
            printf("Process %d allocated %d pages\n", i + 1, req);
            pages -= req;
        } else {
            printf("Process %d cannot be allocated\n", i + 1);
        }
    }

    return 0;
}
```

## os/fifo_page_replacement.c

```c
#include <stdio.h>

int main() {
    int n, f, i, j, flag, faults = 0, pos = 0;

    printf("Enter pages and frames: ");
    scanf("%d %d", &n, &f);

    int p[n], fr[f];
    for (i = 0; i < f; i++)
        fr[i] = -1;

    printf("Enter reference string: ");
    for (i = 0; i < n; i++)
        scanf("%d", &p[i]);

    for (i = 0; i < n; i++) {
        flag = 0;
        for (j = 0; j < f; j++)
            if (fr[j] == p[i]) { flag = 1; break; }

        if (!flag) {
            fr[pos] = p[i];
            pos = (pos + 1) % f;
            faults++;
            printf("Page %d -> Fault  [", p[i]);
            for (j = 0; j < f; j++) printf(" %d", fr[j]);
            printf(" ]\n");
        } else {
            printf("Page %d -> Hit\n", p[i]);
        }
    }

    printf("Total Page Faults: %d\n", faults);
    return 0;
}
```

## os/lru_page_replacement.c

```c
#include <stdio.h>

int main() {
    int n, f, i, j, flag, faults = 0, min, pos;

    printf("Enter pages and frames: ");
    scanf("%d %d", &n, &f);

    int p[n], fr[f], last[f];
    for (i = 0; i < f; i++) {
        fr[i] = -1;
        last[i] = -1;
    }

    printf("Enter reference string: ");
    for (i = 0; i < n; i++)
        scanf("%d", &p[i]);

    for (i = 0; i < n; i++) {
        flag = 0;
        for (j = 0; j < f; j++)
            if (fr[j] == p[i]) { flag = 1; last[j] = i; break; }

        if (!flag) {
            pos = -1;
            for (j = 0; j < f; j++)
                if (fr[j] == -1) { pos = j; break; }

            if (pos == -1) {
                min = last[0]; pos = 0;
                for (j = 1; j < f; j++)
                    if (last[j] < min) { min = last[j]; pos = j; }
            }

            fr[pos] = p[i];
            last[pos] = i;
            faults++;
            printf("Page %d -> Fault  [", p[i]);
            for (j = 0; j < f; j++) printf(" %d", fr[j]);
            printf(" ]\n");
        } else {
            printf("Page %d -> Hit\n", p[i]);
        }
    }

    printf("Total Page Faults: %d\n", faults);
    return 0;
}
```

## os/lfu_page_replacement.c

```c
#include <stdio.h>

int main() {
    int n, f, i, j, flag, faults = 0, min, pos;

    printf("Enter pages and frames: ");
    scanf("%d %d", &n, &f);

    int p[n], fr[f], freq[f];
    for (i = 0; i < f; i++) {
        fr[i] = -1;
        freq[i] = 0;
    }

    printf("Enter reference string: ");
    for (i = 0; i < n; i++)
        scanf("%d", &p[i]);

    for (i = 0; i < n; i++) {
        flag = 0;
        for (j = 0; j < f; j++)
            if (fr[j] == p[i]) { flag = 1; freq[j]++; break; }

        if (!flag) {
            pos = -1;
            for (j = 0; j < f; j++)
                if (fr[j] == -1) { pos = j; break; }

            if (pos == -1) {
                min = freq[0]; pos = 0;
                for (j = 1; j < f; j++)
                    if (freq[j] < min) { min = freq[j]; pos = j; }
            }

            fr[pos] = p[i];
            freq[pos] = 1;
            faults++;
            printf("Page %d -> Fault  [", p[i]);
            for (j = 0; j < f; j++) printf(" %d", fr[j]);
            printf(" ]\n");
        } else {
            printf("Page %d -> Hit\n", p[i]);
        }
    }

    printf("Total Page Faults: %d\n", faults);
    return 0;
}
```

---

# ML

## ml/ipynb/2_Database_Connectivity_using_sqlite.ipynb

```python
import sqlite3
import pandas as pd


conn = sqlite3.connect('example.db')
cursor = conn.cursor()


cursor.execute('''
CREATE TABLE IF NOT EXISTS students (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    name TEXT NOT NULL,
    age INTEGER CHECK(age > 0),
    grade TEXT
)
''')


students_data = [
    ("Alice", 20, "A"),
    ("Bob", 22, "B"),
    ("Charlie", 19, "A")
]

cursor.executemany("INSERT INTO students (name, age, grade) VALUES (?, ?, ?)", students_data)
conn.commit()


cursor.execute("SELECT * FROM students")
rows = cursor.fetchall()

print("Data from database:")
for row in rows:
    print(row)


df = pd.read_sql_query("SELECT * FROM students", conn)
print("\nDataFrame view:")
print(df)


conn.close()
```

## ml/ipynb/3_K_Nearest_Neighbor.ipynb

```python
import pandas as pd

df = pd.read_csv("/content/drive/MyDrive/Datasets/diabetes.csv")

df.head()


x  = df.iloc[ : , 0:8 ]

y  = df.iloc[: , 8]


x

y


from sklearn.model_selection import train_test_split

x_train , x_test , y_train , y_test =train_test_split(x,y,test_size = 0.2 )


df.shape

print(x_train.shape)
print(x_test.shape)
print(y_train.shape)
print(y_test.shape)


from sklearn.neighbors import KNeighborsClassifier

knn_model = KNeighborsClassifier(n_neighbors=5,p=2,metric='minkowski')

knn_model.fit(x_train,y_train)

pred = knn_model.predict(x_test)


from sklearn.metrics import confusion_matrix, accuracy_score, precision_score, recall_score, f1_score

cm = confusion_matrix(y_test, pred)
print("Confusion Matrix:\n", cm)


score = accuracy_score(y_test,pred)
print(score)


precision = precision_score(y_test,pred)
print("Precision:", precision)

recall = recall_score(y_test,pred)
print("Recall:", recall)

f1 = f1_score(y_test,pred)
print("F1 Score:", f1)
```

## ml/ipynb/7_Naive_Bayes_text_classification.ipynb

```python
import pandas as pd
import numpy as np
from sklearn.model_selection import train_test_split
from sklearn.feature_extraction.text import CountVectorizer
from sklearn.naive_bayes import MultinomialNB
from sklearn.metrics import accuracy_score, confusion_matrix
import seaborn as sns
import matplotlib.pyplot as plt


data = pd.read_csv('/content/drive/MyDrive/Datasets/synthetic_text_data.csv')
X = data['text']
y = data['label']


X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)


vectorizer = CountVectorizer()
X_train_vectorized = vectorizer.fit_transform(X_train)
X_test_vectorized = vectorizer.transform(X_test)


model = MultinomialNB()
model.fit(X_train_vectorized, y_train)


y_pred = model.predict(X_test_vectorized)


accuracy = accuracy_score(y_test, y_pred)
conf_matrix = confusion_matrix(y_test, y_pred)
print(f'Accuracy: {accuracy * 100}%')


class_labels = np.unique(y_test)

plt.figure(figsize=(8, 6))
sns.heatmap(conf_matrix, annot=True, fmt='d', cmap='Blues', xticklabels=class_labels, yticklabels=class_labels)
plt.title('Confusion Matrix Heatmap')
plt.xlabel('Predicted Label')
plt.ylabel('True Label')
plt.show()
```

## ml/ipynb/8_Genetic_Algorithm_TSP.ipynb

```python
import random
import numpy as np
import matplotlib.pyplot as plt


NUM_CITIES = int(input("Enter the number of cities: "))

city_names = []
for i in range(NUM_CITIES):
    name = input(f"Enter name for city {i+1}: ")
    city_names.append(name)


def distance(city1, city2):
    return np.linalg.norm(city1 - city2)

def total_distance(route):
    dist = 0
    for i in range(len(route)):
        dist += distance(cities[route[i]], cities[route[(i+1) % len(route)]])
    return dist


POP_SIZE = 100

def create_population():
    return [random.sample(range(NUM_CITIES), NUM_CITIES) for _ in range(POP_SIZE)]

def fitness(route):
    total_dist = total_distance(route)
    if total_dist == 0:
        return 0.0001
    return 1 / total_dist

def selection(population):
    valid_fitness = [fitness(r) for r in population]
    if all(f == 0 for f in valid_fitness):
        return random.choice(population)
    return random.choices(population, weights=valid_fitness)[0]

def crossover(p1, p2):
    start, end = sorted(random.sample(range(NUM_CITIES), 2))
    child = [-1] * NUM_CITIES
    child[start:end] = p1[start:end]
    ptr = 0
    for gene in p2:
        if gene not in child:
            while child[ptr] != -1:
                ptr += 1
            child[ptr] = gene
    return child

def mutate(route, rate=0.02):
    if random.random() < rate:
        i, j = random.sample(range(NUM_CITIES), 2)
        route[i], route[j] = route[j], route[i]
    return route


def plot_route(route, title):
    ordered_cities = cities[route]
    ordered_cities = np.vstack([ordered_cities, ordered_cities[0]])
    plt.plot(ordered_cities[:, 0], ordered_cities[:, 1], 'o-')
    plt.title(title)
    for i, city_idx in enumerate(route):
        plt.annotate(city_names[city_idx], (cities[city_idx, 0], cities[city_idx, 1]), textcoords="offset points", xytext=(5, 5))
    plt.show()


import googlemaps

GOOGLE_MAPS_API_KEY = 'YOUR_API_KEY'
gmaps = googlemaps.Client(key=GOOGLE_MAPS_API_KEY)

def geocode_city(city_name):
    try:
        geocode_result = gmaps.geocode(city_name)
        if geocode_result:
            location = geocode_result[0]['geometry']['location']
            return [location['lat'], location['lng']]
        else:
            return [0, 0]
    except Exception as e:
        return [0, 0]

cities_coords = [geocode_city(name) for name in city_names]
cities = np.array(cities_coords)

print("Geocoded cities:")
for i, name in enumerate(city_names):
    print(f"- {name}: {cities[i]}")


GENERATIONS = 500
population = create_population()

for gen in range(GENERATIONS):
    new_population = []
    for _ in range(POP_SIZE):
        p1 = selection(population)
        p2 = selection(population)
        child = crossover(p1, p2)
        child = mutate(child)
        new_population.append(child)
    population = new_population

best_route = max(population, key=fitness)
print(f"Best distance: {total_distance(best_route):.2f}")
print(f"Best route: {[city_names[i] for i in best_route]}")

plot_route(best_route, f"Best Route (Distance: {total_distance(best_route):.2f})")
```

## ml/ipynb/9_Finite_Words_Classification_Backpropagation.ipynb

```python
import numpy as np

np.random.seed(42)


data = {
    'apple': 'fruit',
    'banana': 'fruit',
    'orange': 'fruit',
    'red': 'color',
    'blue': 'color',
    'green': 'color',
    'dog': 'animal',
    'cat': 'animal',
    'lion': 'animal'
}

words = list(data.keys())
categories = list(set(data.values()))

print(f"Words: {words}")
print(f"Categories: {categories}")


vocabulary = sorted(list(set(''.join(words))))
vocab_size = len(vocabulary)

char_to_idx = {char: i for i, char in enumerate(vocabulary)}
idx_to_char = {i: char for i, char in enumerate(vocabulary)}

print(f"Vocabulary: {vocabulary}")
print(f"Vocabulary Size: {vocab_size}")

def word_to_vector(word, char_to_idx, vocab_size):
    vector = np.zeros(vocab_size)
    for char in word:
        if char in char_to_idx:
            vector[char_to_idx[char]] = 1
    return vector

X = np.array([word_to_vector(word, char_to_idx, vocab_size) for word in words])

category_to_idx = {cat: i for i, cat in enumerate(categories)}
y = np.zeros((len(words), len(categories)))
for i, word in enumerate(words):
    category = data[word]
    y[i, category_to_idx[category]] = 1

print("\nEncoded words (X shape):", X.shape)
print("Encoded categories (y shape):", y.shape)
print("\nFirst word ('apple') vector:", X[0])
print("First category ('fruit') vector:", y[0])


def sigmoid(x):
    return 1 / (1 + np.exp(-x))

def sigmoid_derivative(x):
    return x * (1 - x)

def softmax(x):
    exp_x = np.exp(x - np.max(x, axis=1, keepdims=True))
    return exp_x / np.sum(exp_x, axis=1, keepdims=True)

def cross_entropy_loss(y_true, y_pred):
    y_pred = np.clip(y_pred, 1e-12, 1 - 1e-12)
    return -np.sum(y_true * np.log(y_pred))


input_size = vocab_size
hidden_size = 10
output_size = len(categories)
learning_rate = 0.1
epochs = 5000

W1 = np.random.randn(input_size, hidden_size) * 0.5
b1 = np.zeros((1, hidden_size))
W2 = np.random.randn(hidden_size, output_size) * 0.5
b2 = np.zeros((1, output_size))


for epoch in range(epochs):
    hidden_input = np.dot(X, W1) + b1
    hidden_output = sigmoid(hidden_input)

    final_input = np.dot(hidden_output, W2) + b2
    final_output = softmax(final_input)

    loss = cross_entropy_loss(y, final_output)

    d_output = final_output - y
    dW2 = np.dot(hidden_output.T, d_output)
    db2 = np.sum(d_output, axis=0, keepdims=True)

    d_hidden = np.dot(d_output, W2.T) * sigmoid_derivative(hidden_output)
    dW1 = np.dot(X.T, d_hidden)
    db1 = np.sum(d_hidden, axis=0, keepdims=True)

    W2 -= learning_rate * dW2
    b2 -= learning_rate * db2
    W1 -= learning_rate * dW1
    b1 -= learning_rate * db1

    if epoch % 500 == 0:
        print(f"Epoch {epoch}, Loss: {loss:.4f}")


hidden = sigmoid(np.dot(X, W1) + b1)
predictions = softmax(np.dot(hidden, W2) + b2)
predicted_labels = np.argmax(predictions, axis=1)

idx_to_category = {v: k for k, v in category_to_idx.items()}

print("\nPredictions:")
for i, word in enumerate(words):
    print(f"{word} -> Predicted: {idx_to_category[predicted_labels[i]]}, Actual: {data[word]}")
```

## ml/ipynb/CNN.ipynb

```python
import tensorflow as tf
from tensorflow.keras import datasets, layers, models
import matplotlib.pyplot as plt
import numpy as np


(x_train, y_train), (x_test, y_test) = datasets.cifar10.load_data()
x_train.shape


x_test.shape


plt.imshow(x_train[0])


plt.figure(figsize=(15, 2))
plt.imshow(x_train[0])


y_train[:5]


y_train = y_train.reshape(-1,)
y_train[:5]


classes = ["airplane", "automobile", "bird", "cat", "deer", "dog", "frog", "horse", "ship", "truck"]


def plot_sample(x, y, index):
    plt.figure(figsize=(15, 2))
    plt.imshow(x[index])
    plt.xlabel(classes[y[index]])

plot_sample(x_train, y_train, 0)


plot_sample(x_train, y_train, 1)


x_train = x_train / 255.0
x_test = x_test / 255.0


model = models.Sequential([
    layers.Conv2D(32, (3, 3), activation='relu', input_shape=(32, 32, 3)),
    layers.MaxPooling2D((2, 2)),
    layers.Conv2D(64, (3, 3), activation='relu'),
    layers.MaxPooling2D((2, 2)),
    layers.Conv2D(64, (3, 3), activation='relu'),
    layers.Flatten(),
    layers.Dense(64, activation='relu'),
    layers.Dense(10, activation='softmax')
])

model.summary()


model.compile(optimizer='adam', loss='sparse_categorical_crossentropy', metrics=['accuracy'])
model.fit(x_train, y_train, epochs=10, validation_data=(x_test, y_test))


test_loss, test_acc = model.evaluate(x_test, y_test)
print(f"Test Accuracy: {test_acc * 100:.2f}%")
```

## ml/ipynb/K=clustering.ipynb

```python
import pandas as pd
from matplotlib import pyplot as plt
from sklearn.cluster import KMeans
from sklearn.preprocessing import MinMaxScaler
%matplotlib inline

df=pd.read_csv('/content/drive/MyDrive/Datasets/Income.csv')
df.head()

plt.scatter(df.Age,df.Income)

km=KMeans(n_clusters=3)
km

y_predicted=km.fit_predict(df[['Age','Income']])
y_predicted

df['cluster']=y_predicted
df.head()

df1= df[df.cluster==0]
df2= df[df.cluster==1]
df3= df[df.cluster==2]

plt.scatter(df1.Age,df1.Income,color='green')
plt.scatter(df2.Age,df2.Income,color='red')
plt.scatter(df3.Age,df3.Income,color='black')

plt.xlabel('Age')
plt.ylabel('Income')
plt.legend()

scaler=MinMaxScaler()
scaler.fit(df[['Income']])
df['Income']=scaler.transform(df[['Income']])
df.head()

scaler=MinMaxScaler()
scaler.fit(df[['Age']])
df['Age']=scaler.transform(df[['Age']])
df.head()

km=KMeans(n_clusters=3)
y_predicted=km.fit_predict(df[['Age','Income']])
y_predicted

df['cluster'] = y_predicted
df

df1= df[df.cluster==0]
df2= df[df.cluster==1]
df3= df[df.cluster==2]

plt.scatter(df1.Age,df1.Income,color='green')
plt.scatter(df2.Age,df2.Income,color='red')
plt.scatter(df3.Age,df3.Income,color='black')


plt.legend()

km.cluster_centers_

df1= df[df.cluster==0]
df2= df[df.cluster==1]
df3= df[df.cluster==2]

plt.scatter(df1.Age,df1.Income,color='green')
plt.scatter(df2.Age,df2.Income,color='red')
plt.scatter(df3.Age,df3.Income,color='black')

plt.scatter(km.cluster_centers_[:,0],km.cluster_centers_[:,1],color='purple',marker='*',label='centroid')


plt.legend()
```

## ml/ipynb/Linear_Regression.ipynb

```python
from google.colab import drive
drive.mount('/content/drive')

import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from sklearn.linear_model import LinearRegression

df =pd.read_csv('/content/drive/MyDrive/Datasets/price.csv')
df.head()


%matplotlib inline
plt.xlabel('area(sq.ft)')
plt.ylabel('price')
plt.scatter(df.area,df.price,color='red',marker='+')

from sklearn import linear_model
lr = linear_model.LinearRegression()
lr.fit(df[['area']],df.price)

lr.predict([[3300]])

lr.coef_

lr.intercept_

135.78767123*3300+180616.43835616432

df1=pd.read_csv('/content/drive/MyDrive/Datasets/areas.csv')
df1.head()

ar=lr.predict(df1)

df1['price']=lr.predict(df1[['area']])
ar = df1['price']

ar.to_csv("areas.csv")
df1.head()

%matplotlib inline
plt.xlabel('area(sq.ft)')
plt.ylabel('price')
plt.scatter(df.area,df.price,color='red',marker='+')
plt.plot(df.area,lr.predict(df[['area']]),color='blue')
```

## ml/ipynb/SVM.ipynb

```python
import pandas as pd
from sklearn.datasets import load_iris
iris = load_iris()

dir(iris)

iris.feature_names

df= pd.DataFrame(iris.data, columns=iris.feature_names)
df.head()

df['target'] = iris.target
df.head()

iris.target_names

df.info()

df[df.target==0].head()

df['flower_name'] = df.target.apply(lambda x: iris.target_names[x])
df.head()

from matplotlib import pyplot as plt
%matplotlib inline

df0 = df[df.target==0]
df1 = df[df.target==1]
df2 = df[df.target==2]

df2.head()

plt.xlabel('sepal length (cm)')
plt.ylabel('sepal width (cm)')
plt.scatter(df0['sepal length (cm)'], df0['sepal width (cm)'], color='green', marker='+')
plt.scatter(df1['sepal length (cm)'], df1['sepal width (cm)'], color='red', marker='*')

plt.xlabel('petal length (cm)')
plt.ylabel('petal width (cm)')
plt.scatter(df0['petal length (cm)'], df0['petal width (cm)'], color='green', marker='+')
plt.scatter(df1['petal length (cm)'], df1['petal width (cm)'], color='red', marker='*')

from sklearn.model_selection import train_test_split
x=df.drop(['target','flower_name'], axis='columns')
x

y=df.target
y

x.train, x.test, y.train, y.test = train_test_split(x,y, test_size=0.2)

len(x.train)

len(x.test)

from sklearn.svm import SVC
model = SVC()

model.fit(x.train, y.train)

model.score(x.test, y.test)
```

## ml/py/3_k_nearest_neighbor.py

```python
# -*- coding: utf-8 -*-
"""3.K-Nearest Neighbor.ipynb

Automatically generated by Colab.

Original file is located at
    https://colab.research.google.com/drive/1S4E1W1JewrNaeEAAvkomlNZZOKQ2TTWy
"""



import pandas as pd

df = pd.read_csv("/content/drive/MyDrive/Datasets/diabetes.csv")

df.head()



x  = df.iloc[ : , 0:8 ]

y  = df.iloc[: , 8]

x

y



from sklearn.model_selection import train_test_split

x_train , x_test , y_train , y_test =train_test_split(x,y,test_size = 0.2 )

df.shape

print(x_train.shape)
print(x_test.shape)
print(y_train.shape)
print(y_test.shape)



from sklearn.neighbors import KNeighborsClassifier

knn_model = KNeighborsClassifier(n_neighbors=5,p=2,metric='minkowski')

knn_model.fit(x_train,y_train)

pred = knn_model.predict(x_test)

from sklearn.metrics import confusion_matrix, accuracy_score, precision_score, recall_score, f1_score

cm = confusion_matrix(y_test, pred)
print("Confusion Matrix:\n", cm)

score = accuracy_score(y_test,pred)
print(score)

precision = precision_score(y_test,pred)
print("Precision:", precision)

recall = recall_score(y_test,pred)
print("Recall:", recall)

f1 = f1_score(y_test,pred)
print("F1 Score:", f1)
```

## ml/py/k=clustering.py

```python
# -*- coding: utf-8 -*-
"""K=clustering.ipynb

Automatically generated by Colab.

Original file is located at
    https://colab.research.google.com/drive/19QeqDFK4m6V1yAvuxSRQgQYUeUcpwaVT
"""



import pandas as pd
from matplotlib import pyplot as plt
from sklearn.cluster import KMeans
from sklearn.preprocessing import MinMaxScaler

df=pd.read_csv('/content/drive/MyDrive/Datasets/Income.csv')
df.head()

plt.scatter(df.Age,df.Income)

km=KMeans(n_clusters=3)
km

y_predicted=km.fit_predict(df[['Age','Income']])
y_predicted

df['cluster']=y_predicted
df.head()

df1= df[df.cluster==0]
df2= df[df.cluster==1]
df3= df[df.cluster==2]

plt.scatter(df1.Age,df1.Income,color='green')
plt.scatter(df2.Age,df2.Income,color='red')
plt.scatter(df3.Age,df3.Income,color='black')

plt.xlabel('Age')
plt.ylabel('Income')
plt.legend()

scaler=MinMaxScaler()
scaler.fit(df[['Income']])
df['Income']=scaler.transform(df[['Income']])
df.head()

scaler=MinMaxScaler()
scaler.fit(df[['Age']])
df['Age']=scaler.transform(df[['Age']])
df.head()

km=KMeans(n_clusters=3)
y_predicted=km.fit_predict(df[['Age','Income']])
y_predicted

df['cluster'] = y_predicted
df

df1= df[df.cluster==0]
df2= df[df.cluster==1]
df3= df[df.cluster==2]

plt.scatter(df1.Age,df1.Income,color='green')
plt.scatter(df2.Age,df2.Income,color='red')
plt.scatter(df3.Age,df3.Income,color='black')


plt.legend()

km.cluster_centers_

df1= df[df.cluster==0]
df2= df[df.cluster==1]
df3= df[df.cluster==2]

plt.scatter(df1.Age,df1.Income,color='green')
plt.scatter(df2.Age,df2.Income,color='red')
plt.scatter(df3.Age,df3.Income,color='black')

plt.scatter(km.cluster_centers_[:,0],km.cluster_centers_[:,1],color='purple',marker='*',label='centroid')


plt.legend()
```

## ml/py/linear_regression.py

```python
# -*- coding: utf-8 -*-
"""Linear Regression.ipynb

Automatically generated by Colab.

Original file is located at
    https://colab.research.google.com/drive/1v7WWwmw4R1KUx37JhF9y2JQCJtGRYsZM
"""



from google.colab import drive
drive.mount('/content/drive')

import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from sklearn.linear_model import LinearRegression

df =pd.read_csv('/content/drive/MyDrive/Datasets/price.csv')
df.head()

plt.xlabel('area(sq.ft)')
plt.ylabel('price')
plt.scatter(df.area,df.price,color='red',marker='+')

from sklearn import linear_model
lr = linear_model.LinearRegression()
lr.fit(df[['area']],df.price)

lr.predict([[3300]])

lr.coef_

lr.intercept_

135.78767123*3300+180616.43835616432

df1=pd.read_csv('/content/drive/MyDrive/Datasets/areas.csv')
df1.head()

ar=lr.predict(df1)

df1['price']=lr.predict(df1[['area']])
ar = df1['price']

ar.to_csv("areas.csv")
df1.head()

plt.xlabel('area(sq.ft)')
plt.ylabel('price')
plt.scatter(df.area,df.price,color='red',marker='+')
plt.plot(df.area,lr.predict(df[['area']]),color='blue')

"""# New Section"""
```

## ml/py/svm.py

```python
# -*- coding: utf-8 -*-
"""SVM.ipynb

Automatically generated by Colab.

Original file is located at
    https://colab.research.google.com/drive/1LotJabVSDkMLkmDLd5-ayMtkG2JuKqQW
"""



import pandas as pd
from sklearn.datasets import load_iris
iris = load_iris()

dir(iris)

iris.feature_names

df= pd.DataFrame(iris.data, columns=iris.feature_names)
df.head()

df['target'] = iris.target
df.head()

iris.target_names

df.info()

df[df.target==0].head()

df['flower_name'] = df.target.apply(lambda x: iris.target_names[x])
df.head()

from matplotlib import pyplot as plt

df0 = df[df.target==0]
df1 = df[df.target==1]
df2 = df[df.target==2]

df2.head()

plt.xlabel('sepal length (cm)')
plt.ylabel('sepal width (cm)')
plt.scatter(df0['sepal length (cm)'], df0['sepal width (cm)'], color='green', marker='+')
plt.scatter(df1['sepal length (cm)'], df1['sepal width (cm)'], color='red', marker='*')

plt.xlabel('petal length (cm)')
plt.ylabel('petal width (cm)')
plt.scatter(df0['petal length (cm)'], df0['petal width (cm)'], color='green', marker='+')
plt.scatter(df1['petal length (cm)'], df1['petal width (cm)'], color='red', marker='*')

from sklearn.model_selection import train_test_split
x=df.drop(['target','flower_name'], axis='columns')
x

y=df.target
y

x.train, x.test, y.train, y.test = train_test_split(x,y, test_size=0.2)

len(x.train)

len(x.test)

from sklearn.svm import SVC
model = SVC()

model.fit(x.train, y.train)

model.score(x.test, y.test)
```

## ml/ipynb2/1_KNN.py

```python
import numpy as np
import pandas as pd

from sklearn.datasets import load_iris
from sklearn.model_selection import train_test_split, KFold, StratifiedKFold
from sklearn.neighbors import KNeighborsClassifier
from sklearn.metrics import accuracy_score, precision_score, recall_score, f1_score
from sklearn.utils import resample

iris = load_iris()
X = iris.data
y = iris.target

knn = KNeighborsClassifier(n_neighbors=3)

results = []

X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2)

knn.fit(X_train, y_train)
pred = knn.predict(X_test)

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
    knn.fit(X[train], y[train])
    pred = knn.predict(X[test])

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
    knn.fit(X[train], y[train])
    pred = knn.predict(X[test])

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
    knn.fit(X_boot, y_boot)

    pred = knn.predict(X)

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
```

## ml/ipynb2/2_SVM.py

```python
import numpy as np
import pandas as pd

from sklearn.datasets import load_iris
from sklearn.model_selection import train_test_split, KFold, StratifiedKFold
from sklearn.svm import SVC
from sklearn.metrics import accuracy_score, precision_score, recall_score, f1_score
from sklearn.utils import resample

iris = load_iris()
X = iris.data
y = iris.target

svm = SVC(kernel='linear')

results = []

X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2)

svm.fit(X_train, y_train)
pred = svm.predict(X_test)

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
    svm.fit(X[train], y[train])
    pred = svm.predict(X[test])

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
    svm.fit(X[train], y[train])
    pred = svm.predict(X[test])

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
    svm.fit(X_boot, y_boot)

    pred = svm.predict(X)

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
```

## ml/ipynb2/3_Decision_Tree.py

```python
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
```

## ml/ipynb2/4_Conditional_Probability.py

```python
import numpy as np
import pandas as pd

from sklearn.datasets import load_iris
from sklearn.model_selection import train_test_split, KFold, StratifiedKFold
from sklearn.naive_bayes import GaussianNB
from sklearn.metrics import accuracy_score, precision_score, recall_score, f1_score
from sklearn.utils import resample

iris = load_iris()
X = iris.data
y = iris.target

model = GaussianNB()

results = []

X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2)

model.fit(X_train, y_train)
pred = model.predict(X_test)

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

    model.fit(X[train], y[train])
    pred = model.predict(X[test])

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

    model.fit(X[train], y[train])
    pred = model.predict(X[test])

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
    model.fit(X_boot, y_boot)

    pred = model.predict(X)

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
```

## ml/ipynb2/5_K_Means.py

```python
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
```

## ml/ipynb2/6_Backpropagation.py

```python
import numpy as np
import pandas as pd

from sklearn.datasets import load_iris
from sklearn.model_selection import train_test_split, KFold, StratifiedKFold
from sklearn.neural_network import MLPClassifier
from sklearn.metrics import accuracy_score, precision_score, recall_score, f1_score
from sklearn.utils import resample

iris = load_iris()
X = iris.data
y = iris.target

model = MLPClassifier(hidden_layer_sizes=(10,), max_iter=1000, random_state=42)

results = []

X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2)

model.fit(X_train, y_train)
pred = model.predict(X_test)

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
    model = MLPClassifier(hidden_layer_sizes=(10,), max_iter=1000, random_state=42)

    model.fit(X[train], y[train])
    pred = model.predict(X[test])

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
    model = MLPClassifier(hidden_layer_sizes=(10,), max_iter=1000, random_state=42)

    model.fit(X[train], y[train])
    pred = model.predict(X[test])

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

    model = MLPClassifier(hidden_layer_sizes=(10,), max_iter=1000, random_state=42)
    model.fit(X_boot, y_boot)

    pred = model.predict(X)

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
```

## ml/ipynb2/7_Linear_Regression.py

```python
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
```
