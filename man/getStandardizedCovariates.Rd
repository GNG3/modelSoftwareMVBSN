\name{getStandardizedCovariates}
\alias{getStandardizedCovariates}

\title{
  A function that generates the response vector, non-standardized design matrix, and standardized design matrix for a model.
}

\description{
  This function generates the response vector, non-standardized design matrix, and standardized design matrix for a model.
}

\usage{
  getStandardizedCovariates(formula, data)
}

\arguments{
  \item{formula}{
  Type: string. A string which specifies the formula for the model.
  }
  \item{data}{
  Type: data.frame. The data used in the model.
  }
}

\value{

  \item{y}{
    Type: vector. The resultant response vector.
  }
  \item{X}{
    Type: data.frame. The resultant non-standardized design matrix.
  }
  \item{standardizedX}{
    Type: data.frame. The resultant standardized design matrix.
  }
  
}

\author{
George Gerogiannis
}

\examples{

  data = data.frame(matrix(sample(1:12), 4, 3, dimnames = list(c(), c("Y", "Cov1", "Cov2"))))
  formula = Y ~ as.factor(Cov1) + Cov2
  getStandardizedCovariates(formula, data)
  
}
