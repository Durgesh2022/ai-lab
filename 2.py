#OR perceptron

import numpy as np

class Perceptron:
    def __init__(self, learning_rate=0.1, epochs=1000):
        self.learning_rate = learning_rate
        self.epochs = epochs
        self.weights = None
        self.bias = None

    def fit(self, inputs, outputs):
        num_samples, num_features = inputs.shape
        
        self.weights = np.zeros(num_features)
        self.bias = 0

        for _ in range(self.epochs):
            for index, input_vector in enumerate(inputs):
                linear_combination = np.dot(input_vector, self.weights) + self.bias
                predicted_output = self.activation_function(linear_combination)

                adjustment = self.learning_rate * (outputs[index] - predicted_output)
                self.weights += adjustment * input_vector
                self.bias += adjustment

    def activation_function(self, input_value):
        return 1 if input_value >= 0 else 0

    def predict(self, input_pair):
        input_array = np.array(input_pair)
        linear_combination = np.dot(input_array, self.weights) + self.bias
        return self.activation_function(linear_combination)


inputs = np.array([[0, 0], 
                   [0, 1], 
                   [1, 0], 
                   [1, 1]]) 

outputs = np.array([0, 1, 1, 1])          

perceptron = Perceptron(learning_rate=0.1, epochs=10)
perceptron.fit(inputs, outputs)

def predict_or(input1, input2):
    return perceptron.predict((input1, input2))

user_input = input()
input1, input2 = map(int, user_input.split())  
result = predict_or(input1, input2)
print(result)
