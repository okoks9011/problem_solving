package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
)

type elem struct {
	x int
	h int
}

func main() {
	in := bufio.NewReader(os.Stdin)

	var n int
	fmt.Scanln(&n)

	woods := make([]elem, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &woods[i].x, &woods[i].h)
	}

	last_idx := int(math.MinInt32)
	cnt := 0
	for i, wood := range woods {
		if (wood.x - wood.h) > last_idx {
			last_idx = wood.x
			cnt += 1
		} else if i == n-1 || (wood.x+wood.h) < woods[i+1].x {
			last_idx = wood.x + wood.h
			cnt += 1
		} else {
			last_idx = wood.x
		}
	}
	fmt.Println(cnt)
}
