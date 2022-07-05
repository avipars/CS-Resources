# Comp Arch Notes 

(from the Patterson Book)
How the segments of memory are split up 

![image](https://user-images.githubusercontent.com/5733247/177302019-1638ea3f-1aa1-44d1-9ccd-1059d0910e59.png)

## Floating Point

usually given in hex, such as 0xBE4CCCCD 
Then, simply convert to binary, there is a shortcut for doing this... each digit/letter cooresponds to 4 binary bits (8 4 2 1)... 

signed bit (1 bit)
exp (8 bits)
mantissa (23 bits)

sign of 1 is negative, 0 is positive 
exponent = convert as usual from binary to decimal, then you need to subtract 127 from your result (exp -127)
mantissa = start from the left most bit in mantissa, then the result is that number * 2^-1... and proceed to the next 2^-2 * the next number, and move on till you hit the last 1. Because 0 * anything = 0, you can essentially skip the 0s, but make sure to still increment the exponent based on the position

Now that you got your mantissa, use this formula to convert it to decimal!
(-1)^signedbit * (1+mantissa) * 2^exp = end result!


## Cache Formulas 

tag + set = logbase2(# of blocks in cache)

size of main memory/size of block = # of blocks in cache

N*2^set = # of blocks in cache

2^offset = size of block 

2^set = # of rows 

Total bits in cache = (size of block * 8 + 2 + tag) * N * 2^set //in WB

Total bits in cache = (size of block * 8 + 1 + tag) * N * 2^set //in WT

Size of main address – set – offset = tag
