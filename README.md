# TwoBaseNumSystems
Implementation of (2, 3)-code algorithm and the linear Fibonacci Tree algorithm

  # TwoBaseNumSystems

### (2, 3)-Encoding

  Prefix-free codes are of considerable interest because of their extensive use in various applications, especially, in data compression and telecommunications. The best known representatives of such codes are Huffman code, the class of Elias codes, Levenshtein code, and classes of codes that are based on the representation of integers by sums of Fibonacci numbers.
  
  The program implements a new family of self-synchronizable codes obtained through the  (2, 3)-representation of natural numbers, introduced by Anisimov A.V. In the (2, 3)-representation along with the traditional radix-2, the auxiliary radix-3 is used. Such a choice of natural numbers representation provides a richer va-
riety of properties as compared with classical numeral systems of the single base 2 or 3. These properties are used in the construction of   (2, 3)-codes and they also define the structure of codewords delimiters. For suggested codes, encoding and decoding procedures are very simple and efficient.

**(2, 3)-integer representation**

All considered herein numbers belong to the set of natural numbers _\n_ extended by zero.
Let x be an integer greater or equal to 2. The (2, 3)-representation of is obtained by applying to the following iterative procedure.
Let _x<sub>i<sub/>_ = _x_. Extract from dividers 2 and 3 of maximum powers _n<sub>0<sub/>_ and _k<sub>0<sub/>_, respectively, <img src="https://render.githubusercontent.com/render/math?math=x_0 = 2^{n_0}3^{k_0}x_1">. The number <img src="https://render.githubusercontent.com/render/math?math=x_1"> is odd and not divisible by 3. If <img src="https://render.githubusercontent.com/render/math?math=x_1 = 1">, then the process ends. If <img src="https://render.githubusercontent.com/render/math?math=x_1\neq1">, then represent in the form <img src="https://render.githubusercontent.com/render/math?math=x_1 = 2^{n_1} + 3y_1">, where <img src="https://render.githubusercontent.com/render/math?math=n_1"> is the maximum power of 2 such that <img src="https://render.githubusercontent.com/render/math?math=x_1\equiv 2^{n_1} \mod 3">, and <img src="https://render.githubusercontent.com/render/math?math=x_1 - 2^{n_1} > 0">. If <img src="https://render.githubusercontent.com/render/math?math=y_1 = 1">, then the process ends.
  
  If <img src="https://render.githubusercontent.com/render/math?math=y_1 \neq 1">, then extract from <img src="https://render.githubusercontent.com/render/math?math=y_1"> the divisor of the form <img src="https://render.githubusercontent.com/render/math?math=3^m">, where m is the maximal possible power of 3. Thus, we obtain the representation <img src="https://render.githubusercontent.com/render/math?math=x_1 = 2^{n_1} + 3^{k_1}x_2">, where <img src="https://render.githubusercontent.com/render/math?math=x_2"> is odd and not divisible by 3.
Apply to <img src="https://render.githubusercontent.com/render/math?math=x_2"> actions that are analogous to those used at processing <img src="https://render.githubusercontent.com/render/math?math=x_1">.

In general, at the th stage of the iterative procedure, we get the remaining number  _x<sub>i</sub>_ = _2<sup>n<sub>i</sub><sup/>_ + _3<sup>k<sub>i</sub><sup/>_ _x<sub>n + 1</sub>_, i = 1,...,t.
Here, _n<sub>i<sub/>_ is the maximum power of 2 such that <img src="https://render.githubusercontent.com/render/math?math=x_i\equiv 2^{i} \mod 3"> and <img src="https://render.githubusercontent.com/render/math?math=x - 2^{n_i} > 0">, _x<sub>i+1<sub>_ is odd and not divisible by 3.
At the last step, _x<sub>t</sub>_ = _2<sup>n<sub>t</sub><sup/>_ + _3<sup>k<sub>t</sub><sup/>_ _x<sub>t + 1</sub>_ = 1.
So, the decomposition process described previously associates with the sequence of remaining numbers 
  
  _x<sub>0<sub>_, _x<sub>1<sub>_, _x<sub>2<sub>_,..., _x<sub>t<sub>_, _x<sub>t+1<sub>_     (1)

