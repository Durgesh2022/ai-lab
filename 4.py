import numpy as np
from sklearn.neural_network import MLPClassifier
from sklearn.metrics import accuracy_score

x = np.array([[0,0],[0,1],[1,0],[1,1]])
y = np.array([0,1,1,0])

mlp = MLPClassifier(alpha=0.001,verbose=True)
mlp.fit(x,y)

accuracy_score(y, mlp.predict(x))

print(mlp.predict([[1,1]]))
print(mlp.predict([[0,1]]))
print(mlp.predict([[1,0]]))
print(mlp.predict([[0,0]]))


inp=list(map(int,input().split()))
x_np = np.array(inp)
x_np = np.expand_dims(x_np,axis=0)
print(mlp.predict(x_np))