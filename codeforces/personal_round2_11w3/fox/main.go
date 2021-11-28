package main

import "fmt"

type color int

const (
	white color = iota
	gray
	black
)

func hasCycle(i, j int, grid []string, visited [][]color, label byte, pi, pj int) bool {
	n, m := len(grid), len(grid[0])
	if i < 0 || n <= i || j < 0 || m <= j {
		return false
	}
	if grid[i][j] != label {
		return false
	}
	if visited[i][j] == black {
		return false
	}
	if visited[i][j] == gray {
		return true
	}

	visited[i][j] = gray
	for _, d := range []struct{ x, y int }{{-1, 0}, {0, 1}, {1, 0}, {0, -1}} {
		if (i+d.x == pi) && (j+d.y == pj) {
			continue
		}
		if hasCycle(i+d.x, j+d.y, grid, visited, label, i, j) {
			return true
		}
	}
	visited[i][j] = black

	return false
}

func main() {
	var n, m int
	fmt.Scan(&n)
	fmt.Scan(&m)

	grid := make([]string, n)
	for i := 0; i < n; i++ {
		var tmp string
		fmt.Scan(&tmp)
		grid[i] = tmp
	}

	visited := make([][]color, n)
	for i := 0; i < n; i++ {
		visited[i] = make([]color, m)
	}

	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			if visited[i][j] != white {
				continue
			}
			if hasCycle(i, j, grid, visited, grid[i][j], -1, -1) {
				fmt.Println("Yes")
				return
			}
		}
	}
	fmt.Println("No")
}