where _x<sub>0</sub>_ = _2<sup>n<sub>0</sub><sup/>_ * _3<sup>k<sub>0</sub><sup/>_ _x<sub>1</sub>_, _x<sub>i</sub>_ = _2<sup>n<sub>i</sub><sup/>_ + _3<sup>k<sub>i</sub><sup/>_ _x<sub>i + 1</sub>_, i=1,...,t, _x<sub>t+1<sub>_ = 1.

  Sequence (1) allows us to represent x in the following structural form:

<img src="https://render.githubusercontent.com/render/math?math=x=2^{n_0}3^{k_0}(2^n_1+3^{k_1}(2^{n_2}+...(2^{n_t} + 3^{k_t})...))">    (2)

_Examples_

20092009 = _2<sup>24<sup/>_ + 3(_2<sup>20<sup/>_ + 3 * (_2<sup>13<sup/>_+ _3<sup>2<sup/>_(_2<sup>10<sup/>_ + _3<sup>2<sup/>_(_2<sup>3<sup/>_+ _3<sup>2<sup/>_))))

20122012= _2<sup>2<sup/>_(_2<sup>22<sup/>_+ 3<sup>2<sup/>_( _2<sup>16<sup/>_+ 3 * (_2<sup>13<sup/>_+ 3(_2<sup>7<sup/>_+ 3( _2<sup>4<sup/>_+ _3<sup>2<sup/>_(_2<sup>1<sup/>_ + _3<sup>1<sup/>_))))))
  
  _**Algorithm (2, 3)-Decomposition**_
  
  1.  INPUT: a positive integer x
  2.  OUTPUT: the array A of pairs (_n<sub>i<sub/>_, _k<sub>i<sub/>_) from (1)
  3.  Represent x int the form x = _2<sup>n<sub>0<sub/><sup/>_ _3<sup>k<sub>0<sub/><sup/>_ _x<sub>1<sub/>_ where _x<sub>1<sub/>_ is odd and not divisible by 3, <img src="https://render.githubusercontent.com/render/math?math=i\gets 0">
  4.  Set <img src="https://render.githubusercontent.com/render/math?math=A[0]\gets(n_0, k_0)">, <img src="https://render.githubusercontent.com/render/math?math=u\gets x_1">
  5.  While <img src="https://render.githubusercontent.com/render/math?math=u_\neq_1"> do:
     
      5.1 Represent u in the form u = _2<sup>n<sup/>_+_3<sup>k<sup/>_ v where n is the maximum number such that <img src="https://render.githubusercontent.com/render/math?math=u\equiv2^n\mod3">, u - _2<sup>n<sup/>_ > 0, v is odd and not divisible by 3, <img src="https://render.githubusercontent.com/render/math?math=i\gets"> i+1
     
      5.2 <img src="https://render.githubusercontent.com/render/math?math=A[i]\gets(n, k)">, <img src="https://render.githubusercontent.com/render/math?math=u\gets v">
  
  6.   Return A
  
  

### Linear Fibonacci Forms

Special representation of natural numbers as linear forms of the type _xF<sub>t-1<sub/>_ + _yF<sub>t<sub/>_, where _F<sub>t<sub/>_ and _F<sub>t-1<sub/>_ are adjacent Fibonacci numbers,are used for constructing effective parallel algorithms of  modular  exponentiation  and factorization are considered in this report. These operations over large numbers are ones of the main in design and analysis of well-known public-key cryptosystems like RSA-schemes. Proofs of two important theorems are shown also.

The linear Fibonacci form of a range t is defined as a linear combination of the form: _xF<sub>t-1<sub/>_ + _yF<sub>t-1<sub/>_, where x and y are integers and <img src="https://render.githubusercontent.com/render/math?math=y\neq0">.

The linear Fibonacci tree is constructed in the following way.
1. The starting vertex is marked by n.
2. If a formed vertex is marked by a number z and _z\neq0_, then firstly we construct the linear Fibonacci representation for z of the maximum range, z=_xF<sub>t-1<sub/>_ + _yF<sub>t<sub/>_. Then we form two (or one the right if x = 0) vertices - sons for the vertex z. The left edge of z is marked by _F<sub>t-1<sub/>_, the right edge - by _F<sub>t<sub/>_. The corresponding vertices of the lower level  are  marked  respectively by  x  and  y .
3. Repeat the step 2 on all vertices having marks distinguished from 1.
The following fact is important.

