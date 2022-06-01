#include <Rcpp.h>
#include <string>
#include <map>
#include <vector>

using namespace Rcpp;

// [[Rcpp::plugins(cpp11)]]
// [[Rcpp::export]]

std::vector<std::string> vec_replace( 
	std::vector<std::string> x, 
	std::vector<std::string> find,
	std::vector<std::string> replace
	)
{


    // test if find and replace are same length
    // if not, throw exception 
    if( find.size() != replace.size() ){
	throw std::invalid_argument( "Find and replace vectors are different lengths");
    }

    // map of find keys
    std::unordered_map<std::string, bool> find_map;

    // map of replace keys
    std::unordered_map<std::string, std::string> replace_map;


    // loop over find and push values into find_map and replace_map
    for(int i = 0; i < find.size(); i++){

        find_map[ find[i] ] = true;
        replace_map[ find[i] ] = replace[i];

    }


    // loop over x 
    // if x value in find_map, replace it with the value from replace_map
    for(int i = 0; i < x.size(); i++){

        if( find_map[ x[i] ] == true){

	    x[i] = replace_map[ x[i] ];

	}
    }

    return x;
}
