package main

import (
	"bufio"
	"fmt"
	"os"
)

var in *bufio.Reader

func dfs(cur int, grid [][]bool, visited []int, color int) {
	visited[cur] = color

	for adj := 0; adj < 26; adj++ {
		if cur == adj {
			continue
		}
		if grid[cur][adj] && visited[adj] == 0 {
			dfs(adj, grid, visited, color)
		}
	}
}

func main() {
	in = bufio.NewReader(os.Stdin)

	var n int
	fmt.Fscan(in, &n)

	a := make([]string, 0, n)
	for i := 0; i < n; i++ {
		var ai string
		fmt.Fscan(in, &ai)
		a = append(a, ai)
	}

	grid := make([][]bool, 26)
	for i := 0; i < 26; i++ {
		grid[i] = make([]bool, 26)
	}
	for _, word := range a {
		si := word[0] - 'a'
		for i := 1; i < len(word); i++ {
			ci := word[i] - 'a'
			grid[si][ci] = true
			grid[ci][si] = true
		}
	}

	color := 1
	visited := make([]int, 26)
	for i := 0; i < 26; i++ {
		if visited[i] == 0 {
			dfs(i, grid, visited, color)
			color++
		}
	}

	comps := make(map[int]bool)
	for _, word := range a {
		comps[visited[word[0]-'a']] = true
	}
	fmt.Println(len(comps))
}
