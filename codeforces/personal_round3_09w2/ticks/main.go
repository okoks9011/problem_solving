package main

import (
	"bufio"
	"fmt"
	"os"
)

var in = bufio.NewReader(os.Stdin)

func findMaxTickSize(y, x int, grid [][]byte) int {
	if grid[y][x] == '.' {
		return -1
	}
	m := len(grid[0])

	i := 0
	for ; ; i++ {
		if y-i < 0 {
			break
		}
		if x-i < 0 || x+i >= m {
			break
		}
		if grid[y-i][x-i] == '.' || grid[y-i][x+i] == '.' {
			break
		}
	}
	return i - 1
}

func paintTick(y, x int, grid [][]byte, size int) {
	for i := 0; i <= size; i++ {
		grid[y-i][x-i] = 'v'
		grid[y-i][x+i] = 'v'
	}
}

func solve() {
	var n, m, k int
	fmt.Fscan(in, &n)
	fmt.Fscan(in, &m)
	fmt.Fscan(in, &k)

	grid := make([][]byte, n)
	for i := range grid {
		var tmp string
		fmt.Fscan(in, &tmp)
		grid[i] = []byte(tmp)
	}

	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			size := findMaxTickSize(i, j, grid)
			if size >= k {
				paintTick(i, j, grid, size)
			}
		}
	}

	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			if grid[i][j] == '*' {
				fmt.Println("NO")
				return
			}
		}
	}
	fmt.Println("YES")
}

func main() {
	var t int
	fmt.Fscan(in, &t)

	for i := 0; i < t; i++ {
		solve()
	}
}
