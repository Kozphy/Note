package stat_func

import (
	"github.com/montanaflynn/stats"
)

func Execute_variant() {
	// type dataset stats.Float64Data
	population_dataset := map[string]stats.Float64Data{
		"one": {2, 2, 3, 3},
		"two": {0, 0, 5, 5},
	}
	stats.Variane(population_dataset["one"])
}
