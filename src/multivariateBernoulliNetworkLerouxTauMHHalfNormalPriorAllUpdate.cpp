// [[Rcpp::depends(RcppProgress)]]
#include <progress.hpp>
#include <progress_bar.hpp>

#include <Rcpp.h>
#include "header.h"

using namespace Rcpp;

// [[Rcpp::export]]
List multivariateBernoulliNetworkLerouxTauMHHalfNormalPriorAllUpdate(NumericMatrix standardizedX,
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
                                                  double sigmaSquaredSpatialTau,
                                                  double xi,
                                                  NumericMatrix omega,
                                                  int currentNumberOfIterations,
                                                  const int numberOfSamples,
                                                  const int burnin,
                                                  const int thin,
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
  
  NumericMatrix betaSamples((numberOfSamples / thin), standardizedX.cols() * numberOfResponses);
  NumericMatrix spatialRandomEffectsSamples((numberOfSamples / thin), spatialRandomEffects.size());
  NumericMatrix uRandomEffectsSamples((numberOfSamples / thin), uRandomEffects.size());
  NumericMatrix spatialTauSamples(numberOfSamples / thin, numberOfResponses);
  NumericMatrix spatialRhoSamples(numberOfSamples / thin, numberOfResponses);
  NumericMatrix varianceCovarianceUSamples(numberOfSamples / thin, (numberOfResponses  + (numberOfResponses * numberOfResponses - numberOfResponses) / 2));
  
  NumericMatrix fittedValuesSamples((numberOfSamples / thin), standardizedX.rows() * numberOfResponses);
  NumericMatrix logLikelihoodsSamples((numberOfSamples / thin), standardizedX.rows() * numberOfResponses);
  
  int dimensionOfSpatialMatrix = squareSpatialNeighbourhoodMatrix.cols();
  NumericVector vectorOfOnes(dimensionOfSpatialMatrix, 1.0);
  
  NumericMatrix QSpatialMatrixComponent1 = matrixMatrixSubtractionRcpp(getDiagonalMatrix(matrixVectorMultiplicationRcpp(squareSpatialNeighbourhoodMatrix, vectorOfOnes)),
                                                                       squareSpatialNeighbourhoodMatrix);
  NumericVector QSpatialMatrixComponent1EigenValues = eigenValuesRcppConversion(QSpatialMatrixComponent1);
  
  int sampleCounter = 0;
  
  int totalNumberOfIterations = numberOfSamples + burnin;
  
  Progress progressBar(totalNumberOfIterations, true);
  
  for(int s = 0; s < totalNumberOfIterations; s++){
    
    progressBar.increment();
    
    if (Progress::check_abort()) return  Rcpp::List::create(Rcpp::Named("terminated") = -1);
    
    List output = multivariateBernoulliNetworkLerouxTauMHHalfNormalPriorSingleUpdate(standardizedX,
                                                                 y,
                                                                 numberOfResponses,
                                                                 squareSpatialNeighbourhoodMatrix,
                                                                 spatialAssignment,
                                                                 W,
                                                                 numberOfSpatialAreas,
                                                                 squareSpatialNeighbourhoodMatrixInTripletForm,
                                                                 spatialAssignmentMatrixInTripletForm,
                                                                 WInTripletForm,
                                                                 beta,
                                                                 spatialRandomEffects,
                                                                 uRandomEffects,
                                                                 spatialTau,
                                                                 spatialRho,
                                                                 varianceCovarianceU,
                                                                 covarianceBetaPrior,
                                                                 numberOfBetaBlocks,
                                                                 maxBetaBlockSize,
                                                                 betaTuningParameter,
                                                                 betaAcceptanceRate,
                                                                 numberOfAcceptedBetaDraws,
                                                                 numberOfAllAcceptedBetaDraws,
                                                                 spatialRandomEffectsTuningParameters,
                                                                 spatialRandomEffectsAcceptanceRate,
                                                                 numberOfAcceptedSpatialRandomEffectsDraws,
                                                                 numberOfAllAcceptedSpatialRandomEffectsDraws,
                                                                 uRandomEffectsTuningParameters,
                                                                 uRandomEffectsAcceptanceRate,
                                                                 numberOfAcceptedUREDraws,
                                                                 numberOfAllAcceptedUREDraws,
                                                                 spatialTauTuningParameters,
                                                                 spatialTauAcceptanceRate,
                                                                 numberOfAcceptedSpatialTauDraws,
                                                                 numberOfAllAcceptedSpatialTauDraws,
                                                                 spatialRhoTuningParameters,
                                                                 spatialRhoAcceptanceRate,
                                                                 numberOfAcceptedSpatialRhoDraws,
                                                                 numberOfAllAcceptedSpatialRhoDraws,
                                                                 QSpatialMatrixComponent1,
                                                                 QSpatialMatrixComponent1EigenValues,
                                                                 sigmaSquaredSpatialTau,
                                                                 xi,
                                                                 omega,
                                                                 currentNumberOfIterations,
                                                                 betaFixed,
                                                                 spatialRandomEffectsFixed,
                                                                 uRandomEffectsFixed,
                                                                 spatialTauFixed,
                                                                 spatialRhoFixed,
                                                                 varianceCovarianceUFixed,
                                                                 trueBetaValues,
                                                                 trueSpatialRandomEffectsValues,
                                                                 trueURandomEffectsValues,
                                                                 trueSpatialTauValues,
                                                                 trueSpatialRhoValues,
                                                                 trueVarianceCovarianceUValues,
                                                                 centerSpatialRandomEffects,
                                                                 centerURandomEffects);
    
    
    beta = output[0];
    betaTuningParameter = output[1];
    betaAcceptanceRate = output[2];
    numberOfAcceptedBetaDraws = output[3];
    numberOfAllAcceptedBetaDraws = output[4];
    
    spatialRandomEffects = output[5];
    spatialRandomEffectsTuningParameters = output[6];
    spatialRandomEffectsAcceptanceRate = output[7];
    numberOfAcceptedSpatialRandomEffectsDraws = output[8];
    numberOfAllAcceptedSpatialRandomEffectsDraws = output[9];
    
    uRandomEffects = output[10];
    uRandomEffectsTuningParameters = output[11];
    uRandomEffectsAcceptanceRate = output[12];
    numberOfAcceptedUREDraws = output[13];
    numberOfAllAcceptedUREDraws = output[14];
    
    spatialTau = output[15];
    spatialTauTuningParameters = output[16];
    spatialTauAcceptanceRate = output[17];
    numberOfAcceptedSpatialTauDraws = output[18];
    numberOfAllAcceptedSpatialTauDraws = output[19];
    
    spatialRho = output[20];
    spatialRhoTuningParameters = output[21];
    spatialRhoAcceptanceRate = output[22];
    numberOfAcceptedSpatialRhoDraws = output[23];
    numberOfAllAcceptedSpatialRhoDraws = output[24];
    
    varianceCovarianceU = as<NumericMatrix>(output[25]);
    
    NumericVector fittedValues = output[26];
    NumericVector logLikelihoods = output[27];
    
    if((currentNumberOfIterations > burnin) && (currentNumberOfIterations % thin == 0)){
      
      betaSamples(sampleCounter, _) = beta;
      spatialRandomEffectsSamples(sampleCounter, _) = spatialRandomEffects;
      uRandomEffectsSamples(sampleCounter, _) = uRandomEffects;
      spatialTauSamples(sampleCounter, _)= spatialTau;
      spatialRhoSamples(sampleCounter, _) = spatialRho;
      
      int varianceCovarianceSampleIndex = 0;
      NumericVector varianceCovarianceUCurrentSamples(numberOfResponses + (numberOfResponses * numberOfResponses - numberOfResponses) / 2);
      for(int j = 0; j < numberOfResponses; j++) {
        for(int z = j; z < numberOfResponses; z++) {
          varianceCovarianceUCurrentSamples[varianceCovarianceSampleIndex] = varianceCovarianceU(j, z);
          varianceCovarianceSampleIndex ++;
        }
      }
      varianceCovarianceUSamples(sampleCounter, _) = varianceCovarianceUCurrentSamples;
      
      fittedValuesSamples(sampleCounter, _) = fittedValues;
      logLikelihoodsSamples(sampleCounter, _) = logLikelihoods;
      
      sampleCounter++;
      
    }
    
    currentNumberOfIterations++;
    
  }
  
  List computationOfDIC = getMultivariateBernoulliNetworkLerouxDIC(standardizedX,
                                                                   y,
                                                                   spatialAssignment,
                                                                   W,
                                                                   betaSamples,
                                                                   spatialRandomEffectsSamples,
                                                                   uRandomEffectsSamples,
                                                                   logLikelihoodsSamples,
                                                                   numberOfResponses);
  
  
  double DBar = computationOfDIC[0];
  double posteriorDeviance = computationOfDIC[1];
  double pd = computationOfDIC[2];
  double DIC = computationOfDIC[3];
  
  List modelOutput(22);
  
  modelOutput[0] = betaSamples;
  modelOutput[1] = spatialRandomEffectsSamples;
  modelOutput[2] = uRandomEffectsSamples;
  modelOutput[3] = spatialTauSamples;
  modelOutput[4] = spatialRhoSamples;
  modelOutput[5] = varianceCovarianceUSamples;
  
  modelOutput[6] = betaAcceptanceRate;
  modelOutput[7] = spatialRandomEffectsAcceptanceRate;
  modelOutput[8] = uRandomEffectsAcceptanceRate;
  modelOutput[9] = spatialTauAcceptanceRate;
  modelOutput[10] = spatialRhoAcceptanceRate;
  
  modelOutput[11] = betaTuningParameter;
  modelOutput[12] = spatialRandomEffectsTuningParameters;
  modelOutput[13] = uRandomEffectsTuningParameters;
  modelOutput[14] = spatialTauTuningParameters;
  modelOutput[15] = spatialRhoTuningParameters;
  
  modelOutput[16] = fittedValuesSamples;
  modelOutput[17] = logLikelihoodsSamples;
  
  modelOutput[18] = DBar;
  modelOutput[19] = posteriorDeviance;
  modelOutput[20] = pd;
  modelOutput[21] = DIC;
  
  return modelOutput;
  
}
