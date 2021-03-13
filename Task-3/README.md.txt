For Task - 3:

1.) Assume we have a hash table consisting of m = 11 slots, and suppose nonnegative integer key values are hashed into the table using the following hash function h():
int h1(int key) {
int x = (key + 5) * (key + 5);
x = x / 16;
x = x + key;
x = x % 11;
return x;
}
The sequence of 12 integer key values listed below are to be inserted in the table, in the order given. Suppose that collisions are resolved by using linear probing. Show the probe sequence (the sequence of slots to be probed until an empty one, if any, is available) for each key. In addition, show the final contents of the hash table after all keys are inserted.


2.) Write a C++ program to study how the hash table size affects the collision rate. The following are the requirements of this program:
a.) Generate 1000 random integers that represent the birthdays of people who were born between January 1, 2000 and December 31, 2004 in the format mmddyy. An example of such integers is 112303 for someone who was born on November 23, 2003. For simplicity, assume that all people were born before the 28th day of their birth month and do not worry about duplicate birthdays.
b.) Define four hash tables with the following sizes: m1 = 64, m2 = 66, m3 = 67, and m4 = p. Where p is a prime number of your choice that is less than 70. The size p should be selected so that it improves the performance of its hash table, in terms of number of collisions. 
c.) Simulate storing the 1000 random birthdays that you generate in step a in each of the four hash tables using hash function h(k) = k mod mi. Where k is the birthday integer and mi is the size of table i (i = 1, 2, 3, 4). Assume that collision is resolved by chaining. You do not need to generate the actual chains in your program instead store in each slot of the tables the number of birthdays that are mapped to that slot. Note that, at the end, if a slot of a table has the value x, this means there was (x‐1) collisions on that slot.
d.) For each one of the four tables, calculate the minimum, maximum, mean, and variance of the numbers stored in each table slots.
e.) Comments on the results you calculated in step d by explaining how the hash table size affects the collision rate.


