\name{checkModelMCMCInputParameters}
\alias{checkModelMCMCInputParameters}

\title{
  A function that checks that the values for the numberOfSamples, burnin, and thin are compatible.
}

\description{
  This function that checks that the values for the numberOfSamples, burnin, and thin are compatible for use in the function calls used to run MCMC models in this package.
}

\usage{
  checkModelMCMCInputParameters(numberOfSamples, burnin, thin)
}

\arguments{
  \item{numberOfSamples}{
  Type: integer. The number of samples the user wishes the sampler to go through.
  }
  \item{burnin}{
  Type: integer. The number of samples the user wishes the sampler to discard as burn-in.
  }
  \item{thin}{
  Type: integer. The number of the user wishes to thin by.
  }
}

\author{
  George Gerogiannis
}

\examples{
  checkModelMCMCInputParameters(numberOfSamples = 20000, burnin = 2, thin = 10000)
}
