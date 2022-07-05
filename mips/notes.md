# Comp Arch Notes 

(from the Patterson Book)
How the segments of memory are split up 

![image](https://user-images.githubusercontent.com/5733247/177302019-1638ea3f-1aa1-44d1-9ccd-1059d0910e59.png)


## Cache Formulas 

tag + set = logbase2(# of blocks in cache)

size of main memory/size of block = # of blocks in cache

N*2^set = # of blocks in cache

2^offset = size of block 

2^set = # of rows 

Total bits in cache = (size of block * 8 + 2 + tag) * N * 2^set //in WB

Total bits in cache = (size of block * 8 + 1 + tag) * N * 2^set //in WT

Size of main address – set – offset = tag
