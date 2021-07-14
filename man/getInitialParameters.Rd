\name{getInitialParameters}
\alias{getInitialParameters}

\title{
  A function that generates positive random numbers close to zero to randomly initialize a sampling step.
}

\description{
  This function transforms a computes the number of columns in a dataframe type and returns a vector type of normally distributed numbers near 0 of length equal to the number of columns in the dataframe.
}

\usage{
getInitialParameters(X)
}

\arguments{
  \item{X}{
    Type: data.frame. 
 }
}

\value{
  \item{initialParameters}{Type: vector. The resultant vector of positive random numbers close to zero for the X dataframe.}
}

\author{
George Gerogiannis
}

\examples{

X = matrix(rep(1, 12), 4, 3)
X = as.data.frame(X)
getInitialParameters(X)

}
