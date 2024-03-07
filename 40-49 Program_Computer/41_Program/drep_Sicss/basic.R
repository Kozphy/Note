# my_object <- (2 / 4) * 3

# View(environment)

library(plotly)
g <- ggplot(faithful, aes(x = eruptions, y = waiting)) +
    stat_density_2d(aes(fill = ..level..), geom = "polygon") +
    xlim(1, 6) +
    ylim(40, 100)
ggplotly(g)
