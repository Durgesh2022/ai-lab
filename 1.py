# NOT perceptron

import numpy as np

class Perceptron:
    def __init__(self, learning_rate=0.1, n_epochs=1000):
        self.learning_rate = learning_rate
        self.n_epochs = n_epochs
        self.weights = None
        self.bias = None

    def fit(self, features, labels):
        n_samples, n_features = features.shape
        
        self.weights = np.zeros(n_features)
        self.bias = 0

        for _ in range(self.n_epochs):
            for index, feature_vector in enumerate(features):
                linear_combination = np.dot(feature_vector, self.weights) + self.bias
                predicted_label = self.activation_function(linear_combination)

                update_amount = self.learning_rate * (labels[index] - predicted_label)
                self.weights += update_amount * feature_vector
                self.bias += update_amount

    def activation_function(self, input_value):
        return 1 if input_value >= 0 else 0

    def predict(self, single_input):
        input_vector = np.array([single_input]) 
        linear_combination = np.dot(input_vector, self.weights) + self.bias
        return self.activation_function(linear_combination)


features = np.array([[0], 
                     [1]]) 
labels = np.array([1, 0])          

perceptron = Perceptron(learning_rate=0.1, n_epochs=10)
perceptron.fit(features, labels)

def predict_not(single_input):
    return perceptron.predict(single_input)

user_input = int(input())
result = predict_not(user_input)
print(result)
