package main

func calCostV(cur int, dpCostV []int, v int) int {
	if dpCostV[cur] != -1 {
		return dpCostV[cur]
	}

	if cur == v {
		return 0
	}
	if cur > v {
		panic("impossible")
	}
	result := 1001
	for x := cur; x >= 1; x-- {
		next := cur + cur/x
		if next > v {
			break
		}
		candi := calCostV(next, dpCostV, v) + 1
		if candi < result {
			result = candi
		}
	}
	if result == 1001 {
		panic("impossible")
	}
	dpCostV[cur] = result
	return dpCostV[cur]
}

func getCost2(v int) int {
	if dpCost[v] != -1 {
		return dpCost[v]
	}

	dpCostV := make([]int, v+1)
	for i := range dpCostV {
		dpCostV[i] = -1
	}
	dpCost[v] = calCostV(1, dpCostV, v)
	return dpCost[v]
}
