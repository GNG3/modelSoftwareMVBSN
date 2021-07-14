#include <Rcpp.h>
#include "header.h"

using namespace Rcpp;

List multivariateBernoulliNetworkLerouxTauMHHalfNormalPriorUpdate(NumericMatrix squareSpatialNeighbourhoodMatrix,
                                                                           NumericVector spatialRandomEffects,
                                                                           const int numberOfResponses,
                                                                           NumericVector spatialTau,
                                                                           NumericVector spatialTauTuningParameters,
                                                                           NumericVector spatialTauAcceptanceRate,
                                                                           NumericVector numberOfAcceptedSpatialTauDraws,
                                                                           NumericVector numberOfAllAcceptedSpatialTauDraws,
                                                                           NumericVector spatialRho,
                                                                           double sigmaSquaredSpatialTau,
                                                                           NumericMatrix QSpatialMatrixComponent1,
                                                                           int currentNumberOfIterations)
{
  
  int numberOfColumnsInSpatialAssignmentMatrix = spatialRandomEffects.size() / numberOfResponses;

  for(int j = 0; j < numberOfResponses; j++) {
    
    List output = univariateBernoulliNetworkLerouxTauMHHalfNormalPriorUpdate(squareSpatialNeighbourhoodMatrix,
                                                                               getSubvector(spatialRandomEffects, j * numberOfColumnsInSpatialAssignmentMatrix, ((j + 1) * numberOfColumnsInSpatialAssignmentMatrix) - 1),
                                                                               spatialTau[j],
                                                                               spatialTauTuningParameters[j],
                                                                               spatialTauAcceptanceRate[j],
                                                                               numberOfAcceptedSpatialTauDraws[j],
                                                                               numberOfAllAcceptedSpatialTauDraws[j],
                                                                               spatialRho[j],
                                                                               sigmaSquaredSpatialTau,
                                                                               QSpatialMatrixComponent1,
                                                                               currentNumberOfIterations);
    
    spatialTau[j] = output[0];
    spatialTauTuningParameters[j] = output[1];
    spatialTauAcceptanceRate[j] = output[2];
    numberOfAcceptedSpatialTauDraws[j] = output[3];
    numberOfAllAcceptedSpatialTauDraws[j] = output[4];
    
  }
  
  List output(5);
  output[0] = spatialTau;
  output[1] = spatialTauTuningParameters;
  output[2] = spatialTauAcceptanceRate;
  output[3] = numberOfAcceptedSpatialTauDraws;
  output[4] = numberOfAllAcceptedSpatialTauDraws;
  return output;
      
}