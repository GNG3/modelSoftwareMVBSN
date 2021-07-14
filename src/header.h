#include <Rcpp.h>
using namespace Rcpp;

double sumMatrix(NumericMatrix matrix);

NumericMatrix getDiagonalMatrix(NumericVector vector);

NumericMatrix matrixInverseRcppConversion(NumericMatrix matrix) ;

double getVectorMean(NumericVector vector);

double getSumLogExp(NumericVector XBetaStar, 
                    NumericVector resultantVByVRandomEffects, 
                    NumericVector resultantWByURandomEffects);

double vectorTransposeVectorMultiplicationRcpp(NumericVector vectorOne, 
                                               NumericVector vectorTwo);

NumericVector matrixVectorMultiplicationRcpp(NumericMatrix matrix, 
                                             NumericVector vector);

NumericVector getSubvector(NumericVector vector,
                           int startIndex,
                           int endIndex);

NumericVector getSubvectorIndecies(NumericVector vector,
                                   NumericVector indecies);

NumericVector getNonZeroEntries(NumericVector vector);

NumericVector doubleVectorMultiplicationRcpp(double number, 
                                             NumericVector vector);

double getSumVector(NumericVector vector);

double getSumLogExp(NumericVector XBetaStar, NumericVector resultantVByVRandomEffects, NumericVector resultantWByURandomEffects);

double getSumLogExpIndecies(NumericVector XBetaStar,
                            NumericVector resultantVByVRandomEffects,
                            NumericVector resultantWByURandomEffects,
                            NumericVector indecies);

NumericVector getMeanCenteredRandomEffects(NumericVector vector);

NumericVector eigenValuesRcppConversion(NumericMatrix matrix);

NumericMatrix matrixMatrixAdditionRcpp(NumericMatrix matrix1, 
                                       NumericMatrix matrix2);

NumericMatrix doubleMatrixMultiplicationRcpp(double number, 
                                             NumericMatrix matrix);

NumericMatrix vectorVectorTransposeMultiplicationRcpp(NumericVector vectorOne, 
                                                      NumericVector vectorTwo);

NumericVector getExpDividedByOnePlusExp(NumericVector logitTheta);

NumericMatrix matrixMatrixSubtractionRcpp(NumericMatrix matrix1, 
                                          NumericMatrix matrix2);

List getMultivariateBernoulliNetworkLerouxDIC(NumericMatrix standardizedX,
                                              NumericVector y,
                                              NumericMatrix V,
                                              NumericMatrix W,
                                              NumericMatrix betaSamples,
                                              NumericMatrix vRandomEffectsSamples,
                                              NumericMatrix uRandomEffectsSamples,
                                              NumericMatrix logLikelihoodSamples,
                                              int numberOfResponses);

List getMultivariateBernoulliNetworkLerouxFittedValuesForDICEveryIteration(NumericMatrix standardizedX,
                                                                                        NumericVector y,
                                                                                        NumericMatrix V,
                                                                                        NumericMatrix W,
                                                                                        NumericVector beta,
                                                                                        NumericVector vRandomEffects,
                                                                                        NumericVector uRandomEffects,
                                                                                        int numberOfResponses);

  
List univariateBernoulliNetworkLerouxBetaUpdate(NumericMatrix standardizedX,
                                                NumericVector y,
                                                const int numberOfRowsInX,
                                                const int numberOfColumnsInX,
                                                NumericMatrix spatialAssignmentMatrixInTripletForm,
                                                NumericMatrix WInTripletForm,
                                                const int numberOfRowsInSpatialAssignmentMatrixTripletForm,
                                                const int numberOfRowsInWTripletForm,
                                                NumericVector beta,
                                                NumericVector spatialRandomEffects,
                                                NumericVector uRandomEffects,
                                                double covarianceBetaPrior,
                                                const int numberOfBetaBlocks,
                                                const int maxBetaBlockSize,
                                                NumericVector betaTuningParameter,
                                                NumericVector betaAcceptanceRate,
                                                NumericVector numberOfAcceptedBetaDraws,
                                                NumericVector numberOfAllAcceptedBetaDraws,
                                                int currentNumberOfIterations);

List univariateBernoulliNetworkLerouxSpatialRandomEffectsUpdate(NumericMatrix standardizedX,
                                                                NumericMatrix spatialAssignment,
                                                                NumericMatrix squareSpatialNeighbourhoodMatrix,
                                                                NumericVector y,
                                                                const int numberOfRowsInX,
                                                                const int numberOfColumnsInX,
                                                                const int numberOfSpatialAreas,
                                                                NumericMatrix squareSpatialNeighbourhoodMatrixInTripletForm,
                                                                NumericMatrix WInTripletForm,
                                                                const int numberOfRowsInSquareSpatialNeighbourhoodMatrix,
                                                                const int numberOfRowsInWTripletForm,
                                                                NumericVector beta,
                                                                NumericVector spatialRandomEffects,
                                                                NumericVector uRandomEffects,
                                                                double spatialTauSquared,
                                                                double spatialRho,
                                                                NumericVector spatialRandomEffectsTuningParameters,
                                                                NumericVector spatialRandomEffectsAcceptanceRate,
                                                                NumericVector numberOfAcceptedSpatialRandomEffectsDraws,
                                                                NumericVector numberOfAllAcceptedSpatialRandomEffectsDraws,
                                                                int currentNumberOfIterations,
                                                                bool centerSpatialRandomEffects);

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
                                                                int currentNumberOfIterations);

