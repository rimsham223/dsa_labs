# DSA Lab 01

**Name:** Rimsha Mahmood
**Registration Number:** YOUR_REGISTRATION_NUMBER

## Programs

### Task 1

Creates an integer array, updates the third element, and displays all five elements using a loop.

### Task 2

Reads five integers into an array and calculates their total using a second loop. Simple test cases are used to verify the result.

### Task 3

Defines a `Student` class with roll number, marks, and a display function. Two objects are created and the effect of changing one object's marks is demonstrated.

### Task 4

Reads eight integers and finds the largest and smallest values along with their indices. For duplicate values, the first occurrence is reported.

### Task 5

Reads eight integers and finds the largest and smallest values along with their indices. For duplicate values, the first occurrence is reported.

### Task 6

Reads six integers and reverses the array in-place without using another array.

### Task 7

Reads ten integers and moves the first occurrence of each distinct value to the beginning of the same array while preserving the original order.

## Task 2 Test Results

| Test Input  | Expected Total | Actual Total |
| ----------- | -------------: | -----------: |
| 1 2 3 4 5   |             15 |           15 |
| 0 0 0 0 0   |              0 |            0 |
| -2 4 -1 0 3 |              4 |            4 |

## Task 3 Test Results

### Before changing s1.marks

```text
Roll Number: 1
Marks: 75
Roll Number: 2
Marks: 90
```

### After changing s1.marks to 80

```text
Roll Number: 1
Marks: 80
Roll Number: 2
Marks: 90
```

Changing `s1.marks` does not change `s2.marks` because `s1` and `s2` are separate objects, and each object has its own data members.
