//File: README.txt
//Author: Jonathan Carpenter
//Email: carpenter.102@wright.edu

This program implements a hash table using a given hashing function.
The two hashing functions supplied, sdbm and djb2 are used to 
create the hash table. Both functions distribute the data with
an average of one item per bucket. 

X = Random variable representing the number of elements in a bucket
P(X) = Probability of random variable X

sdbm
Expected number of entries in a bucket: 1
X    |0           |1           |2           |3           |4           |5           |6           |7           |8           
P(x) |0.367887    |0.368033    |0.183245    |0.062084    |0.015124    |0.00310814  |0.000450456 |5.63069e-05 |1.12614e-05

djb2
Expected number of entries in a bucket: 1
X    |0           |1           |2           |3           |4           |5           |6           |7           |8           |9           
P(x) |0.368124    |0.367065    |0.185351    |0.0600795   |0.0156533   |0.00309688  |0.000551808 |5.63069e-05 |1.12614e-05 |1.12614e-05  

To run program on unix
   1) type: make
   2) type: ./p4



