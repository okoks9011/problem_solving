package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
)

var in = bufio.NewReader(os.Stdin)

func main() {
	var n int
	fmt.Fscan(in, &n)

	a := make([]float64, n)
	for i := range a {
		fmt.Fscan(in, &a[i])
	}

	var maxSum int64 = 0
	for _, ai := range a {
		maxSum += int64(math.Ceil(ai))
	}

	cnt := maxSum
	for _, ai := range a {
		// Is it okay to compare float with equal?
		if ai == math.Floor(ai) {
			fmt.Println(int64(ai))
			continue
		}

		if cnt > 0 {
			fmt.Println(int64(math.Floor(ai)))
			cnt--
		} else {
			fmt.Println(int64(math.Ceil(ai)))
		}
	}
}
