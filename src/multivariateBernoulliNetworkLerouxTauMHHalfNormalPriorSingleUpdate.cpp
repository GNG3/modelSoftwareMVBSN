#include <Rcpp.h>
#include "header.h"

using namespace Rcpp;

List multivariateBernoulliNetworkLerouxTauMHHalfNormalPriorSingleUpdate(NumericMatrix standardizedX,
                                                                         NumericVector y,
                                                                         const int numberOfResponses,
                                                                         NumericMatrix squareSpatialNeighbourhoodMatrix,
                                                                         NumericMatrix spatialAssignment,
                                                                         NumericMatrix W,
                                                                         const int numberOfSpatialAreas,
                                                                         NumericMatrix squareSpatialNeighbourhoodMatrixInTripletForm,
                                                                         NumericMatrix spatialAssignmentMatrixInTripletForm,
                                                                         NumericMatrix WInTripletForm,
                                                                         NumericVector beta,
                                                                         NumericVector spatialRandomEffects,
                                                                         NumericVector uRandomEffects,
                                                                         NumericVector spatialTau,
                                                                         NumericVector spatialRho,
                                                                         NumericMatrix varianceCovarianceU,
                                                                         double covarianceBetaPrior,
                                                                         const int numberOfBetaBlocks,
                                                                         const int maxBetaBlockSize,
                                                                         NumericVector betaTuningParameter,
                                                                         NumericVector betaAcceptanceRate,
                                                                         NumericVector numberOfAcceptedBetaDraws,
                                                                         NumericVector numberOfAllAcceptedBetaDraws,
                                                                         NumericVector spatialRandomEffectsTuningParameters,
                                                                         NumericVector spatialRandomEffectsAcceptanceRate,
                                                                         NumericVector numberOfAcceptedSpatialRandomEffectsDraws,
                                                                         NumericVector numberOfAllAcceptedSpatialRandomEffectsDraws,
                                                                         NumericVector uRandomEffectsTuningParameters,
                                                                         NumericVector uRandomEffectsAcceptanceRate,
                                                                         NumericVector numberOfAcceptedUREDraws,
                                                                         NumericVector numberOfAllAcceptedUREDraws,
                                                                         NumericVector spatialTauTuningParameters,
                                                                         NumericVector spatialTauAcceptanceRate,
                                                                         NumericVector numberOfAcceptedSpatialTauDraws,
                                                                         NumericVector numberOfAllAcceptedSpatialTauDraws,
                                                                         NumericVector spatialRhoTuningParameters,
                                                                         NumericVector spatialRhoAcceptanceRate,
                                                                         NumericVector numberOfAcceptedSpatialRhoDraws,
                                                                         NumericVector numberOfAllAcceptedSpatialRhoDraws,
                                                                         NumericMatrix QSpatialMatrixComponent1,
                                                                         NumericVector QSpatialMatrixComponent1EigenValues,
                                                                         double sigmaSquaredSpatialTau,
                                                                         double xi,
                                                                         NumericMatrix omega,
                                                                         int currentNumberOfIterations,
                                                                         bool betaFixed,
                                                                         bool spatialRandomEffectsFixed,
                                                                         bool uRandomEffectsFixed,
                                                                         bool spatialTauFixed,
                                                                         bool spatialRhoFixed,
                                                                         bool varianceCovarianceUFixed,
                                                                         NumericVector trueBetaValues,
                                                                         NumericVector trueSpatialRandomEffectsValues,
                                                                         NumericVector trueURandomEffectsValues,
                                                                         NumericVector trueSpatialTauValues,
                                                                         NumericVector trueSpatialRhoValues,
                                                                         NumericMatrix trueVarianceCovarianceUValues,
                                                                         bool centerSpatialRandomEffects,
                                                                         bool centerURandomEffects)
  
