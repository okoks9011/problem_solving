package main

import (
	"bufio"
	"fmt"
	"os"
)

var (
	in  = bufio.NewReader(os.Stdin)
	out = bufio.NewWriter(os.Stdout)
)

var diffs = []struct {
	i, j int
}{
	{0, -1}, {1, 0}, {0, 1}, {-1, 0},
}

func dfs(x, y int, grid []string, component [][]int, color int) int {
	n := len(component)
	m := len(component[0])

	// Assume always within valid grid.
	component[x][y] = color
	pictures := 0
	for _, d := range diffs {
		ni, nj := x+d.i, y+d.j
		if ni < 0 || n <= ni || nj < 0 || m <= nj {
			continue
		}
		if grid[ni][nj] == '*' {
			pictures++
		} else if grid[ni][nj] == '.' {
			if component[ni][nj] == 0 {
				pictures += dfs(ni, nj, grid, component, color)
			}
		} else {
			panic("impossible")
		}
	}
	return pictures
}

func main() {
	defer out.Flush()

	var n, m, k int

	fmt.Fscan(in, &n)
	fmt.Fscan(in, &m)
	fmt.Fscan(in, &k)

	grid := make([]string, n)
	for i := range grid {
		fmt.Fscan(in, &grid[i])
	}

	component := make([][]int, n)
	for i := range component {
		component[i] = make([]int, m)
	}

	newColor := 1
	results := []int{-1}
	for q := 0; q < k; q++ {
		var x, y int
		fmt.Fscan(in, &x)
		fmt.Fscan(in, &y)
		x--
		y--

		if component[x][y] == 0 {
			pictures := dfs(x, y, grid, component, newColor)
			newColor++
			results = append(results, pictures)
		}

		fmt.Fprintln(out, results[component[x][y]])
	}
}
