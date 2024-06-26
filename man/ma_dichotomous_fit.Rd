% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/model_averaging_fits.R
\name{ma_dichotomous_fit}
\alias{ma_dichotomous_fit}
\title{ma_dichotomous_fit - Fit a model averaged dichotomous BMD model.}
\usage{
ma_dichotomous_fit(
  D,
  Y,
  N,
  model_list = integer(0),
  fit_type = "laplace",
  BMR_TYPE = "extra",
  BMR = 0.1,
  point_p = 0.01,
  alpha = 0.05,
  samples = 21000,
  burnin = 1000,
  BMD_TYPE = NA,
  threads = 2,
  seed = 12331
)
}
\arguments{
\item{D}{doses matrix}

\item{Y}{response matrix}

\item{N}{number of replicates matrix}

\item{model_list}{a list of configurations for the single models (priors, model type)}

\item{fit_type}{the method used to fit (laplace, mle, or mcmc)}

\item{BMR_TYPE}{Specifies the type of benchmark dose analysis to be performed. For dichotomous models, "extra" is the default BMR type. Other strings lead to "added" BMR calculations.}

\item{BMR}{This option specifies the benchmark response BMR. The BMR is defined in relation to the BMD calculation requested (see BMD).  By default, the "BMR = 0.1."}

\item{point_p}{This option is only used for hybrid BMD calculations. It defines a probability that is the cutpoint for observations.  It is the probability that observations have this probability, or less, of being observed at the background dose.}

\item{alpha}{Alpha is the specified nominal coverage rate for computation of the lower bound on the BMDL and BMDU, i.e., one computes a \eqn{100\times(1-\alpha)\% }.  For the interval (BMDL,BMDU) this is a \eqn{100\times(1-2\alpha)\% }.  By default, it is set to 0.05.}

\item{samples}{the number of samples to take (MCMC only)}

\item{burnin}{the number of burnin samples to take (MCMC only)}

\item{BMD_TYPE}{Deprecated version of BMR_TYPE that specifies the type of benchmark dose analysis to be performed}

\item{threads}{number of threads to use. Default = 2}

\item{seed}{specify the GSL seed. Default = 12331}
}
\value{
a model object containing a list of single models
\itemize{
 \item \code{Individual_Model_X}: Here \code{X} is a number \eqn{1\leq X \leq n,} where \eqn{n}
        is the number of models in the model average.  For each \code{X}, this is an individual model
        fit identical to what is returned in `\code{single_continuous_fit}.'
 \item \code{ma_bmd}: The CDF of the model averaged BMD distribution.
 \item \code{posterior_probs}: The posterior model probabilities used in the MA.
 \item \code{bmd}: The BMD and the \eqn{100\times(1-2\alpha)\%} confidence intervals.
}
}
\description{
Fit a model averaged dichotomous BMD model.
}
\examples{
\donttest{
mData <- matrix(c(
  0, 2, 50,
  1, 2, 50,
  3, 10, 50,
  16, 18, 50,
  32, 18, 50,
  33, 17, 50
), nrow = 6, ncol = 3, byrow = TRUE)
D <- mData[, 1]
Y <- mData[, 2]
N <- mData[, 3]
model <- ma_dichotomous_fit(D, Y, N)

summary(model)
}
}
