# Comp Arch Notes 

## Cache Formulas 

tag + set = logbase2(# of blocks in cache)

size of main memory/size of block = # of blocks in cache

N*2^set = # of blocks in cache

2^offset = size of block 

2^set = # of rows 

Total bits in cache = (size of block * 8 + 2 + tag) * N * 2^set //in WB

Total bits in cache = (size of block * 8 + 1 + tag) * N * 2^set //in WT

Size of main address – set – offset = tag