{
  
  int numberOfRowsInSquareSpatialNeighbourhoodMatrix = squareSpatialNeighbourhoodMatrixInTripletForm.rows();
  int numberOfRowsInSpatialAssignmentMatrixTripletForm = spatialAssignmentMatrixInTripletForm.rows();
  int numberOfRowsInWTripletForm = WInTripletForm.rows();
  
  NumericVector spatialTauSquared(numberOfResponses); 
  for(int j = 0; j < numberOfResponses; j++){
    spatialTauSquared[j] = spatialTau[j] * spatialTau[j];
  }
  
  if(betaFixed){
    
    beta = trueBetaValues;
    
  } else {
    
    List output = multivariateBernoulliNetworkLerouxBetaUpdate(standardizedX,
                                                               y,
                                                               numberOfResponses,
                                                               spatialAssignmentMatrixInTripletForm,
                                                               WInTripletForm,
                                                               numberOfRowsInSpatialAssignmentMatrixTripletForm,
                                                               numberOfRowsInWTripletForm,
                                                               beta,
                                                               spatialRandomEffects,
                                                               uRandomEffects,
                                                               covarianceBetaPrior,
                                                               numberOfBetaBlocks,
                                                               maxBetaBlockSize,
                                                               betaTuningParameter,
                                                               betaAcceptanceRate,
                                                               numberOfAcceptedBetaDraws,
                                                               numberOfAllAcceptedBetaDraws,
                                                               currentNumberOfIterations);
    
    beta = output[0];
    betaTuningParameter = output[1];
    betaAcceptanceRate = output[2];
    numberOfAcceptedBetaDraws = output[3];
    numberOfAllAcceptedBetaDraws = output[4];
    
  }
  
  if(spatialRandomEffectsFixed){
    
    spatialRandomEffects = trueSpatialRandomEffectsValues;
    
  } else {
    
    List output = multivariateBernoulliNetworkLerouxSpatialRandomEffectsUpdate(standardizedX,
                                                                               numberOfResponses,
                                                                               spatialAssignment,
                                                                               squareSpatialNeighbourhoodMatrix,
                                                                               y,
                                                                               numberOfSpatialAreas,
                                                                               squareSpatialNeighbourhoodMatrixInTripletForm,
                                                                               WInTripletForm,
                                                                               numberOfRowsInSquareSpatialNeighbourhoodMatrix,
                                                                               numberOfRowsInWTripletForm,
                                                                               beta,
                                                                               spatialRandomEffects,
                                                                               uRandomEffects,
                                                                               spatialTauSquared,
                                                                               spatialRho,
                                                                               spatialRandomEffectsTuningParameters,
                                                                               spatialRandomEffectsAcceptanceRate,
                                                                               numberOfAcceptedSpatialRandomEffectsDraws,
                                                                               numberOfAllAcceptedSpatialRandomEffectsDraws,
                                                                               currentNumberOfIterations,
                                                                               centerSpatialRandomEffects);
    
    spatialRandomEffects = output[0];
    spatialRandomEffectsTuningParameters = output[1];
    spatialRandomEffectsAcceptanceRate = output[2];
    numberOfAcceptedSpatialRandomEffectsDraws = output[3];
    numberOfAllAcceptedSpatialRandomEffectsDraws = output[4];
    
  }
  
  if(uRandomEffectsFixed){
    
    uRandomEffects = trueURandomEffectsValues;
    
  } else {
    
    List output = multivariateBernoulliNetworkLerouxURandomEffectsUpdate(standardizedX,
                                                                         y,
                                                                         W,
                                                                         numberOfResponses,
                                                                         spatialAssignmentMatrixInTripletForm,
                                                                         WInTripletForm,
                                                                         numberOfRowsInSpatialAssignmentMatrixTripletForm,
                                                                         numberOfRowsInWTripletForm,
                                                                         beta,
                                                                         spatialRandomEffects,
                                                                         uRandomEffects,
                                                                         varianceCovarianceU,
                                                                         uRandomEffectsTuningParameters,
                                                                         uRandomEffectsAcceptanceRate,
                                                                         numberOfAcceptedUREDraws,
                                                                         numberOfAllAcceptedUREDraws,
                                                                         currentNumberOfIterations,
                                                                         centerURandomEffects);
    
    uRandomEffects = output[0];
    uRandomEffectsTuningParameters = output[1];
    uRandomEffectsAcceptanceRate = output[2];
    numberOfAcceptedUREDraws = output[3];
    numberOfAllAcceptedUREDraws = output[4];
    
    
  }
  
  if(spatialTauFixed){
    
    spatialTau = trueSpatialTauValues;
    
  } else {
    
    List output = multivariateBernoulliNetworkLerouxTauMHHalfNormalPriorUpdate(squareSpatialNeighbourhoodMatrix,
                                                                               spatialRandomEffects,
                                                                               numberOfResponses,
                                                                               spatialTau,
                                                                               spatialTauTuningParameters,
                                                                               spatialTauAcceptanceRate,
                                                                               numberOfAcceptedSpatialTauDraws,
                                                                               numberOfAllAcceptedSpatialTauDraws,
                                                                               spatialRho,
                                                                               sigmaSquaredSpatialTau,
                                                                               QSpatialMatrixComponent1,
                                                                               currentNumberOfIterations);
    
    spatialTau = output[0];
    spatialTauTuningParameters = output[1];
    spatialTauAcceptanceRate = output[2];
    numberOfAcceptedSpatialTauDraws = output[3];
    numberOfAllAcceptedSpatialTauDraws = output[4];
    
    for(int j = 0; j < numberOfResponses; j++){
      spatialTauSquared[j] = spatialTau[j] * spatialTau[j];
    }
    
  }
  
  
  if(spatialRhoFixed){
    
    spatialRho = trueSpatialRhoValues;
    
  } else {
    
    List output = multivariateBernoulliNetworkLerouxRhoUpdate(squareSpatialNeighbourhoodMatrix,
                                                              spatialRandomEffects,
                                                              numberOfResponses,
                                                              spatialTauSquared,
                                                              spatialRho,
                                                              spatialRhoTuningParameters,
                                                              spatialRhoAcceptanceRate,
                                                              numberOfAcceptedSpatialRhoDraws,
                                                              numberOfAllAcceptedSpatialRhoDraws,
                                                              QSpatialMatrixComponent1,
                                                              QSpatialMatrixComponent1EigenValues,
                                                              currentNumberOfIterations);
    
    spatialRho = output[0];
    spatialRhoTuningParameters = output[1];
    spatialRhoAcceptanceRate = output[2];
    numberOfAcceptedSpatialRhoDraws = output[3];
    numberOfAllAcceptedSpatialRhoDraws = output[4];
    
  }
  
  
  if(varianceCovarianceUFixed){
    
    varianceCovarianceU = trueVarianceCovarianceUValues;
    
  } else {
    
    varianceCovarianceU = multivariateBernoulliNetworkLerouxVarianceCovarianceUUpdate(uRandomEffects,
                                                                                      numberOfResponses,
                                                                                      xi,
                                                                                      omega);
  }
  
  List fittedValuesAndLikelihood = getMultivariateBernoulliNetworkLerouxFittedValuesForDICEveryIteration(standardizedX,
                                                                                                                       y,
                                                                                                                       spatialAssignment,
                                                                                                                       W,
                                                                                                                       beta,
                                                                                                                       spatialRandomEffects,
                                                                                                                       uRandomEffects,
                                                                                                                       numberOfResponses);
  
  NumericVector fittedValues = fittedValuesAndLikelihood[0];
  NumericVector logLikelihoods = fittedValuesAndLikelihood[1];
  
  
  
  List output(28);
  
  output[0] = beta;
  output[1] = betaTuningParameter;
  output[2] = betaAcceptanceRate;
  output[3] = numberOfAcceptedBetaDraws;
  output[4] = numberOfAllAcceptedBetaDraws;
  
  output[5] = spatialRandomEffects;
  output[6] = spatialRandomEffectsTuningParameters;
  output[7] = spatialRandomEffectsAcceptanceRate;
  output[8] = numberOfAcceptedSpatialRandomEffectsDraws;
  output[9] = numberOfAllAcceptedSpatialRandomEffectsDraws;
  
  output[10] = uRandomEffects;
  output[11] = uRandomEffectsTuningParameters;
  output[12] = uRandomEffectsAcceptanceRate;
  output[13] = numberOfAcceptedUREDraws;
  output[14] = numberOfAllAcceptedUREDraws;
  
  output[15] = spatialTau;
  output[16] = spatialTauTuningParameters;
  output[17] = spatialTauAcceptanceRate;
  output[18] = numberOfAcceptedSpatialTauDraws;
  output[19] = numberOfAllAcceptedSpatialTauDraws;
  
  output[20] = spatialRho;
  output[21] = spatialRhoTuningParameters;
  output[22] = spatialRhoAcceptanceRate;
  output[23] = numberOfAcceptedSpatialRhoDraws;
  output[24] = numberOfAllAcceptedSpatialRhoDraws;
  
  output[25] = varianceCovarianceU;
  
  output[26] = fittedValues;
  output[27] = logLikelihoods;
  
  return output;
  
}