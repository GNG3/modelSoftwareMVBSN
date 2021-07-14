plot.modelSoftwareMVBSN = function(x, ...) {
  
  covariateNames =  colnames(x)
  
  for(i in 1:ncol(x)){
    
    buffer = 0.1 * (max(x[, i]) - min(x[, i]))
    maxValue = x[, i] + buffer
    minValue = x[, i] - buffer
    
    par(mfrow = c(1,3))
    
    plot(x = 1:length(x[, i]), y = x[, i], type = "l", xlab = "Iteration", ylab = covariateNames[i], ylim = range(minValue, maxValue))
    
    plot(density(x[, i]), main = paste(covariateNames[i]), xlim = range(minValue, maxValue))
    
    acf(x[, i], main = paste(covariateNames[i]))
    
  } 
  
}
