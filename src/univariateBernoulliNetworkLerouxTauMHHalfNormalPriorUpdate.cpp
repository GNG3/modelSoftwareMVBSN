#include <Rcpp.h>
#include "header.h"

using namespace Rcpp;

List univariateBernoulliNetworkLerouxTauMHHalfNormalPriorUpdate(NumericMatrix squareSpatialNeighbourhoodMatrix,
                                                                NumericVector spatialRandomEffects,
                                                                double spatialTau,
                                                                double spatialTauTuningParameters,
                                                                double spatialTauAcceptanceRate,
                                                                double numberOfAcceptedSpatialTauDraws,
                                                                double numberOfAllAcceptedSpatialTauDraws,
                                                                double spatialRho,
                                                                double sigmaSquaredSpatialTau,
                                                                NumericMatrix QSpatialMatrixComponent1,
                                                                int currentNumberOfIterations)
{
  
  int updateIndex = 100;
  
  int dimensionOfSpatialMatrix = squareSpatialNeighbourhoodMatrix.cols();
  NumericVector vectorOfOnes(dimensionOfSpatialMatrix, 1.0);
  
  double spatialTauStar = -1.0;
  
  while(spatialTauStar < 0){
    spatialTauStar = rnorm(1, spatialTau, spatialTauTuningParameters)[0];
  }
  
  NumericMatrix QSpatialMatrix = matrixMatrixAdditionRcpp(doubleMatrixMultiplicationRcpp(spatialRho, QSpatialMatrixComponent1),
                                                          doubleMatrixMultiplicationRcpp((1 - spatialRho),  getDiagonalMatrix(vectorOfOnes)));
  
  double spatialRandomEffectsBySpatialQBySpatialRandomEffectsMultiplication = vectorTransposeVectorMultiplicationRcpp(spatialRandomEffects, matrixVectorMultiplicationRcpp(QSpatialMatrix, spatialRandomEffects));
  
  double spatialTauSquared = spatialTau * spatialTau;
  double spatialTauSquaredStar = spatialTauStar * spatialTauStar;
  
  double logSpatialTauStarLikelihood = - dimensionOfSpatialMatrix * 0.5 * log(spatialTauSquaredStar)
    - 0.5 * (spatialTauSquaredStar / sigmaSquaredSpatialTau) 
    - (1 / spatialTauSquaredStar) * (0.5 * spatialRandomEffectsBySpatialQBySpatialRandomEffectsMultiplication)
    + log(R::pnorm(spatialTauSquared / spatialTauTuningParameters, 0.0, 1.0, TRUE, FALSE)); 
    
  double logSpatialTauCurrentLikelihood = - dimensionOfSpatialMatrix * 0.5 * log(spatialTauSquared)
    - 0.5 * (spatialTauSquared / sigmaSquaredSpatialTau) 
    - (1 / spatialTauSquared) * (0.5 * spatialRandomEffectsBySpatialQBySpatialRandomEffectsMultiplication)
    + log(R::pnorm(spatialTauSquaredStar / spatialTauTuningParameters, 0.0, 1.0, TRUE, FALSE));
    
  double logA = logSpatialTauStarLikelihood - logSpatialTauCurrentLikelihood;
  
  double U = runif(1)[0];
  
  if(log(U) < logA){
    spatialTau = spatialTauStar;
    numberOfAcceptedSpatialTauDraws++;
    numberOfAllAcceptedSpatialTauDraws++;
  }
  
  spatialTauAcceptanceRate = numberOfAllAcceptedSpatialTauDraws / currentNumberOfIterations;
  
  if(currentNumberOfIterations % updateIndex == 0){
    double kthSpatialTauAcceptanceRate = numberOfAcceptedSpatialTauDraws / updateIndex;
    if(kthSpatialTauAcceptanceRate > 0.5){
      spatialTauTuningParameters = 1.1 * spatialTauTuningParameters;
    }
    if(kthSpatialTauAcceptanceRate < 0.4){
      spatialTauTuningParameters = 0.9 * spatialTauTuningParameters;
    }
    numberOfAcceptedSpatialTauDraws = 0;
  }
  
  List output(5);
  output[0] = spatialTau;
  output[1] = spatialTauTuningParameters;
  output[2] = spatialTauAcceptanceRate;
  output[3] = numberOfAcceptedSpatialTauDraws;
  output[4] = numberOfAllAcceptedSpatialTauDraws;
  return output;
      
}