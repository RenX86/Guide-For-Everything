def add(a, b):
    print(f" adding {a} + {b}")
    return a + b

def subtract(a, b):
    print(f" subtracting {a} - {b}")
    return a - b

def multiply(a, b):
    print(f" multiplying {a} * {b}")
    return a * b

def divide(a, b):
    print(f" dividing {a} / {b}")
    return a / b

print("Let's do some math with just functions!")

age = add(int(input("What is your age: ")), int(input("What is your age: ")))
height = subtract(int(input("What is your height: ")), int(input("What is your height: ")))
weight = multiply(int(input("What is your weight: ")), int(input("What is your weight: ")))
iq = divide(int(input("What is your iq: ")), int(input("What is your iq: ")))

print(f"Age: {age}, Height: {height}, Weight: {weight}, Iq: {iq}")

print("Here's a puzzle ")
what = add(age, subtract(height, multiply(weight, divide(iq, 2))))

print("That becomes: ", what, "can you do you it by hand?")