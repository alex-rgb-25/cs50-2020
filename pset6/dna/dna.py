import csv
import sys
from csv import DictReader
from csv import reader

tofind=[]
ok=0

if len(sys.argv) == 3:

    with open(sys.argv[2], newline='') as seqfile:  #read the seq file
        seq = seqfile.read()

    with open(sys.argv[1], 'r') as read_obj:  #read the db file
        csv_dict_reader = DictReader(read_obj)
        # iterate over each line as a ordered dictionary
        for row in csv_dict_reader:
            # row variable is a dictionary that represents a row in csv
            column_names = csv_dict_reader.fieldnames

    for i in range(len(column_names)-1):
        tofind.insert(i,[column_names[i+1],1])   # create the list with each STR


#count the number of STRs in a sequence in the file and add them to tofind
    for i in range(len(tofind)):
        for j in range(len(seq)):
            if tofind[i][0] == seq[j: j+len(tofind[i][0])]:
                #print(tofind[i])
                if seq[j+len(tofind[i][0]) : j+len(tofind[i][0])+len(tofind[i][0])] == tofind[i][0]: #then there are two matches in a row
                    tofind[i][1] += 1
                    #print(seq[j: j+len(tofind[i][0])])

#search the DB for matches:

    with open(sys.argv[1], 'r') as read_obj:
        csv_reader = reader(read_obj)
        header = next(csv_reader)
        # Check file as empty
        if header != None:
            # Iterate over each row after the header in the csv
            for row in csv_reader:
                found = 1
               # print("NEW ROW RIGHT HERE")
                # row variable is a list that represents a row in csv
                for i in range(len(row)-1):
                    #print(f"line {i} tofind[i][1]:",tofind[i][1])
                    #print(f"line {i} row[i]",row[i+1])

                    if int(row[i+1]) != tofind[i][1]:
                        found = 0

                    #check if reached end of row. If at the end found still 1 it's a match!
                    if i == len(row)-2 and found == 1:
                        #print("Here is the bastard:")
                        print(row[0])
                        ok=1

    if ok == 0:
        print("No match")

else:
    print('Two arguments required. Usage: python dna.py data.csv sequence.txt')
