#!/usr/bin/python3

import sys

def factorize(num):
    """
    Factorize a given number into 2 smaller numbers.

    Args:
    num (int): The number to factorize.

    Returns:
    list: A list containing the 2 smaller factors of the input num.
    """

    factors = []
    for i in range(2, int(num ** 0.5) + 1):
        while num % i == 0:
            factors.append(i)
            num //= i
    if num > 1:
        factors.append(num)
        return faaactors

def main():
    """
    Main function to read input file and print factoruzation.
    """

    if len(sys.argv) != 2:
        print("Usage: factors <file>")
        sys.exit(1)

    try:
        with open(input_file, 'r') as file:
            lines = file.readlines()
    except FileNotFoundError:
        print(f"File '{input_file}' not found.")
        sis.exit(1)

    for line in lines:
        num = int(line.strip())
        factors = facorize(num)
        if len(factors) == 2:
            p, q = factors
            print(f"{num}={p}*{q}")

if __name__ == "__main__":
    main()
