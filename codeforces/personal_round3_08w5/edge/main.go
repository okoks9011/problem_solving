package main

import (
	"bufio"
	"fmt"
	"os"
)

var in = bufio.NewReader(os.Stdin)

const tolerance float64 = 0.000001

func isClose(a, b float64) bool {
	if a > b {
		b, a = a, b
	}
	return b-a < tolerance
}

func solve() {
	var n int
	fmt.Fscan(in, &n)

	a := make([]float64, n)
	for i := range a {
		fmt.Fscan(in, &a[i])
	}

	if n == 1 {
		fmt.Println(0)
		return
	}

	result := n
	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			diff := (a[j] - a[i]) / float64(j-i)

			v := a[i] - diff*float64(i)
			curCnt := 0
			for k := 0; k < n; k++ {
				if !isClose(a[k], v) {
					curCnt++
				}
				v += diff
			}
			if curCnt < result {
				result = curCnt
			}
		}
	}
	fmt.Println(result)
}

func main() {
	var t int
	fmt.Fscan(in, &t)

	for i := 0; i < t; i++ {
		solve()
	}
}
