import csv

with open('dcc01.csv') as infile, open('dcc01.txt', 'w') as outfile:
    reader = csv.reader(infile, delimiter=',')
    writer = csv.writer(outfile, delimiter=' ')
    for row in reader:
        writer.writerow(row)
