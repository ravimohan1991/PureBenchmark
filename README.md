# PureBenchmark
Testing a contention written in [blog-post](https://celdevs.com/2021/09/14/unreal-engine-and-the-hidden-pitfalls-of-blueprints/). The suggested measures are pondered upon,
introspected, and concretely subjected to large stresses. The results do fall in line with the said article.

Contention: <ins>[Pure](https://docs.unrealengine.com/4.27/en-US/ProgrammingAndScripting/Blueprints/UserGuide/Functions/#purevs.impure) Blueprint Nodes are expensive in certain contexts</ins>.

Resolution: <ins>Cache the relevant outputs of the Pure nodes</ins>.


# Testify yourself
Clone the repository and open with UE 4.27.2. Start the PIE and press R or T for un-optimized and optimized unit testing. Observe the logs by manipulating the ``ArrayLength``
in ``TestorPC_BP``.

![image](https://user-images.githubusercontent.com/2173654/164894742-bb9b8d32-ea57-443a-a55b-a913f6e6d6f2.png)
(courtsey: [https://www.dcode.fr/points-plotter](https://www.dcode.fr/points-plotter))

The labels are as follows:

**x-axis**: array length <br>
**y-axis**: function (foreach loop) completion time in milliseconds


Now, we focus attention on relevant Blueprint logic

![image](https://user-images.githubusercontent.com/2173654/164894970-d3bc2228-6050-47d1-a48a-737bc4c615bd.png)

I would like to name the methadology as RT sampling. You just need to press R and T once the ``ArrayLenght`` is set.

**R**: Bare Pure logic (with native Pure node) with the claimed pitfall (in above blog-post)<br>
**T**: Cache introduced with same logic flow

Finally, logs (because logs...)
```
ArrayLength = 100
LogTemp: +------------------------------------------------
LogTemp: | Observervation Begin Clip ----> 
LogTemp: | Current seconds are: 30
LogTemp: | Current milliseconds are: 266
LogTemp: |   ===========================  
LogTemp: | Observervation End Clip ----> 
LogTemp: | Current seconds are: 30
LogTemp: | Current milliseconds are: 267
LogTemp: | Total Elapsed Time (milli): 1
LogTemp: +------------------------------------------------
LogTemp: +------------------------------------------------
LogTemp: | Observervation Begin Clip ----> 
LogTemp: | Current seconds are: 31
LogTemp: | Current milliseconds are: 700
LogTemp: |   ===========================  
LogTemp: | Observervation End Clip ----> 
LogTemp: | Current seconds are: 31
LogTemp: | Current milliseconds are: 700
LogTemp: | Total Elapsed Time (milli): 0
LogTemp: +------------------------------------------------

ArrayLength = 500
LogTemp: +------------------------------------------------
LogTemp: | Observervation Begin Clip ----> 
LogTemp: | Current seconds are: 4
LogTemp: | Current milliseconds are: 147
LogTemp: |   ===========================  
LogTemp: | Observervation End Clip ----> 
LogTemp: | Current seconds are: 4
LogTemp: | Current milliseconds are: 151
LogTemp: | Total Elapsed Time (milli): 4
LogTemp: +------------------------------------------------
LogTemp: +------------------------------------------------
LogTemp: | Observervation Begin Clip ----> 
LogTemp: | Current seconds are: 5
LogTemp: | Current milliseconds are: 12
LogTemp: |   ===========================  
LogTemp: | Observervation End Clip ----> 
LogTemp: | Current seconds are: 5
LogTemp: | Current milliseconds are: 14
LogTemp: | Total Elapsed Time (milli): 2
LogTemp: +------------------------------------------------

ArrayLength = 1500
LogTemp: +------------------------------------------------
LogTemp: | Observervation Begin Clip ----> 
LogTemp: | Current seconds are: 45
LogTemp: | Current milliseconds are: 708
LogTemp: |   ===========================  
LogTemp: | Observervation End Clip ----> 
LogTemp: | Current seconds are: 45
LogTemp: | Current milliseconds are: 727
LogTemp: | Total Elapsed Time (milli): 19
LogTemp: +------------------------------------------------
LogTemp: +------------------------------------------------
LogTemp: | Observervation Begin Clip ----> 
LogTemp: | Current seconds are: 46
LogTemp: | Current milliseconds are: 116
LogTemp: |   ===========================  
LogTemp: | Observervation End Clip ----> 
LogTemp: | Current seconds are: 46
LogTemp: | Current milliseconds are: 124
LogTemp: | Total Elapsed Time (milli): 8
LogTemp: +------------------------------------------------

ArrayLength = 2000
LogTemp: +------------------------------------------------
LogTemp: | Observervation Begin Clip ----> 
LogTemp: | Current seconds are: 51
LogTemp: | Current milliseconds are: 1
LogTemp: |   ===========================  
LogTemp: | Observervation End Clip ----> 
LogTemp: | Current seconds are: 51
LogTemp: | Current milliseconds are: 33
LogTemp: | Total Elapsed Time (milli): 32
LogTemp: +------------------------------------------------
LogTemp: +------------------------------------------------
LogTemp: | Observervation Begin Clip ----> 
LogTemp: | Current seconds are: 51
LogTemp: | Current milliseconds are: 653
LogTemp: |   ===========================  
LogTemp: | Observervation End Clip ----> 
LogTemp: | Current seconds are: 51
LogTemp: | Current milliseconds are: 665
LogTemp: | Total Elapsed Time (milli): 12
LogTemp: +------------------------------------------------

ArrayLength = 2500
LogTemp: +------------------------------------------------
LogTemp: | Observervation Begin Clip ----> 
LogTemp: | Current seconds are: 37
LogTemp: | Current milliseconds are: 143
LogTemp: |   ===========================  
LogTemp: | Observervation End Clip ----> 
LogTemp: | Current seconds are: 37
LogTemp: | Current milliseconds are: 185
LogTemp: | Total Elapsed Time (milli): 42
LogTemp: +------------------------------------------------
LogTemp: +------------------------------------------------
LogTemp: | Observervation Begin Clip ----> 
LogTemp: | Current seconds are: 37
LogTemp: | Current milliseconds are: 484
LogTemp: |   ===========================  
LogTemp: | Observervation End Clip ----> 
LogTemp: | Current seconds are: 37
LogTemp: | Current milliseconds are: 497
LogTemp: | Total Elapsed Time (milli): 13
LogTemp: +------------------------------------------------

ArrayLength = 3000
LogTemp: +------------------------------------------------
LogTemp: | Observervation Begin Clip ----> 
LogTemp: | Current seconds are: 28
LogTemp: | Current milliseconds are: 714
LogTemp: |   ===========================  
LogTemp: | Observervation End Clip ----> 
LogTemp: | Current seconds are: 28
LogTemp: | Current milliseconds are: 773
LogTemp: | Total Elapsed Time (milli): 59
LogTemp: +------------------------------------------------
LogTemp: +------------------------------------------------
LogTemp: | Observervation Begin Clip ----> 
LogTemp: | Current seconds are: 29
LogTemp: | Current milliseconds are: 38
LogTemp: |   ===========================  
LogTemp: | Observervation End Clip ----> 
LogTemp: | Current seconds are: 29
LogTemp: | Current milliseconds are: 53
LogTemp: | Total Elapsed Time (milli): 15
LogTemp: +------------------------------------------------

ArrayLength = 4000
LogTemp: +------------------------------------------------
LogTemp: | Observervation Begin Clip ----> 
LogTemp: | Current seconds are: 14
LogTemp: | Current milliseconds are: 588
LogTemp: |   ===========================  
LogTemp: | Observervation End Clip ----> 
LogTemp: | Current seconds are: 14
LogTemp: | Current milliseconds are: 685
LogTemp: | Total Elapsed Time (milli): 97
LogTemp: +------------------------------------------------
LogTemp: +------------------------------------------------
LogTemp: | Observervation Begin Clip ----> 
LogTemp: | Current seconds are: 14
LogTemp: | Current milliseconds are: 983
LogTemp: |   ===========================  
LogTemp: | Observervation End Clip ----> 
LogTemp: | Current seconds are: 15
LogTemp: | Current milliseconds are: 4
LogTemp: | Total Elapsed Time (milli): 21
LogTemp: +------------------------------------------------

ArrayLength = 5000
LogTemp: +------------------------------------------------
LogTemp: | Observervation Begin Clip ----> 
LogTemp: | Current seconds are: 14
LogTemp: | Current milliseconds are: 958
LogTemp: |   ===========================  
LogTemp: | Observervation End Clip ----> 
LogTemp: | Current seconds are: 15
LogTemp: | Current milliseconds are: 107
LogTemp: | Total Elapsed Time (milli): 149
LogTemp: +------------------------------------------------
LogTemp: +------------------------------------------------
LogTemp: | Observervation Begin Clip ----> 
LogTemp: | Current seconds are: 15
LogTemp: | Current milliseconds are: 439
LogTemp: |   ===========================  
LogTemp: | Observervation End Clip ----> 
LogTemp: | Current seconds are: 15
LogTemp: | Current milliseconds are: 464
LogTemp: | Total Elapsed Time (milli): 25
LogTemp: +------------------------------------------------
```
