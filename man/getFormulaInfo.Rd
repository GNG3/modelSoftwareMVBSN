\name{getFormulaInfo}
\alias{getFormulaInfo}

\title{
  A function that generates generates user-defined inputs for use in getStandardizedCovariates.
}

\description{
  This function generates user-defined inputs for use in getStandardizedCovariates.
}

\usage{
  getFormulaInfo(formula, data)
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

  \item{call}{
    Type: string.
  }
  \item{matchCall}{
    Type: string.
  }
  \item{namesMatchCall}{
    Type: string. 
  }
  \item{match}{
    Type: string. 
  }
  \item{matchCallAttributes}{
    Type: string. 
  }
  
}

\author{
George Gerogiannis
}

\examples{

  data = data.frame(matrix(rnorm(9), 3, 3, dimnames = list(c(), c("Y", "X1", "X2"))))
  formula = Y ~ X1 + X2
  getFormulaInfo(formula, data)
  
}
