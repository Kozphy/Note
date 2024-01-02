package stat_func

import (
	"fmt"

	"github.com/montanaflynn/stats"
)

func Execute_variant() {
	population_dataset := map[string]stats.Float64Data{
		"first":  {2, 2, 3, 3},
		"second": {0, 0, 5, 5},
	}
	for dataset_name, data := range population_dataset {
		if result, err := stats.Variance(data); err == nil {
			fmt.Printf("%s dataset variance is %v\n", dataset_name, result)
		}
	}
}
