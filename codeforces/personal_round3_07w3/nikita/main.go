package main

import "fmt"

func max(a, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}

func main() {
	var s string
	fmt.Scan(&s)

	n := len(s)

	aCnt, bCnt := 0, 0
	aAcc, bAcc := make([]int, n+1), make([]int, n+1)
	for i, si := range s {
		if si == 'a' {
			aCnt++
		} else if si == 'b' {
			bCnt++
		} else {
			panic("impossible")
		}
		aAcc[i+1] = aCnt
		bAcc[i+1] = bCnt
	}

	maxSize := 0
	for i := 0; i <= n; i++ {
		for j := i; j <= n; j++ {
			curSize := aAcc[i]
			curSize += bAcc[j] - bAcc[i]
			curSize += aAcc[n] - aAcc[j]
			maxSize = max(maxSize, curSize)
		}
	}
	fmt.Println(maxSize)
}
