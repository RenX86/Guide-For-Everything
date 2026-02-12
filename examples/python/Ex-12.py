cheese_count = input("How many cheeses do you have? ")
boxes_of_crackers = input("How many boxes of crackers do you have? ")

def cheese_and_crackers(cheese_count, boxes_of_crackers):
    print(f"You have {cheese_count} cheeses!")
    print(f"You have {boxes_of_crackers} boxes of crackers!")
    print("man that's enough for a party!")
    print("Get a blanket.\n")

print("We can just give the function numbers directly: ")
# cheese_and_crackers(input("How many cheeses do you have? "), input("How many boxes of crackers do you have? "))

print("OR, we can use variables from our script: ")
amount_of_cheese = 10 
amount_of_crackers = 50

cheese_and_crackers(amount_of_cheese, amount_of_crackers)

print("we can even do math inside too: ")
cheese_and_crackers(int(cheese_count) + 20, int(boxes_of_crackers) + 6)

print("And we can combine the two, variables and math: ")
cheese_and_crackers(amount_of_cheese + 100, amount_of_crackers + 1000)

