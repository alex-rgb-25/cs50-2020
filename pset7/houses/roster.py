from cs50 import SQL
from csv import DictReader
from csv import reader
import sys
db = SQL("sqlite:///students.db")

# check command line args.... with sys module  in argv.
if len(sys.argv) == 2:
    hs = sys.argv[1]
    test = db.execute("SELECT * from students where house = '"+hs+"' ORDER BY last, first")   #query db

    for i in test:  # go through every dict in query
        strng = ''
        for key in i.keys():  # compose a string in strng and display the info
            if key == 'first':
                strng += i[key]
            if key == 'last':
                strng += " " +i[key]
            if key == 'middle' and i[key] != None:
                strng += " " + i[key]
            if key == 'birth':
                strng += ", born " + str(i[key])
        print(strng)
else:
    print("Incorrect nubmer of args. Please provide 2 arguments. Eg: python rooster.py Slytherin")