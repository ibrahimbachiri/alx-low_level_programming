#!/usr/bin/python3
import random
import ctypes
import os

# Get the current working directory
current_directory = os.getcwd()

# Full path to the shared object file
shared_object_path = os.path.join(current_directory, '100-operations.so')

# Load the dynamic library
cops = ctypes.CDLL(shared_object_path)

# Generate random numbers
a = random.randint(-111, 111)
b = random.randint(-111, 111)

# Call the C functions from Python
print("{} + {} = {}".format(a, b, cops.add(a, b)))
print("{} - {} = {}".format(a, b, cops.sub(a, b)))
print("{} x {} = {}".format(a, b, cops.mul(a, b)))
print("{} / {} = {}".format(a, b, cops.div(a, b)))
print("{} % {} = {}".format(a, b, cops.mod(a, b)))
