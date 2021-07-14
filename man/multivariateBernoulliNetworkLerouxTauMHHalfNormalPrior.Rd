\name{multivariateBernoulliNetworkLerouxTauMHHalfNormalPrior}
\alias{multivariateBernoulliNetworkLerouxTauMHHalfNormalPrior}

\title{
  A function that generates samples for a multivariate Bernoulli Network Leroux 
  model.
}

\description{
  This function generates samples for a multivariate Bernoulli Network Leroux 
  model.
}

\usage{
multivariateBernoulliNetworkLerouxTauMHHalfNormalPrior(formula, 
data, squareSpatialNeighbourhoodMatrix, spatialAssignment, W,
numberOfSamples = 10, burnin = 0, thin = 1, seed = 1, trueBeta = NULL,
trueSpatialRandomEffects = NULL, trueURandomEffects = NULL,
trueSpatialTau = NULL, trueSpatialRho = NULL, trueVarianceCovarianceU = NULL,
covarianceBetaPrior = 10^5, sigmaSquaredSpatialTau = 1000, xi, omega, 
centerSpatialRandomEffects = TRUE, centerURandomEffects = TRUE) 
}

\arguments{

  \item{formula}{
    Type: string.A formula for the covariate part of the model using a similar 
    syntax to thatused in the lm() function.
  }
  \item{data}{
    Type: data.frame. The data containing the responses and covariates.
  }
  \item{squareSpatialNeighbourhoodMatrix}{
    Type: data.frame. A $S times S$ symmetric and non-negative neighbourhood
    matrix whose row sums must all be positive. Typically a binary specification
    is used, where the $sl$th element $a_{sl}$ equals one if areas 
    ($mathcal{G}_{s}$, $mathcal{G}_{s}$) are spatially close (e.g. share a 
    common border) and is zero otherwise.
  }
  \item{spatialAssignment}{
    Type: data.frame. The spatial assignment of individuals to areas.
  }
  \item{W}{
    Type: data.frame. A $sum_{s=1}^{S}N_{s} times J$ matrix that encodes the 
    social network structure and whose rows sum to 1.
  }
  \item{numberOfSamples}{
    Type: integer. The number of samples to generate pre-thinning.
  }
  \item{burnin}{
    Type: integer. The number of MCMC samples to discard as the burn-in period.
  }
  \item{thin}{
    Type: integer. The value by which to thin numberOfSamples.
  }
  \item{seed}{
    Type: integer.
  }
  \item{trueBeta}{
    Type: vector. The option to fix betas in the model to some fixed value. 
  }
  \item{trueSpatialRandomEffects}{
    Type: vector. The option to fix spatial random effects in the model to some 
    fixed value. 
  }
  \item{trueURandomEffects}{
    Type: vector. The option to fix u random effects in the model to some fixed 
    value. 
  }
  \item{trueSpatialTau}{
    Type: vector. The option to fix spatial taus in the model to some fixed 
    value. 
  }
  \item{trueSpatialRho}{
    Type: vector. The option to fix rho in the model to some fixed value. 
  }
  \item{trueVarianceCovarianceU}{
    Type: data.frame. The option to fix Variance Covariance U in the model to 
    some fixed value. 
  }
  \item{covarianceBetaPrior}{
    Type: double. Hyper parameter for the Gaussian prior relating to the betas 
    in the model. the double scales an identity matrix.
  }
  \item{sigmaSquaredSpatialTau}{
    Type: double. Hyper parameter for the Half-Normal prior relating to spatial
    tau parameter in the model.
  }
  \item{xi}{
    Type: integer. Hyper parameter for the Inverse-Wishart relating to variance
    covariance u in the model.
  }
  \item{omega}{
    Type: data.frame. Hyper parameter for the Inverse-Wishart relating to Variance
    Covariance u in the model.
  }
  \item{centerSpatialRandomEffects}{
    Type: boolean. An option to center the spatial random effects after every 
    iteration of the sampler.
  }
  \item{centerURandomEffects}{
    Type: boolean. An option to center the u random effects after every 
    iteration of the sampler.
  }
}

\value{

  \item{call}{
    Type: string.
  }
  \item{y}{
    Type: vector.
  }
  \item{X}{
    Type: data.frame.
  }
  \item{squareSpatialNeighbourhoodMatrix}{
    Type: data.frame.
  }
  \item{spatialAssignment}{
    Type: data.frame.
  }
  \item{W}{
    Type: data.frame.
  }
  \item{standardizedX}{
    Type: data.frame.
  }
  \item{samples}{
    Type: data.frame.
  }
  \item{betaSamples}{
    Type: data.frame.
  }
  \item{spatialTauSamples}{
    Type: vector.
  }
  \item{spatialRhoSamples}{
    Type: vector.
  }
  \item{varianceCovarianceUSamples}{
    Type: data.frame.
  }
  \item{spatialRandomEffectsSamples}{
    Type: data.frame.
  }
  \item{uRandomEffectsSamples}{
    Type: data.frame.
  }
  \item{acceptanceRates}{
    Type: vector.
  }
  \item{betaAcceptanceRate}{
    Type: vector.
  }
  \item{spatialTauAcceptanceRate}{
    Type: vector.
  }
  \item{spatialRhoAcceptanceRate}{
    Type: vector.
  }
  \item{varianceCovarianceUAcceptanceRate}{
    Type: vector.
  }
  \item{spatialRandomEffectsAcceptanceRate}{
    Type: vector.
  }
  \item{uRandomEffectsAcceptanceRate}{
    Type: vector.
  }
  \item{timeTaken}{
    Type: double.
  }
  \item{burnin}{
    Type: integer.
  }
  \item{thin}{
    Type: integer.
  }
  \item{DBar}{
    Type: double.
  }
  \item{posteriorDeviance}{
    Type: double.
  }
  \item{posteriorLogLikelihood}{
    Type: double.
  }
  \item{pd}{
    Type: double.
  }
  \item{DIC}{
    Type: double.
  }
  
}

\author{
George Gerogiannis
}
