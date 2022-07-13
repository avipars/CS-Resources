# Comp Arch Notes 

| Binary Spot | Digit |
| ----------- | ----- |
| 1           | 0     |
| 2           | 1     |
| 4           | 2     |
| 8           | 3     |
| 16          | 4     |
| 32          | 5     |
| 64          | 6     |
| 128         | 7     |
| 256         | 8     |
| 512         | 9     |
| 1024        | 10    |
| 2048        | 11    |
| 4096        | 12    |
| 8192        | 13    |
| 16384       | 14    |
| 32768       | 15    |
| 65536       | 16    |
| 131072      | 17    |
| 262144      | 18    |
| 524288      | 19    |
| 1048576     | 20    |
| 2097152     | 21    |
| 4194304     | 22    |
| 8388608     | 23    |
| 16777216    | 24    |
| 33554432    | 25    |
| 67108864    | 26    |
| 134217728   | 27    |
| 268435456   | 28    |
| 536870912   | 29    |
| 1073741824  | 30    |
| 2147483648  | 31    |

(from the Patterson Book)
How the segments of memory are split up (note that this is generally accepted for the simulator, on actual MIPS chips the partitions could be set differently or non-existent)

![image](https://user-images.githubusercontent.com/5733247/177302019-1638ea3f-1aa1-44d1-9ccd-1059d0910e59.png)

## Floating Point

usually given in hex, such as 0xBE4CCCCD 
Then, simply convert to binary, there is a shortcut for doing this... each digit/letter cooresponds to 4 binary bits (8 4 2 1)... 

signed bit (1 bit)
exp (8 bits)
mantissa (23 bits)

sign of 1 is negative, 0 is positive 
exponent = convert as usual from binary to decimal, then you need to subtract 127 from your result (exp -127)
mantissa = start from the left most bit in mantissa, then the result is that number * 2<sup>-1</sup>... and proceed to the next 2<sup>-2</sup> * the next number, and move on till you hit the last 1. Because 0 * anything = 0, you can essentially skip the 0s, but make sure to still increment the exponent based on the position

Now that you got your mantissa, use this formula to convert it to decimal!

(-1)<sup>signedbit</sup> * (1+mantissa) * 2<sup>exp</sup> = end result!


## Cache Formulas 

Block is composed of: Tag | Set | Offset 

tag + set = logbase2(# of blocks in cache)

Size of main address – set – offset = tag

(size of main memory)/(size of block) = # of blocks in cache

2<sup>offset</sup> = size of block 

2<sup>set</sup> = # of rows 

N is for the n in n-way set associative (2-way SA -> = 2)
N*2<sup>set</sup> = # of blocks in cache

Total bits in cache = (size of block * 8 + 2 + tag) * N * 2<sup>set</sup> //in writeback

Total bits in cache = (size of block * 8 + 1 + tag) * N * 2<sup>set</sup> //in writethrough

Stack = LIFO

Queue = FIFO

Miss – no load to cache
-	Go to direct main memory 
o	Write into memory directly 


WB = Write Back

WA = Write Allocate

WT = Write Through

LRU = Least Recently Used

No WA = 	No-write allocate (also called write-no-allocate or write around): data at the missed-write location is not loaded to cache, and is written directly to the backing store. In this approach, data is loaded into the cache on read misses only.

1 Bit = 8 Bytes

4 Bytes = 1 Word = 32 Bits = 1 Instruction

2<sup>20</sup> = megabyte

## Stages

IF - fetch instruction

ID - decode instruction

EX - execute instruction 

MEM - Read memory

WB - write back (only needed for LW and such commands)
