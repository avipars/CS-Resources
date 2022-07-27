---
title: 'C LeetCode Problem and Solution — Check if an array contains duplicate elements'
layout: post

external: true
blog: Medium
blog_link: https://aviparshan.medium.com/c-leetcode-problem-and-solution-check-if-an-array-contains-duplicate-elements-d7b4936c3130

categories: post
tags:
- CS
- C
- leetcode
---

C LeetCode problem and solution — Check if an array contains duplicate elements

Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct. I provide two possible solutions in C, one is brute force and O(N²) while the second one is O(nlogn).

Example 1:

Input: nums = [1,2,3,1]

Output: true

Example 2:

Input: nums = [1,2,3,4]

Output: false

Example 3:

Input: nums = [1,1,1,3,3,4,3,2,4,2]

Output: true

My solution is quite intuitive and it runs in O(N²) time. The worst case is where there are no duplicates, as both loops will have to execute till the end. Best case is if there are duplicate entries in the beginning as the program will detect tat and return true without needing to traverse so far.

bool containsDuplicate(int* nums, int numsSize){

for(int i = 0; i < numsSize; i++){ //outer loop n

for(int j = 0; j < i; j++){ //inner loop n

if(*(nums+j) == *(nums+i)){

return true; //found match

}

}

}

return false;

}

As it is brute force, we are better off with a different approach. Unsurprisingly, this will not run in LeetCode because it just takes too much time ;)

One possible approach would be to start sorting the array, then check for duplicates as they would have to appear in consecutive order. QuickSort, is the sort I selected is included in the C library. Unfortunately, the efficiency isn’t defined from the C standard, but we can assume it works similar to/ if not better than a standard quick sort.

It should be somewhere around O(nlogn) in the best and average case, while the worst is unknown as we don’t know where the partition is… It is certainly going to be better than O(N²). Just a reminder about the worst case in a standard QuickSort Algorithm… If the pivot happens to be at the start or end and the array is sorted already in ascending or descending order. If you were to put the pivot on a more optimal place, this case won’t happen.

Lastly, our check would occur in O(n) time.

#include <stdlib.h> //base library

int compare(const void * i1, const void * i2) //the quick sort requires a compare function

{

return *(const int *)i1 — *(const int *)i2;

}

bool containsDuplicate(int* nums, int numsSize){

qsort(nums, numsSize,sizeof(nums[0]), compare); //run the quicksort, pass the size of the array, size of each element (size of int), and the compare function

for(int i = 0; i < numsSize-1; ++i){ //don’t exceed bounds of array

if(*(nums+i) == *(nums+i+1)){ //check current with next element

return true;

}

}

return false;

}

An alternative approach is to implement your own sorting algorithm, and then do a check for duplicate entries there. Or, you can use another data structure such as a Set or HashSet