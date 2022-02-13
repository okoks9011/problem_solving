package main

import (
	"bufio"
	"fmt"
	"os"
)

var in *bufio.Reader

func solve() {
	var n int64
	fmt.Fscan(in, &n)

	c := make([]int, n)
	for i := int64(0); i < n; i++ {
		fmt.Fscan(in, &c[i])
	}

	evenMin, oddMin := c[0], c[1]
	evenAcc, oddAcc := int64(evenMin), int64(oddMin)
	evenSum, oddSum := int64(evenMin)*n, int64(oddMin)*n
	result := evenSum + oddSum
	for i := int64(2); i < n; i++ {
		if i%2 == 0 {
			evenAcc += int64(c[i])
			if c[i] < evenMin {
				evenMin = c[i]
			}
			evenSum = evenAcc + (n-(i/2+1))*int64(evenMin)
		} else {
			oddAcc += int64(c[i])
			if c[i] < oddMin {
				oddMin = c[i]
			}
			oddSum = oddAcc + (n-(i/2+1))*int64(oddMin)
		}
		cur := evenSum + oddSum
		if cur < result {
			result = cur
		}
	}
	fmt.Println(result)
}

func main() {
	in = bufio.NewReader(os.Stdin)

	var t int
	fmt.Fscan(in, &t)

	for i := 0; i < t; i++ {
		solve()
	}
}
