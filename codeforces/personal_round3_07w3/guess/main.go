package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
)

var (
	in  = bufio.NewReader(os.Stdin)
	out = bufio.NewWriter(os.Stdout)
)

func getDiff(cur int) int {
	fmt.Fprintf(out, "? 1 %d\n", cur)
	out.Flush()

	var sum int
	fmt.Fscan(in, &sum)
	return cur - sum
}

func main() {
	defer out.Flush()

	var n, t int
	fmt.Fscan(in, &n)
	fmt.Fscan(in, &t)

	if t != 1 {
		log.Fatalf("invalid t: %d", t)
	}
	var k int
	fmt.Fscan(in, &k)

	cnt := 0
	result := -1
	left, right := 1, n
	for left <= right {
		mid := left + (right-left)/2
		if getDiff(mid) >= k {
			result = mid
			right = mid - 1
		} else {
			left = mid + 1
		}
		cnt++
		if cnt > 20 {
			log.Fatal("cnt is over")
		}
	}
	fmt.Fprintf(out, "! %d\n", result)
}
