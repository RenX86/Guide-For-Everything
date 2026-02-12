fruit = [
    ['apples', 12, 'AAA'],
    ['oranges',1,'B'],
    ['Pears',2,'A'],
    ['Grapes',14,'UR']
    ]
cars = [
    ['Cadilac',['black','Big', 34500]],
    ['Corvette',['Red','Little', 10000000]],
    ['Ford',['Blue','Medium', 1234]],
    ['BMW',['White','Baby', 7890]]
    ]

languages = [
    ['Python' , ['slow',['Terrible']]],
    ['JavaScript',['Fun',['Alright', 'Mush']]],
    ['Perl',['Moderate',['Fun','Wierd']]],
    ['C',['Fast',['Annoying','Dagerous']]],
    ['Forth',['Fast',['Fun','Difficult']]]
    ]


def search(fruit, cars, languages):
    list_choice = input("Enter the list you want to search: ").lower()

    try:
        index1 = int(input("Enter the index of the list: "))
        index2 = int(input("Enter the index of the list: "))

        if list_choice == 'fruit':return  fruit[index1][index2]
        elif list_choice == 'cars':
            if index2 == 1:
                index3 = int(input("Enter the index of the list: "))
                return cars[index1][index2][index3]
            else:
                return cars[index1][index2]
            
        elif list_choice == 'languages':
            if index2 == 1:
                index3 = int(input("Enter the index of the list: "))
                return languages[index1][index2][index3]
            return languages[index1][index2]
        else:
            return "Invalid list choice"

    except IndexError:
        print("Index out of range")
    except ValueError:
        print("Invalid index value")
        
result = search(fruit, cars, languages)
print("Result: ", result)
