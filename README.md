# vec_replace

`vec_replace` is an R function for finding and replacing strings withing a vector.


### Inputs

The `vec_replace` function has three inputs:


* `` = a vector of string in which to search and replace
* `find` =  the strings to look for
* `replace` = the strings to replace

Note: `find` and `replace` must have the same length.

### Output
`vec_replace` returns the vector `x` with the appropriate substitutions. 


### Example


```R
library(Rcpp)
sourceCpp("vec_replace.cpp")

x = c("Bob", "Harry", "Sally", "Angela", "David")

find = c("Bob", "Angela")
replace = c("test1", "test2")

x_replace = vec_replace(x, find, replace)

[1] "test1" "Harry" "Sally" "test2" "David"

```



### Installation
To use `vec_replace`, install the following R packages:
 * [Rcpp](https://cran.r-vec_replace.org/web/packages/Rcpp/index.html) 

Put the source code (`vec_replace.cpp`) in the directory of your R script. Then source it with the command `sourceCpp('vec_replace.cpp')`.




