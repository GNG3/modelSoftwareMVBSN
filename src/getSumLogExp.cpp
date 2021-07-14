#include <Rcpp.h>
#include "header.h"
using namespace Rcpp;

double getSumLogExp(NumericVector XBetaStar, NumericVector resultantVByVRandomEffects, NumericVector resultantWByURandomEffects)
{
  
  double answer = 0.0;
  
  for(int i = 0; i < XBetaStar.size(); i++){
    answer = answer + log(1 + exp(XBetaStar[i] + resultantVByVRandomEffects[i] + resultantWByURandomEffects[i]));
  }
  
  return answer;
  
}

