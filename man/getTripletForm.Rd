\name{getTripletForm}
\alias{getTripletForm}

\title{
  A function that converts a matrix into triplet form.
}

\description{
  This function converts a matrix into triplet form.
}

\usage{
  getTripletForm(membershipMatrix)
}

\arguments{

  \item{membershipMatrix}{
    Type: data.frame. Matrix.
  }
  
}

\value{

  \item{membershipMatrixInTripletForm}{
    Type: data.frame. Matrix in triplet form.
  }
  
}

\author{
George Gerogiannis
}

\examples{

  matrix = matrix(c(0, 3, 0, 0, 0, 1, 1, 0, 0), 3, 3)
  getTripletForm(matrix)
  
}
