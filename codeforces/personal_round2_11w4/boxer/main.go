package main

import (
	"bufio"
	"fmt"
	"os"
)

var in *bufio.Reader

const weightLimit = 150000

func main() {
	in = bufio.NewReader(os.Stdin)

	var n int
	fmt.Fscan(in, &n)

	cnt := make([]int, weightLimit+3)
	for i := 0; i < n; i++ {
		var ai int
		fmt.Fscan(in, &ai)
		cnt[ai]++
	}

	result := 0
	for i := 1; i <= weightLimit+1; i++ {
		for j := -1; j <= 1; j++ {
			if cnt[i+j] > 0 {
				cnt[i+j]--
				result++
				break
			}
		}
	}
	fmt.Println(result)
}
