package main

import "fmt"

type set map[int]struct{}

func copySet(s set) set {
	result := make(set)
	for k := range s {
		result[k] = struct{}{}
	}
	return result
}

func min(a, b int) int {
	if a < b {
		return a
	} else {
		return b
	}
}

func main() {
	var n int
	fmt.Scan(&n)

	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	prefSet := make(set)
	result := n
	for i := 0; i < n; i++ {
		curSet := copySet(prefSet)
		j := n - 1
		for ; j >= i; j-- {
			if _, ok := curSet[a[j]]; ok {
				break
			}
			curSet[a[j]] = struct{}{}
		}
		result = min(result, j-i+1)

		_, ok := prefSet[a[i]]
		if ok {
			break
		}
		prefSet[a[i]] = struct{}{}
	}
	fmt.Println(result)
}
