# TODO
from cs50 import SQL
from csv import DictReader
from csv import reader
import sys
db = SQL("sqlite:///students.db")

# check command line args.... with sys module  in argv.
if len(sys.argv) == 2:
    # open read file
    with open(sys.argv[1], newline='') as seqfile:
        csv_reader = reader(seqfile)
        header = next(csv_reader)
        #db.execute("CREATE TABLE students (firstName varchar(255), midName varchar(255), lastName varchar(255), house varchar(255), birth int)")
        for row in csv_reader: # each row after column names
            if len(row[0].split()) == 3: # check if there is a midName and build the query
                x = row[0].split()
                first = x[0]
                mid = x[1]
                last = x[2]
                house = row[1]
                birth = row[2]
                db.execute("INSERT INTO students (first,middle,last,house,birth) VALUES ('"+first+"','"+mid+"','"+last+"','"+house+"','"+birth+"')")
            if len(row[0].split()) == 2:  # if there is no midName insert NULL
                y = row[0].split()
                first1 = y[0]
                last1 = y[1]
                house1 = row[1]
                birth1 = row[2]
                db.execute("INSERT INTO students (first,middle,last,house,birth) VALUES ('"+first1+"',NULL,'"+last1+"','"+house1+"','"+birth1+"')")
else:
    print("incorrect number of args.")