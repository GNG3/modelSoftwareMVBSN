#include <Rcpp.h>
#include "header.h"

using namespace Rcpp;

List getMultivariateBernoulliNetworkLerouxFittedValuesForDICEveryIteration(NumericMatrix standardizedX,
                                                                                         NumericVector y,
                                                                                         NumericMatrix spatialAssignment,
                                                                                         NumericMatrix W,
                                                                                         NumericVector beta,
                                                                                         NumericVector spatialRandomEffects,
                                                                                         NumericVector uRandomEffects,
                                                                                         int numberOfResponses)
{
  
  int numberOfLoglikelihoods = (standardizedX.rows() * numberOfResponses);
  NumericVector logitTheta(numberOfLoglikelihoods);
  NumericVector logLikelihoods(numberOfLoglikelihoods);
  
  int numberOfColumnsInX = standardizedX.cols();
  int numberOfColumnsInV = spatialAssignment.cols();
  int numberOfColumnsInW = W.cols();
  
  for(int i = 0; i < numberOfResponses; i++) {
    logitTheta[Range(i * standardizedX.rows(), ((i + 1) * standardizedX.rows()) - 1)] = matrixVectorMultiplicationRcpp(standardizedX, getSubvector(beta, i * numberOfColumnsInX, ((i + 1) * numberOfColumnsInX) - 1))
    + matrixVectorMultiplicationRcpp(spatialAssignment, getSubvector(spatialRandomEffects, i * numberOfColumnsInV, ((i + 1) * numberOfColumnsInV) - 1))
    + matrixVectorMultiplicationRcpp(W, getSubvector(uRandomEffects, i * numberOfColumnsInW, ((i + 1) * numberOfColumnsInW) - 1));
  }
  
  NumericVector fittedValues = getExpDividedByOnePlusExp(logitTheta);
  
  for(int i = 0; i < numberOfLoglikelihoods; i++) {
    logLikelihoods[i] = R::dbinom(y[i], 1, fittedValues[i], true);
  }
  
  List output(2);
  output[0] = fittedValues;
  output[1] = logLikelihoods;
  return output;
  
}