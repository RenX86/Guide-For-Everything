from sys import argv
from os.path import exists

from_file = input("What is the filename: ")
to_file = input("What is the name of the file to copy to: ")

print(f"Copying from {from_file} to {to_file}")

in_file = open(from_file)
indata = in_file.read()

print(f"The input file is {len(indata)} bytes long")
print(f"Does the output file exist? {exists(to_file)}")
print("Ready hit ENTER to continue, CTRL-C to abort.")

input()

out_file = open(to_file, 'w')
out_file.write(indata)

print("Alright, all done.")

out_file.close()
in_file.close()