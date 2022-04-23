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


Now, finally, we focus attention on relevant Blueprint logic

![image](https://user-images.githubusercontent.com/2173654/164894970-d3bc2228-6050-47d1-a48a-737bc4c615bd.png)

I would like to name the methadology as RT sampling. You just need to press R and T once the ``ArrayLenght`` is set.

**R**: Bare Pure logic (with native Pure node) with the claimed pitfall (in above blog-post)<br>
**T**: Cache introduced with same logic flow

