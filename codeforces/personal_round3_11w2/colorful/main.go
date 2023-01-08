package main

import (
	"bufio"
	"fmt"
	"os"
)

const UNKNOWN_COLOR = 100001

var in = bufio.NewReader(os.Stdin)

func main() {
	var n, m int
	fmt.Fscan(in, &n)
	fmt.Fscan(in, &m)

	colors := make(map[int]map[int]struct{})
	c := make([]int, n)
	for i := range c {
		fmt.Fscan(in, &c[i])
		if _, ok := colors[c[i]]; !ok {
			colors[c[i]] = make(map[int]struct{})
		}
	}

	for i := 0; i < m; i++ {
		var ai, bi int
		fmt.Fscan(in, &ai)
		fmt.Fscan(in, &bi)
		ai--
		bi--

		if c[ai] != c[bi] {
			colors[c[ai]][c[bi]] = struct{}{}
			colors[c[bi]][c[ai]] = struct{}{}
		}
	}

	selected, maxV := UNKNOWN_COLOR, 0
	for color, neighbors := range colors {
		fmt.Printf("%d: %v\n", color, neighbors)
		freq := len(neighbors)
		if freq > maxV {
			maxV = freq
			selected = color
		} else if freq == maxV {
			if selected > color {
				selected = color
			}
		}
	}
	fmt.Println(selected)
}