**The depth of the linear Fibonacci tree of any number n is bounded by a value.**

It is interesting to note that in cryptographic schemes such as RSA or digital signature, in computing <img src="https://render.githubusercontent.com/render/math?math=x^{y}\mod(z)">, values y and z are given constants and x - is a variable. That is why the necessity to build a Fibonacci tree arises only once and the process of obtaining modular exponentiation is reduced to runs over the fixed Fibonacci tree.
Let's consider  the factorization  problem of large numbers. This problem often arises in different aspects of the open cryptology. There exist special computing factorization machines, for example, the sifting machine of C.Pomerance. The importance of finding concurrent homogeneous algorithms for this problem was also stressed by many authors.

Let _n=pq_, where q is a greater factor. For q there exists a linear Fibonacci representation of the maximum range t, q=_aF<sub>t-1<sub/>_ + _bF<sub>t<sub/>_. If n=_A<sub>0<sub/>_ _F<sub>t-1<sub/>_ + _A<sub>1<sub/>_ _F<sub>t<sub/>_ is some representation of the integer n as a linear Fibonacci form of the range t then for some parameter i the following equalities hold true: ap = _A<sub>0<sub/>_ + _iF<sub>t<sub/>_,
bp =  _A<sub>1<sub/>_ + _iF<sub>t-1<sub/>_.
  
From this using some properties of linear Fibonacci forms the factorization of n could be reduced to the sorting out problem p=GCD(n,d+i), where d is a computing constant and i is a sorting out parameter. It is possible to prove that for i the following inequality holds true:

<img src="https://render.githubusercontent.com/render/math?math=\frac{m}{F_tF_{t + 1}}<i<\frac{m}{F_tF_{t-1}}<p">                                                                      

where t is a range of the maximal linear Fibonacci form of q.

The sequential algorithm computing p by this formula gives time evaluation <img src="https://render.githubusercontent.com/render/math?math=O(\frac{m}{F_tF_{t+1}})">. This method works well if the number n has large (or small) factors or factors with large Fibonacci degrees. In this case the value _F<sub>t<sub/>_ is large and therefore <img src="https://render.githubusercontent.com/render/math?math=\frac{m}{F_tF_{t+1}}"> is of computable degree. When p and q are of the same degree the sequential search becomes quite exhaustive.
  
It is evident that this case also defines the possible parallel implementation like "processor farms" using partition of the diapason for i.
Taking into account the fact that all computations in the process of finding GCD(n,d+i) are similar to each other and based on the operation x mod y it is possible to suggest a pipe-line architecture for this considered task.
The basic computing module fulfills  computation:

_input (x,y); if  then {z:=x\mody; (x,y)=(y,z)}; output (x,y)}_. 

Connecting  of such elements into a ring and choosing a control point for data loading and checking the second field in pairs (x,y) one can assemble ring computing structure having  modules of the same type. The number  is taken from consideration that the number of steps in computing GCD according to the Euclid's scheme does not exceed . That is why under passing the control point if the second field is equal to 1 then loading of a next corresponding portion of data could be done, or if it is different from 1 then it is equal to the corresponding divisor of n.

### Useful Articles

- [Prefix Encoding by Means of the (2,3)-Representation of Numbers](https://ieeexplore.ieee.org/document/6384741)
- [Variable-length Splittable Codes with Multiple Delimiters](https://arxiv.org/abs/1508.01360)
- [Linear Fibonacci Forms and Parallel Algorithms for High Dimension Arithmetic](https://link.springer.com/chapter/10.1007/3-540-60222-4_93)
- [Representation of numbers in a mixed basis (2, 3)](http://dspace.nbuv.gov.ua/handle/123456789/44380)
- [Anti-jamming prefix coding using lower (2,3) -representation of numbers](http://dspace.nbuv.gov.ua/handle/123456789/115783)


