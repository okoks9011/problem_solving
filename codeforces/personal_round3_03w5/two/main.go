package main

import (
	"bufio"
	"fmt"
	"os"
)

var in = bufio.NewReader(os.Stdin)

func main() {
	var n int
	fmt.Fscan(in, &n)

	var limit int64 = 1
	for i := 0; i < 31; i++ {
		limit *= 2
	}

	cnt := make(map[int64]int64)
	var result int64 = 0
	for i := 0; i < n; i++ {
		var ai int64
		fmt.Fscan(in, &ai)

		for x := int64(2); x <= limit; x <<= 1 {
			v, ok := cnt[x-ai]
			if ok {
				result += v
			}
		}
		cnt[ai]++
	}
	fmt.Println(result)
}
