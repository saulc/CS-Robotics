from math import pi, cos, sin, tan
import numpy as np


def deg(rad):
    return rad/pi

def rad(deg):
    return pi * deg/180


def demo():
    print (pi)
    # https://www.programiz.com/python-programming/matrix
    v = np.array([ [5], [30], [10] ])
    A = np.array([[2, 4], [5, -6]])
    B = np.array([[9, -3], [3, 6]])
    C = A + B      # element wise addition
    print(A)
    print(B)
    print("C = A + B")
    print(C)
    print("C = A dot B")
    C = A.dot(B)
    print(C)

def ex3():
    v = np.array([ [5], [30], [10] ])

    r1 = np.array([ [cos(rad(30)), -sin(rad(30)), 0] ,
                [sin(rad(30)), cos(rad(30)), 0],
                [0, 0, 1] ])
    print(r1)


ex3()


# A = [[1, 4, 5, 12],
#     [-5, 8, 9, 0],
#     [-6, 7, 11, 19]]
# print("A =", A)
# print("A[1] =", A[1])      # 2nd row
# print("A[1][2] =", A[1][2])   # 3rd element of 2nd row
# print("A[0][-1] =", A[0][-1])   # Last element of 1st Row
# column = [];        # empty list
# for row in A:
#   column.append(row[2])
# print("3rd column =", column)
