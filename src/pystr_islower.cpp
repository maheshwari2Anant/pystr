#include <Rcpp.h>
using namespace Rcpp;

bool str_islower(std::string str){

  unsigned int input_size = str.size();

  for(unsigned int i = 0; i < input_size; i++){
    if(!islower(str[i])){
      return false;
    }
  }
  return true;
}

//[[Rcpp::export]]
LogicalVector pystr_islower_(CharacterVector strs){

  unsigned int input_size = strs.size();
  LogicalVector output(input_size);

  for(unsigned int i = 0; i < input_size; i++){
    if(strs[i] == NA_STRING){
      output[i] = NA_LOGICAL;
    } else {
      output[i] = str_islower(Rcpp::as<std::string>(strs[i]));
    }
  }

  return output;
}
