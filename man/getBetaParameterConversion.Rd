\name{getBetaParameterConversion}
\alias{getBetaParameterConversion}

\title{
  A function that converts beta parameter samples relating to the standardized design matrix to the non-standardized design matrix.
}

\description{
  This function converts beta parameter samples relating to the standardized design matrix to the non-standardized design matrix.
}

\usage{
  getBetaParameterConversion(X, betaSamples)
}

\arguments{

  \item{X}{
    Type: data.frame. The non-standarized design matrix.
  }
  \item{betaSamples}{
    Type: data.frame. The beta parameter samples relating to the standardized design matrix
  }
  
}

\value{

  \item{betaSamples}{
    Type: data.frame. The beta parameter samples relating to the non-standarized design matrix
  }
  
}

\author{
George Gerogiannis
}

\examples{

  X = matrix(cbind(rnorm(10), rnorm(10)), 10, 2, dimnames = list(c(), c("(Intercept)", "X2")))
  betaSamples = matrix(rnorm(20), 10, 2, dimnames = list(c(), c("beta1", "beta1")))
  betaSamples = data.frame(betaSamples)
  betaSamples = getBetaParameterConversion(X, betaSamples)
  
}
