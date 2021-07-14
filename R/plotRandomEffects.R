plotRandomEffects = function(randomEffectsSamples, trueRandomEffects) {
  postMean = apply(randomEffectsSamples, 2, mean)
  randomEffects = as.data.frame(cbind(postMean, trueRandomEffects))
  rownames(randomEffects) = paste("R.E.", seq(1, ncol(randomEffectsSamples)))
  
  plot = ggplot(randomEffects,
                aes(x = postMean, y = trueRandomEffects, label = rownames(randomEffects))) +
    geom_abline(slope = 1, intercept = 0) +
    geom_point(color = "white", size = 3) +
    geom_text() +
    ggtitle("Random Effects: True Values vs. Posterior Means") +
    xlab("Posterior Means") +
    ylab("True Values") +
    xlim(min(c(postMean, trueRandomEffects)), max(c(postMean, trueRandomEffects))) +
    ylim(min(c(postMean, trueRandomEffects)), max(c(postMean, trueRandomEffects)))
  
  return(plot)
}
