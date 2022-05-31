#include <Rcpp.h>
#include <string>
#include <vector>
#include <numeric>      
#include <algorithm> 

using namespace Rcpp;

// [[Rcpp::plugins(cpp11)]]
// [[Rcpp::export]]

CharacterVector vec_replace( 
			    CharacterVector x,
			    CharacterVector find,
			    CharacterVector replace
			    )

{

    // sort x and keep sorted ids
    ///-----------------------------------------------------

    // test if find and replace are same length
    // if not, throw exception 
    int n_find = find.size();
    int n_replace = replace.size();

    if( n_find != n_replace){
	throw std::invalid_argument( "find and replace vectors are different lengths");
    }

    // make original id vector
    int n_x = x.size();
    IntegerVector id_x = seq(0, n_x - 1);

    // get index of sorted ids
     std::iota( id_x.begin(), id_x.end(), 0 ); 
     std::sort( id_x.begin(), id_x.end(), [&](int i,int j){return x[i] < x[j]; } );

    // sort x 
    x = x[id_x];


    // sort find and replace in same order
    ///-----------------------------------------------------

    // make original id vector
    IntegerVector id_find = seq(0, n_find - 1);

    // get index of sorted ids
     std::iota( id_find.begin(), id_find.end(), 0); 
     std::sort( id_find.begin(), id_find.end(), [&](int i,int j){return find[i] < find[j]; } );

    // sort find and replace
    find = find[id_find];
    replace = replace[id_find];



    // loop over x_sorted and find / replace
    int find_counter = 0;

    for( int i = 0; i < n_x; i++ ){

	// if find counter not at end
	// and x matches find at current counter
	//  then replace x with replace
	    

	if( find_counter < n_find && x[i] == find[ find_counter ] ){
	    
	    // save old element
	    String x_old = x[i];
	    
	    // replace element
	    x[i] =  replace[ find_counter ];

	    // if next element still in x
	    // test if next element of x equals current element
	    // if true, then advance find counter

	    if( i + 1 < n_x ){

		if( x_old != x[i+1] ){

		    find_counter++;

		}
	    }
	}
    }


    // return x to original order
    //-----------------------------------------------------


    // make final id vector
    IntegerVector id_final = seq(0, n_x - 1);

    // get index of sorted ids
     std::iota( id_final.begin(), id_final.end(), 0); 
     std::sort( id_final.begin(), id_final.end(), [&](int i,int j){return id_x[i] < id_x[j]; } );

    // sort in original order
     x = x[id_final];


    return x;

}