List univariateBernoulliNetworkLerouxRhoUpdate(NumericMatrix squareSpatialNeighbourhoodMatrix,
                                               NumericVector spatialRandomEffects,
                                               double spatialTauSquared,
                                               double spatialRho,
                                               double spatialRhoTuningParameters,
                                               double spatialRhoAcceptanceRate,
                                               double numberOfAcceptedSpatialRhoDraws,
                                               double numberOfAllAcceptedSpatialRhoDraws,
                                               NumericMatrix QSpatialMatrixComponent1,
                                               NumericVector QSpatialMatrixComponent1EigenValues,
                                               int currentNumberOfIterations);

List multivariateBernoulliNetworkLerouxBetaUpdate(NumericMatrix standardizedX,
                                                  NumericVector y,
                                                  const int numberOfResponses,
                                                  NumericMatrix spatialAssignmentMatrixInTripletForm,
                                                  NumericMatrix WInTripletForm,
                                                  const int numberOfRowsInSpatialAssignmentMatrixTripletForm,
                                                  const int numberOfRowsInWTripletForm,
                                                  NumericVector beta,
                                                  NumericVector spatialRandomEffects,
                                                  NumericVector uRandomEffects,
                                                  double covarianceBetaPrior,
                                                  const int numberOfBetaBlocks,
                                                  const int maxBetaBlockSize,
                                                  NumericVector betaTuningParameter,
                                                  NumericVector betaAcceptanceRate,
                                                  NumericVector numberOfAcceptedBetaDraws,
                                                  NumericVector numberOfAllAcceptedBetaDraws,
                                                  int currentNumberOfIterations);

List multivariateBernoulliNetworkLerouxSpatialRandomEffectsUpdate(NumericMatrix standardizedX,
                                                                  const int numberOfResponses,
                                                                  NumericMatrix spatialAssignment,
                                                                  NumericMatrix squareSpatialNeighbourhoodMatrix,
                                                                  NumericVector y,
                                                                  const int numberOfSpatialAreas,
                                                                  NumericMatrix squareSpatialNeighbourhoodMatrixInTripletForm,
                                                                  NumericMatrix WInTripletForm,
                                                                  const int numberOfRowsInSquareSpatialNeighbourhoodMatrix,
                                                                  const int numberOfRowsInWTripletForm,
                                                                  NumericVector beta,
                                                                  NumericVector spatialRandomEffects,
                                                                  NumericVector uRandomEffects,
                                                                  NumericVector spatialTauSquared,
                                                                  NumericVector spatialRho,
                                                                  NumericVector spatialRandomEffectsTuningParameters,
                                                                  NumericVector spatialRandomEffectsAcceptanceRate,
                                                                  NumericVector numberOfAcceptedSpatialRandomEffectsDraws,
                                                                  NumericVector numberOfAllAcceptedSpatialRandomEffectsDraws,
                                                                  int currentNumberOfIterations,
                                                                  bool centerSpatialRandomEffects);

List multivariateBernoulliNetworkLerouxURandomEffectsUpdate(NumericMatrix standardizedX,
                                                            NumericVector y,
                                                            NumericMatrix W,
                                                            const int numberOfResponses,
                                                            NumericMatrix spatialAssignmentMatrixInTripletForm,
                                                            NumericMatrix WInTripletForm,
                                                            const int numberOfRowsInSpatialAssignmentMatrixInTripletForm,
                                                            const int numberOfRowsInWTripletForm,
                                                            NumericVector beta,
                                                            NumericVector spatialRandomEffects,
                                                            NumericVector uRandomEffects,
                                                            NumericMatrix varianceCovarianceU,
                                                            NumericVector uRandomEffectsTuningParameters,
                                                            NumericVector uRandomEffectsAcceptanceRate,
                                                            NumericVector numberOfAcceptedUREDraws,
                                                            NumericVector numberOfAllAcceptedUREDraws,
                                                            int currentNumberOfIterations,
                                                            bool centerURandomEffects);

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
                                                                           int currentNumberOfIterations);

List multivariateBernoulliNetworkLerouxRhoUpdate(NumericMatrix squareSpatialNeighbourhoodMatrix,
                                                 NumericVector spatialRandomEffects,
                                                 const int numberOfResponses,
                                                 NumericVector spatialTauSquared,
                                                 NumericVector spatialRho,
                                                 NumericVector spatialRhoTuningParameters,
                                                 NumericVector spatialRhoAcceptanceRate,
                                                 NumericVector numberOfAcceptedSpatialRhoDraws,
                                                 NumericVector numberOfAllAcceptedSpatialRhoDraws,
                                                 NumericMatrix QSpatialMatrixComponent1,
                                                 NumericVector QSpatialMatrixComponent1EigenValues,
                                                 int currentNumberOfIterations);

NumericMatrix multivariateBernoulliNetworkLerouxVarianceCovarianceUUpdate(NumericVector randomEffects,
                                                                          const int numberOfResponses,
                                                                          double xi,
                                                                          NumericMatrix omega);

List getMultivariateBernoulliNetworkLerouxFittedValuesAndLikelihoodForDICEveryIteration(NumericMatrix standardizedX,
                                                                         NumericVector y,
                                                                         NumericMatrix spatialAssignment,
                                                                         NumericMatrix W,
                                                                         NumericVector beta,
                                                                         NumericVector spatialRandomEffects,
                                                                         NumericVector uRandomEffects,
                                                                         int numberOfResponses);

List getMultivariateBernoulliNetworkLerouxDIC(NumericMatrix standardizedX,
                                              NumericVector y,
                                              NumericMatrix spatialAssignment,
                                              NumericMatrix W,
                                              NumericMatrix betaSamples,
                                              NumericMatrix spatialRandomEffectsSamples,
                                              NumericMatrix uRandomEffectsSamples,
                                              NumericMatrix logLikelihoodSamples,
                                              int numberOfResponses);


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
                                                                        bool centerURandomEffects);

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
                                                                     bool centerURandomEffects);


